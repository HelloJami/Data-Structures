#include <iostream>
#include <string>

#include "ExpresionEvaluation.h"
using namespace std;

int main()
{

    string expression;
    cout << "Enter a string: ";
    getline(cin, expression);// taking input from user in string

    cout << "Answer is: " << expressionEvaluate(expression); // calling the function
    return 0;
}
