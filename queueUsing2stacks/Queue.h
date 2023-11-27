#pragma once
#include "Stack.h"

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
