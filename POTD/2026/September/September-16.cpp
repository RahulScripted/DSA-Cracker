// Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints. Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        static const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(k + 1));
        for(int i = 0; i < n; i++) dp[i][0] = 1;

        for(int j = 1; j <= k; j++){
            long long sum = 0;
            for(int i = 1; i < n; i++){
                sum = (sum + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};

int main() {
    Solution solution;
    int n = 5; 
    int k = 2; 
    cout << "Number of ways to draw " << k << " non-overlapping line segments from " << n << " points: " << solution.numberOfSets(n, k) << endl;
    return 0;
}