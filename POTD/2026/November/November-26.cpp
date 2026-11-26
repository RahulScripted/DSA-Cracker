// Alice and Bob are playing a game where they take turns removing stones from a pile, with Alice going first.

//     1 - Alice starts by removing exactly 10 stones on her first turn.
//     2 - For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent.
//     3 - The player who cannot make a move loses the game.

// The player who cannot make a move loses the game. Given a positive integer n, return true if Alice wins the game and false otherwise.








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        bool t = 0;
        int pile = 10;

        while (n >= pile) {
            n -= pile--;
            t ^= 1;
        }

        return t;
    }
};

int main() {
    Solution solution;
    int n = 15;
    bool result = solution.canAliceWin(n);

    if (result) cout << "Alice wins the game." << endl;
    else cout << "Bob wins the game." << endl;
}