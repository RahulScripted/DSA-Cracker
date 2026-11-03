// Given a 2D matrix matrix, handle multiple queries of the following types:

//     1 - Update the value of a cell in matrix.
//     2 - Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

// Implement the NumMatrix class:

//     1 - NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
//     2 - void update(int row, int col, int val) Updates the value of matrix[row][col] to be val.
//     3 - int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its corner (row1, col1) and lower right corner (row2, col2).








#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
private:
    int rows, cols;
    vector<vector<int>> mat;
    vector<vector<int>> bit;

    void add(int r, int c, int delta) {
        for (int i = r; i <= rows; i += i & -i) {
            for (int j = c; j <= cols; j += j & -j) {
                bit[i][j] += delta;
            }
        }
    }

    int query(int r, int c) {
        int sum = 0;
        for (int i = r; i > 0; i -= i & -i) {
            for (int j = c; j > 0; j -= j & -j) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        rows = matrix.size();
        cols = matrix[0].size();
        mat = matrix;
        bit.assign(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)  add(i + 1, j + 1, matrix[i][j]);
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - mat[row][col];
        mat[row][col] = val;
        add(row + 1, col + 1, delta);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2 + 1, col2 + 1) 
             - query(row1, col2 + 1) 
             - query(row2 + 1, col1) 
             + query(row1, col1);
    }
};

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    numMatrix.update(3, 2, 2);
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
}