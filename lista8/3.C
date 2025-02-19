//Escreva uma função recursiva que imprime uma contagem de 0 à max.

#include <iostream>
using namespace std;

void count_max(int num, int max)
{
    if(num > max)return;
    cout << num << endl;
    count_max(num + 1, max);
}