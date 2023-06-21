#include<iostream>
#include<queue>
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

int findBstHeight(Node* root)
{
    if(root==nullptr)
    {
        return 0;
    }
    else
    {
        int lheight = findBstHeight(root->left);
        int rheight = findBstHeight(root->right);
        if(lheight>rheight)
        {
            
            return (lheight+1);
        }
        else
        {
            
            return (rheight+1);
        }
    }

}

int leafNodes(Node* root)
{
    int count = 0;
    if (root == nullptr) {
        return 0;
    }
    if (root != nullptr) {
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->data << " ";
        }
        leafNodes(root->left);
        leafNodes(root->right);
    }
    return count;
}

// Print nodes at a current level
/*void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}*/

void printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node*> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false) {
         
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        // Enqueue left child
        if (node->left != NULL)
            q.push(node->left);
 
        // Enqueue right child
        if (node->right != NULL)
            q.push(node->right);
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
        cout << "5) B-tree height" << endl;
        cout << "6) leaf nodes" << endl;
        cout << "7) BFS" << endl;
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

            case 5:
                cout << endl << "Binary Tree Height: " << endl;
                cout << "********************************" << endl;
                cout<<findBstHeight(root);
                cout << endl << "********************************" << endl;
                break;

            case 6:
                cout << endl << "Leaf Nodes: " << endl;
                cout << "********************************" << endl;
                leafNodes(root);
                cout << endl << "********************************" << endl;
                break;
            
            case 7:
                cout << endl << "Breadth First Search Travesal: " << endl;
                cout << "********************************" << endl;
                printLevelOrder(root);
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
