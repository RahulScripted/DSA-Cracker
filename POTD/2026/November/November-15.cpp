// You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0. Return the minimum sum of such a subarray. If no such subarray exists, return -1. A subarray is a contiguous non-empty sequence of elements within an array.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;
                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1, -2, 3, -4, 5};
    int l = 2, r = 4;
    cout << "The minimum sum of a subarray is: " << sol.minimumSumSubarray(nums, l, r) << endl;
}