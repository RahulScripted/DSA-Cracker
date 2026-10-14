// You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock. Find and return the maximum profit you can achieve.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size() - 1;
        for (int i = 0; i < n; i++)  ans += max(prices[i + 1] - prices[i], 0);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int max_profit = solution.maxProfit(prices);
    cout << "Maximum Profit: " << max_profit << endl;
}