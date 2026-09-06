// Given two strings s and t, return the number of distinct subsequences of s which equals t. The test cases are generated so that the answer fits on a 32-bit signed integer.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        if(sSize < tSize) return 0;

        vector<unsigned long long> dp(tSize + 1);
        dp[tSize] = 1;

        for(int i = (sSize - 1); i >= 0; i--) {
            char sChar = s[i];
            for(int j = 0; j < tSize; j++) {
                if(sChar == t[j]) dp[j] += dp[j + 1];
            }
        }

        return dp[0];
    }
};

int main(){
    Solution solution;
    
    string s = "rabbbit", t = "rabbit";
    int result = solution.numDistinct(s, t);
    cout << "Number of distinct subsequences: " << result << endl;

    s = "babgbag", t = "bag";
    result = solution.numDistinct(s, t);
    cout << "Number of distinct subsequences: " << result << endl;
}