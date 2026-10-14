// Given an integer array nums, return a list of all the leaders in the array. A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size(), maximum = INT_MIN;
        vector<int>ans;
        for(int i = (n - 1);i >= 0;i--){
            if(nums[i] > maximum) {
                ans.push_back(nums[i]);
                maximum = nums[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> result = sol.leaders(nums);
    
    cout << "Leaders in the array: ";
    for(int leader : result) cout << leader << " ";
}   