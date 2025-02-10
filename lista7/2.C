//Escreva uma função que recebe o endereço de um array de inteiros e devolve uma list<int>, contendo
//os elementos do array na mesma ordem.


#include <iostream>
#include <list>

using namespace std;

list<int> vet_to_list(int* v, int n){
    list<int>result;
    for(int i = 0; i < n; i ++){
    result.push_back(v[i]);
    }
    return result;
}

