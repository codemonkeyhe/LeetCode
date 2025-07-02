/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-02
 * @tag BFS
 * @similar 419, 2101
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode.cn/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (52.19%)
 * Likes:    1013
 * Dislikes: 0
 * Total Accepted:    288.8K
 * Total Submissions: 533.7K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 *
 *
 * 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 * 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 *
 *
 *
 * 示例 1：
 * 输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 *
 *
 * 示例 2：
 * 输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
 *
 *
 * 示例 3：
 * 输入：grid = [[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 *
 *
 * 提示：
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] 仅为 0、1 或 2
 *
 *
 */

// @lc code=start
class Solution {
public:
    const vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int cntGood = 0;
        int cntBad = 0;
        queue<pair<int, int>> que;
        int step = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    que.push(make_pair(i,j));
                } else if (grid[i][j] == 1) {
                    cntGood++;
                }
            }
        }
        if (cntGood == 0) {
            return 0;
        }

        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                auto pa = que.front();
                que.pop();
                for (auto& di : dirs) {
                    int newi = pa.first + di.first;
                    int newj = pa.second + di.second;
                    if (newi < 0 || newi >= row || newj < 0 || newj >= col) {
                        continue;
                    }
                    if (grid[newi][newj] == 0 || grid[newi][newj] == 2) {
                        continue;
                    }
                    if (grid[newi][newj] == 1) {
                        que.push(make_pair(newi, newj));
                        grid[newi][newj] = 2;
                        cntBad++;
                    }
                }
            }
            step++;
        }
        if (cntGood != cntBad) {
            return -1;
        }
        return step-1;
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


