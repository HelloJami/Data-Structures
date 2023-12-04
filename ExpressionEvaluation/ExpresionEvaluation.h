#pragma once
#include<string>
#include<cctype>
using namespace std;

#include "StackUsingLinkedList.h"

// Stacks
Stack <int> values;
Stack <char> operators;

// Functions declarations
string removeIllegalCharacters(string expression);
int precedence(char op);
int infixToPostfix(string& expression);
int result();
int expressionEvaluate(string expression);

// Functions Definitions
string removeIllegalCharacters(string expression) {
    //remove extra or illegal characters from inputted string
    string newS;
    for (int i = 0; i < (int)expression.size(); ++i)
    {
        char ch = expression[i];

        if ((ch >= 48 && ch <= 57) || (ch == '+' || ch == '-' || ch == '*' || ch == '/')) {
            newS += ch; //String concatenation 
        }
        else {
            continue;
        }
    }
    return newS;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOperator(int val1, int val2, char op) {
    switch (op) {
    case '+': return val1 + val2;
    case '-': return val1 - val2;
    case '*': return val1 * val2;
    case '/': return val1 / val2;
    }
}

int result() {
    int val2 = 0;
    values.pop(val2);

    int val1 = 0;
    values.pop(val1);

    char op = NULL;
    operators.pop(op);

    return applyOperator(val1, val2, op);
}

int infixToPostfix(string& expression) {

    for (int i = 0;i < (int)expression.length(); ++i) {

        char token = expression[i];

        if (isdigit(token)) //if toekn is int digit
        {
            string number = "";

            while (i < (int)expression.length() && isdigit(expression[i])) 
            {        //more than one digit
                number += expression[i++];
            }
            values.push(stoi(number));
            --i;
        }
        else {      //if token is not number
            char op = expression[i];
            while (!operators.isEmpty() && precedence(op) >= precedence(expression[i]))
            {
                values.push(result());
                
            }
            operators.push(expression[i]);
        }
    }


    while (!operators.isEmpty()) {
        values.push(result());
    }

    int res = 0;
    values.pop(res);
    return res;
}
int expressionEvaluate(string expression) {
        expression = removeIllegalCharacters(expression);
        return infixToPostfix(expression);
        //return result();
    }
