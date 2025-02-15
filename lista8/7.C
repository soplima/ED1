//Escreva uma função recursiva que imprime todos os elementos de uma Lista 
//Simplesmente Encadeada (forward_list), em ordem inversa.

#include <iostream>
#include <forward_list>
using namespace std;

void print_rev(forward_list<int>& lst, forward_list<int>::iterator& it){
    if(it == lst.end()) return;
    auto next_it = it;
    next_it++;
    print_rev(lst, next_it);
    cout << *it << endl;
}