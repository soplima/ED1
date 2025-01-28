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

    while(ss >> token){
        result.push_back(token);
    }
}
float calc_posfix(string expression){
    stack<float>operands;
    vector<string>tokens = vectorize_expression(expression);

    for (const string& token : tokens) {
        if(isdigit(token[0])){
            operands.push(stof(token));
        }else{
            if(operands.size() < 2){
                return false;
            }
            float b = operands.top(); operands.pop();
            float a = operands.top(); operands.pop();

            if(token == "+"){
                operands.push(a + b);
            } 
            else if (token == "-"){
                operands.push(a - b);
            }
            else if (token == "*"){
                operands.push(a * b);
            }
            else if (token == "/"){
                if(b == 0){
                    return false;
                }
                operands.push(a / b);
            }
            else{
                throw invalid_argument("Operador inválido: " + token);
            }
        }
    }
    if (operands.size() != 1){
        throw invalid_argument("Expressão inválida.");
    }
    return operands.top();
}