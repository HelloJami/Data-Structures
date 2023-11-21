#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

class SinglyLinkedListClass
{
private:
    Node *head ;
    Node *tail ;

public:
    SinglyLinkedListClass();//default constructor
    SinglyLinkedListClass(const SinglyLinkedListClass &other); // copy constructor
    SinglyLinkedListClass &operator=(const SinglyLinkedListClass &rhs); // Assignment operator overloading
    ~SinglyLinkedListClass();

    void insert(const int value);
    void insertAtHead(const int value);
    bool search(const int value) const;
    bool remove(int &value);
    bool removeAtHead(int &value);
    bool isEmpty() const;
    void print() const;
};

SinglyLinkedListClass ::SinglyLinkedListClass(){
    head = nullptr;
    tail = nullptr;
}
SinglyLinkedListClass::SinglyLinkedListClass(const SinglyLinkedListClass &other)
{
    Node *curr = other.head;

    while (curr != nullptr)
    {
        Node *newNode = new Node();
        newNode->value = curr->value;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        curr = curr->next;
    }
}

SinglyLinkedListClass &SinglyLinkedListClass::operator=(const SinglyLinkedListClass &rhs)
{
    if (this != &rhs)
    {
        while (head != nullptr) // delete all previous if have
        {
            Node *next = head->next;
            delete head;
            head = next;
        }
        tail = nullptr;

        Node *curr = rhs.head; // start copying values
        while (curr != nullptr)
        {
            Node *newNode = new Node();
            newNode->value = curr->value;

            if (head == nullptr)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            curr = curr->next;
        }
    }
    return *this;
}

SinglyLinkedListClass::~SinglyLinkedListClass()
{
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    head = tail = nullptr;
}

void SinglyLinkedListClass::insert(const int value)
{
    Node *newNode = new Node();
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
    Node *newNode = new Node();
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

bool SinglyLinkedListClass::remove(int &value)
{
    if (head == nullptr)
    {
        return false;
    }
    if (head == tail)
    {
        value = head->value;
        delete head;
        tail = head = nullptr;
        return true;
    }

    Node *pre = head;
    Node *curr = head;
    while (curr != nullptr)
    {
        pre = curr;
        curr = curr->next;
    }
    value = curr->value;
    delete curr;
    tail = pre;
    return true;
}

bool SinglyLinkedListClass::removeAtHead(int &value)
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

    Node *current = head->next;
    value = head->value;
    delete head;
    head = current;
    return true;
}

bool SinglyLinkedListClass::search(const int value) const
{
    if (head == nullptr)
        return false;

    if (head->value == value)
        return true;
    else
    {
        Node *temp = head->next;
        while (temp != nullptr)
        {
            if (temp->value == value)
            {
                return true;
            }
            temp = temp->next;
        }
    }

    return false;
}

void SinglyLinkedListClass::print() const
{
    Node *node = head;

    while (node != nullptr)
    {
        cout << node->value << " ";
        node = node->next;
    }
}

bool SinglyLinkedListClass::isEmpty() const
{
    return head == nullptr;
}
