/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-25
 * @tag bfs,dfs,unionFind
 * @similar  200, 695, 1905
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 *
 * https://leetcode.cn/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (61.42%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    92.5K
 * Total Submissions: 149.8K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
 *
 * 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
 *
 * 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
 *
 *
 *
 * 示例 1：
 * 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * 输出：3
 * 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
 *
 *
 * 示例 2：
 * 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * 输出：0
 * 解释：所有 1 都在边界上或可以到达边界。
 *
 *
 *
 *
 * 提示：
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] 的值为 0 或 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; i++ ) {
            if (grid[i][0] == 1) { // left
                markLand(grid, i, 0);
            }
            if (grid[i][c-1] == 1) { //right
                markLand(grid, i, c-1);
            }
        }
        for (int j = 0; j < c; j++ ) {
            if (grid[0][j] == 1) { // up
                markLand(grid, 0, j);
            }
            if (grid[r-1][j] == 1) { //down
                markLand(grid, r-1, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    // duplicate
                    // ans+= markLand(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void markLand(vector<vector<int>>& grid, int i ,int j) {
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 || i >= r || j < 0 || j >=c) {
            return ;
        }
        if (grid[i][j] == 0) {
            return ;
        }
        grid[i][j] = 0;
        for (auto& di: dirs) {
            int ni = i + di[0];
            int nj = j + di[1];
            markLand(grid, ni, nj);
        }
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


