//Escreva uma função que recebe o endereço de um array de inteiros e devolve uma forward_list<int>,
//contendo os elementos do array na mesma ordem.

#include <forward_list>
#include <iostream>

std::forward_list<int> vet_to_flist(int *v, int n)
{
    std::forward_list<int>flist;

    if(n == '0' || v == nullptr){
        return flist;
    }
    auto it = flist.before_begin();
    for (int i = 0; i < n; i ++){
        it = flist.insert_after(it, v[i]);
    }
    return flist;
}