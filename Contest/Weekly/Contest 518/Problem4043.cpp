// You are given a string s of length n and an integer k. A cyclic rotation of s is obtained by choosing a prefix of s whose length is between 0 and n - 1 (inclusive), and moving it to the end of the string while preserving the order of all characters. For every cyclic rotation of s, let its score be the number of indices i such that 0 <= i < n - 1 and the characters at positions i and i + 1 are equal. Return the number of cyclic rotations of s whose score equals k.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRotations(string s, int k) {
        int rotation = 0, n = s.size();

        for(int i = 0;i < (n - 1); i++){
            if(s[i] == s[i + 1]) rotation++;
        }

        if(s[n - 1] == s[0]) rotation++;
        if(rotation == k) return n - rotation;
        if(k == (rotation - 1)) return rotation;
        return 0;
    }
};

int main(){
    Solution sol;
    string s = "aabbaa";
    int k = 2;
    cout << "Number of cyclic rotations of s whose score equals " << k << " : " << sol.countRotations(s, k) << endl; 
}