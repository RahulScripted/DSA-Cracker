// Imagine you have a special keyboard with the following keys:

//     1 - A: Print one 'A' on the screen.
//     2 - Ctrl-A: Select the whole screen.
//     3 - Ctrl-C: Copy selection to buffer.
//     4 - Ctrl-V: Print buffer on screen appending it after what has already been printed.

// Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.









#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 3; i < n + 1; ++i) {
            for (int j = 2; j < i - 1; ++j) dp[i] = max(dp[i], dp[j - 1] * (i - j));
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    int n = 6;
    cout << "Maximum A's: " << sol.maxA(n) << endl;
}