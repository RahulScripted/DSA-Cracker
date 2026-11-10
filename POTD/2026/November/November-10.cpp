// You are climbing a staircase with n + 1 steps, numbered from 0 to n. You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i. From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2 You start from step 0 with cost = 0. Return the minimum total cost to reach step n.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = 0, c = 0;
        for (int cost : costs) {
            int cur = cost + min({a + 1, b + 4, c + 9});
            c = b, b = a, a = cur;
        }
        return a;
    }
};

int main() {
    Solution solution;
    int n = 5;
    vector<int> costs = {1, 2, 3, 4, 5};
    int result = solution.climbStairs(n, costs);
    cout << "Minimum total cost to reach step " << n << ": " << result << endl;
}