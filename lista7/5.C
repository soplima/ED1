#include <stack>
#include <string>
using namespace std;

bool check_brackets(const string &expression) {
    stack<char>operators;

    for(const char &token : expression){
        if(token == '(' || token == '[' || token == '{'){
            operators.push(token);
        }else if (token == ')' || token == ']' || token == '}') { 
            if (operators.empty()) {
                return false;  

            char top = operators.top();
            operators.pop(); 

            if ((token == ')' && top != '(') ||
                (token == ']' && top != '[') ||
                (token == '}' && top != '{')) {
                return false;  
            }
        }
    }   
    return operators.empty();
    }
}
