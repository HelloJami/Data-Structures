template <typename T>
struct Node
{
    T value;
    Node<T>* pre;
    Node<T>* next;
};
template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();                                       // default constructor
    DoublyLinkedList(const DoublyLinkedList& other);          // copy constructor
    DoublyLinkedList& operator=(const DoublyLinkedList& rhs); // Assignment operator overloading
    ~DoublyLinkedList();

    void insert(const T value);
    void insertAtHead(const T value);
    bool search(const T value) const;
    bool remove(T& value);
    bool removeAtHead(T& value);
    bool isEmpty() const;
    void print() const;
};

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
{
    Node* curr = other.head;

    while (curr != nullptr)
    {
        Node* newNode = new Node();
        newNode->value = curr->value;       //copying values

        if (head == nullptr)
        {
            head = tail = newNode;
            newNode->pre = nullptr;
        }
        else
        {
            newNode->pre = tail;
            tail->next = newNode;       // tail to newly added last Node
            tail = newNode;
        }

        curr = curr->next;
    }
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& rhs)
{
    if (this != &rhs)
    {
        while (head != nullptr) // delete all previous if have
        {
            Node* next = head->next;
            delete head;
            head = next;
        }
        tail = nullptr;

        Node* curr = rhs.head; // start copying values
        while (curr != nullptr)
        {
            Node* newNode = new Node();
            newNode->value = curr->value;

            if (head == nullptr)// when first Node come
            {
                head = tail = newNode;
                newNode->pre = nullptr;
            }
            else
            {       // when already have some Nodes in list
                newNode->pre = tail;
                tail->next = newNode;
                tail = newNode;
            }

            curr = curr->next;
        }
    }
    return *this;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head != nullptr)
    {
        Node* next = head->next;
        delete head;    //delete all nodes
        head = next;
    }

    head = tail = nullptr;
}

void DoublyLinkedList::insert(const T value)  // insert at tail
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr) // if no Node in list
    {
        newNode->pre = nullptr;
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->pre = tail;
    tail->next = newNode;
    tail = newNode;     // tail to newly added last Node at last
}

void DoublyLinkedList::insertAtHead(const T value)
{
    Node* newNode = new Node();
    newNode->pre = nullptr;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }

    head->pre = newNode;
    // pointers for the new head.
    newNode->next = head;
    head = newNode;
}

bool DoublyLinkedList::remove(T& value)
{
    if (head == nullptr) // when no Node in list
    {
        return false;
    }
    if (head == tail) // when only one Node in list
    {
        value = head->value;
        delete head;
        tail = head = nullptr;
        return true;
    }
    Node* curr = head; // cuur to last Node
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    value = curr->value; // tail to 2nd last Node
    tail = curr->pre;
    tail->next = nullptr;

    // delete last node
    delete curr;
    return true;
}

bool DoublyLinkedList::removeAtHead(T& value)
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
    value = head->value; // return first Node value

    Node* current = head->next;
    delete head;
    head = current;

    if (head != nullptr) // if there are still nodes in the list
        head->pre = nullptr;

    return true;
}

bool DoublyLinkedList::search(const T value) const
{
    Node* temp = head;

    while (temp != nullptr)
    {
        if (temp->value == value)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void DoublyLinkedList::print() const
{
    Node* node = head;

    while (node != nullptr)
    {
        cout << node->value << " ";
        node = node->next;
    }
}

bool DoublyLinkedList::isEmpty() const
{
    return head == nullptr; // return true if any Node in list
}
