//Escreva uma função recursiva que copia o conteúdo de list1 para list2.

#include <iostream>
#include <list>
using namespace std;

void copy(list<int>& list1, list<int>::iterator it, list<int>& list2){
    if(it == list1.end()) return;
    list2.push_back(*it);
    copy(list1, next(it), list2);
}