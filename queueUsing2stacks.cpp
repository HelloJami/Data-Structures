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

        ++top;
        arr[top] = val;
        return true;
    }
    int pop()
    {
        return arr[top--];
    }
};

class Queue
{
    Stack s1;
    Stack s2;

public:
    void enqueue(int x = 0)
    {
        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }

        s2.push(x);

        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
    }

    int dequeue()
    {
        return s1.pop();
    }
};

int main()
{
    Queue q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";

    q.enqueue(5);

    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
}