// You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column. Return the number of servers that communicate with any other server.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> rows(m), cols(n);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j){
                if (grid[i][j] && rows[i] + cols[j] > 2) ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    cout << "The number of servers can communicate : " << solution.countServers(grid) << endl;
}