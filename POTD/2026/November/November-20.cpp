// You are given a 0-indexed array nums consisting of positive integers. Initially, you can increase the value of any element in the array by at most 1. After that, you need to select one or more elements from the final array such that those elements are consecutive when sorted in increasing order. For example, the elements [3, 4, 5] are consecutive while [3, 4, 6] and [1, 1, 2, 3] are not. Return the maximum number of elements that you can select.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        ranges::sort(nums);
        int best = 1, keep = 1, bump = 1, last = -10;
        for (int x : nums) {
            switch (x - last) {
                case 0: bump = keep + 1; break;
                case 1: ++keep, ++bump; break;
                case 2: keep = bump + 1, bump = 1; break; 
                default: keep = bump = 1;
            }
            best = max({best, keep, bump}), last = x;
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "The maximum number of elements that can be selected is: " << sol.maxSelectedElements(nums) << endl;
}