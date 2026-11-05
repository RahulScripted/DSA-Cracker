// Given a string s, write a program to invert the case of each character:

//     1 - Convert lowercase letters to uppercase
//     2 - Convert uppercase letters to lowercase
//     3 - Leave non-alphabetic characters unchanged







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toggleCase(const string& s) {
        string ans = s;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] >= 'a' && ans[i] <= 'z') ans[i] = ans[i] - 32;
            else if (ans[i] >= 'A' && ans[i] <= 'Z') ans[i] = ans[i] + 32;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s = 'JavA';
    string result = solution.toggleCase(s);
    cout << "Inverted case string: " << result << endl;
}