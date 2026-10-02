// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.





#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<string> sol;
    void backtrack(string &temp, int open, int close) {
        if(open == 0 && close == 0){
            sol.push_back(temp);
            return;
        }
        if(open > 0){
            temp.push_back('(');
            backtrack(temp, open - 1, close);
            temp.pop_back();
        }
        if(close > open){
            temp.push_back(')');
            backtrack(temp, open, close - 1);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        backtrack(str, n, n);
        return sol;
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<string> result = s.generateParenthesis(n);
    for(const string &p : result) cout << p << endl;
}