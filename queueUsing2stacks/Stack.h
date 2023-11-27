class Stack
{
    int top = -1;
    const static int SIZE = 5;
    int arr[SIZE] = { 0 };

public:
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == SIZE - 1;
    }

    bool push(int val = 0)
    {
        if (isFull())
            return false;

        ++top;
        arr[top] = val;
        return true;
    }
    int pop()
    {
        return arr[top--];
    }
};
