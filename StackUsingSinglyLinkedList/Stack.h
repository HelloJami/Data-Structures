#pragma once
#include "SinglyLinkedlist.h"
class Stack
{
    SinglyLinkedListClass list;

public:
    void push(const int& value);
    bool pop(int& value);

    bool isEmpty()
    {
        return list.isEmpty();
    }

    bool isFull()
    {
        return false;
    }
};

void Stack::push(const int& value) {
    list.insertAtHead(value);
}

bool Stack::pop(int& value) {
    if (!list.isEmpty()) {
        list.removeAtHead(value);
        return  true;
    }
    else {
        return false;
    }
}

