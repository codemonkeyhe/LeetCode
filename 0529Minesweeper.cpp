/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-15
 * @tag      dfs,bfs
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
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 *
 * https://leetcode.cn/problems/minesweeper/description/
 *
 * algorithms
 * Medium (63.83%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    63.3K
 * Total Submissions: 98.2K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n' +
  '[3,0]'
 *
 * 让我们一起来玩扫雷游戏！
 *
 * 给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：
 *
 *
 * 'M' 代表一个 未挖出的 地雷，
 * 'E' 代表一个 未挖出的 空方块，
 * 'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
 * 数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
 * 'X' 则表示一个 已挖出的 地雷。
 *
 *
 * 给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的 方块（'M' 或者
 * 'E'）中的下一个点击位置（clickr 是行下标，clickc 是列下标）。
 *
 * 根据以下规则，返回相应位置被点击后对应的盘面：
 * 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
 * 如果一个 没有相邻地雷 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出 方块都应该被递归地揭露。
 * 如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
 * 如果在此次点击中，若无更多方块可被揭露，则返回盘面。
 *
 *
 *
 *
 * 示例 1：
 * 输入：board =
 * [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]],
 * click = [3,0]
 *
 * 输出：[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
 *
 *
 * 示例 2：
 * 输入：board =
 * [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]],
 * click = [1,2]
 *
 * 输出：[["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
 *
 *
 *
 *
 * 提示：
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 50
 * board[i][j] 为 'M'、'E'、'B' 或数字 '1' 到 '8' 中的一个
 * click.length == 2
 * 0 <= clickr < m
 * 0 <= clickc < n
 * board[clickr][clickc] 为 'M' 或 'E'
 *
 *
 */

// @lc code=start
class Solution {
public:
    // dfs
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int cx =  click[0];
        int cy =  click[1];
        //dfs(board, cx, cy);
        bfs(board, cx, cy);
        return board;
    }

    const vector<pair<int, int>> dirs = {{-1, 0},  {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

    void dfs(vector<vector<char>>& board, int cx, int cy) {
        int row = board.size();
        int col = board[0].size();
        if (board[cx][cy] == 'M') {
            board[cx][cy] = 'X';
            return ;
        }

        int cntM = 0;
        vector<pair<int, int>> todo;
        for (auto& dir : dirs) {
            int nx = cx + dir.first;
            int ny = cy + dir.second;
            if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
                continue;
            }
            if (board[nx][ny] == 'M') {
                cntM++;
            } else if (board[nx][ny] == 'E'){
                todo.push_back(make_pair(nx, ny));
            }
        }
        if (cntM > 0) {
            board[cx][cy] = char(cntM + '0');
        } else {
            board[cx][cy] = 'B';
            for (auto &xy : todo) {
                dfs(board, xy.first, xy.second);
            }
        }
    }

    void bfs(vector<vector<char>> &board, int x, int y) {
        int row = board.size();
        int col = board[0].size();
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        unordered_set<int> walked;
        int key = x * 100 + y;
        walked.insert(key);
        queue<pair<int, int>> que;
        que.push(make_pair(x, y));
        while(!que.empty()) {
            auto& cur = que.front();
            int cx = cur.first;
            int cy = cur.second;
            que.pop();
            int cntM = 0;
            vector<pair<int, int>> todo;
            for (auto &dir : dirs) {
                int nx = cx + dir.first;
                int ny = cy + dir.second;
                if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
                    continue;
                }
                if (board[nx][ny] == 'M') {
                    cntM++;
                } else if (board[nx][ny] == 'E') {
                    todo.push_back(make_pair(nx, ny));
                }
            }
            if (cntM > 0) {
                board[cx][cy] = char(cntM + '0');
            } else {
                board[cx][cy] = 'B';
                for (auto& xy : todo) {
                    int key1 = xy.first*100 + xy.second;
                    if (walked.count(key1) == 0) {
                        que.push(xy);
                        walked.insert(key1);
                    }
                }
            }
        }
    }
};
// @lc code=end


/*
0 1 2
'0' '1' '2'

*/


/* golang
DFS



var dirs [][2]int = [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}}


 func dfs(board [][]byte, x int, y int) {
    row := len(board)
    col := len(board[0])
    if board[x][y] == 'M' {
        board[x][y] = 'X'
        return
    }
    cntM := 0
    todo := make([][2]int,0, 8)
    for _, dir := range dirs {
        nx := x + dir[0]
        ny := y + dir[1]
        if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
            continue;
        }
        if board[nx][ny] == 'M' {
            cntM++;
        } else if board[nx][ny] == 'E' {
            todo = append(todo, [2]int{nx, ny})
        }
    }

    if cntM > 0 {
        board[x][y] = byte(cntM+'0')
    } else {
        board[x][y] = 'B'
        for _, xy := range todo {
            dfs(board, xy[0], xy[1])
        }
    }
 }


func updateBoard(board [][]byte, click []int) [][]byte {
    x := click[0]
    y := click[1]
    dfs(board, x, y)
    return board
}


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
