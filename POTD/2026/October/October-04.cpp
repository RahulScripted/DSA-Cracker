// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid. The following rules define a valid string:

//     1 - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//     2 - Any right parenthesis ')' must have a corresponding left parenthesis '('.
//     3 - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//     4 - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (auto& c : s) {
            low += ((c == '(') << 1) - 1;
            high += ((c != ')') << 1) - 1;
            if (high < 0) return 0;
            low = max(low, 0);
        }

        return low == 0;
    }
};

int main() {
    Solution solution;
    string s = "(*))";
    bool isValid = solution.checkValidString(s);
    cout << (isValid ? "true" : "false") << endl;
}