#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <stdexcept>
using namespace std;

string posfix_to_infix(string expression)
{
    stack<string> operand;
    int i = 0;
    while (i < expression.length())
    {
        char token = expression[i];
        if (token == ' ')
        {
            i++;
            continue;
        }
        if (isdigit(token))
        {
            string num = "";
            while (i < expression.length() && isdigit(expression[i]))
            {
                num += expression[i];
                i++;
            }
            operand.push(num);
        }
        else if(token == '+' || token == '-' || token == '*' || token == '/'){
            if (operand.size() < 2) {
                throw invalid_argument("Expressão posfixa inválida.");
            }
            string operand2 = operand.top(); operand.pop();
            string operand1 = operand.top(); operand.pop();
            string infix_exp = "(" + operand1 + " " + token + " " + operand2 + ")";
            operand.push(infix_exp);
            i++;
        }
        if (operand.size() != 1) {
        throw invalid_argument("Expressão posfixa inválida.");
        }
    }
    return operand.top();
}