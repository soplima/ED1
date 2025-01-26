#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>
using namespace std;

vector<string> vectorize_expression(const string &expression)
{
    vector<string> result;
    stringstream ss(expression);
    string token;

    while (ss >> token)
    {
        result.push_back(token);
    }
    return result;
}

bool check_posfix(string expression)
{
    stack<int> stack;
    vector<string> tokens = vectorize_expression(expression);

    for (const string &token : tokens)
    {
        if (isdigit(token[0]))
        {
            stack.push(1);
        }
        else
        {
            if (stack.size() < 2)
            {
                return false;
            }
            stack.pop();
        }
    }
    return stack.size() == 1;
}