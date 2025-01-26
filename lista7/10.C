#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

string posfix_to_infix(string expression) {
    stack<string> operands; 
    int i = 0;

    while (i < expression.length()) {
        char token = expression[i];

        if (token == ' ') {
            i++;
            continue;
        }

        if (isdigit(token)) {
            string num = "";
            while (i < expression.length() && isdigit(expression[i])) {
                num += expression[i];
                i++;
            }
            operands.push(num);
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            if (operands.size() < 2) {
                throw invalid_argument("Expressão posfixa inválida.");
            }
            string operand2 = operands.top(); operands.pop();
            string operand1 = operands.top(); operands.pop();
            string infix_expr = "( " + operand1 + " " + token + " " + operand2 + " )";
            operands.push(infix_expr);
            i++;
        }
        else {
            throw invalid_argument("Caractere inválido na expressão.");
        }
    }

    if (operands.size() != 1) {
        throw invalid_argument("Expressão posfixa inválida.");
    }

    return operands.top();
}