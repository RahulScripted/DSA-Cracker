// You are given an integer n. Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting. In standard formatting:

//     1 - A comma is inserted after every three digits from the right.
//     2 - Numbers with fewer than 4 digits contain no commas.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0, p;
        for(p = 1000; p <= n; p *= 1000) res += (n - p + 1);
        return res;
    }
};

int main() {
    Solution sol;
    long long n;
    cout<< "Enter a number: ";
    cin >> n;
    cout << "Number of commas: " << sol.countCommas(n) << endl;
}