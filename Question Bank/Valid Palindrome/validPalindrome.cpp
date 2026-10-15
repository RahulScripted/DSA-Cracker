// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if(!isalnum(s[start])) start++;
            else if(!isalnum(s[end])) end--;
            else {
                if(tolower(s[start]) != tolower(s[end])) return false;
                start++;
                end--;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    cout << "Is palindrome: " << (solution.isPalindrome(s) ? "true" : "false") << endl;
}