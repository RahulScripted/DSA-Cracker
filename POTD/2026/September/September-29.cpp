// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// 1 - It is ().
// 2 - It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// 3 - It can be written as (A), where A is a valid parentheses string.

// You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions: The path starts from the upper left cell (0, 0). The path ends at the bottom-right cell (m - 1, n - 1). The path only ever moves down or right. The resulting parentheses string formed by the path is valid. Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.










#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int length = m + n - 1;

        if (length % 2 != 0 || grid[0][0] != '(' ||
            grid[m - 1][n - 1] != ')') {
            return false;
        }

        vector<bitset<201>> dp(n);
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                bitset<201> reachable;

                if (row > 0) reachable |= dp[col];
                if (col > 0) reachable |= dp[col - 1];
                if (row == 0 && col == 0) reachable.set(0);

                dp[col] = grid[row][col] == '(' ? (reachable << 1) : (reachable >> 1);
            }
        }

        return dp[n - 1].test(0);
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'(', '(', ')'},
        {')', '(', ')'},
        {'(', '(', ')'}
    };

    bool result = solution.hasValidPath(grid);
    cout << (result ? "True" : "False") << endl;
}