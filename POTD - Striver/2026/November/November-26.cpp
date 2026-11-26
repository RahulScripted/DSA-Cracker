// Given an array arr of size n containing elements, find the next greater element for each element in the array in the order of their appearance. The next greater element of an element in the array is the nearest element on the right that is greater than the current element. If there does not exist a next greater element for the current element, then the next greater element for that element is -1.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
       int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) st.pop();
            if (!st.empty()) result[i] = st.top();
            st.push(arr[i]);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = solution.nextLargerElement(arr);

    cout << "Next greater elements: ";
    for (int num : result) cout << num << " ";
}