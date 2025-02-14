#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>

using namespace std;

float apply_operator(float a, float b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        default:
            throw runtime_error("Invalid operator");
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

float calc_infix(string expression) {
    stack<char> operators;
    stack<float> operands;
    int i = 0;

    while (i < expression.length()) {
        char token = expression[i];

        if (isspace(token)) {
            i++;
            continue;
        }
        else if (isdigit(token) || token == '.') { // Handle multi-digit numbers and decimals
            string numStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i++];
            }
            operands.push(stof(numStr)); // Convert to float and push to stack
        }
        else if (token == '(') {
            operators.push(token);
            i++;
        }
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                if (operands.size() < 2) throw runtime_error("Invalid expression");
                float b = operands.top(); operands.pop();
                float a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(apply_operator(a, b, op));
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
            i++;
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                if (operands.size() < 2) throw runtime_error("Invalid expression");
                float b = operands.top(); operands.pop();
                float a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(apply_operator(a, b, op));
            }
            operators.push(token);
            i++;
        }
        else {
            throw runtime_error("Invalid character in expression");
        }
    }

    // Process remaining operators
    while (!operators.empty()) {
        if (operands.size() < 2) throw runtime_error("Invalid expression");
        float b = operands.top(); operands.pop();
        float a = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        operands.push(apply_operator(a, b, op));
    }

    if (operands.size() != 1) {
        throw runtime_error("Invalid expression");
    }
    return operands.top();
}