//Escreva uma função recursiva que inverte os elementos em uma list, 
//de início em first e final em last.

#include <iostream>
#include <list>
using namespace std;

void reverse(list<int>& lst, list<int>::iterator first, 
    list<int>::iterator last)
    {
    if (first == last || next(first) == last) return;
    swap(*first, *last);
    reverse(lst, next(first), prev(last));
}