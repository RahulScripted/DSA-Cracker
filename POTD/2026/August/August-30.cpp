// You are given a 0-indexed array of distinct integers nums. There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array. A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array. Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        int front = right + 1;
        int back = n - left;
        int frontBack = (left + 1) + (n - right);
        return min({front, back, frontBack});
    }
};

int main() {
    Solution solution;

    // 1st Test Case
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    cout<<"The the minimum number of deletions required : "<<solution.minimumDeletions(nums) << endl;

    // 2nd Test Case
    nums = {0, -4, 19, 1, 8, -2, -3, 5};
    cout<<"The the minimum number of deletions required : "<<solution.minimumDeletions(nums) << endl;

    // 3rd Test Case
    nums = {101};
    cout<<"The the minimum number of deletions required : "<<solution.minimumDeletions(nums) << endl;
}