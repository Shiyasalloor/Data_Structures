#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
    
        Node(int value){
            data = value;
            next = nullptr;
        }
        
};

class Stack{
    private:
        Node* top;
        int size;
    
    public:
        Stack(){
            this->size = 0;
            top = nullptr;
        }
        
        void push(int value){
            Node* newNode = new Node(value);
            newNode-> next = top;
            top = newNode;
            size = size+1;
        }
        
        int pop(){
            if(isEmpty()){
                cout<<"Stack is empty.**STACK UNDERFLOW**"<<endl;
                return -1;
            }
            else{
                int poppedValue = top->data;
                Node* temp = top;
                top = top->next;
                delete temp;
                size = size-1;
                
                return poppedValue;
            }
        }
        
        bool isEmpty(){
            return top == nullptr;
        }
        
        int sizeOfStack(){
            return size;
        }
        
        void printStack(){
            cout<<"Stack Elements : ";
            Node* temp = top;
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        
};

int main(){
    Stack stack;
    
    int choice;
    while (true) {
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Stack is Empty" << endl;
        cout << "4. Get the Size of the Stack" << endl;
        cout << "5. Print the Stack" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int ele;
                cout << "Enter the number to add in the Stack: ";
                cin >> ele;
                stack.push(ele);
                break;
            case 2:
                {
                    int poppedValue = stack.pop();
                    if (poppedValue != -1)
                        cout << "Popped value: " << poppedValue << endl;
                }
                break;
            case 3:
                if (stack.isEmpty()) {
                    cout << "The Stack is Empty" << endl;
                } else {
                    cout << "The Stack is not Empty" << endl;
                }
                break;
            case 4:
                cout << "Stack has " << stack.sizeOfStack() << " elements" << endl;
                break;
            case 5:
                stack.printStack();
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
