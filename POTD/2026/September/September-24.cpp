// You are given an integer array nums. Return the smallest index i such that the sum of the digits of nums[i] is equal to i. If no such index exists, return -1.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        const int n = min(28, int(nums.size()));

        for(int i = 0; i < n; i++){
            int x = nums[i], digitSum = 0;
            for(; x > 0; x /= 10) digitSum += x % 10;
            if (digitSum == i) return i;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = solution.smallestIndex(nums);
    cout << "The smallest index is: " << result << endl;
}