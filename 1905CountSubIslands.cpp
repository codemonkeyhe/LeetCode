/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-25
 * @tag  bfs,dfs,unionFind,matrix
 * @similar 200,695
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 *
 * https://leetcode.cn/problems/count-sub-islands/description/
 *
 * algorithms
 * Medium (67.08%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    36K
 * Total Submissions: 53K
 * Testcase Example:  '[[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]]\n' +
  '[[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]'
 *
 * 给你两个 m x n 的二进制矩阵 grid1 和 grid2 ，它们只包含 0 （表示水域）和 1 （表示陆地）。一个 岛屿 是由 四个方向
 * （水平或者竖直）上相邻的 1 组成的区域。任何矩阵以外的区域都视为水域。
 *
 * 如果 grid2 的一个岛屿，被 grid1 的一个岛屿 完全 包含，也就是说 grid2 中该岛屿的每一个格子都被 grid1
 * 中同一个岛屿完全包含，那么我们称 grid2 中的这个岛屿为 子岛屿 。
 *
 * 请你返回 grid2 中 子岛屿 的 数目 。
 *
 *
 *
 * 示例 1：
 * 输入：grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
 * grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
 * 输出：3
 * 解释：如上图所示，左边为 grid1 ，右边为 grid2 。
 * grid2 中标红的 1 区域是子岛屿，总共有 3 个子岛屿。
 *
 *
 * 示例 2：
 * 输入：grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]],
 * grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
 * 输出：2
 * 解释：如上图所示，左边为 grid1 ，右边为 grid2 。
 * grid2 中标红的 1 区域是子岛屿，总共有 2 个子岛屿。
 *
 *
 *
 *
 * 提示：
 * m == grid1.length == grid2.length
 * n == grid1[i].length == grid2[i].length
 * 1 <= m, n <= 500
 * grid1[i][j] 和 grid2[i][j] 都要么是 0 要么是 1 。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int countSubIslandsStupid(vector<vector<int> >& grid1, vector<vector<int> >& grid2) {
        int r = grid2.size();
        int c = grid2[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid2[i][j] == 1) {
                    if (grid1[i][j] == 1) {
                        if (subIslands(grid1, grid2, i, j)) {
                           // cout << "i=" << i << " j=" << j << " isIs" << endl;
                            ans ++;
                        }
                    } else { // not subIsland, set island to 0
                        setIsland(grid2, i, j);
                    }
                }
            }
        }
        return ans;
    }


    int subIslands(vector<vector<int> >& grid1, vector<vector<int> >& grid2, int i, int j) {
        int r = grid1.size();
        int c = grid1[0].size();

        if (grid2[i][j] == 1 && grid1[i][j] == 0) {
            // means not subisland
            return 0;
        }

        grid2[i][j] = 0;

        int isSub = 1;
        for (auto& di : dirs) {
            int ni = i + di[0];
            int nj = j + di[1];
            if (ni < 0 || ni >= r || nj < 0 || nj >= c) {
                continue;
            }
            if (grid2[ni][nj] == 0) {
                continue;
            }
            int res = subIslands(grid1, grid2, ni, nj);
            if (res == 0) {
                //ErrorCase : return res;
                isSub = 0;
            }
        }
        return isSub;
    }

    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void setIsland(vector<vector<int> >& grid, int i, int j) {
        int r = grid.size();
        int c = grid[0].size();
        grid[i][j] = 0;

        for (auto& di: dirs) {
            int ni = i + di[0];
            int nj = j + di[1];
            if (ni < 0 || ni >= r || nj < 0 || nj >= c) {
                continue;
            }
            if (grid[ni][nj] == 0) {
                continue;
            }
            setIsland(grid, ni, nj);
        }
    }

    int countSubIslandsM1(vector<vector<int> >& grid1, vector<vector<int> >& grid2) {
        int r = grid2.size();
        int c = grid2[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid2[i][j] == 1) {
                    if (grid1[i][j] == 1) {
                        if (subIslands(grid1, grid2, i, j)) {
                           // cout << "i=" << i << " j=" << j << " isIs" << endl;
                            ans ++;
                        }
                    }
                }
            }
        }
        return ans;
    }


    int countSubIslands(vector<vector<int> >& grid1, vector<vector<int> >& grid2) {
        int r = grid2.size();
        int c = grid2[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid2[i][j] == 1) {
                    if (grid1[i][j] == 0) {
                        setIsland(grid2, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid2[i][j] == 1) {
                    setIsland(grid2, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }


};
// @lc code=end

/*
Wrong Answer
12/57 cases passed (N/A)
Testcase
[[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]]
' +
  '[[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Answer
3
Expected Answer
2

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


