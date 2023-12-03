#pragma once
//#include <iostream>
#include<string>
#include<cctype>
using namespace std;

#include "StackUsingLinkedList.h"

Stack <int> values;
Stack <char> operators;
int result();

string removeExtraCharacters(string expression) {
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

void infixToPostfix(string& expression) {

    for (int i = 0;i < (int)expression.length(); ++i) {

        char token = expression[i];

        if (isdigit(token)) //if toekn is int digit
        {
            string number = "";

            while (i <= (int)expression.length() && isdigit(expression[i])) {//more than one digit
                number += expression[i++];
            }
            //int n = ;
            values.push(stoi(number));
            //number = ""; //reset number
            --i;
        }

        else {       //if token is not number
            while (!operators.isEmpty()) 
            {
                char op = NULL;
                operators.pop(op);
                if (precedence(op) >= precedence(expression[i])) {
                    values.push(result());
                }
                else {
                    operators.push(op);
                }
                
            }
            operators.push(token);
        }
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
        while (!operators.isEmpty()) {
            int val2 = 0;
            values.pop(val2);

            int val1 = 0;
            values.pop(val1);

            char op = NULL;
            operators.pop(op);

            values.push(applyOperator(val1, val2, op));
        }
        int res = 0;
        values.pop(res);
        return res;
    }


    int expressionEvaluate(string expression) {
        expression = removeExtraCharacters(expression);
        infixToPostfix(expression);
        return result();
    }