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
        //arr[rear++] =  val;
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
    Queue q;
    while (!q.isFull())
    {
        int temp = 0;
        cout << "Enter value: ";
        cin >> temp;
        if (q.enqueue(temp))
            cout << "Entered successfully!" << endl;
        else
            cout << "Queue filled" << endl;
    }

    while (!q.isEmpty())
    {
        int output = 0;
        if (q.dequeue(output))
            cout << " value :" << output << endl;
    }
}
