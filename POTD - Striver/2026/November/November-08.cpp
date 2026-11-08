// Given a non-negative integer n, determine whether it is odd. Return true if the number is odd, otherwise return false.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOdd(int n) {
        return n % 2 != 0;
    }
};

int main() {
    Solution solution;
    int n = 7 ;
    cout << "Is " << n << " odd? " << solution.isOdd(n) << endl;
}