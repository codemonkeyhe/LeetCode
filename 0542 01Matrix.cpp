/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-25
 * @tag  bfs, dynamicProgramming
 * @similar  542,  1162
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 *
 * https://leetcode.cn/problems/01-matrix/description/
 *
 * algorithms
 * Medium (46.84%)
 * Likes:    991
 * Dislikes: 0
 * Total Accepted:    153.6K
 * Total Submissions: 323.8K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
 * 两个相邻元素间的距离为 1 。
 *
 *
 *
 * 示例 1：
 * 输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：[[0,0,0],[0,1,0],[0,0,0]]
 *
 *
 * 示例 2：
 * 输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
 * 输出：[[0,0,0],[0,1,0],[1,2,1]]
 *
 *
 *
 *
 * 提示：
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 104
 * 1 <= m * n <= 104
 * mat[i][j] is either 0 or 1.
 * mat 中至少有一个 0
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrixM1v1(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> dp(row, vector<int>(col, INT_MAX/2));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    continue;
                }
                int up = INT_MAX/2;
                if (i > 0) {
                    up = dp[i-1][j];
                }
                int left = INT_MAX/2;
                if (j > 0) {
                    left = dp[i][j-1];
                }
                dp[i][j] = min(up, left) + 1;
            }
        }

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    continue;
                }
                int down = INT_MAX/2;
                if (i < row-1) {
                    down = dp[i+1][j];
                }
                int right = INT_MAX/2;
                if (j < col - 1) {
                    right = dp[i][j+1];
                }
                int minV = min(down, right) + 1;
                dp[i][j] = min(dp[i][j], minV);
            }
        }
        return dp;
    }

      vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int defV = INT_MAX/2;
        vector<vector<int>> dp(row, vector<int>(col, defV));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                int up = (i > 0) ? dp[i - 1][j] : defV;
                int left = (j > 0) ? dp[i][j - 1] : defV;
                dp[i][j] = min(up, left) + 1;
            }
        }

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    continue;
                }
                int down = (i + 1 < row) ? dp[i + 1][j] : defV;
                int right = (j + 1 < col) ? dp[i][j + 1] : defV;
                int minV = min(down, right) + 1;
                dp[i][j] = min(dp[i][j], minV);
            }
        }
        return dp;
    }
};
// @lc code=end




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
