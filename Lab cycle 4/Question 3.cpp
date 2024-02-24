#include<iostream>
using namespace std;

class Queue{
    private:
        int capacity;
        int front;
        int rear;
        int* queue;
        
    public:
        Queue(int capacity){
            this->capacity = capacity;
            front = rear=-1;
            queue = new int[capacity];
        }
        
        bool isEmpty(){
            return front == -1;
        }
        
        bool isFull(){
            return (rear + 1) % capacity == front;
        }
        
        int size(){
            if(isEmpty()){
                return 0;
            }
            else if (rear >= front) {
                return rear - front + 1;
            }
            else {
                return this->capacity - front + rear + 1;
            }
        }
        
        void enqueue(int item){
            if (isFull()) {
                cout << "Queue is full. Cannot enqueue." << endl;
                return;
            }
            else if (isEmpty()) {
                front = rear = 0;
            }
            else {
                rear = (rear + 1) % capacity;
            }
            queue[rear] = item;
            cout<<"Enqueued Succussfully"<<endl;
        }
        
        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty. Cannot dequeue." << endl;
                return -1;
            }
            int removedItem = queue[front];
            if (front == rear) {
                front = rear = -1;
            }
            else {
                front = (front + 1) % capacity;
            }
            return removedItem;
        }
        
        void printQueue(){
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }
        
            int current = front;
            cout << "Queue elements: ";
            
            while (current != rear) {
                cout << queue[current] << " ";
                current = (current + 1) % capacity;
            }
            
            cout << queue[rear] << endl;
        }

};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue queue(capacity);

    while (true) {
        cout << "\nQueue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if the queue is empty" << endl;
        cout << "4. Get the size of the queue" << endl;
        cout << "5. Print the Queue" << endl;
        cout << "6. Quit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                int item;
                cout << "Enter the item to enqueue: ";
                cin >> item;
                queue.enqueue(item);
                break;

            case 2:
                cout << "Dequeue: " << queue.dequeue() << endl;
                break;

            case 3:
                if (queue.isEmpty()) {
                    cout << "The queue is empty." << endl;
                } else {
                    cout << "The queue is not empty." << endl;
                }
                break;

            case 4:
                cout << "Queue size: " << queue.size() << endl;
                break;

            case 5:
                queue.printQueue();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }

    return 0;
}
