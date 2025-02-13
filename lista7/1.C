//Escreva uma função que recebe o endereço de um array de inteiros e 
//devolve um vector<int>, contendo os elementos do array na mesma ordem.

#include <vector>

std::vector<int> vet_to_vector(int *v, int n)
{
    std::vector<int>result;
    for(int i = 0; i < n; i ++){
        result.push_back(v[i]);
    }
    return result;
}