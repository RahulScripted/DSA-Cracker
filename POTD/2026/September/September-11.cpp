// You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits. Note: Each copy of a digit can only be used once per number, and there may not be leading zeros






#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            if (digits[i] % 2 == 1) continue;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                for (int k = 0; k < n; ++k) {
                    if (digits[k] == 0 || k == i || k == j) continue;
                    s.insert(digits[k] * 100 + digits[j] * 10 + digits[i]);
                }
            }
        }
        return s.size();
    }
};

int main() {
    Solution solution;
    vector<int> digits = {1, 2, 3, 0};
    cout << "Number of distinct three-digit even numbers: " << solution.totalNumbers(digits) << endl;
    return 0;
}