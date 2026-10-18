// You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues. Your solution must modify the input stack in-place to reverse the order of its elements.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertBottom(stack<int>& s, int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }
        int t = s.top();
        s.pop();
        insertBottom(s, x);
        s.push(t);
    }

    void reverseStack(stack<int>& s) {
        if (s.empty()) return;
        int x = s.top();
        s.pop();
        reverseStack(s);
        insertBottom(s, x);
    }
};

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    Solution sol;
    sol.reverseStack(s);

    cout<< "Reversed stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}