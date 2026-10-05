// Given a balanced parentheses string s, return the score of the string. The score of a balanced parentheses string is based on the following rule:

//     1 - "()" has score 1.
//     2 - AB has score A + B, where A and B are balanced parentheses strings.
//     3 - (A) has score 2 * A, where A is a balanced parentheses string.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            }
            else {
                score = st.top() + max(2 * score, 1);
                st.pop();
            }
        }
        return score;
    }
};

int main() {
    Solution sol;
    string s = "(()(()))";
    cout << sol.scoreOfParentheses(s) << endl;
}