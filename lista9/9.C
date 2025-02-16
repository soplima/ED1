//Escreva uma função recursiva que verifica se uma string forma um 
//palíndromo.

#include <iostream>
using namespace std;

bool palindrome(string& str, int first, int last) {
    if(first >= last) return true;
    if(str[first] != str[last])return false;
    palindrome(str, first+1, last-1);
}