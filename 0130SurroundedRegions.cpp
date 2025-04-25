/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-25
 * @tag bfs,dfs,matrix,unionFind
 * @similar 200
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode.cn/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (46.47%)
 * Likes:    1207
 * Dislikes: 0
 * Total Accepted:    328.4K
 * Total Submissions: 697.9K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
 *
 *
 * 连接：一个单元格与水平或垂直方向上相邻的单元格连接。
 * 区域：连接所有 'O' 的单元格来形成一个区域。
 * 围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，则该区域被 'X' 单元格围绕。
 *
 *
 * 通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 *
 * 解释：
 * 在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。
 *
 *
 * 示例 2：
 * 输入：board = [["X"]]
 * 输出：[["X"]]
 *
 *
 * 提示：
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] 为 'X' 或 'O'
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                if (i == 0 || (i == r-1) || (j == 0) || (j == c-1)) { // O on the edge
                    markBoard(board, i, j);
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void markBoard(vector<vector<char>>& board, int i, int j) {
        int r = board.size();
        int c = board[0].size();
        if (i < 0 || i >= r || j < 0 || j >= c) {
            return;
        }
        if (board[i][j] == 'X' || board[i][j] == 'S') {
            // equal  board[i][j] != 'O'
            return;
        }

        board[i][j] = 'S';

        for (auto& di: dirs) {
            int ni = i + di[0];
            int nj = j + di[1];
            markBoard(board, ni, nj);
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


