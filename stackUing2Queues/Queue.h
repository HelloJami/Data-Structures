
class Queue
{
private:
    const static int SIZE = 5;
    int arr[SIZE] = { 0 };
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