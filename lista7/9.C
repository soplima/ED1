#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>

using namespace std;

float apply_operands(float a, float b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int precedence(char op){
    if(op == '+' || '-') return 1;
    if(op == '*' || '/') return 2;
    return 0;
}

bool check_posfix(string expression){
    stack<float>operands;
    stack<char>operators;

    int i = 0;
    while(i<expression.length()){
        char token = expression[i];

        if(token == ' '){
            i++;
            continue;
        }
        else if(isdigit(token)){
            float num = 0;
            while(i<expression.length() && isdigit(token)){
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            operands.push(num);
        }
        else if (token == '('){
            operators.push(token);
        }
        else if(token == ')'){
            while(!operators.empty() && operators.top() != '('){
                if (operands.size() < 2) throw runtime_error("Invalid expression");
                float b = operands.top(); operands.pop();
                float a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(apply_operands(a, b, op));
            }
            if(token == '('){
                operators.pop();
            }
            i++;
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/'){
            while(!operators.empty() && precedence(operands.top()) >= precedence(token)){
            if (operands.size() < 2) throw runtime_error("Invalid expression");
            float b = operands.top(); operands.pop();
            float a = operands.top(); operands.pop();
            char op = operators.top(); operators.pop();
            operands.push(apply_operands(a, b, op));
        }
        operators.push(token);
        i++;

        }
    }
    while(!operands.empty()){
        float b = operands.top(); operands.pop();
        float a = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        operands.push(apply_operands(a, b, op));
    }
    if(operands.size() != 1){
        __throw_invalid_argument("Expressao invalida");
    }
    return operands.top();
}