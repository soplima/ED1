//Escreva uma função que recebe a referência de duas forward_list<int> e concatena seus conteúdos
//em um vector<int>, a ser devolvido pelo função.


#include <forward_list>
#include <vector>
using namespace std;

vector<int> list_concat(forward_list<int> &list1, forward_list<int> &list2)
{
    vector<int>result;
    for(int val: list1){
        result.push_back(val);
    }
    for(int val: list2){
        result.push_back(val);
    }
    return result;
}