// Given an array of integers nums, return the value of the largest element in the array





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest = INT_MIN;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i] > largest) largest = nums[i];
        }
        return largest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5, 2, 9, 1};
    cout << "The largest element in the array is: " << sol.largestElement(nums) << endl;
}