// Given an array of keywords words and a string s, make all appearances of all keywords words[i] in s bold. Any letters between <b> and </b> tags become bold. Return s after adding the bold tags. The returned string should use the least number of tags possible, and the tags should form a valid combination.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.length();
        vector<bool> bold(n, false);
        
        for (const string& word : words) {
            size_t pos = s.find(word, 0);
            while (pos != string::npos) {
                for (size_t i = pos; i < pos + word.length(); ++i) {
                    bold[i] = true;
                }
                pos = s.find(word, pos + 1);
            }
        }
        
        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (bold[i] && (i == 0 || !bold[i - 1])) ans += "<b>";
            
            ans += s[i];
            if (bold[i] && (i == n - 1 || !bold[i + 1])) ans += "</b>";
        }
        
        return ans;
    }
};


int main() {
    Solution solution;
    vector<string> words = {"abc", "123"};
    string s = "abcxyz123";
    string result = solution.boldWords(words, s);
    cout << "Answer: " << result << endl;
}