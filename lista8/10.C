//Escreva uma função recursiva que desempilha todos os elementos da 
//stack1 e os empilha, em ordem inversa, na stack2.

#include <iostream>
#include <stack>
using namespace std;

void push_to(stack<int>& stk1, stack<int>& stk2){
    if(stk1.empty()) return;
    int top = stk1.top();
    stk1.pop();
    push_to(stk1, stk2);
    stk2.push(top);
}