//Escreva uma função recursiva que remove todos os elementos, 
//um a um, de um vector.

#include <iostream>
#include <vector>
using namespace std;

void remove_all(vector<int>& vec){
    if(vec.size() == 0) return;
    cout << vec.front() << " ";
    vec.erase(vec.begin());
    remove_all(vec);
}