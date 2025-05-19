/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-19
 * @tag  dynamicProgramming
 * @similar  62
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode.cn/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (41.36%)
 * Likes:    1420
 * Dislikes: 0
 * Total Accepted:    627.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m -
 * 1][n - 1]）。机器人每次只能向下或者向右移动一步。
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
 * 返回机器人能够到达右下角的不同路径数量。
 * 测试用例保证答案小于等于 2 * 10^9。
 *
 *
 *
 * 示例 1：
 *
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 * 解释：3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 *
 *
 * 示例 2：
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //cout << "i=" << i << " j=" << j << endl;
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                // if == 1 dp[i][j] = 0 equal defaultVal
            }
        }
        return dp[m-1][n-1];
        //return uniqueBT(obstacleGrid, m - 1, n - 1);
    }


    //不加cache TLE
    unordered_map<int, int> cache;
    // Your runtime beats 7.55 % of cpp submissions

    // row = [0, m-1]   col = [0, n-1]
    int uniqueBT(vector<vector<int>>& obs, int row, int col) {
        if (row < 0 || col < 0) {
            return 0;
        }
        if (obs[row][col] == 1) { // means obs
            return 0;
        }
        if (row == 0 && col == 0) {
            return 1;
        }
        int key = row * 100 + col;
        if (cache.count(key)) {
            return cache[key];
        }
        int res = uniqueBT(obs, row - 1, col) + uniqueBT(obs, row, col - 1);
        cache[key] = res;
        return res;
    }


};
// @lc code=end


/*

Wrong Answer
20/42 cases passed (N/A)
Testcase
[[1,0]]
Answer
1
Expected Answer
0

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


