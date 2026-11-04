// Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones. If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.






#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &mat) {
        // Optimized 
        int n = mat.size();
        int m = mat[0].size();
        int i = 0, j = m - 1, idx = -1;

        while (i < n && j >= 0) {
            if (mat[i][j] == 1) {
                idx = i;
                j--;
            }
            else i++;
        }

        return idx;

        // Brute-force Approach
        // int n = mat.size();
        // int m = mat[0].size();
        // int countOne = 0, maxCountOne = 0, idx = -1;

        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j < m;j++){
        //         if(mat[i][j] == 1) countOne++;
        //     }
        //     if(countOne > maxCountOne){
        //         idx = i;
        //         maxCountOne = countOne;
        //     }
        //     countOne = 0;
        // }

        // return idx;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> mat = {{0, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    cout << "Maximum ones in row: " << obj.rowWithMax1s(mat) << endl; 
}