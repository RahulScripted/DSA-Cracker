// Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:

//     1 - Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
//     2 - Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
//     3 - In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

// You can insert the characters '(' and ')' at any position of the string to balance it if needed. Return the minimum number of insertions needed to make s balanced.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int open = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else {
                if (i + 1 < s.size() && s[i + 1] == ')') i++;
                else ans++;

                if (open > 0) open--;
                else ans++;
            }
        }

        return ans + open * 2;
    }
};

int main() {
    Solution solution;
    string s = "(()))";
    int result = solution.minInsertions(s);
    cout << "Minimum insertions needed: " << result << endl;
}