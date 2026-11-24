// You are given an array of positive integers nums. An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

//     1 - prod(arr) is the product of all elements of arr.
//     2 - gcd(arr) is the GCD of all elements of arr.
//     3 - lcm(arr) is the LCM of all elements of arr.

// Return the length of the longest product equivalent subarray of nums.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        const long long LIMIT = 25200;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long prod = 1, g = 0, l = 1;
                bool ok = true;

                for (int k = i; k <= j; k++) {
                    prod *= nums[k];
                    if (prod > LIMIT) { 
                        ok = false; 
                        break; 
                    }
                    g = gcd(g, (long long) nums[k]);
                    l = lcm(l, (long long) nums[k]);
                }

                if (ok && prod == g * l) ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 4, 6};
    int result = solution.maxLength(nums);
    cout << "Length of the longest product equivalent subarray: " << result << endl;
}