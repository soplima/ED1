#include <iostream>
#include <vector>
using namespace std;

bool all_even(vector<int>& vec, int n){
    if(n == vec.size())return true;
    if(vec[n] % 2 != 0) return false;
    return all_even(vec, ++n);
}
