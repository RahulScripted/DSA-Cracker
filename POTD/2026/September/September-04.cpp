// You are given an integer array nums of length n and an integer k. For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]). In other words:

//     1 - max(nums[0..i]) is the largest value among the elements from index 0 to index i.
//     2 - min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.

// An index i is called stable if its instability score is less than or equal to k. Return the smallest stable index. If no such index exists, return -1







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n, 0);

        int mini = INT_MAX; 
        for (int i = n - 1; i >= 0; i--){
            mini = min(mini, nums[i]);
            suffix[i] = mini;
        }
 
        int maxi = 0;
        for (int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            int score = maxi - suffix[i];
            if (score <= k) return i;
        }
 
        return -1;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1, 3, 2, 4, 5};
    int k = 2;
    int result = solution.firstStableIndex(nums, k);
    cout << "The smallest stable index is: " << result << endl;
}