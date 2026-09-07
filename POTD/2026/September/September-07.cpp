// Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7. A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        long long res = 1;
        vector<long long> dp(26, 0);

        for(char ch : s) {
            long long temp = res;
            res = (res * 2) % mod;
            res = (res - dp[ch - 'a'] + mod) % mod;
            dp[ch - 'a'] = temp;
        }

        res = (res + mod) % mod;
        return (res - 1 + mod) % mod;
    }
};

int main() {
    Solution solution;

    string s = "abc";
    int result = solution.distinctSubseqII(s);
    cout << "Number of distinct non-empty subsequences: " << result << endl;

    s = "aba";
    result = solution.distinctSubseqII(s);
    cout << "Number of distinct non-empty subsequences: " << result << endl;
}