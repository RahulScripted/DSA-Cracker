// You are given a string s that contains some bracket pairs, with each pair containing a non-empty key. For example, in the string "(name)is(age)yearsold", there are two bracket pairs that contain the keys "name" and "age". You know the values of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [keyi, valuei] indicates that key keyi has a value of valuei. You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key keyi, you will: 

//     1 - Replace keyi and the bracket pair with the key's corresponding valuei.
//     2 - If you do not know the value of the key, you will replace keyi and the bracket pair with a question mark "?" (without the quotation marks).

// Each key will appear at most once in your knowledge. There will not be any nested brackets in s. Return the resulting string after evaluating all of the bracket pairs.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        unordered_map<string, string> map;

        for (const vector<string>& list : knowledge) map["(" + list[0] + ")"] = list[1];

        for (int i = 0; i < s.length(); ++i) {
            const char c = s[i];
            if (c == '(') {
                const int j = s.find_first_of(')', i);
                const string& key = s.substr(i, j - i + 1);
                ans += map.contains(key) ? map[key] : "?";
                i = j;
            } else ans += c;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {{"name", "bob"}, {"age", "two"}};
    cout << solution.evaluate(s, knowledge) << endl;
}