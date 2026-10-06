// A parentheses string is valid if and only if:

//     1 - It is the empty string,
//     2 - It can be written as AB (A concatenated with B), where A and B are valid strings, or
//     3 - It can be written as (A), where A is a valid string.

// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string. Return the minimum number of moves required to make s valid.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, add = 0;
        for (char c : s) {
            if (c == '(') open++;
            else {
                if (open > 0) open--;
                else add++;
            }
        }
        return (add + open);
    }
};

int main() {
    Solution solution;
    string s = "())";
    cout << "Minimum needs to be added: " << solution.minAddToMakeValid(s) << endl;
}