/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-27
 */

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Spiral Matrix.
*/
    vector<int> spiralOrderM3(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row == 0) {
            return  res;
        }
        int col = matrix[0].size();
        int up = 0;
        int down = row-1;
        int left = 0;
        int right = col-1;
        int i = 0;
        int j = 0;
        while(up <= down && left<=right) {
            //up
            for (j=left; j<=right; ++j) {
                res.push_back(matrix[up][j]);
            }
            up++;
            if (up>down) {
                break;
            }
            //right
            for(i=up; i<=down; ++i) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (right<left) {
                break;
            }
            //down
            for (j=right; j>=left; --j) {
                res.push_back(matrix[down][j]);
            }
            down--;
            //left
            for(i=down; i>=up; --i) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }


    //M2
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row == 0) {
            return  res;
        }
        int col = matrix[0].size();
        int up = 0;
        int down = row-1;
        int left = 0;
        int right = col-1;
        int i = 0;
        int j = 0;
        while(up <= down && left<=right) {
            //up
            for (j=left; j<=right; ++j) {
                res.push_back(matrix[up][j]);
            }
            //right
            for(i=up+1; i<=down; ++i) {
                res.push_back(matrix[i][right]);
            }
            if (up < down && left < right) {
                // down
                for (j = right - 1; j >= left; --j) {
                    res.push_back(matrix[down][j]);
                }
                // left
                for (i = down - 1; i > up ; --i) {
                    res.push_back(matrix[i][left]);
                }
            }
            up++;
            right--;
            down--;
            left++;
        }
        return res;
    }

};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

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

    Solution s;
    auto r = s.spiralOrder(vv);
    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}


/*
Tips
M1 Simulation 真实模拟
https://leetcode-cn.com/problems/spiral-matrix/solution/luo-xuan-ju-zhen-by-leetcode/
根据当前位置(i,j) + 下一步的位置增量(di[k], dj[k])得到新的位置(ni, nj) ,其中ni=i+di[k], nj=j+dj[k]
增量(di[k],dj[k]) 为下面个数组,。
        int[] di = {0, 1, 0, -1};
        int[] dj = {1, 0, -1, 0};
遍历up层时，k=0, di=0，dj=1,即每次j+1,i不变
遍历right时，k=1, di=1, dj=0, 即每次i+1,j不变
转向逻辑
i大于row或者j大于col时，则转向，相当于k=(k+1)%4。总共4个转向，需要设计转向数组di和dj。


M2 Layer-by-Layer 按圈遍历
遍历完外圈之后，再一次性修改四个下标，把矩阵最外圈砍掉

M3 URDL up-right-down-left  本质上和M2类似
每遍历完一边，实时调整边界,慢慢缩小边界直到边界锁定到最后一个元素上
主要在于下标的处理，容易踩坑


Skill
为了考虑下标的边界情况，构造一行或者一列的矩阵作为测试
*/
