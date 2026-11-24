// Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int k) {
       int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == k) return mid;

            if (nums[low] <= nums[mid]) {
                if (k >= nums[low] && k < nums[mid]) high = mid - 1;
                else low = mid + 1;
            } 

            else {
                if (k > nums[mid] && k <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int k = 0;
    int result = solution.search(nums, k);
    cout << "Index of " << k << ": " << result << endl;
}