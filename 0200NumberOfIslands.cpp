/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-25
 * @tag dfs,bfs,matrix,unionFind
 * @similar 1905,695
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (60.35%)
 * Likes:    2470
 * Dislikes: 0
 * Total Accepted:    819.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 *
 *
 * 示例 1：
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 *
 *
 * 示例 2：
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] 的值为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < r ; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    setIsland(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void setIsland(vector<vector<char>>& grid, int i , int j) {
        int r = grid.size();
        int c = grid[0].size();
        if (grid[i][j] == '2') { //visited
            return;
        }
        grid[i][j] = '2';

        for (auto& di: dirs) {
            int ni = i + di[0];
            int nj = j + di[1];
            if (ni < 0 || ni >= r || nj < 0 || nj >= c) {
                continue;
            }
            if (grid[ni][nj] == '0') {
                continue;
            }
            setIsland(grid, ni, nj);
        }
    }

    void setIslandV2(vector<vector<char>>& grid, int i, int j) {
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 || i >= r || j < 0 || j >= c) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }

        if (grid[i][j] == '2') { //visited
            return;
        }
        grid[i][j] = '2';


        for (auto& di: dirs) {
            int ni = i + di[0];
            int nj = j + di[1];
            setIsland(grid, ni, nj);
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


