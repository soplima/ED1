#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <vector>
#include <stdexcept>
using namespace std;

float apply_operands(float a, float b, char op){
    switch(op){
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': 
    if(b == 0){
        throw runtime_error("Division by zero");
    }
    return a / b;
    }
}
int precedence (char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

float calc_infix(string expression){
    stack <char>operators;
    stack<float>operands;

    int i = 0;
    while(i < expression.length()){
        char token = expression[i];

        if (token == ' '){
            i++;
            continue;
        }

        else if(isdigit(token)){
            float num = 0;
            while (i<expression.length() && isdigit(expression[i])){
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            operands.push(num);
        }
        if(token == '('){
            operators.push(token);
            i++;
        }
        if(token == ')'){
            while(!operands.empty() && operators.top()!= '('){
                float b = operands.top(); operands.pop();
                float a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(apply_operands(a, b, op));
            } 
            if(operators.top() == '('){
                operators.pop();
            } 
            i++;
        }
        if(token == '+' || token == '-' || token == '*' || token == '/'){
            while(!operators.empty() && precedence(operators.top()) >= precedence(token)){
                float b = operands.top(); operands.pop();
                float a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(apply_operands(a, b, op));
            }
            operators.push(token);
            i++;
        }
        }
        while(!operators.empty()){
            float b = operands.top(); operands.pop();
            float a = operands.top(); operands.pop();
            char op = operators.top(); operators.pop();
            operands.push(apply_operands(a, b, op));
        }
        if(operands.size() != 1){
            return false;
        }
        return operands.top();
    }