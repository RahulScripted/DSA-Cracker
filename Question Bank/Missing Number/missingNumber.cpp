// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Math Formula
        int n = nums.size(), currentSum = 0;
        int totalSum = (n * (n + 1)) / 2;
        for(int num: nums) currentSum += num;
        return totalSum - currentSum;

        // Using Sorting Algorithm
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < n;i++){
        //     if(nums[i] != i) return i;
        // }
        // return n;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,0,1};
    cout << "Missing number : " << s.missingNumber(nums) << endl;
}