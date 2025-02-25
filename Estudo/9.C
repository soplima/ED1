#include <iostream>
#include <vector>
using namespace std;

bool palindrome(string& str, int first, int last){
    if(first >= last) return true;
    if(str[first] != str[last]) return false;
    return palindrome(str, first++, last--);
}
