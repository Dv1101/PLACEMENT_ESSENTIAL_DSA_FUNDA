#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node* head = NULL;

void insert_at_beginning(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = head;

    if (head != NULL) {
        head->left = new_node;
    }

    head = new_node;
}

void insert_at_end(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->right = NULL;

    if (head == NULL) {
        new_node->left = NULL;
        head = new_node;
        return;
    }

    struct node* ptr = head;
    while (ptr->right != NULL) {
        ptr = ptr->right;
    }

    ptr->right = new_node;
    new_node->left = ptr;
}

void insert_at_anywhere(int data, int posData) {
    if (head == NULL) {
        cout << "Cannot insert at any position. List is empty." << endl;
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    struct node* ptr = head;
    while (ptr != NULL && ptr->data != posData) {
        ptr = ptr->right;
    }

    if (ptr == NULL) {
        cout << "Position data not found in the list." << endl;
        return;
    }

    new_node->right = ptr->right;
    if (ptr->right != NULL) {
        ptr->right->left = new_node;
    }
    ptr->right = new_node;
    new_node->left = ptr;
}

void update(int data, int posData) {
    if (head == NULL) {
        cout << "Cannot update. List is empty." << endl;
        return;
    }

    struct node* ptr = head;
    while (ptr != NULL && ptr->data != posData) {
        ptr = ptr->right;
    }

    if (ptr == NULL) {
        cout << "Position data not found in the list." << endl;
        return;
    }

    ptr->data = data;
}


void delete_at_beginning() {
    if (head == NULL) {
        cout << "Cannot delete. List is empty." << endl;
        return;
    }

    struct node* ptr = head;
    head = ptr->right;

    if (head != NULL) {
        head->left = NULL;
    }

    delete ptr;
}

void delete_at_end() {
    if (head == NULL) {
        cout << "Cannot delete. List is empty." << endl;
        return;
    }

    struct node* ptr = head;

    if (ptr->right == NULL) {
        head = NULL;
        delete ptr;
        return;
    }

    while (ptr->right->right != NULL) {
        ptr = ptr->right;
    }

    struct node* ptr1 = ptr->right;
    ptr->right = NULL;
    delete ptr1;
}

void delete_at_anywhere(int posData) {
    if (head == NULL) {
        cout << "Cannot delete. List is empty." << endl;
        return;
    }

    if (posData == head->data) {
        delete_at_beginning();
        return;
    }

    struct node* ptr = head;

    while (ptr != NULL && ptr->data != posData) {
        ptr = ptr->right;
    }

    if (ptr == NULL) {
        cout << "Position data not found in the list." << endl;
        return;
    }

    struct node* prevNode = ptr->left;
    struct node* nextNode = ptr->right;

    if (prevNode != NULL) {
        prevNode->right = nextNode;
    }

    if (nextNode != NULL) {
        nextNode->left = prevNode;
    }

    delete ptr;
}



void display()
{
    if(head == NULL)
    {
        cout<<endl<<"********************************"<<endl;
        cout<<"LL is EMPTY !!"<<endl;
        cout<<endl<<"********************************"<<endl;
    }
    else
    {
        struct node* ptr;
        ptr = head;
        while(ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->right;
        }
    }
    
}

void find_Pos_left_right(int data) {
    struct node* ptr = head;
    int countPos = 1;
    bool found = false;

    while (ptr != NULL) {
        if (ptr->data == data) {
            found = true;
            break;
        }

        ptr = ptr->right;
        countPos++;
    }

    if (found) {
        cout << "Element: " << data << " is found in LL at position: " << countPos << endl;

        if (ptr->left != NULL) {
            cout << "Left Node: " << ptr->left->data << " is found in LL at position: " << (countPos - 1) << endl;
        }

        if (ptr->right != NULL) {
            cout << "Right Node: " << ptr->right->data << " is found in LL at position: " << (countPos + 1) << endl;
        }
    } else {
        cout << "Element: " << data << " is not found in LL" << endl;
    }
}


int main()
{
    bool flag = true;
    int data, posData;
    while(flag)
    {
        cout<<endl<<endl<<"---+++--- Doubly Linked List ---+++---"<<endl<<endl;
        cout<<"1) Insert at beginning"<<endl;
        cout<<"2) Insert at end"<<endl;
        cout<<"3) Insert at anywhere"<<endl;
        cout<<"4) Update Data"<<endl;
        cout<<"5) Delete at beginning"<<endl;
        cout<<"6) Delete at end"<<endl;
        cout<<"7) Delete at anywhere"<<endl;
        cout<<"8) Find Data, position and left, Right Nodes"<<endl;
        cout<<"9) EXIT"<<endl;
        cout<<endl<<endl<<"Enter choice : ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<endl<<"Enter Data : ";
                cin>>data;
                insert_at_beginning(data);
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                break;

            case 2:
                cout<<endl<<"Enter Data : ";
                cin>>data;
                insert_at_end(data);
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                break;

            case 3:
                cout<<endl<<"Enter Data : ";
                cin>>data;
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                cout<<endl<<"Enter a data from above LL, where next to insert : ";
                cin>>posData;
                insert_at_anywhere(data, posData);
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                break;

            case 4:
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                cout<<endl<<"Enter a data from above LL, which you want to update : ";
                cin>>posData;
                cout<<endl<<"Enter Data : ";
                cin>>data;
                update(data, posData);
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                break;

            case 5:
                delete_at_beginning();
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                break;

            case 6:
                delete_at_end();
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                break;

            case 7:
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                cout<<endl<<"Enter a data from above LL, which u want to delete : ";
                cin>>posData;
                delete_at_anywhere(posData);
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                break;

            case 8:
                cout<<endl<<"********************************"<<endl;
                display();
                cout<<endl<<"********************************"<<endl;
                cout<<endl<<"Enter Node's Data : ";
                cin>>data;
                find_Pos_left_right(data);
                break;

            case 9:
                cout<<endl<<"********************************"<<endl;
                cout<<"Goodbye !!!, Dont forget to give star to my masters GitHub repo **** Dv1101 ****"<<endl;
                cout<<endl<<"********************************"<<endl;
                flag = false;
                break;

            default:
                break;
        }
    }
    return 0;
}