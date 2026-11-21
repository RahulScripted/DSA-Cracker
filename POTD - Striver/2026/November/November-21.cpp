// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.





#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        unordered_map<long long, int> prefixSumMap;
        long long currentSum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            if (currentSum == k) maxLength = i + 1;
            long long remaining = currentSum - k;
            if (prefixSumMap.find(remaining) != prefixSumMap.end()) maxLength = max(maxLength, i - prefixSumMap[remaining]);
            if (prefixSumMap.find(currentSum) == prefixSumMap.end()) prefixSumMap[currentSum] = i;
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    int result = solution.longestSubarray(nums, k);
    cout << "Length of the longest sub-array that sums to " << k << " is: " << result << endl;
}