//Escreva uma função recursiva que retorna a quantidade de 
//ocorrência de um elemento em um vectorv de tamanho n.

#include <iostream>
#include <vector>
using namespace std;

int count(vector<int>& vec, int n, int elem){
    if(n < 0) return 0;
    return (vec[n] == elem) + count(vec, n-1, elem);
}