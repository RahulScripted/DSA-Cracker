// Given a string s, find the length of the longest substring without duplicate characters.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), left = 0, maxLength = 0;
        unordered_set<char> charSet;

        for(int right = 0; right < n; ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: "  << solution.lengthOfLongestSubstring(s) << endl;
}