// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Optimal Approach
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()) return {mp[complement], i};
            mp[nums[i]] = i;
        }
        return {-1, -1};

        // Brute-force Approach
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i, j};
        //         }
        //     }
        // }
        // return {-1, -1};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    
    cout << "Indices of the two numbers that add up to " << target << ": ";
    for(int index : result) cout << index << " ";
}