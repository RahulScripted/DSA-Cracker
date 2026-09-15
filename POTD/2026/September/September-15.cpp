// You are given a string s and a positive integer k. Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

//     1 - The length of each substring is at least k.
//     2 - Each substring is a palindrome.

// Return the maximum number of substrings in an optimal selection. A substring is a contiguous sequence of characters within a string.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n;

        int res = 0;
        for (int i = 0; i <= n - k;) {
            int step = 1;

            for (int d : {k, k + 1}) {
                if (i + d <= n && equal(s.begin() + i, s.begin() + i + (d >> 1), s.rbegin() + (n - (i + d)))) {
                    step = d;
                    res++;
                    break;
                }
            }

            i += step;
        }

        return res;
    }
};

int main() {
    Solution solution;
    string s = "ababa";
    int k = 3;
    int result = solution.maxPalindromes(s, k);
    cout << "Maximum number of palindromic substrings: " << result << endl;
}