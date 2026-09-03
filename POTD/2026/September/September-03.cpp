// You are given an array nums1 of n distinct integers. You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even. For each index i, you must choose exactly one of the following (in any order):

//     1 - nums2[i] = nums1[i]​​​​​​​
//     2 - nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1

// Return true if it is possible to construct such an array, otherwise return false.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = INT_MAX, oddCnt = 0;
        for (int x : nums) {
            mn = min(mn, x);
            if (x % 2 == 1) oddCnt++;
        }
        return mn % 2 || oddCnt == 0; 
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 4, 6, 8};
    cout << "Can we construct a uniform array? " << (sol.uniformArray(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {1, 3, 5, 7};
    cout << "Can we construct a uniform array? " << (sol.uniformArray(nums2) ? "true" : "false") << endl;

    vector<int> nums3 = {2, 3, 4, 5};
    cout << "Can we construct a uniform array? " << (sol.uniformArray(nums3) ? "true" : "false") << endl;
}