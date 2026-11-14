// Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target. Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in any order.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()) return {mp[complement], i};
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 6, 2, 10, 3};
    int target  = 7;

    vector<int>result = sol.twoSum(nums, target);
    cout<< "The indexes are : ";
    for(int i = 0;i < result.size(); i++) cout<<result[i] << " ";
}