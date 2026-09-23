// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations. Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s = accumulate(nums.begin(), nums.end(), 0) - x;
        unordered_map<int, int> vis = {{0, -1}};
        int mx = -1, t = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            t += nums[i];
            if (!vis.contains(t)) vis[t] = i;
            if (vis.contains(t - s)) mx = max(mx, i - vis[t - s]);
        }
        return mx == -1 ? -1 : n - mx;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    int result = solution.minOperations(nums, x);
    cout << "Minimum operations to reduce x to 0: " << result << endl;
}