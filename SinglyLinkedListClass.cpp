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
    Node *head = nullptr;
    Node *tail = nullptr;
    
public:
    SinglyLinkedListClass(/* args */); // copy constructor 
    SinglyLinkedListClass & operaotr=(const SinglyLinkedListClass &rhs); // Assignment operator overloading
    ~SinglyLinkedListClass();// ok

    void insert(const int value);//ok
    void insertAtHead(const int value);//ok
    bool search(const int value) const;//ok
    bool remove(const int value);
    bool removeAtHead(const int value);//ok
    void print()const;//ok

};

SinglyLinkedListClass::SinglyLinkedListClass(/* args */)
{
    Node *
}

SinglyLinkedListClass::~SinglyLinkedListClass()
{
        while(head != nullptr){
        Node* next = head->next;
        delete head;
        head = next;
    }
    
    head = tail = nullptr;
}
void SinglyLinkedListClass :: insert(const int value){
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

}

void SinglyLinkedListClass :: insertAtHead(const int value){
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

bool SinglyLinkedListClass :: remove(int& value){
    if(head == nullptr){
        return false;
    }
    if(head == tail){
        value = head->value;
        delete head;
        tail = head = nullptr;
        return true;
    }

    // Node* pre = head->next;
    // Node *curr = head->next;
    // while(curr != nullptr){
    //     pre = cur
    //     curr = curr->next;

    // }
    //------------------
}

bool SinglyLinkedListClass ::removeAtHead(int& value){
    if(head == nullptr)
        return false;
    
    if(head == tail){
        value = head->value;
        delete head;
        tail = head = nullptr;
        return true;
    }

    Node * current = head->next;
    value = head->value;
    delete head;
    head = current;
    return true
}
bool SinglyLinkedListClass::search(const int value) const{
    if(head == nullptr)
        return false;

    if(head->value == value)
        return true;
    else{
        Node *temp = head->next;
        while(temp != nullptr){
            if(temp->value == value){
                return true;
            }
            temp = temp->next;
        }
    }

    return false;
}
void SinglyLinkedListClass :: print()const{
    Node * node = head;

    while(node != nullptr){
        cout<< node->value <<" ";
        node = node->next;
    }
}
int main(){
    SinglyLinkedListClass list;

    list.insert(4);
    list.insert(5);
    list.insert(8);

    list.print();
}