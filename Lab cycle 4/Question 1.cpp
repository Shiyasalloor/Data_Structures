#include <iostream>
using namespace std;

class Stack {
private:
    int* stackArray;
    int top;
    int maxSize;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        stackArray[++top] = value;
        cout << "Element added to Stack successfully" << endl;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int value = stackArray[top--];
        return value;
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }

    void printStack() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
        } else {
            for (int i = 0; i <= top; i++) {
                cout << stackArray[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the Stack: ";
    cin >> n;
    Stack stack(n);

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
                cout << "Stack has " << stack.size() << " elements" << endl;
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
