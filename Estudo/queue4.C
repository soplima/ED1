#include <iostream>
#include <queue>
using namespace std;

void rotate_queue(queue<int>& q){
    int front = q.front();
    q.pop();
    q.push(front);
}
