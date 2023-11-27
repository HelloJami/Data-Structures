#include <iostream>
using namespace std;

class Stack
{
    int top = -1;
    const static int SIZE = 5;
    int arr[SIZE] = {0};

public:
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == SIZE - 1;
    }

    bool push(int val = 0)
    {
        if (isFull())
            return false;

        arr[++top] = val;
        return true;
    }
    int pop()
    {
        return arr[top--];
    }
};

int main()
{
    Stack s;
    Stack s2;

    for (int i = 0; !(s.isFull()); ++i)
    {
        int temp = 0;
        cout << "Enter a value: ";
        cin >> temp;

        if (s.push(temp))
            cout << "Value enter successfully !!" << endl;
        else
            cout << "Stack is full!!" << endl;
    }
    for (int i = 0; !(s2.isFull()); ++i)
    {
        if (s2.push(s.pop()))
            continue;
    }

    while (!s2.isEmpty()) // s2 work as queue
    {
        int i = 0;
        cout << s2.pop() << " ";
    }
}
