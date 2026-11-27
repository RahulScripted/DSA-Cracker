// You are given a 2D integer array items, where items[i] = [factori, pricei] represents the ith item. You are also given an integer budget. There are unlimited copies of each item available for purchase.You may buy any number of copies of any items such that the total cost of the purchased copies is at most budget. After buying items, you may receive free copies according to the following rules:

//     1 - For each item i that you bought at least one copy of, you receive one free copy of every item j such that j != i and factori divides factorj.
//     2 - Buying multiple copies of the same item i does not give additional free copies through item i.
//     3 - The same item j can be received multiple times for free if it is received from purchases of different item types.

// Return the maximum total number of item copies you can obtain, including both purchased copies and free copies, while spending at most budget on purchased items.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int mult[1501] = {};
        for (auto& it : items) {
            int fac = it[0];
            for (int f = 1; f <= 1500; ++f) {
                if (fac % f == 0) ++mult[f];
            }
        }
        vector<int> dp(budget + 1, 0);
        for (auto& it : items) {
            int f = it[0], p = it[1];
            vector<int> ndp = dp;
            for (int b = budget; b >= p; --b) ndp[b] = max(ndp[b], dp[b - p] + mult[f]);
            for (int b = p; b <= budget; ++b) ndp[b] = max(ndp[b], ndp[b - p] + 1);
            dp = move(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> items = {{2, 3}, {3, 4}, {4, 5}};
    int budget = 10;
    cout << "Maximum total number of item copies: " << sol.maximumSaleItems(items, budget) << endl;
}