// You are given a 2D integer array items, where items[i] = [factori, pricei] represents the ith item. You are also given an integer budget. There are unlimited copies of each item available for purchase. You may buy any number of copies of any items such that the total cost of the purchased copies is at most budget. After buying items, you may receive free copies according to the following rules:

//     1 - Each purchased copy of item i can give you at most one free copy of another item j.
//     2 - The free item must satisfy i != j and factori divides factorj.
//     3 - For each ordered pair (i, j), you can receive a free copy of item j from purchases of item i at most once, regardless of how many copies of item i you buy.
//     4 - The same item j can be received multiple times for free if it is received from purchases of different item types.

// Return the maximum total number of item copies you can obtain, including both purchased copies and free copies, while spending at most budget on purchased items.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), cheapest = INT_MAX;
        vector<int> have(n + 1);
        for (auto& item : items) {
            have[item[0]]++;
            cheapest = min(cheapest, item[1]);
        }
        vector<int> deals(n + 1, -1);

        vector<pair<int, int>> worth;
        for (auto& item : items){
            if (item[1] < 2 * cheapest) worth.emplace_back(item[1], item[0]);
        }

        priority_queue heap(greater<>(), std::move(worth));
        int copies = 0;
        while (!heap.empty() && heap.top().first <= budget) {
            auto [price, factor] = heap.top();
            heap.pop();
            if (deals[factor] < 0){
                for (int multiple = factor; multiple <= n; multiple += factor) deals[factor] += have[multiple];
            }
            
            int pairs = min(deals[factor], budget / price);
            copies += 2 * pairs;
            budget -= pairs * price;
        }
        return copies + budget / cheapest;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> items = {{1, 2}, {2, 3}, {3, 4}};
    int budget = 10;
    int result = solution.maximumSaleItems(items, budget);
    cout << "The maximum total number of item copies obtainable is: " << result << endl;
}