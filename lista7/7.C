#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>
using namespace std;

vector<string> vectorize_expression(const string& expression) {
vector<string>result;
stringstream ss (expression);
string token;

while (ss >> token)
{
    result.push_back(token);
}
return result;
}

float calc_posfix(const string& expression) {
    stack<float>operators;
    vector<string> tokens = vectorize_expression(expression);

    for (const string& token : tokens){
        if(isdigit(token[0])){
            operators.push(stof(token));
        } else {
            if(operators.size() < 2){
                throw invalid_argument("Expressão inválida: operandos insuficientes.");
        }
            float b = operators.top(); operators.pop(); 
            float a = operators.top(); operators.pop(); 

            if (token == "+") {
                operators.push(a + b);
            } else if (token == "-") {
                operators.push(a - b);
            } else if (token == "*") {
                operators.push(a * b);
            } else if (token == "/") {
                if (b == 0) { 
                    throw invalid_argument("Erro: divisão por zero.");
                }
                operators.push(a / b);
            } else {
                throw invalid_argument("Operador inválido: " + token);
            }
        }

    }
     if (operators.size() != 1) {
        throw invalid_argument("Expressão inválida.");
    }

    return operators.top(); 
}