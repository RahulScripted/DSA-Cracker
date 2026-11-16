// You are given a string s consisting of digits and an integer k. A round can be completed if the length of s is greater than k. In one round, do the following:

//     1 - Divide s into consecutive groups of size k such that the first k characters are in the first group, the next k characters are in the second group, and so on. Note that the size of the last group can be smaller than k.
//     2 - Replace each group of s with a string representing the sum of all its digits. For example, "346" is replaced with "13" because 3 + 4 + 6 = 13.
//     3 - Merge consecutive groups together to form a new string. If the length of the string is greater than k, repeat from step 1.

// Return s after all rounds have been completed.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while (ssize(s) > k) {
            string next;
            for (int i = 0; i < ssize(s); i += k) {
                string_view group = string_view(s).substr(i, k);
                next += to_string(accumulate(group.begin(), group.end(), 0, [](int sum, char d) { return sum + d - '0'; }));
            }
            s = next;
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "11111222223";
    int k = 3;
    cout << "After all rounds: " << solution.digitSum(s, k) << endl;
}