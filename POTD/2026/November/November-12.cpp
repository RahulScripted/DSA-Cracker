// You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, up = 1, down = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            up = nums[i - 1] < nums[i] ? up + 1 : 1;
            down = nums[i - 1] > nums[i] ? down + 1 : 1;
            best = max({best, up, down});
        }
        return best;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 2, 1, 0, -1};
    cout << "Longest monotonic subarray length: " << solution.longestMonotonicSubarray(nums) << endl;
}