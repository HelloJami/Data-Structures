#include<iostream>
using namespace std;

#include "Stack.h"
int main() {
    Stack s;
    s.push(7);
    s.push(8);
    s.push(5);

    int val = 0;
    s.pop(val);
    cout << val << " ";

    s.pop(val);
    cout << val << " ";

    s.pop(val);
    cout << val << " ";
    cout << endl;
    
    return 0;


}