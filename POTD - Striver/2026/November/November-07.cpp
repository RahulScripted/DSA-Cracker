// A word's generalized abbreviation can be constructed by taking any number of non-overlapping and non-adjacent substrings and replacing them with their respective lengths.





#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(const string& word, int pos, int count, string cur, vector<string>& res) {
        if (pos == word.length()) {
            if (count > 0) cur += to_string(count);
            res.push_back(cur);
            return;
        }

        backtrack(word, pos + 1, count + 1, cur, res);
        backtrack(word, pos + 1, 0, cur + (count > 0 ? to_string(count) : "") + word[pos], res);
    }

public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        backtrack(word, 0, 0, "", res);
        return res;
    }
};

int main() {
    Solution solution;
    string word = "word";
    vector<string> abbreviations = solution.generateAbbreviations(word);

    cout << "Generalized Abbreviations of \"" << word << "\":" << endl;
    for (const string& abbr : abbreviations) cout << abbr << endl;
}