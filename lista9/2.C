//Escreva uma função recursiva que retorna o produto de todos os 
//elementos de uma list de início em it.

#include <iostream>
#include <list>
using namespace std;

int product(list<int>& lst, list<int>::iterator it)
{
    if(it == lst.end())return 1;
    return *it * product(lst, next(it));
}