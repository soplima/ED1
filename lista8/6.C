//Escreva uma função recursiva que imprime todos os elementos de uma 
//Lista Duplamente Encadeada (list).

#include <iostream>
#include <list>

using namespace std;


void print_list(list<int>& lst, list<int>::iterator& it){
    if(it == lst.end()) return;
    cout << *it << " ";
    print_list(lst, ++it);
}