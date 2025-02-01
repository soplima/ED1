#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

float apply_operator(float a, float b, char op){
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': 
    if(b == 0){
        return false;
    }
    return a / b;
    }
}

    int precedence(char op){
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

float calc_infix(string expression){
    stack<float>operands;
    stack<char>operators;

    int i = 0;
    while (i < expression.length()){
        char token = expression[i];
        if (token == ' '){
            i++;
            continue;
        }

        else if (isdigit(token)){
            float num = 0;
            while(i < expression.length() && isdigit(token)){
            num = num * 10 + (expression[i] - '0');
            i++;
            }
            operands.push(num);
        }
        else if (token == '('){
            operators.push(token);
            i++;
        }
        else if (token == ')'){
            while(!operands.empty() && operators.top() != '('){
            float b = operands.top(); operands.pop();
            float a = operands.top(); operands.pop();
            char op = operators.top(); operators.pop();
            operands.push(apply_operator(a, b, op));
            }
            if (operators.top() == '('){
                operators.pop();
            }
            i++;
        }
        else if (token == '+'|| token == '-'|| token == '*'|| token == '/'){
            while(!operands.empty() && precedence(operators.top()) >= precedence(token)){
            float b = operands.top(); operands.pop();
            float a = operands.top(); operands.pop();
            char op = operators.top(); operators.pop();
            operands.push(apply_operator(a, b, op));
            }
        operators.push(token);
        i++;
         } else {
            return false;
        }
        while(!operators.empty()){
            float b = operands.top(); operands.pop();
            float a = operands.top(); operands.pop();
            char op = operators.top(); operators.pop();
            operands.push(apply_operator(a, b, op));
        }
        if(operands.size() != 1){
            return false;
        }
    }
    return operands.top();
}