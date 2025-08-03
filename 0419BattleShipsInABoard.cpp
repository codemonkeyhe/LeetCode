/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-02
 * @tag  matrix
 * @similar  200
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 *
 * https://leetcode.cn/problems/battleships-in-a-board/description/
 *
 * algorithms
 * Medium (77.76%)
 * Likes:    314
 * Dislikes: 0
 * Total Accepted:    72K
 * Total Submissions: 91.6K
 * Testcase Example:  '[["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]'
 *
 * 给你一个大小为 m x n 的矩阵 board 表示棋盘，其中，每个单元格可以是一艘战舰 'X' 或者是一个空位 '.' ，返回在棋盘 board
 * 上放置的 舰队 的数量。
 *
 * 舰队 只能水平或者垂直放置在 board 上。换句话说，舰队只能按 1 x k（1 行，k 列）或 k x 1（k 行，1 列）的形状放置，其中 k
 * 可以是任意大小。两个舰队之间至少有一个水平或垂直的空格分隔 （即没有相邻的舰队）。
 *
 *
 *
 * 示例 1：
 * 输入：board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
 * 输出：2
 *
 *
 * 示例 2：
 * 输入：board = [["."]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] 是 '.' 或 'X'
 *
 *
 * 进阶：你可以实现一次扫描算法，并只使用 O(1) 额外空间，并且不修改 board 的值来解决这个问题吗？
 *
 */

// @lc code=start
class Solution {
public:
    int countBattleshipsM1(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'X') {
                    bool leftDot = false;
                    bool upDot = false;
                    if ((i == 0) || (i >= 1 && board[i - 1][j] == '.')) {
                        upDot = true;
                    }
                    if ((j == 0) || (j >= 1) && (board[i][j - 1] == '.')) {
                        leftDot = true;
                    }
                    if (leftDot && upDot) {
                        cnt++;
                        //cout << "i=" << i << " j=" << j << " cnt=" << cnt << endl;
                    }
                }

            }
        }
        return cnt;
    }

    int countBattleships(vector<vector<char>> &board) {
        int row = board.size();
        int col = board[0].size();
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'X') {
                    if (i >= 1 && board[i - 1][j] == 'X') {
                        continue;
                    }
                    if ((j >= 1) && (board[i][j - 1] == 'X')) {
                        continue;
                    }
                    cnt++;
                }

            }
        }
        return cnt;
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
