#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

queue<int> myQueue;

void enqueue(int data)
{
    myQueue.push(data);
}

void dequeue()
{
    if(myQueue.empty())
        cout<<"Stack is underflow"<<endl;
    else
        myQueue.pop();
}

void display()
{
    queue<int> tempQueue = myQueue;
    vector <int> a;

    while (!tempQueue.empty()) {
        cout<<tempQueue.front()<<" ";
        tempQueue.pop();
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

    while (flag)
    {
        cout << "\n 1) Enqueue" << endl;
        cout << " 2) Dequeue" << endl;
        cout << " 3) Display" << endl;
        cout << " 4) Exit" << endl;

        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                int data;
                cout << "Data: ";
                cin >> data;
                enqueue(data);
                break;

            case 2:
                dequeue();
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