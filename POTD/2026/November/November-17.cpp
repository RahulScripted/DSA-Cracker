// Given a string s and an integer k, partition s into k substrings such that the letter changes needed to make each substring a semi-palindrome are minimized. Return the minimum number of letter changes required. A semi-palindrome is a special type of string that can be divided into palindromes based on a repeating pattern. To check if a string is a semi-palindrome:​

//     1 - Choose a positive divisor d of the string's length. d can range from 1 up to, but not including, the string's length. For a string of length 1, it does not have a valid divisor as per this definition, since the only divisor is its length, which is not allowed.
//     2 - For a given divisor d, divide the string into groups where each group contains characters from the string that follow a repeating pattern of length d. Specifically, the first group consists of characters at positions 1, 1 + d, 1 + 2d, and so on; the second group includes characters at positions 2, 2 + d, 2 + 2d, etc.
//     3 - The string is considered a semi-palindrome if each of these groups forms a palindrome.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size(), inf = INT_MAX / 2;
        auto peel = [&](int i, int j, int d) { 
            int changes = 0;
            for (; j - i > d; i += d, j -= d){
                for (int t = 0; t < d; ++t) changes += s[i + t] != s[j - d + t];
            }
            return changes;
        };

        vector cost(n + 1, vector(n + 1, inf));
        for (int d = 1; 2 * d <= n; ++d){
            for (int length = 2 * d; length <= n; length += d){
                for (int i = 0, j = length; j <= n; ++i, ++j) cost[i][j] = min(cost[i][j], peel(i, j, d));
            }
        }

        vector best(n + 1, inf);
        best[0] = 0;
        auto extend = [&](int j) { 
            return ranges::min(views::iota(0, j - 1) | views::transform([&](int i) { return best[i] + cost[i][j]; }));
        };
        for (int pieces = 1; pieces < k; ++pieces) {
            vector next(n + 1, inf);
            for (int j = 2 * pieces; j <= n - 2 * (k - pieces); ++j) next[j] = extend(j);
            swap(best, next);
        }
        return extend(n);
    }
};

int main(){
    Solution sol;
    string s = "abcac";
    int k = 3;
    cout << "Minimum changes required: " << sol.minimumChanges(s, k) << endl;
}