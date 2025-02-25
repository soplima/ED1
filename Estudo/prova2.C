#include <iostream>
#include <vector>
using namespace std;

// 1, 3, 5, 2, 7, 8, 10

bool sorted(vector<int>& vec, int i){
    if(i == vec.size()) return true;
    if(vec[i] > vec[i+ 1]) return false;
    return sorted(vec, ++i);
}
