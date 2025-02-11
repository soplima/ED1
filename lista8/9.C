//Escreva uma função recursiva que imprime todos os elementos de uma 
//Pilha (stack).

#include <iostream>
#include <stack>
using namespace std;

void print_stack(stack<int>& stk){
    if(stk.empty()) return;
    int top = stk.top();
    stk.pop();
    cout << top << " ";
    print_stack(stk); 
}