// You are given an integer n. Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting. In standard formatting:

//     1 - A comma is inserted after every three digits from the right.
//     2 - Numbers with fewer than 4 digits contain no commas.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        return max(0, n - 999);
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter a number : ";
    cin >> n;
    cout << "Number of commas required : " << solution.countCommas(n) << endl;
}