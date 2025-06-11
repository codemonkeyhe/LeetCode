/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-11
 * @tag dynamicProgramming
 * @similar 120,931,1289
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 *
 * https://leetcode.cn/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (67.54%)
 * Likes:    403
 * Dislikes: 0
 * Total Accepted:    137.4K
 * Total Submissions: 202.4K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
 * 下降路径
 * 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置
 * (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1)
 * 。
 *
 *
 *
 * 示例 1：
 * 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * 输出：13
 * 解释：如图所示，为和最小的两条下降路径
 *
 *
 * 示例 2：
 * 输入：matrix = [[-19,57],[-40,-5]]
 * 输出：-59
 * 解释：如图所示，为和最小的下降路径
 *
 *
 *
 *
 * 提示：
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n;i++) {
            for (int j = 0; j < n; j++) {
                int minVal = dp[i-1][j];
                if (j >= 1) {
                    minVal = min(minVal, dp[i-1][j-1]);
                }
                if (j + 1 < n) {
                    minVal = min(minVal, dp[i-1][j+1]);
                }
                dp[i][j] = minVal + matrix[i][j];
            }
        }
        auto& lastRow = dp[n-1];
        int minRes = *min_element(lastRow.begin(), lastRow.end());
        return minRes;
    }
};
// @lc code=end

/*
dp[i][j]表示从matrix[0][X]下降到matrix[i][j]的路径最小和

易得
dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];

dp[0][j] = matrix[0][j]

answer = min(dp[n-1][0 .. n-1])


*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


