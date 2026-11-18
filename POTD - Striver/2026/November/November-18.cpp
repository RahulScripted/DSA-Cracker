// Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.






#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int current_xor = 0;
        int count = 0;
        unordered_map<int, int> prefix_xor_map;
        prefix_xor_map[0] = 1;
        
        for (int num : nums) {
            current_xor ^= num;
            int target_xor = current_xor ^ k;
            
            if (prefix_xor_map.find(target_xor) != prefix_xor_map.end()) count += prefix_xor_map[target_xor];
            prefix_xor_map[current_xor]++;
        }
        
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    cout<<"Total number of subarrays : "<<sol.subarraysWithXorK(nums, k);
}