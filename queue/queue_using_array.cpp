#include<iostream>
using namespace std;

int queue[100], n = 100;
int l_left = 0, r_right = 0;

void enqueue(int data)
{
    if (r_right == n)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        queue[r_right] = data;
        r_right++;
    }
}

void dequeue()
{
    if (l_left == 0 && r_right == 0)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        queue[r_right] = 0;
        r_right--;
    }
}

void display()
{
    for (int i = 0; i < r_right; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
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
