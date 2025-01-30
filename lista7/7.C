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
    return result;
}
float calc_posfix(string expression){
    stack<float>operand;
    vector<string>tokens = vectorize_expression(expression);

    for (const string& token: tokens){
        if(isdigit(token[0])){
            operand.push(stof(token));
        }
        else {
            if(operand.size() < 2){
            return false;
        }
            float b = operand.top(); operand.pop();
            float a = operand.top(); operand.pop();
            
            if(token == "+"){
                operand.push(a + b);
            }
            if(token == "-"){
                operand.push(a - b);
            }
            if(token == "*"){
                operand.push(a * b);
            }
            if(token == "/"){
                if(b == 0){
                    return false;
                }
                operand.push(a / b);
            }
        }
        if(operand.size() != 1){
            return false;
        }
    }
    return operand.top();
}