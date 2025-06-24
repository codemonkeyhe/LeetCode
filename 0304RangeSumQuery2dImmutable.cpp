/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-24
 * @tag prefixSum,matrix
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 *
 * https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (62.38%)
 * Likes:    603
 * Dislikes: 0
 * Total Accepted:    158.1K
 * Total Submissions: 250.1K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * 给定一个二维矩阵 matrix，以下类型的多个请求：
 *
 *
 * 计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
 *
 *
 * 实现 NumMatrix 类：
 *
 *
 * NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
 * int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1)
 * 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入:
 * ["NumMatrix","sumRegion","sumRegion","sumRegion"]
 *
 * [[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
 * 输出:
 * [null, 8, 11, 12]
 *
 * 解释:
 * NumMatrix numMatrix = new
 * NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -10^5 <= matrix[i][j] <= 10^5
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * 最多调用 10^4 次 sumRegion 方法
 *
 *
 */

// @lc code=start
class NumMatrix1 {
public:
    NumMatrix1(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        ps.resize(row, vector<int>(col, 0));
        ps[0][0] = matrix[0][0];
        for (int i = 1; i < row; i++) {
            ps[i][0] = ps[i - 1][0] + matrix[i][0];
        }
        for (int j = 1; j < col; j++) {
            ps[0][j] = ps[0][j - 1] + matrix[0][j];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                ps[i][j] = matrix[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
//        return ps[row2][col2] - (ps[row1-1][col2] + ps[row2][col1-1] - ps[row1-1][col1-1]);
        int res =  ps[row2][col2];
        if (row1 >= 1) {
            res -= ps[row1 - 1][col2];
        }
        if (col1 >=1) {
            res -= ps[row2][col1-1];
        }
        if (col1 >=1 && row1>=1) {
            res+= ps[row1-1][col1-1];
        }
        return res;
    }

    vector<vector<int>> ps;
};


// offset偏移1位，避免下标计算
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        ps.resize(row + 1, vector<int>(col + 1, 0));
        ps[0][0] = matrix[0][0];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ps[i+1][j+1] = matrix[i][j] + ps[i][j+1] + ps[i+1][j] - ps[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return ps[row2+1][col2+1] - (ps[row1][col2+1] + ps[row2+1][col1] - ps[row1][col1]);
    }

    vector<vector<int>> ps;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

/*
通过画图可得知
preSum[i][j] = mat[i][j] + preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1]
preSum[0][0] = mat[0][0]
第1行和第一列参照一维数组前缀和即可


sumReg(r1,c1, r2,c2) = preSum[r2][c2] - (preSum[r1-1][c2] + preSum[r2][c1-1] - preSum[r1-1][c1-1])



Runtime Error
1/22 cases passed (N/A)
Error
Line 1126: Char 34: runtime error: addition of unsigned offset to 0x5030000006a0 overflowed to 0x503000000688 (stl_vector.h)
Line 1126: Char 34: runtime error: addition of unsigned offset to 0x5030000006a0 overflowed to 0x503000000688 (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_vector.h:1131:34
Testcase
["NumMatrix","sumRegion"]
[[[[-1]]],[0,0,0,0]]
Expected Answer
[null,-1]

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


