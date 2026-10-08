// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings. Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                if (count > 0) ans += c;
                count++;
            } else {
                count--;
                if (count > 0) ans += c;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "(()())(())";
    string result = solution.removeOuterParentheses(s);
    cout << "After removing outer parentheses: " << result << endl;
}