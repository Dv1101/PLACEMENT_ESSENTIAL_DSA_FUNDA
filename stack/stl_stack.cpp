#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

stack<int> myStack;

void push(int data)
{
    myStack.push(data);
}

void pop()
{
    if(myStack.empty())
        cout<<"Stack is underflow"<<endl;
    else
        myStack.pop();
}

void display()
{
    stack<int> tempStack = myStack;
    vector <int> a;

    while (!tempStack.empty()) {
        int element = tempStack.top();
        a.push_back(element);
        cout << element << " ";
        tempStack.pop();
    }

    cout<<endl;
    reverse(a.begin(), a.end());
    cout<<"Actual sequence is : ";
    for(int i=0; i<a.size(); i++)
    {
        cout<<a.at(i)<<" ";
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