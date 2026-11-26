// A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. An integer h represents the total time in hours to eat all the bananas. Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile and does not consume any more bananas in that hour. Determine the minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int minimumRateToEatBananas(vector<int> nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHours = 0;

            for (int bananas : nums) totalHours += (bananas + mid - 1) / mid;
            if (totalHours <= h) {
                ans = mid;
                high = mid - 1;
            } 
            else low = mid + 1;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 6, 7, 11};
    int h = 8;
    int result = solution.minimumRateToEatBananas(nums, h);
    cout << "Minimum number of bananas the monkey must eat per hour: " << result << endl;
}