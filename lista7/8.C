#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>
using namespace std;

vector<string> vectorize_expression(const string &expression)
{
    vector<string>result;
    stringstream ss (expression);
    string token;

    while(ss >> token){
        result.push_back(token);
    }
    return result;
}
bool check_posfix(string expression){
    stack<float>operand;
    vector<string>tokens = vectorize_expression(expression);

    for (const string& token: tokens){
        if(isdigit(token[0])){
            operand.push(1);
        }
        else {
            if(operand.size() < 2){
                return false;
            }
            operand.pop();
        }
    }
    return operand.size() == 1;
}
