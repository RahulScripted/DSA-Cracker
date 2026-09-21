// You are given an array of positive integers nums, and a positive integer k. You are allowed to perform an operation once on nums, where in each operation you can remove any non-overlapping prefix and suffix from nums such that nums remains non-empty. You need to find the x-value of nums, which is the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x when divided by k. Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= k - 1. A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it. A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dp(k, 0);

        for (int num : nums) {
            int x = num % k;
            vector<long long> next(k, 0);
            next[x]++;

            for (int r = 0; r < k; r++) {
                int newR = (r * x) % k;
                next[newR] += dp[r];
            }

            for (int r = 0; r < k; r++) ans[r] += next[r];
            dp = next;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;
    vector<long long> result = solution.resultArray(nums, k);
    
    cout <<"Result array: ";
    for (long long val : result) cout << val << " ";
    cout << endl;
}