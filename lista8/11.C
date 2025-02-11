//Escreva uma função recursiva que copia o conteúdo de vec1 para vec2.

#include <iostream>
#include <vector>
using namespace std;

void copy(vector<int>& vec1, int idx, vector<int>& vec2) {
    if(idx > vec1.size()) return;
    vec2.push_back(vec1[idx]);
    copy(vec1, idx + 1, vec2);
}