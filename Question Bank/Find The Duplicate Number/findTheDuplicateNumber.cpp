// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number. You must solve the problem without modifying the array nums and using only constant extra space.





#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Masking
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int idx = abs(nums[i]);
            if(nums[idx] < 0) return idx;
            nums[idx] = -nums[idx];
        }
        
        return n;

        // Two Pointer
        // int slow = nums[0], fast = nums[0];
        // do {
        //     fast = nums[nums[fast]];
        //     slow = nums[slow];
        // } while(fast != slow);
        
        // fast = nums[0];
        // while(fast != slow){
        //     fast = nums[fast];
        //     slow = nums[slow];
        // }
        
        // return slow;

        // Hashset
        // unordered_set<int> isSeen;
        // for (int num : nums) {
        //     if (isSeen.find(num) != isSeen.end()) return num;
        //     isSeen.insert(num);
        // }
        // return -1; 

        // Hashmap
        // unordered_map<int, int> isSeen;
        // for(int num : nums) isSeen[num]++;
        // for(auto num : isSeen) {
        //     if(num.second > 1) return num.first;
        // }
        // return -1;
        
        // Sorting Algorithm
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // for(int i = 1;i < n;i++){
        //     if(nums[i] == nums[i - 1]) return nums[i];
        // }
        // return -1;

        // 2 Loops
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(nums[i] == nums[j]) return nums[i];
        //     }
        // }
        // return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate Number: " << s.findDuplicate(nums) << endl;
}