// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.Note that you must do this in-place without making a copy of the array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //  Single Loop
        int n = nums.size(), isZero = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] != 0){
                swap(nums[i] , nums[isZero]);
                isZero++;
            }
        }

        // Double Loop
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if(nums[i] == 0 && nums[j] != 0) swap(nums[i], nums[j]);
        //     }
        // }
    }
};

void print(vector<int> nums){
    for(auto it: nums) cout<<it<<" ";
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> nums = {0,1,0,3,12};
    cout<<"Before moving 0's : ";
    print(nums);
    
    s.moveZeroes(nums);
    cout<<"After moving 0's : ";
    print(nums);
}