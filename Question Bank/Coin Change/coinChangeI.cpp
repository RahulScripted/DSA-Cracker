// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. You may assume that you have an infinite number of each kind of coin.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1;i <= amount;i++){
            for(int coin : coins){
                if(i - coin >= 0) dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(){
    Solution solution;
    vector<int> coins = {1,3,4};
    int amount = 6;
    cout << "Minimum coins required : " << solution.coinChange(coins, amount) << endl;

    coins = {2};
    amount = 3;
    cout << "Minimum coins required : " << solution.coinChange(coins, amount) << endl;
}