//Escreva uma função recursiva que inverte os elementos em um 
//vector, de início em first e final em last.

#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& vec, int first, int last) 
{
    if(first >= last) return;
    swap(vec[first], vec[last]);
    reverse(vec, first +1, last -1);
}