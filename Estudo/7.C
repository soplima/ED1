#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& vec, int first, int last){
    if(first >= last)return;
    swap(vec[first], vec[last]);
    reverse(vec, first++, last--);
}