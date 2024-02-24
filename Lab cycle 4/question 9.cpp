#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList(){
        head=nullptr;
    }

    void insert(int key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    bool remove(int key) {
        if (!head) {
            return false;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return true;
            }
            current = current->next;
        }

        return false;
    }

    bool search(int key) {
        Node* current = head;
        while (current) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class HashTable {
private:
    static const int tableSize = 10;
    LinkedList* table;

public:
    HashTable() {
        table = new LinkedList[tableSize];
    }

    ~HashTable() {
        delete[] table;
    }

    int hash(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int index = hash(key);
        table[index].insert(key);
        cout << "Inserted key " << key << " at index " << index << endl;
    }

    void remove(int key) {
        int index = hash(key);
        if (table[index].remove(key)) {
            cout << "Deleted key " << key << " from index " << index << endl;
        } else {
            cout << "Key " << key << " not found in the hash table." << endl;
        }
    }

    bool search(int key) {
        int index = hash(key);
        if (table[index].search(key)) {
            cout << "Key " << key << " found at index " << index << endl;
            return true;
        } else {
            cout << "Key " << key << " not found in the hash table." << endl;
            return false;
        }
    }
};

int main() {
    HashTable ht;

    int choice, key;
    while (true) {
        cout<<"\nHash Table Menu:" << endl;
        cout << "1. Insert key" << endl;
        cout << "2. Delete key" << endl;
        cout << "3. Search key" << endl;
        cout << "4. Exit" << std::endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            }
            case 2: {
                cout << "Enter the key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            }
            case 3: {
                cout << "Enter the key to search: ";
                cin >> key;
                ht.search(key);
                break;
            }
            case 4: {
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
