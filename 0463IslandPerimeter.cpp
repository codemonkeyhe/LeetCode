/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-24
 * @tag bfs,dfs,matrix
 * @similar 733,695
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 *
 * https://leetcode.cn/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (70.12%)
 * Likes:    745
 * Dislikes: 0
 * Total Accepted:    157K
 * Total Submissions: 223.8K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
 *
 * 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 *
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100
 * 。计算这个岛屿的周长。
 *
 *
 *
 * 示例 1：
 * 输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * 输出：16
 * 解释：它的周长是上面图片中的 16 个黄色的边
 *
 * 示例 2：
 * 输入：grid = [[1]]
 * 输出：4
 *
 *
 * 示例 3：
 * 输入：grid = [[1,0]]
 * 输出：4
 *
 *
 *
 *
 * 提示：
 * row == grid.length
 * col == grid[i].length
 * 1
 * grid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    //vector<vector<int, int> > dis;

    const int dis[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


    Solution(){
        //  [[0, 1], [0, -1], [1, 0], [-1, 0]];
       // dis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    }


    int islandPerimeter(vector<vector<int>>& grid) {
        int rou = 0;
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    getShapeLen(grid, i, j, rou);
                    return rou;
                }
            }
        }
        return rou;
    }


    void getShapeLen(vector<vector<int>>& grid, int i, int j, int& rou) {
        int r = grid.size();
        int c = grid[0].size();
        if (grid[i][j] == 2) {
            return;
        }
        // set cur is visited
        grid[i][j] = 2;

        for (auto& di : dis) {
            int ni = i + di[0];
            int nj = j + di[1];
            if (ni < 0 || ni >= r || nj < 0 || nj >= c) {
                rou += 1;
                continue;
            }
            if (grid[ni][nj] == 0) {
                rou += 1;
            } else {
                getShapeLen(grid, ni, nj, rou);
            }
        }
    }
};
// @lc code=end

/*
Wrong Answer
5015/5833 cases passed (N/A)
Testcase
[[0],[1]]
Answer
0
Expected Answer
4

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


