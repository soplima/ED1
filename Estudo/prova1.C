#include <stack>
#include <string>
using namespace std;

// 1, 2, 3, 4, 5
// 5, 4, 3, 2, 1

stack<int>reverse (stack<int>& stk){
    stack<int>copy;
    while(!stk.empty()){
        int top = stk.top();
        stk.pop();
        copy.push(top);
    }
    return copy;
}
