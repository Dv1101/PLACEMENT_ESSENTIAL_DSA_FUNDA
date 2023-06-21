#include<iostream>
using namespace std;

int stack[100], n=100, top = -1; 

void push(int data)
{
    if(top>=n-1)
        cout<<"\n Stack Overflow !!"<<endl;
    else
        top++;
        stack[top] = data;
        cout<<"Pushed"<<endl;
}

void pop()
{
    if(top==-1)
        cout<<"Stack is already empty"<<endl;
    else
        stack[top] = 0;
        top--;
}

void display()
{
    cout<<endl;
    if(top==-1)
        cout<<"Stack is already empty"<<endl;
    else
        for(int i=0; i<=top; i++){
            cout<<stack[i]<<" ";
        }
}

int main()
{
    int choice;
    bool flag = true;

    while(flag)
    {
        cout<<"\n 1) Push : "<<endl;
        cout<<"\n 2) Pop : "<<endl;
        cout<<"\n 3) Display :"<<endl;
        cout<<"\n 4) Exit :"<<endl;

        cout<<"Your choice : ";
        cin>>choice;

        switch (choice)
        {
            case 1:
                int data;
                cout<<"Data : ";
                cin>>data;
                push(data);
                break;
            
            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                flag = false;
                break;
            
        }
       
    }
    return 0;
}