// You are given an integer array nums.

//     1 - The low score of nums is the minimum absolute difference between any two integers.
//     2 - The high score of nums is the maximum absolute difference between any two integers.
//     3 - The score of nums is the sum of the high and low scores.

// Return the minimum score after changing two elements of nums.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int s0 = INT_MAX, s1 = INT_MAX, s2 = INT_MAX;
        int l0 = 0, l1 = 0, l2 = 0;

        for (int x : nums) {
            if (x < s0) {
                s2 = s1;
                s1 = s0;
                s0 = x;
            } else if (x < s1) {
                s2 = s1;
                s1 = x;
            } else if (x < s2) s2 = x;

            if (x > l0) {
                l2 = l1;
                l1 = l0;
                l0 = x;
            } else if (x > l1) {
                l2 = l1;
                l1 = x;
            } else if (x > l2) {
                l2 = x;
            }
        }

        return min({l0 - s2, l2 - s0, l1 - s1});
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 4, 3};
    int result = solution.minimizeSum(nums);
    cout << "Minimum score after changing two elements: " << result << endl;
}