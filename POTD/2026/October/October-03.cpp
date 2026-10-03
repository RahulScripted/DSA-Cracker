// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(auto& s) {
        int res = 0;
        vector<int> stack = {-1};
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stack.push_back(i);
            else {
                stack.pop_back();
                if (stack.empty()) stack.push_back(i);
                else res = max(res, i - stack.back());
            }
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    string s = "(()())";
    cout << solution.longestValidParentheses(s) << endl;
}