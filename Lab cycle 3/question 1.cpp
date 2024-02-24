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
    int searchValue(int val);
    int countDuplicates(int val);
    void removeDuplicates(int val);
    void displayList();
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
    
    if (pos==size) {
        insertAtEnd(val);
        return;
    }
    
    if (pos>size) {
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

int LinkedList::searchValue(int val) {
    int pos=0;
    int finalPos=-1;
    bool found=false;
    Node* temp=head;
    int* positions=new int[size];
    int t=0;
    
    while(temp!=nullptr) {
        if (temp->value==val) {
            found=true;
            positions[t++]=pos;
            finalPos=pos;
        }
        pos++;
        temp=temp->next;
    }
    
    if(!found) {
        cout<<"Value not found."<<endl;
        return -1;
    }
    else{
        cout<<"Positions of value "<<val<<" in the linked list: ";
        for (int i=0;i<t;i++) {
            cout<<positions[i]<<" ";
        }
        cout<<endl;
    }
    
    return finalPos;
}

int LinkedList::countDuplicates(int val) {
    int pos=0;
    int count=-1;
    bool notFound=true;
    Node* temp=head;
    
    while(temp!=nullptr) {
        if(temp->value==val) {
            count++;
            notFound=false;
        }
        pos++;
        temp=temp->next;
    }
    
    if(notFound){
        cout<<"No duplicates found."<<endl;
    }
    else{
        cout<<"Number of duplicates for value "<<val<<": "<<count<<endl;
    }
    
    return count;
}

void LinkedList::removeDuplicates(int val) {
    bool firstOccurrence=false;
    Node* prev=nullptr;
    Node* current=head;
    
    while(current!=nullptr) {
        if(current->value==val) {
            if(firstOccurrence) {
                if(prev != nullptr) {
                    prev->next=current->next;
                    delete current;
                    current=prev->next;
                    size--;
                }
                else{
                    Node* temp=current;
                    current=current->next;
                    head=current;
                    delete temp;
                    size--;
                }
            }
            else{
                firstOccurrence=true;
                prev=current;
                current=current->next;
            }
        }
        else{
            prev=current;
            current=current->next;
        }
    }
}

void LinkedList::displayList() {
    Node* temp=head;
    
    while(temp!=nullptr) {
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    
    cout<<"END"<<endl;
}

int main() {
    cout<<"Enter the number of elements in the linked list: ";
    int n=0;
    cin>>n;
    
    cout<<"Enter the elements of the list separated by space: ";
    int val;
    LinkedList list;
    
    for(int i=0;i<n;i++) {
        cin>>val;
        list.insertAtEnd(val);
    }
    
    char choice;
    int ele, x;
    
    do{
        cout<<"Enter 's' to search for elements,"<<endl;
        cout<<"Enter 'c' to print the number of times a value is duplicated in the list,"<<endl;
        cout<<"Enter 'r' to delete duplicate entries of a value in the list,"<<endl;
        cout<<"Enter 'i' to insert an element at a specific position in the list,"<<endl;
        cout<<"Enter 'd' to display the list,"<<endl;
        cout<<"Enter 'e' to exit the program."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        switch(choice){
            case 's':
                cout<<"Enter the element to search for: ";
                cin>>ele;
                cout<<endl;
                x=list.searchValue(ele);
                break;
            case 'c':
                cout<<"Enter the element to find the count of duplicates: ";
                cin>>ele;
                cout<<endl;
                x=list.countDuplicates(ele);
                break;
            case 'r':
                cout<<"Enter the element to delete the duplicates of: ";
                cin>>ele;
                cout<<endl;
                list.removeDuplicates(ele);
                break;
            case 'i':
                int pos;
                cout<<"Enter the element to be inserted: ";
                cin>>ele;
                cout<<"Enter the position to insert: ";
                cin>>pos;
                cout<<endl;
                list.insertAtPosition(ele, pos);
                break;
            case 'd':
                cout<<endl<<"The linked list is: ";
                list.displayList();
                break;
            case 'e':
                break;        
            default:
                cout<<"Invalid choice!"<<endl;
        }
        
        cout<<endl<<endl;
    } while(choice!='e');
    
    cout<<"Thank you!"<<endl;
    return 0;
}




/* Enter the number of elements in the linked list: 5
Enter the elements of the list separated by space: 7 9 4 15 25
Enter 's' to search for elements,
Enter 'c' to print the number of times a value is duplicated in the list,
Enter 'r' to delete duplicate entries of a value in the list,
Enter 'i' to insert an element at a specific position in the list,
Enter 'd' to display the list,
Enter 'e' to exit the program.
Enter your choice: s
Enter the element to search for: 15

Positions of value 15 in the linked list: 3 


Enter 's' to search for elements,
Enter 'c' to print the number of times a value is duplicated in the list,
Enter 'r' to delete duplicate entries of a value in the list,
Enter 'i' to insert an element at a specific position in the list,
Enter 'd' to display the list,
Enter 'e' to exit the program.
Enter your choice: c
Enter the element to find the count of duplicates: 15

Number of duplicates for value 15: 0


Enter 's' to search for elements,
Enter 'c' to print the number of times a value is duplicated in the list,
Enter 'r' to delete duplicate entries of a value in the list,
Enter 'i' to insert an element at a specific position in the list,
Enter 'd' to display the list,
Enter 'e' to exit the program.
Enter your choice: r
Enter the element to delete the duplicates of: 15



Enter 's' to search for elements,
Enter 'c' to print the number of times a value is duplicated in the list,
Enter 'r' to delete duplicate entries of a value in the list,
Enter 'i' to insert an element at a specific position in the list,
Enter 'd' to display the list,
Enter 'e' to exit the program.
Enter your choice: i
Enter the element to be inserted: 50
Enter the position to insert: 3



Enter 's' to search for elements,
Enter 'c' to print the number of times a value is duplicated in the list,
Enter 'r' to delete duplicate entries of a value in the list,
Enter 'i' to insert an element at a specific position in the list,
Enter 'd' to display the list,
Enter 'e' to exit the program.
Enter your choice: d

The linked list is: 7->9->4->50->15->25->END


Enter 's' to search for elements,
Enter 'c' to print the number of times a value is duplicated in the list,
Enter 'r' to delete duplicate entries of a value in the list,
Enter 'i' to insert an element at a specific position in the list,
Enter 'd' to display the list,
Enter 'e' to exit the program.
Enter your choice: e


Thank you! */
