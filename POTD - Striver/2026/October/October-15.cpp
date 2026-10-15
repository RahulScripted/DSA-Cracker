// Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.






#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] < minVal) minVal = matrix[i][0];
            if (matrix[i][m - 1] > maxVal) maxVal = matrix[i][m - 1];
        }

        int desired = (n * m + 1) / 2;
        int lo = minVal, hi = maxVal;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int place = 0;
            for (int i = 0; i < n; ++i) place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            
            if (place < desired) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << sol.findMedian(matrix) << endl;
    return 0;
}