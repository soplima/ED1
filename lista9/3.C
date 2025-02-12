//Escreva uma função recursiva que retorna o menor dos 
//elementos de um vector de tamanho n.

#include <iostream>
#include <vector>
using namespace std;

int min(vector<int>& vec, int n){
    if(n == 0) return vec[n];
    int menor = min(vec, n - 1);
    return(vec[n] < menor) ? vec[n] : menor;
}