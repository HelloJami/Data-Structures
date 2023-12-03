#pragma once
#include <iostream>
#include<string>
#include<cctype>
using namespace std;

#include "StackUsingLinkedList.h"

stack <int> values;
stack <char> operators;

void expressionEvaluate(string expression) {
    expression = removeExtraCharacters(expression);
    infixToPostfix(expression);

}

string removeExtraCharacters(string expression) {
    string newS;

    for (int i = 0; i < s.size(); ++i)
    {
        char ch = s[i];

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


string infixToPostfix(string& expression) {

    for (int i = 0;i <= expression.length(); ++i) {

        char token = expression[i];

        if (isdigit(token)) //if toekn is int digit
        {
            string number = "";

            while (i <= expression.length() && isdigit(expression[i])) {//more than one digit
                number += expression[i++];
            }

            values.push(stio(number));
            number = ""; //reset number
        }
        
        else{       //if token is not number
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) 
            {
                values.push(result());
            }
            ops.push(tokens[i]);
    }
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
    while (!operators.empty()) {
        int val2 = 0;
        values.pop(val2);

        int val1 = 0;
        values.pop(val1);

        char op = '';
        operators.pop(op);

        values.push(applyOperator(val1, val2, op));
    }
    int res = 0
    values.pop(res);
    return res;
}