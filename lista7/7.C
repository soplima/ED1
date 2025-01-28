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

float calc_posfix(const string& expression) {
    stack<float>operands;
    vector<string> tokens = vectorize_expression(expression);

    
}