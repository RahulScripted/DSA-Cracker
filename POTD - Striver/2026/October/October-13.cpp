// You are given three arrays: username, website, and timestamp, all of the same length n. The ith tuple [username[i], website[i], timestamp[i]] represents that user username[i] visited website website[i] at time timestamp[i]. A pattern is a sequence of exactly three websites (not necessarily distinct) visited by the same user in chronological order. Your task is to find the most visited pattern — the pattern visited by the maximum number of distinct users. If multiple patterns have the same maximum count, return the lexicographically smallest one.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> d;
        int n = username.size();
        for (int i = 0; i < n; ++i) {
            auto user = username[i];
            int ts = timestamp[i];
            auto site = website[i];
            d[user].emplace_back(ts, site);
        }
        unordered_map<string, int> cnt;
        for (auto& [_, sites] : d) {
            int m = sites.size();
            unordered_set<string> s;
            if (m > 2) {
                sort(sites.begin(), sites.end());
                for (int i = 0; i < m - 2; ++i) {
                    for (int j = i + 1; j < m - 1; ++j) {
                        for (int k = j + 1; k < m; ++k) {
                            s.insert(sites[i].second + "," + sites[j].second + "," + sites[k].second);
                        }
                    }
                }
            }
            for (auto& t : s) {
                cnt[t]++;
            }
        }
        int mx = 0;
        string t;
        for (auto& [p, v] : cnt) {
            if (mx < v || (mx == v && t > p)) {
                mx = v;
                t = p;
            }
        }
        return split(t, ',');
    }

    vector<string> split(string& s, char c) {
        vector<string> res;
        stringstream ss(s);
        string t;
        while (getline(ss, t, c)) {
            res.push_back(t);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> username = {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary"};
    vector<int> timestamp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<string> website = {"home", "about", "career", "home", "cart", "maps", "home", "home", "about"};
    
    vector<string> result = solution.mostVisitedPattern(username, timestamp, website);
    cout << "Most visited pattern: ";
    for (const string& site : result) cout << site << " ";
}