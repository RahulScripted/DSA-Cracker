// You are given an integer n denoting the total number of servers and a 2D 0-indexed integer array logs, where logs[i] = [server_id, time] denotes that the server with id server_id received a request at time time. You are also given an integer x and a 0-indexed integer array queries. Return a 0-indexed integer array arr of length queries.length where arr[i] represents the number of servers that did not receive any requests during the time interval [queries[i] - x, queries[i]].






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int q = queries.size();
        vector<int> idx(q);
        for (int i = 0; i < q; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> cnt(n + 1, 0), res(q);
        int distinct = 0, l = 0, r = 0, m = logs.size();

        for (int id : idx) {
            int t = queries[id];
            while (r < m && logs[r][1] <= t) {
                if (cnt[logs[r][0]]++ == 0) distinct++;
                r++;
            }
            while (l < r && logs[l][1] < t - x) {
                if (--cnt[logs[l][0]] == 0) distinct--;
                l++;
            }
            res[id] = n - distinct;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<vector<int>> logs = {{0, 1}, {1, 2}, {2, 3}};
    int x = 1;
    vector<int> queries = {2, 3};
    vector<int> result = solution.countServers(n, logs, x, queries);
    
    cout<<"Number of servers that did not receive any requests during the time intervals:\n";
    for (int count : result) cout << count << " ";
}