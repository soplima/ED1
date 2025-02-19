//Escreva uma função recursiva que verifica se os elementos de uma 
//list foram um palíndromo.

#include <iostream>
#include <list>
using namespace std;

bool palindrome(list<int>& lst, list<int>::iterator first, 
list<int>::iterator last)
{
    if (first == last || next(first) == last) return true; 
    if(*first != *last) return false;
    return palindrome(lst, next(first), prev(last));
}