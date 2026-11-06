// You are given an unsorted array arr[] of integers that may contain duplicates. Your task is to remove the duplicate elements, keeping only the first occurrence of each element, and return the resulting array.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicates(vector<int>& arr) {
        unordered_set<int> seen;
        vector<int> result;
        
        for (int num : arr) {
            if (seen.find(num) == seen.end()) {
                seen.insert(num);
                result.push_back(num);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {4, 2, 3, 2, 1, 4, 5};
    
    vector<int> result = solution.removeDuplicates(arr);
    cout << "Array after removing duplicates: ";
    for (int num : result) cout << num << " ";
}