// You are given an array of integers arr and an integer target. You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum. Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int Maxi = n + 1;
        vector<int> dp(n, Maxi);
        int left = 0, sum = 0, ans = Maxi;

        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && dp[left - 1] != Maxi) ans = min(ans, len + dp[left - 1]);
                dp[right] = len;
            }

            if (right > 0) dp[right] = min(dp[right], dp[right - 1]);
        }

        return ans == Maxi ? -1 : ans;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 2, 2, 4, 3};
    int target = 3;
    int result = solution.minSumOfLengths(arr, target);
    cout << "Minimum sum of lengths: " << result << endl;
}