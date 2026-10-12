// Given that the prices and profits of length n in the 0-indexed arrays. An item at a store has a price of prices[i] and a profit of profits[i], and there are n goods in total. Three objects must be chosen under the following circumstances:

//     1 - costs[i] < costs[j] < costs[k] where i < j < k.
//     2 - The profit would be profits[i] + profits[j] + profits[k] if we chose products whose indices i, j, and k met the criteria mentioned above.

// Return the highest potential profit and -1 if selecting three things under the specified conditions is not feasible








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        int maxTotalProfit = -1;

        for (int j = 0; j < n; ++j) {
            int maxLeftProfit = 0;
            int maxRightProfit = 0;

            for (int i = 0; i < j; ++i) {
                if (prices[i] < prices[j]) maxLeftProfit = max(maxLeftProfit, profits[i]);
            }

            for (int k = j + 1; k < n; ++k) {
                if (prices[j] < prices[k]) maxRightProfit = max(maxRightProfit, profits[k]);
            }

            if (maxLeftProfit > 0 && maxRightProfit > 0) maxTotalProfit = max(maxTotalProfit, maxLeftProfit + profits[j] + maxRightProfit);
        }

        return maxTotalProfit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {1, 2, 3, 4, 5};
    vector<int> profits = {10, 20, 30, 40, 50};
    int result = solution.maxProfit(prices, profits);
    cout << "Maximum Profit: " << result << endl;
}