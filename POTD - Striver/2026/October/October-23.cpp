// Given an array of integers nums. Check whether the array represents a binary min-heap or not. Return true if it does, otherwise return false. A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHeap(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i<=(n - 2) / 2; i++) {
            if (nums[(2 * i) + 1] < nums[i]) return false;
            if (nums[(2 * i) + 2] < nums[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    if (sol.isHeap(nums)) cout << "The array represents a binary min-heap." << endl;
    else cout << "The array does not represent a binary min-heap." << endl;
}