// You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.If two or more characters have same frequency then arrange them in alphabetic order.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<char> frequencySort(string& s) {
        vector<char> result;
        unordered_map<char, int> hash_map;
        for (char ch : s) hash_map[ch]++;

        vector<pair<char, int>> freq(hash_map.begin(), hash_map.end());
        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        for (auto& [ch, count] : freq) result.push_back(ch);
        return result;
    }
};

int main() {
    string s = "tree";
    Solution solution;
    vector<char> result = solution.frequencySort(s);
    cout<<"Unique characters sorted by frequency: ";
    for (char ch : result) cout << ch << " ";
}