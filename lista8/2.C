//Escreva uma função recursiva que imprime uma contagem de 0 à 50.

#include <iostream>
using namespace std;

void count(int num){
    if(num > 50) return;
    cout << num << endl;
    count(num + 1);
}