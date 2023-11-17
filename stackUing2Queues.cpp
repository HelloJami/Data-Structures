#include <iostream>
using namespace std;

class Queue
{
private:
    const static int SIZE = 5;
    int arr[SIZE] = {0};
    int element = 0;
    int front = 0;
    int rear = 0;

public:
    bool isFull() const
    {
        return element == SIZE;
    }
    bool isEmpty() const
    {
        return element == 0;
    }
    bool enqueue(int val = 0)
    {
        if (isFull())
            return false;

        arr[rear] = val;
        rear = (rear + 1) % SIZE;
        element++;
        return true;
    }
    int dequeue()
    {
        if (isEmpty())
            return -1;

        int output = arr[front];
        front = (front + 1) % SIZE;
        element--;
        return output;
    }
};

class Stack
{
    Queue q1;
    Queue q2;
public:
    void push(int x)
    {
        q2.enqueue(x);

        while (!q1.isEmpty())
        {
            q2.enqueue(q1.dequeue());
        }

        // Swap the names of q1 and q2
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop()
    {
        if (q1.isEmpty())
            return -1;

        return q1.dequeue();
    }
};

int main()
{
    Stack s1;
    s1.push(2);
    s1.push(3);
    s1.push(5);

    cout << s1.pop() << " ";
    cout << s1.pop() << " ";
    cout << s1.pop() << " ";

    return 0;
}
