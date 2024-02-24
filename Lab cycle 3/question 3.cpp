#include<iostream>
using namespace std;

class Node {
public:
    int value;
    static int keyCounter;
    Node* next;
    Node* prev;

    Node() : value(0), next(nullptr), prev(nullptr) {}
    Node(int val) : value(val), next(nullptr), prev(nullptr) {
        keyCounter++;
    }
    Node(int val, Node* nextNode) : value(val), next(nextNode), prev(nullptr) {
        keyCounter++;
    }
};

class BaseList {
public:
    virtual void display() = 0;
    virtual void insertAtBeginning(int val) = 0;
    virtual void insertAtEnd(int val) = 0;
    virtual void insertAtPosition(int val, int pos) = 0;
};

int Node::keyCounter=0;

class SingleLinkedList : public BaseList {
public:
    Node* head;
    Node* tail;
    int size;

    SingleLinkedList() : size(0), head(nullptr), tail(nullptr) {}
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int val, int pos);
    void display();
};

void SingleLinkedList::insertAtBeginning(int val) {
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;

    if(tail==nullptr) {
        tail=head;
    }

    size++;
}

void SingleLinkedList::insertAtEnd(int val) {
    if(tail==nullptr) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode=new Node(val);
    tail->next=newNode;
    tail=newNode;

    size++;
}

void SingleLinkedList::insertAtPosition(int val, int pos) {
    if(pos==0) {
        insertAtBeginning(val);
        return;
    }

    if(pos==size) {
        insertAtEnd(val);
        return;
    }

    if(pos>size) {
        cout<<"Position out of range."<<endl;
        return;
    }

    Node* temp=head;
    for(int i=1;i<pos;i++) {
        temp=temp->next;
    }

    Node* newNode=new Node(val, temp->next);
    temp->next=newNode;

    size++;
}

void SingleLinkedList::display() {
    Node* temp=head;
    while(temp!=nullptr) {
        cout<<temp->value<< "->";
        temp=temp->next;
    }
    cout<<" END"<<endl;
}

class DoubleLinkedList : public BaseList {
public:
    Node* head;
    Node* tail;
    int size;

    DoubleLinkedList() : size(0), head(nullptr), tail(nullptr) {}
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int val, int pos);
    void display();
    void displayFromEnd();
    void insertExisting(Node* exist);
};

void DoubleLinkedList::insertAtBeginning(int val) {
    Node* newNode=new Node(val);
    newNode->next=head;
    newNode->prev=nullptr;

    if(head!=nullptr) {
        head->prev=newNode;
    }
    
    head=newNode;

    if(tail==nullptr) {
        tail=head;
    }

    size++;
}

void DoubleLinkedList::insertAtEnd(int val) {
    if(tail==nullptr) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode=new Node(val);
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;

    size++;
}

void DoubleLinkedList::insertAtPosition(int val, int pos) {
    if (pos==0) {
        insertAtBeginning(val);
        return;
    }

    if(pos==size) {
        insertAtEnd(val);
        return;
    }

    if(pos>size) {
        cout<<"Position out of range."<<endl;
        return;
    }

    Node* temp=head;
    for(int i=1;i<pos;i++) {
        temp=temp->next;
    }

    Node* newNode=new Node(val, temp->next);
    newNode->prev=temp;
    temp->next=newNode;

    size++;
}

void DoubleLinkedList::display() {
    Node* temp=head;
    while(temp!=nullptr) {
        cout<<temp->value<<"<->";
        temp=temp->next;
    }
    cout<<" END"<<endl;
}

void DoubleLinkedList::displayFromEnd() {
    Node* temp=tail;
    while (temp!=nullptr) {
        cout<<temp->value<<"<->";
        temp=temp->prev;
    }
    cout<<" END"<<endl;
}

void DoubleLinkedList::insertExisting(Node* exist) {
    if(tail==nullptr) {
        insertAtBeginning(exist->value);
        return;
    }

    exist->prev=tail;
    tail->next=exist;
    tail=exist;

    size++;
}

class Convert {
public:
    void convertToDoubleLinkedList(const SingleLinkedList& sList, DoubleLinkedList& dList) {
        Node* node=sList.head;
        while (node!=nullptr) {
            dList.insertExisting(node);
            node=node->next;
        }
    }
};

int main() {
    cout<<"Enter the number of elements in the Single Linked List: ";
    int n=0;
    cin>>n;

    cout<<"Enter the elements of the list separated by space: ";
    int val;
    SingleLinkedList sList;

    for (int i=0;i<n;i++) {
        cin>>val;
        sList.insertAtEnd(val);
    }

    DoubleLinkedList dList;
    Convert converter;
    converter.convertToDoubleLinkedList(sList, dList);

    cout<<"The Single Linked List converted into Double Linked List."<<endl;
    cout<<"The Double Linked List from Head to Tail: ";
    dList.display();
    cout<<"The Double Linked List from Tail to Head: ";
    dList.displayFromEnd();

    return 0;
}
#include<iostream>
using namespace std;

class Node {
public:
    int value;
    static int keyCounter;
    Node* next;
    Node* prev;

    Node() : value(0), next(nullptr), prev(nullptr) {}
    Node(int val) : value(val), next(nullptr), prev(nullptr) {
        keyCounter++;
    }
    Node(int val, Node* nextNode) : value(val), next(nextNode), prev(nullptr) {
        keyCounter++;
    }
};

class BaseList {
public:
    virtual void display() = 0;
    virtual void insertAtBeginning(int val) = 0;
    virtual void insertAtEnd(int val) = 0;
    virtual void insertAtPosition(int val, int pos) = 0;
};

int Node::keyCounter=0;

class SingleLinkedList : public BaseList {
public:
    Node* head;
    Node* tail;
    int size;

    SingleLinkedList() : size(0), head(nullptr), tail(nullptr) {}
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int val, int pos);
    void display();
};

void SingleLinkedList::insertAtBeginning(int val) {
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;

    if(tail==nullptr) {
        tail=head;
    }

    size++;
}

void SingleLinkedList::insertAtEnd(int val) {
    if(tail==nullptr) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode=new Node(val);
    tail->next=newNode;
    tail=newNode;

    size++;
}

void SingleLinkedList::insertAtPosition(int val, int pos) {
    if(pos==0) {
        insertAtBeginning(val);
        return;
    }

    if(pos==size) {
        insertAtEnd(val);
        return;
    }

    if(pos>size) {
        cout<<"Position out of range."<<endl;
        return;
    }

    Node* temp=head;
    for(int i=1;i<pos;i++) {
        temp=temp->next;
    }

    Node* newNode=new Node(val, temp->next);
    temp->next=newNode;

    size++;
}

void SingleLinkedList::display() {
    Node* temp=head;
    while(temp!=nullptr) {
        cout<<temp->value<< "->";
        temp=temp->next;
    }
    cout<<" END"<<endl;
}

class DoubleLinkedList : public BaseList {
public:
    Node* head;
    Node* tail;
    int size;

    DoubleLinkedList() : size(0), head(nullptr), tail(nullptr) {}
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int val, int pos);
    void display();
    void displayFromEnd();
    void insertExisting(Node* exist);
};

void DoubleLinkedList::insertAtBeginning(int val) {
    Node* newNode=new Node(val);
    newNode->next=head;
    newNode->prev=nullptr;

    if(head!=nullptr) {
        head->prev=newNode;
    }
    
    head=newNode;

    if(tail==nullptr) {
        tail=head;
    }

    size++;
}

void DoubleLinkedList::insertAtEnd(int val) {
    if(tail==nullptr) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode=new Node(val);
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;

    size++;
}

void DoubleLinkedList::insertAtPosition(int val, int pos) {
    if (pos==0) {
        insertAtBeginning(val);
        return;
    }

    if(pos==size) {
        insertAtEnd(val);
        return;
    }

    if(pos>size) {
        cout<<"Position out of range."<<endl;
        return;
    }

    Node* temp=head;
    for(int i=1;i<pos;i++) {
        temp=temp->next;
    }

    Node* newNode=new Node(val, temp->next);
    newNode->prev=temp;
    temp->next=newNode;

    size++;
}

void DoubleLinkedList::display() {
    Node* temp=head;
    while(temp!=nullptr) {
        cout<<temp->value<<"<->";
        temp=temp->next;
    }
    cout<<" END"<<endl;
}

void DoubleLinkedList::displayFromEnd() {
    Node* temp=tail;
    while (temp!=nullptr) {
        cout<<temp->value<<"<->";
        temp=temp->prev;
    }
    cout<<" END"<<endl;
}

void DoubleLinkedList::insertExisting(Node* exist) {
    if(tail==nullptr) {
        insertAtBeginning(exist->value);
        return;
    }

    exist->prev=tail;
    tail->next=exist;
    tail=exist;

    size++;
}

class Convert {
public:
    void convertToDoubleLinkedList(const SingleLinkedList& sList, DoubleLinkedList& dList) {
        Node* node=sList.head;
        while (node!=nullptr) {
            dList.insertExisting(node);
            node=node->next;
        }
    }
};

int main() {
    cout<<"Enter the number of elements in the Single Linked List: ";
    int n=0;
    cin>>n;

    cout<<"Enter the elements of the list separated by space: ";
    int val;
    SingleLinkedList sList;

    for (int i=0;i<n;i++) {
        cin>>val;
        sList.insertAtEnd(val);
    }

    DoubleLinkedList dList;
    Convert converter;
    converter.convertToDoubleLinkedList(sList, dList);

    cout<<"The Single Linked List converted into Double Linked List."<<endl;
    cout<<"The Double Linked List from Head to Tail: ";
    dList.display();
    cout<<"The Double Linked List from Tail to Head: ";
    dList.displayFromEnd();

    return 0;
}

/*Enter the number of elements in the Single Linked List: 5
Enter the elements of the list separated by space: 5 7 10 25 46
The Single Linked List converted into Double Linked List.
The Double Linked List from Head to Tail: 5<->7<->10<->25<->46<-> END
The Double Linked List from Tail to Head: 46<->25<->10<->7<->5<-> END*/


