#include <string>
#include <vector>
#include <sstream>
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