#include<iostream>
using namespace std;

#include "queue.h"
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