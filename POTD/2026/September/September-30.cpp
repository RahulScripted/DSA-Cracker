// A string is a valid parentheses string (denoted VPS) if and only if it consists of "(" and ")" characters only, and:

//     1  - It is the empty string, or
//     2  - It can be written as AB (A concatenated with B), where A and B are VPS's, or
//     3  - It can be written as (A), where A is a VPS.

// We can similarly define the nesting depth depth(S) of any VPS S as follows:

//     1 - depth("") = 0
//     2 - depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
//     3 - depth("(" + A + ")") = 1 + depth(A), where A is a VPS.

// Given a VPS seq, split it into two disjoint subsequences A and B, such that A and B are VPS's (and A.length + B.length = seq.length). The subsequences may not necessarily be contiguous. This corresponds to the output [0, 1, 0, 1, 0, 1, 0, 1, 0]  where 0 indicates membership in A and 1 indicates membership in B. Now choose any such A and B such that max(depth(A), depth(B)) is the minimum possible value. Return an answer array (of length seq.length) that encodes such a choice of A and B:  answer[i] = 0 if seq[i] is part of A, else answer[i] = 1.  Note that even though multiple answers may exist, you may return any of them.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = s.size(); 
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = (i ^ s[i]) & 1;
        return res;
    }
}; 

int main() {
    Solution sol;
    string seq = "(()())";
    vector<int> result = sol.maxDepthAfterSplit(seq);
    
    for (int i : result) cout << i << " ";
    cout << endl;
}