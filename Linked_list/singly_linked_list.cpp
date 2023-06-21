#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* head = NULL;

void insert_at_beginning(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    struct node* ptr;
    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
}

void insert_at_anywhere(int data, int posData)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    struct node* ptr;
    ptr = head;
    while(ptr->data != posData)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void update(int data,int posData)
{
    struct node* ptr;
    ptr = head;
    while(ptr->data != posData)
    {
        ptr = ptr->next;
    }
    ptr->data = data;
}

void delete_at_beginning()
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
        head = ptr->next;
        ptr = NULL;
    }
}

void delete_at_end()
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
        struct node* ptr1;
        ptr = head;
        while(ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr1 = ptr->next;
        ptr1 = NULL;
        ptr->next = NULL;
    }
    
}

void delete_at_anywhere(int posData)
{
    if(head == NULL)
    {
        cout<<endl<<"********************************"<<endl;
        cout<<"LL is EMPTY !!"<<endl;
        cout<<endl<<"********************************"<<endl;
    }
    else if(posData == head->data)
    {
        delete_at_beginning();
    }
    else
    {
        struct node* ptr;
        struct node* ptr1;
        struct node* ptr2;
        ptr = head;
        while(ptr->next->data != posData)
        {
            ptr = ptr->next;
        }
        ptr1 = ptr->next;
        ptr2 = ptr->next->next;
        ptr->next = ptr2;
        ptr1 = NULL;
    }

    
}



void display()
{
    struct node* ptr;
    ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    bool flag = true;
    int data, posData;
    while(flag)
    {
        cout<<endl<<endl<<"---+++--- Singular Linked List ---+++---"<<endl<<endl;
        cout<<"1) Insert at beginning"<<endl;
        cout<<"2) Insert at end"<<endl;
        cout<<"3) Insert at anywhere"<<endl;
        cout<<"4) Update Data"<<endl;
        cout<<"5) Delete at beginning"<<endl;
        cout<<"6) Delete at end"<<endl;
        cout<<"7) Delete at anywhere"<<endl;
        cout<<"8) EXIT"<<endl;
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