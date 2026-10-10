// You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n. The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n. You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times. Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.







#iinclude <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> d(100001, 0);
        long long k = (long long)k1 + k2, sum = 0;
        int mx = 0;

        // Step 1: count the differences
        for (int i = 0; i < nums1.size(); i++) {
            int x = abs(nums1[i] - nums2[i]);
            d[x]++;
            sum += x;
            mx = max(mx, x);
        }

        // Step 2: shave the biggest differences, level by level
        if (sum <= k) return 0;
        for (int i = mx; i > 0 && k > 0; i--) {
            long long move = min(k, (long long)d[i]);
            d[i] -= move;
            d[i - 1] += move;
            k -= move;
        }

        // Step 3: add up the squares
        long long ans = 0;
        for (int i = 0; i <= mx; i++) ans += (long long)i * i * d[i];

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6};
    int k1 = 3;
    int k2 = 2;
    long long result = solution.minSumSquareDiff(nums1, nums2, k1, k2);
    cout << "Minimum sum of squared difference: " << result << endl;
}