//Escreva uma função recursiva que retorna a soma de todos os 
//elementos de um vector de tamanho n que estão em posições pares.

#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>& vec, int n){
    if(n < 0) return 0;
    int s = (n % 2 == 0)? vec[n]: 0;
    return s + sum(vec, n -1);
}