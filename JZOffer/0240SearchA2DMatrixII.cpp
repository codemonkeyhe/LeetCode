/**
 * @file
 * @brief  P3
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-05
 */

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example:
Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // M1
    // Runtime: 76 ms, faster than 88.89% of C++ online submissions for Search a 2D Matrix II.
    // Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix II.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }
        int i = 0;
        int j = col-1;
        int rightUp = 0;
        while(i < row && j >=0 ) {
            rightUp = matrix[i][j];
            if (target == rightUp) {
                return true;
            } else if (target > rightUp) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }

};

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return false;
}

void parseMatrix(int ** matrix, int row, int col, vector<vector<int>> *vv) {
    for (auto i=0;i < row; ++i) {
        vector<int> v;
        for (auto j = 0; j < col; ++j) {
            v.push_back(matrix[i][j]);
        }
        vv->push_back(v);
    }
}

int main() {
    int n = 5;
    int m = 5;
    int matrix[n][m] = {
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
};
    int target = 5;

    int *pm[n];
    for (int i = 0; i < n; ++i) {
        pm[i] = *(matrix+i);
    }

    vector<vector<int>> vv;
    parseMatrix(pm, n, m, &vv);

    auto r1 = searchMatrix(pm, n, m, target);
    printf("C: %d\n", r1);

    Solution s;
    auto r2 = s.searchMatrix(vv, target);
    cout << "CPP: " << r2 << endl;

    return 0;
}

/*
M1
从左下角或右上角分析，每次砍掉1行或者1列
T=O(m+n)


*/
