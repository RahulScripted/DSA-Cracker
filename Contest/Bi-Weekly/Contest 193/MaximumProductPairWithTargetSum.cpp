// You are given an integer array nums and an integer target. A pair of distinct indices (i, j) is valid if:

//     1 - nums[i] + nums[j] == target
//     2 - nums[i] > nums[j]

// Return a valid pair [i, j] whose product nums[i] * nums[j] is maximum among all valid pairs. If no valid pair exists, return [-1, -1]. If multiple valid pairs achieve the maximum product, you may return any of them.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans = {-1, -1};
        long long bestProduct = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (nums[i] + nums[j] == target && nums[i] > nums[j]) {
                    long long prod = (long long)nums[i] * nums[j];
                    if (prod > bestProduct) {
                        bestProduct = prod;
                        ans = {i, j};
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 6;
    vector<int> result = sol.maxProductPair(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "] is the maximum product pair" << endl;
}