#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void insertNode(Node*& root, int data) {
    if (root == nullptr) {
        root = newNode(data);
    } else if (data < root->data) {
        if (root->left == nullptr) {
            root->left = newNode(data);
        } else {
            insertNode(root->left, data);
        }
    } else if (data > root->data) {
        if (root->right == nullptr) {
            root->right = newNode(data);
        } else {
            insertNode(root->right, data);
        }
    }
}

void traversePreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}

void traverseInOrder(Node* root) {
    if (root != nullptr) {
        traverseInOrder(root->left);
        cout << root->data << " ";
        traverseInOrder(root->right);
    }
}

void traversePostOrder(Node* root) {
    if (root != nullptr) {
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    bool flag = true;
    int data;
    Node* root = nullptr;

    while (flag) {
        cout << endl << endl << "---+++--- Binary Tree ---+++---" << endl << endl;
        cout << "1) Insert" << endl;
        cout << "2) preOrder Traversal" << endl;
        cout << "3) inOrder Traversal" << endl;
        cout << "4) postOrder Traversal" << endl;
        cout << "8) EXIT" << endl;
        cout << endl << endl << "Enter choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << endl << "Enter Data: ";
                cin >> data;
                insertNode(root, data);
                break;

            case 2:
                cout << endl << "Pre Order Traversal: " << endl;
                cout << "********************************" << endl;
                traversePreOrder(root);
                cout << endl << "********************************" << endl;
                break;

            case 3:
                cout << endl << "In Order Traversal: " << endl;
                cout << "********************************" << endl;
                traverseInOrder(root);
                cout << endl << "********************************" << endl;
                break;

            case 4:
                cout << endl << "Post Order Traversal: " << endl;
                cout << "********************************" << endl;
                traversePostOrder(root);
                cout << endl << "********************************" << endl;
                break;

            case 8:
                cout << endl << "********************************" << endl;
                cout << "Goodbye!!! Don't forget to give a star to my master's GitHub repo **** Dv1101 ****" << endl;
                cout << endl << "********************************" << endl;
                flag = false;
                break;

            default:
                break;
        }
    }

    return 0;
}
