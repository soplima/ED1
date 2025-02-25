#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>& vec, int n){
    if(n == vec.size()) return 0;
    int s = (n % 2 == 0)? vec[n]: 0;
    return s + sum(vec, n++);
}