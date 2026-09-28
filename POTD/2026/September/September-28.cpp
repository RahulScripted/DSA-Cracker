// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepthVal = 0;
        for (char c : s) {
            if (c == ')') {
                depth--;
                continue;
            }
            if (c != '(') continue;
            depth++;
            if (depth > maxDepthVal) maxDepthVal = depth;
        }
        return maxDepthVal;
    }
};

int main() {
    Solution solution;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << solution.maxDepth(s) << endl;
}