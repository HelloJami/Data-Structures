#include<iostream>
using namespace std;

#include "Queue.h"
int main() {

    // Queue
    Queue q;
    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(7);

    int val = 0;
    q.dequeue(val);
    cout << val << " ";

    q.dequeue(val);
    cout << val << " ";

    q.dequeue(val);
    cout << val << " ";

    return 0;


}