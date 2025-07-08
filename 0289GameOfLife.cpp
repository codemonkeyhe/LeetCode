/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-08
 * @tag   simulation,matrix
 * @similar
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 *
 * https://leetcode.cn/problems/game-of-life/description/
 *
 * algorithms
 * Medium (76.13%)
 * Likes:    608
 * Dislikes: 0
 * Total Accepted:    111K
 * Total Submissions: 145.7K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * 根据 百度百科 ， 生命游戏 ，简称为 生命 ，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
 * 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为
 * 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
 *
 *
 * 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
 * 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
 * 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
 * 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
 *
 *
 * 下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board
 * 的当前状态，返回下一个状态。
 *
 *
 *
 * 示例 1：
 * 输入：board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
 * 输出：[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
 *
 *
 * 示例 2：
 * 输入：board = [[1,1],[1,0]]
 * 输出：[[1,1],[1,1]]
 *
 *
 *
 *
 * 提示：
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 25
 * board[i][j] 为 0 或 1
 *
 *
 *
 *
 * 进阶：
 * 你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
 * 本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
 *
 *
 */

// @lc code=start
class Solution {
public:
    const vector<pair<int, int> > dires = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
    int row;
    int col;

    int getAround(vector<vector<int>>& oldbd, int i, int j) {
        int cnt = 0;
        for (auto& dir: dires) {
            int ni =  i + dir.first;
            int nj =  j + dir.second;
            if (ni < 0 || ni >= row || nj < 0 || nj >= col) {
                continue;
            }
            if (oldbd[ni][nj] == 1 || oldbd[ni][nj] == 2) { // 为了V2做调整, V2引入了状态2和3
                cnt++;
            }
        }
        return cnt;
    }


    void gameOfLifeV1(vector<vector<int>>& board) {
        row = board.size();
        col = board[0].size();
        vector<vector<int> > oldbd(board.begin(), board.end());
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int& cell = oldbd[i][j];
                int liveCnt = getAround(oldbd, i, j);
                //cout << "i=" << i << " j=" << j << " livecnt=" << liveCnt << endl;
                if (cell) { // alive
                    if (liveCnt < 2 || liveCnt > 3) { //aliveToDead
                        board[i][j] = 0;
                    }
                } else { //dead
                    if (liveCnt == 3) { //deadToAlive
                        board[i][j] = 1;
                    }
                }
            }
        }
        return;
    }


    //M2
    //status: 2  aliveToDead
    //status: 3  deadToAlive
    void gameOfLife(vector<vector<int>>& board) {
        row = board.size();
        col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int& cell = board[i][j];
                int liveCnt = getAround(board, i, j);
                if (cell == 1) { // alive
                    if (liveCnt < 2 || liveCnt > 3) { //aliveToDead
                        board[i][j] = 2;
                    }
                } else if (cell == 0) { //dead
                    if (liveCnt == 3) { //deadToAlive
                        board[i][j] = 3;
                    }
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int& cell = board[i][j];
                if (cell == 2)  {
                    cell = 0;
                } else if (cell == 3) {
                    cell = 1;
                }
            }
        }
        return;
    }
};
// @lc code=end

/*
Wrong Answer
7/23 cases passed (N/A)
Testcase
[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Answer
[[0,1,0],[1,0,1],[1,1,1],[0,1,0]]
Expected Answer
[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


