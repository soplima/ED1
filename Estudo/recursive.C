#include <iostream>
#include <list>
#include <iterator>
using namespace std;

//1, 3, 2, 5, 10

bool is_sorted(list<int>& lst, list<int>::iterator it){
    if(it == lst.end()) return true;
    if(*it >= *next(it)) return false;
    return is_sorted(lst, next(it));
}
