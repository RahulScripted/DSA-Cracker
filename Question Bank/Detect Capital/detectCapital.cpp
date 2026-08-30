// We define the usage of capitals in a word to be right when one of the following cases holds:

//     1 - All letters in this word are capitals, like "USA".
//     2 - All letters in this word are not capitals, like "leetcode".
//     3 - Only the first letter in this word is capital, like "Google".

// Given a string word, return true if the usage of capitals in it is right.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count  = 0, n = word.size();
        if (n == 1) return true;

        for(int i = 0;i < n;i++){
            if(isupper(word[i])) count++;
        }

        if(count == 1 && isupper(word[0])) return true;
        if(count == 0 || count == n) return true;
        else return false;
    }
};

int main() {
    Solution solution;
    string word = "USA";
    cout<< "The usage of capitals in it is right ?  => " << (solution.detectCapitalUse(word) ? "Yes" : "No") << endl;

    word = "FlaG";
    cout<< "The usage of capitals in it is right ?  => " << (solution.detectCapitalUse(word) ? "Yes" : "No") << endl;
}