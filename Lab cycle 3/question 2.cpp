#include<iostream>
using namespace std;

class Node {
public:
    int value;
    static int keyCounter;
    Node* next;

    Node() : value(0), next(nullptr) {}
    Node(int val) : value(val), next(nullptr) {
        keyCounter++;
    }
    Node(int val, Node* nextNode) : value(val), next(nextNode) {
        keyCounter++;
    }
};

int Node::keyCounter=0;

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() : size(0), head(nullptr), tail(nullptr) {}
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int val, int pos);
    void display();
};

void LinkedList::insertAtBeginning(int val) {
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;

    if(tail==nullptr) {
        tail=head;
    }

    size++;
}

void LinkedList::insertAtEnd(int val) {
    if(tail==nullptr) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode=new Node(val);
    tail->next=newNode;
    tail=newNode;

    size++;
}

void LinkedList::insertAtPosition(int val, int pos) {
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
    for(int i=1;i<pos; i++) {
        temp=temp->next;
    }

    Node* newNode=new Node(val, temp->next);
    temp->next=newNode;

    size++;
}

void LinkedList::display() {
    Node* temp=head;
    while(temp!=nullptr) {
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<" END"<<endl;
}

class AlternatingLists {
private:
    LinkedList evenList;
    LinkedList oddList;

public:
    AlternatingLists(LinkedList list);
    void displayLists();
};

AlternatingLists::AlternatingLists(LinkedList list) {
    Node* current=list.head;
    int count=0;

    while(current!=nullptr) {
        if(count % 2==0) {
            evenList.insertAtEnd(current->value);
        }else{
            oddList.insertAtEnd(current->value);
        }
        current=current->next;
        count++;
    }
}

void AlternatingLists::displayLists() {
    cout<<"The Even List is: ";
    evenList.display();
    cout<<"The Odd List is: ";
    oddList.display();
}

int main() {
    cout<<"Enter the number of Elements in the Linked List: ";
    int n=0;
    cin>>n;

    cout<<"Enter the Elements of the List separated by space: ";
    int val;
    LinkedList list;

    for(int i=0;i<n;i++) {
        cin>>val;
        list.insertAtEnd(val);
    }

    AlternatingLists alternatingLists(list);
    alternatingLists.displayLists();

    return 0;
}



/* Enter the number of Elements in the Linked List: 5
Enter the Elements of the List separated by space: 8 15 20 25 50
The Even List is: 8->20->50->END
The Odd List is: 15->25->END */
