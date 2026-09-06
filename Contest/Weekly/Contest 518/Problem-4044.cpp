// You are given an integer array nums of even length n. A cyclic rotation of nums is obtained by choosing a prefix of nums whose length is between 0 and n - 1 (inclusive), and moving it to the end of the array while preserving the order of all elements. A cyclic rotation is good if the sum of its first n / 2 elements is strictly greater than the sum of its last n / 2 elements. Return the number of cyclic rotations of nums that are good.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long int total = accumulate(nums.begin(), nums.end(), 0ll);
        int n = nums.size();

        vector<long long int> prefix(n + 1, 0);
        for(int i = 1;i <= n;i++) prefix[i] += prefix[i - 1] + nums[i - 1];

        int sol = 0;
        for(int i = (n / 2) + 1;i <= n;i++){
            long long int left = prefix[i] - prefix[i - n/2];
            long long int right = total - left;

            if(left != right) sol++;
        }
        return sol;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << "Number of good cyclic rotations of nums : " << sol.countGoodRotations(nums) << endl; 
}