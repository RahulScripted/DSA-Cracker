// You are given an array prices where prices[i] is the price of a given stock on the ith day. Find the maximum profit you can achieve. You may complete at most two transactions.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            f1 = max(f1, -prices[i]);
            f2 = max(f2, f1 + prices[i]);
            f3 = max(f3, f2 - prices[i]);
            f4 = max(f4, f3 + prices[i]);
        }
        return f4;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int max_profit = solution.maxProfit(prices);
    cout << "Maximum Profit: " << max_profit << endl;
}