#include <stack>
using namespace std;

stack<int> vet_to_stack(int *v, int n)
{
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(v[i]);
    }

    return s;
}