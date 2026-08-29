// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int  n = nums.size();
        unordered_map<int, int>isSeen;
        for(int i = 0;i < n;i++){
            int val = nums[i];
            if((isSeen.find(val) != isSeen.end()) && (i - isSeen[val] <= k)) return true;
            isSeen[val] = i;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout << "Contains Duplicate : " << (solution.containsNearbyDuplicate(nums, k) == true ? "Yes, it contains duplicate" : "No, it doesn't duplicate");
}