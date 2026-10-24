// You are given an integer n. You need to check if the number is a perfect number or not. Return true if it is a perfect number, otherwise, return false. A perfect number is a number whose proper divisors (excluding the number itself) add up to the number itself.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfect(int n) {
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) sum += i;
        }
        return sum == n;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (sol.isPerfect(n)) cout << n << " is a perfect number." << endl;
    else cout << n << " is not a perfect number." << endl;
}