// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0. You may assume that you have an infinite number of each kind of coin. The final answer is guaranteed to fit into a signed 32-bit integer.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> required(amount + 1, 0);
        required[0] = 1;

        for(int coin : coins){
            for(int i = coin; i <= amount;i++){
                required[i] += required[i - coin];
            }
        }

        return required[amount];
    }
};

int main(){
    Solution solution;
    int amount = 5;
    vector<int> coins = {1,2,5};
    cout << "Number of combinations that make up that " << amount << " is : " << solution.change(amount, coins) << endl;

    amount = 3;
    coins = {2};
    cout << "Number of combinations that make up that " << amount << " is : " << solution.change(amount, coins) << endl;
}