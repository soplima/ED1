#include <iostream>
#include <list>
using namespace std;

int min(list<int>& lst, list<int>::iterator it){
    if(it == lst.end()) return INT_MAX;
    int menor = min(lst, next(it));
    return(*it < menor)? *it: menor;
}