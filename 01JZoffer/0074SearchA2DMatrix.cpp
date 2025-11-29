/**
 * @file
 * @brief  P3-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-02
 */

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input:
matrix = [
  [1,  3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // M1　即麻烦而且容易写错
    // Runtime: 20 ms, faster than 13.44% of C++ online submissions for Search a 2D Matrix.
    // Memory Usage: 11.2 MB, less than 6.06% of C++ online submissions for Search a 2D Matrix.
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return false;
        }
        //bin-search row
        int left = 0;
        int right = row-1;
        int last = col -1;
        if (target > matrix[right][last]) {
            return false;
        }
        while(left<right) {  //非标准的二分写法 <  为了让left-right指向正确
            int mid = (left+right)>>1;
            if (target == matrix[mid][last] ) {
                return true;
            } else if (target < matrix[mid][last] ) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        //left == right
        int x = left;
        if (x >= row) {
            return false;
        }
        //bin-search col
        left = 0;
        right = last;
        while (left <= right) {
            int mid = (left+right)>>1;
            if (target == matrix[x][mid] ) {
                return true;
            } else if (target < matrix[x][mid] ) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

};


//M2
// Runtime: 4 ms, faster than 100.00% of C online submissions for Search a 2D Matrix.
// Memory Usage: 6.7 MB, less than 100.00% of C online submissions for Search a 2D Matrix.
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if( matrixSize == 0){
        return false;
    }
    int row = matrixSize;
    int col = *matrixColSize;
    int len = row*col;
    int left = 0;
    int right = len - 1;
    while(left<=right) {
        // BUG:  int mid = left + (right-left) >> 1;   + first then >>
        int mid = left + ((right-left) >> 1);
        int midVal = matrix[mid/col][mid%col];
        if ( target > midVal ) {
            left = mid +1;
        } else if (target < midVal) {
            right = mid -1;
        } else {
            return true;
        }
    }
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
    /*
    int n = 3;
    int m = 4;
    int matrix[n][m] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int target = 10;
    */

    int n = 1;
    int m = 1;
    int matrix[n][m] = {{1}};
    int target = 1;

    int *pm[n];
    for (int i = 0; i < n; ++i) {
        pm[i] = *(matrix+i);
    }

    vector<vector<int>> vv;
    parseMatrix(pm, n, m, &vv);

    auto r1 = searchMatrix(pm, n, &m, target);
    printf("C: %d\n", r1);

    Solution s;
    auto r2 = s.searchMatrix(vv, target);
    cout << "CPP: " << r2 << endl;

    return 0;
}


/*
Tips
M0 暴力法
T=O(m*n)

M1 二分查找
先定位行坐标，再定位列坐标
T=O(lgM*lgN)

M2 二维展开成一维的二分查找
T=O(lgM*N)
涉及到二维的行列坐标到一维转换
N行M列 Matrix[i][j]  转为 arr[k]
k = i*M + j
所以有 i=k/M   j=k%M

*/