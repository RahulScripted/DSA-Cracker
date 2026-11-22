// Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int countB = 0;
        int n = s.size();
        for(char ch : s){
            if(ch == 'a' && countB == 0) continue;
            else if(ch == 'a' && countB != 0) return false;
            else countB++;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "aaaaaaaaabbb";
    cout << "If every 'a' appears before every 'b' in the string \"" << s << "\": " << (sol.checkString(s) ? "true" : "false") << endl;
}