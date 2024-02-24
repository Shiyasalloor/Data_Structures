#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int capacity) {
        size = capacity;
        queue = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    int getSize() {
        if (isEmpty()) {
            return 0;
        }
        if (isFull()) {
            return size;
        }
        return (rear - front + size + 1) % size;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Enqueue operation failed." << endl;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            queue[rear] = item;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Dequeue operation failed." << endl;
            return -1;
        } else {
            int item = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            return item;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            int i = front;
            do {
                cout << queue[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the Circular Queue: ";
    cin >> capacity;

    CircularQueue cq(capacity);

    int choice;
    while (true) {
        cout << "\nCircular Queue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if Queue is Empty" << endl;
        cout << "4. Get Queue Size" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int item;
                cout << "Enter the item to enqueue: ";
                cin >> item;
                cq.enqueue(item);
                break;
            }
            case 2: {
                int item = cq.dequeue();
                if (item != -1) {
                    cout << "Dequeued item: " << item << endl;
                }
                break;
            }
            case 3: {
                if (cq.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            }
            case 4: {
                int size = cq.getSize();
                cout << "Queue size: " << size << endl;
                break;
            }
            case 5: {
                cout << "Queue contents: ";
                cq.display();
                break;
            }
            case 6: {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
