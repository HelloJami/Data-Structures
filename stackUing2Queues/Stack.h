#pragma once
#include "Queue.h"
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