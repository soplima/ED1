//Escreva uma função recursiva que imprime todos os elementos de uma 
//Lista Sequencial (vector).

#include <iostream>
#include <vector>
using namespace std;


void print_vec(vector<int>& vec, int idx){
    if(idx < 0) return;
    cout << vec[idx] << endl;
    print_vec(vec, idx -1 );
}