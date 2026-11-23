// Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream. Implement the ProductOfNumbers class:

//     1 - ProductOfNumbers() Initializes the object with an empty stream.
//     2 - void add(int num) Appends the integer num to the stream.
//     3 - int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.

// The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing








#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    vector<int> prefix{1};
public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) prefix = {1};
        else prefix.push_back(prefix.back() * num);
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) return 0;
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};

int main() {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    cout << productOfNumbers.getProduct(2) << endl;
    cout << productOfNumbers.getProduct(3) << endl;
    cout << productOfNumbers.getProduct(4) << endl;
}