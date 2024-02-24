#include <iostream>
using std::cout;
using std::cin;
using std::endl;

    class HashTable {
    private:
        static const int tableSize = 10;
        int* table;
        bool* occupied;

    public:
        HashTable() {
            table = new int[tableSize];
            occupied = new bool[tableSize];
            for (int i = 0; i < tableSize; i++) {
                table[i] = -1;
                occupied[i] = false;
            }
        }

        ~HashTable() {
            delete[] table;
            delete[] occupied;
        }

        int hash(int key) {
            return key % tableSize;
        }

        void insert(int key) {
            int index = hash(key);

            while (occupied[index]) {
                index = (index + 1) % tableSize;
            }

            table[index] = key;
            occupied[index] = true;
            cout << "Inserted key " << key << " at index " << index << endl;
        }

        void remove(int key) {
            int index = hash(key);

            while (occupied[index]) {
                if (table[index] == key) {
                    table[index] = -1;
                    occupied[index] = false;
                    cout << "Deleted key " << key << " from index " << index << endl;
                    return;
                }
                index = (index + 1) % tableSize;
            }

            cout << "Key " << key << " not found in the hash table." << endl;
        }

        bool search(int key) {
            int index = hash(key);

            while (occupied[index]) {
                if (table[index] == key) {
                    cout << "Key " << key << " found at index " << index << endl;
                    return true;
                }
                index = (index + 1) % tableSize;
            }

            cout << "Key " << key << " not found in the hash table." << endl;
            return false;
        }
    };


int main() {
    
    HashTable ht;

    int choice, key;
    while (true) {
        cout << "\nHash Table Menu:" << endl;
        cout << "1. Insert key" << endl;
        cout << "2. Delete key" << endl;
        cout << "3. Search key" << endl;
        cout << "4. Exit" << endl;
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
