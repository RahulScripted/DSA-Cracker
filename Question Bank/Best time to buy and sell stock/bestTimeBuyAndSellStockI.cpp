// Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock at most once.  The stock should be purchased before selling it, and both actions cannot occur on the same day.





#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        // Optimized Solution
        int minPrice = INT_MAX, maxProfit = 0;
        for(int i = 0; i < n; i++){
            minPrice = min(minPrice, arr[i]);
            maxProfit = max(maxProfit, arr[i] - minPrice);
        }
        return maxProfit;

        // Brute-force Approach
        // int maxProfit = 0;
        // for(int i = 0; i < (n - 1); i++){
        //     for(int j = (i + 1); j < n; j++){
        //         if(arr[j] > arr[i]) maxProfit = max(maxProfit, arr[j] - arr[i]);
        //     }
        // }

        // return maxProfit;
    }
};

int main(){
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout<< "Maximum profit: " << sol.stockBuySell(arr, arr.size()) << endl;
}