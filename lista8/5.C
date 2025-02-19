//Escreva uma função recursiva que imprime todos os elementos pares de uma 
//Lista Sequencial (vector), em ordem inversa.

#include <iostream>
#include <vector>
using namespace std;

void print_even(vector<int>& vec, int idx)
{
    if(idx < 0)return;
    if(vec[idx] % 2 == 0){
    cout<<vec[idx] << endl;
    }
    print_even(vec, idx -1);
}
