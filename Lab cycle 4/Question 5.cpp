#include <iostream>
using std::cout;
using std::cin;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

bool search(Node* root, int data) {
    if (root == nullptr) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;

    while (true) {
        cout << "Binary Tree Menu:\n";
        cout << "1. Insert a value\n";
        cout << "2. Search for a value\n";
        cout << "3. In-order traversal\n";
        cout << "4. Pre-order traversal\n";
        cout << "5. Post-order traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << value << " found in the binary tree.\n";
                } else {
                    cout << value << " not found in the binary tree.\n";
                }
                break;
            }
            case 3:
                cout << "In-order traversal: ";
                inOrderTraversal(root);
                cout << "\n";
                break;
            case 4:
                cout << "Pre-order traversal: ";
                preOrderTraversal(root);
                cout << "\n";
                break;
            case 5:
                cout << "Post-order traversal: ";
                postOrderTraversal(root);
                cout << "\n";
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
