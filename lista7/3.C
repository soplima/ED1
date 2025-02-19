//Escreva uma função que recebe o endereço de um array de inteiros e 
//devolve uma stack<int>, contendo os elementos do array na mesma ordem.

#include <stack>
using namespace std;

stack<int> vet_to_stack(int *v, int n)
{
  stack<int>result;
  for(int i = 0; i < n; i ++){
    result.push(v[i]);
  }
  return result;
}
