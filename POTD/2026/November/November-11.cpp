// You are given five integers cost1, cost2, costBoth, need1, and need2. There are three types of items available:

//     1 - An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
//     2 - An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
//     3 - An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.

// You must collect enough items so that the total contribution toward type 1 is at least need1 and the total contribution toward type 2 is at least need2. Return an integer representing the minimum possible total cost to achieve these requirements.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1 == 0 && need2 == 0) return 0;

        long long ans = LLONG_MAX;
        long long x;

        x = 0;
        ans = min(ans, x * (long long)costBoth + need1 * (long long)cost1 + need2 * (long long)cost2);
        x = min(need1, need2);
        ans = min(ans, x * (long long)costBoth + (need1 - x) * (long long)cost1 + (need2 - x) * (long long)cost2);


        x = max(need1, need2);
        ans = min(ans, x * (long long)costBoth + max(0LL, need1 - x) * (long long)cost1 + max(0LL, need2 - x) * (long long)cost2);

        return ans;
    }
};

int main() {
    Solution solution;
    int cost1 = 2, cost2 = 3, costBoth = 4, need1 = 5, need2 = 6;
    long long result = solution.minimumCost(cost1, cost2, costBoth, need1, need2);
    cout << "Minimum possible total cost: " << result << endl;
}