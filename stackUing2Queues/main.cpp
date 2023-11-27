#include<iostream>
using namespace std;

# include "Stack.h"
int main()
{
    Stack s1;
    s1.push(2);
    s1.push(3);
    s1.push(5);

    cout << s1.pop() << " ";
    cout << s1.pop() << " ";
    cout << s1.pop() << " ";

    return 0;
}