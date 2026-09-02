// You are given an array nums1 of n distinct integers. You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even. For each index i, you must choose exactly one of the following (in any order):

//     1 - nums2[i] = nums1[i]
//     2 - nums2[i] = nums1[i] - nums1[j], for an index j != i

// Return true if it is possible to construct such an array, otherwise, return false.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    bool result = solution.uniformArray(nums1);
    cout << "Can we construct a uniform array? " << (result ? "True" : "False") << endl;
}