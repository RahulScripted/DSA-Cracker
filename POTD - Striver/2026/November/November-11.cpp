// You are given an integer n. You need to find out the number of prime numbers in the range [1, n] (inclusive). Return the number of prime numbers in the range. A prime number is a number which has no divisors except, 1 and itself.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int primeUptoN(int n) {
        vector<bool> isPrime(n + 1, true);
        
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;
        
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) isPrime[i] = false;
            }
        }
        
        int count = 0;
        for (int p = 2; p <= n; p++) {
            if (isPrime[p]) count++;
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    int n = 6;
    int result = solution.primeUptoN(n);
    cout << "Number of prime numbers in the range [1, " << n << "] is: " << result << endl;
}