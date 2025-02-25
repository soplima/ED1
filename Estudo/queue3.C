#include <iostream>
#include <queue>
using namespace std;


int sum_queue(queue<int> q){
    int sum = 0;
    while(!q.empty()){
        sum += q.front();
        q.pop();
    }
    return sum;
}
