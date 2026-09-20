// Given a string s, calculate its reverse degree. The reverse degree is calculated as follows:

//     1 - For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
//     2 - Sum these products for all characters in the string.

// Return the reverse degree of s.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0, n = s.length();
        for(int i = 0; i < n;i++){
            int pos = (i + 1);
            int charVal = 26 - (s[i] - 'a');
            sum += (pos * charVal);
        }
        return sum;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    cout << "Reverse degree of \"" << s << "\" is: " << sol.reverseDegree(s) << endl;
}