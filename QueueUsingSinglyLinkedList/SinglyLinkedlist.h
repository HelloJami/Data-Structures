#pragma once

struct Node
{
    int value;
    Node* next;
};

class SinglyLinkedListClass
{
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedListClass();  // default constructor
    ~SinglyLinkedListClass(); // destructor

    void insert(const int value);
    void insertAtHead(const int value);
    //bool remove(int& value);
    bool removeAtHead(int& value);
    bool isEmpty() const;
};

SinglyLinkedListClass::SinglyLinkedListClass()
{
    head = nullptr;
    tail = nullptr;
}

SinglyLinkedListClass::~SinglyLinkedListClass()
{
    while (head != nullptr)
    {
        Node* next = head->next;
        delete head;
        head = next;
    }

    head = tail = nullptr;
}

void SinglyLinkedListClass::insert(const int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}
void SinglyLinkedListClass::insertAtHead(const int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}


bool SinglyLinkedListClass::removeAtHead(int& value)
{
    if (head == nullptr)
        return false;

    if (head == tail)
    {
        value = head->value;
        delete head;
        tail = head = nullptr;
        return true;
    }

    Node* current = head->next;
    value = head->value;
    delete head;
    head = current;
    return true;
}

bool SinglyLinkedListClass::isEmpty() const
{
    return head == nullptr;
}