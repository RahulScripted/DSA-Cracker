// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Hashset
        unordered_set<int> hasCopy;
        for(int num : nums) hasCopy.insert(num);
        return hasCopy.size() < nums.size();

        // Hashmap
        // unordered_map<int, int> hasCopy;
        // for(int num : nums) hasCopy[num]++;
        // for(auto num : hasCopy){
        //     if(num.second > 1) return true;
        // }
        // return false;

        // Sorting
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i = 1;i < n;i++){
        //     if(nums[i - 1] == nums[i]) return true;
        // } 
        // return false;

        // 2 Loops
        // int n = nums.size();
        // for(int i = 0; i < n;i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }
        // return false;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,2,3,1};
    cout << "Contains Duplicate : " << (solution.containsDuplicate(nums) == true ? "Yes, it contains duplicate" : "No, it doesn't duplicate");
}