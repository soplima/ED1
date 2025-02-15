//Escreva uma função recursiva que imprime 10 vezes a mesma linha de texto.

#include <iostream>
using namespace std;

void print_txt(char* text, int count = 10) {
    if(count == 0) return;
    cout << text << " ";
    print_txt(text, 10 - 1);
}

