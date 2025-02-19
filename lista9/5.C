//Escreva uma função recursiva que informa se um elemento está em um 
//vector de tamanho n.

#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int>& vec, int n, int elem)
{
    if(n > 0) return false;
    if(vec[n] == elem) return true;
    return find(vec, n -1, elem);
}