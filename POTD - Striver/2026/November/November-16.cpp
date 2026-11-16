// Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once. Return the number of unique elements in the array. If the number of unique elements be k, then,

//     1- Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.
//     2- The remaining elements, as well as the size of the array does not matter in terms of correctness.
//     3 - The driver code will assess correctness by printing and checking only the first k elements of the modified array.

// An array sorted in non-decreasing order is an array where every element to the right of an element is either equal to or greater in value than that element.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 1; 
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = solution.removeDuplicates(nums);
    
    cout << "Number of unique elements: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}