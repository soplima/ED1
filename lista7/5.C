#include <stack>
#include <string>
using namespace std;

bool check_brackets(const string &expression)
{
    stack<char>s;
    for(char ch : expression){
        if (ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}'){
            if (s.empty()){
                return false;
            }
            char top = s.top();
            s.pop();
            if((ch == ')' && top != '(') ||
               (ch == ']' && top != ']') ||
               (ch == '}' && top != '}')){
                return false;
               }
        }
    }
    return s.empty();
}