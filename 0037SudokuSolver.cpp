/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-31
 * @tag  dfs,backtracking
 * @similar  36, 37, 980
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode.cn/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (67.78%)
 * Likes:    1938
 * Dislikes: 0
 * Total Accepted:    293.4K
 * Total Submissions: 433.3K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 数独的解法需 遵循如下规则：
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 *
 * 输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * 解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
 *
 *
 *
 * 提示：
 * board.length == 9
 * board[i].length == 9
 * board[i][j] 是一位数字或者 '.'
 * 题目数据 保证 输入数独仅有一个解
 *
 *
 *
 *
 *
 */

// @lc code=start
class SolutionTLE {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector< set<char> >  row(9, set<char>());
        vector< set<char> >  col(9, set<char>());
        vector< set<char> >  mini(9, set<char>());
        int dotCnt = 0;
        for (int i = 0; i < 9; i++) { // row
            for (int j = 0; j < 9; j++) { //col
                char& cur = board[i][j];
                if (cur == '.') {
                    dotCnt++;
                    continue;
                }
                row[i].insert(cur);
                col[j].insert(cur);
                int k = 3*(i/3)+j/3;
                mini[k].insert(cur);
            }
        }

        int findCnt = 0;
        for (int cnt = 0; cnt < 81; cnt++) {
            for (int i = 0; i < 9; i++) {     // row
                for (int j = 0; j < 9; j++) { // col
                    char &cur = board[i][j];
                    if (cur != '.') {
                        continue;
                    }
                    auto nums = getNums(board, i, j, row, col, mini);
                    if (nums.size() == 1) {
                        char& num = nums[0];
                        board[i][j] = num;
                        row[i].insert(num);
                        col[j].insert(num);
                        int k = 3 * (i / 3) + j / 3;
                        mini[k].insert(num);
                        findCnt++;
                       //cout << "i=" << i << " j-" << j << " nums=" << nums[0] << endl;
                    }
                }
            }
        }

        cout << "dotCnt=" << dotCnt << " findCnt=" << findCnt << endl;

        dfs(board, row, col, mini, dotCnt-findCnt);
    }

    bool dfs(vector<vector<char>> &board, vector<set<char>> &row,
             vector<set<char>> &col, vector<set<char>> &mini, int dotCnt) {
        cout << "dotcnt=" << dotCnt << endl;
        if (dotCnt == 0) {
            // find answer
            return true;
        }

        for (int i = 0; i < 9; i++) {     // row
            for (int j = 0; j < 9; j++) { // col
                char &cur = board[i][j];
                if (cur != '.') {
                    continue;
                }
                int k = 3 * (i / 3) + j / 3;
                auto nums = getNums(board, i, j, row, col, mini);
                for (auto &num : nums) {
                    cur = num;
                    row[i].insert(num);
                    col[j].insert(num);
                    mini[k].insert(num);
                    bool find = dfs(board, row, col, mini, dotCnt - 1);
                    if (find) {
                        return true;
                    }
                    cur = '.';
                    row[i].erase(num);
                    col[j].erase(num);
                    mini[k].erase(num);
                }
            }
        }
        return false;
    }

    const vector<char> numList = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    vector<char> getNums(vector<vector<char>> &board, int i, int j,
                         vector<set<char>>& row, vector<set<char>>& col,
                         vector<set<char>>& mini) {
        vector<char> res;
        int k = 3 * (i / 3) + j / 3;
        for (auto &ch : numList) {
            if (row[i].count(ch) != 0) {
                continue;
            }
            if (col[j].count(ch) != 0) {
                continue;
            }
            if (mini[k].count(ch) != 0) {
                continue;
            }
            res.push_back(ch);
        }
        return res;
    }
};

/*
7/7 cases passed (2679 ms)
Your runtime beats 5.01 % of cpp submissions
Your memory usage beats 5.01 % of cpp submissions (466.4 MB)
*/
class Solution {
    public:
    //1 参数从函数参数变成类成员变量，作用不大
    // 2 把char全部改为int, 作用不大
    // 3 把   vector< set<int> >  row 改成   vector< vector<int> >  row;
    // 耗时缩短到746ms，依然是  runtime beats 5.55 %
    vector< vector<int> >  row;
    vector<vector<int>> col;
    vector<vector<int>> mini;

    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<int>>(9, vector<int>(10, 0));
        col = vector<vector<int>>(9, vector<int>(10, 0));
        mini = vector<vector<int>>(9, vector<int>(10, 0));
        int dotCnt = 0;
        for (int i = 0; i < 9; i++) { // row
            for (int j = 0; j < 9; j++) { //col
                char& cur = board[i][j];
                if (cur == '.') {
                    dotCnt++;
                    continue;
                }
                int icur = cur-'0';
                row[i][icur] = 1;
                col[j][icur] = 1;
                int k = 3*(i/3)+j/3;
                mini[k][icur] = 1;
            }
        }

        /* 作用不大
        int findCnt = 0;
        for (int cnt = 0; cnt < dotCnt; cnt++) {
            for (int i = 0; i < 9; i++) {     // row
                for (int j = 0; j < 9; j++) { // col
                    char &cur = board[i][j];
                    if (cur != '.') {
                        continue;
                    }
                    auto nums = getNums(i, j);
                    if (nums.size() == 1) {
                        int num = nums[0];
                        board[i][j] = num+'0';
                        row[i][num] = 1;
                        col[j][num] = 1;
                        int k = 3 * (i / 3) + j / 3;
                        mini[k][num] = 1;
                        findCnt++;
                       //cout << "i=" << i << " j-" << j << " nums=" << nums[0] << endl;
                    }
                }
            }
        }
        */

        vector<pair<int, int> > dotList;
        for (int i = 0; i < 9; i++) { // row
            for (int j = 0; j < 9; j++) { //col
                char& cur = board[i][j];
                if (cur == '.') {
                    dotList.push_back(make_pair(i, j));
                }
            }
        }

        //cout << "olddotCnt=" << dotCnt << " findCnt=" << findCnt << " dotListSize=" << dotList.size() << endl;

        dfs(board,  0, dotList);
    }

    bool dfs(vector<vector<char>> &board, int idx, vector<pair<int, int>> &dotList) {
        if (idx == dotList.size()) {
            // find answer
            return true;
        }

        auto curDot = dotList[idx];
        int i = curDot.first;
        int j = curDot.second;

        char &cur = board[i][j];

        int k = 3 * (i / 3) + j / 3;
        auto nums = getNums(i, j);
        for (auto &num : nums) {
            cur = num+'0';
            row[i][num] = 1;
            col[j][num] = 1;
            mini[k][num] = 1;

            bool find = dfs(board, idx + 1, dotList);
            if (find) {
                return true;
            }
            //cur = '.'; // useless, no need to recover
            row[i][num] = 0;
            col[j][num] = 0;
            mini[k][num] = 0;
        }
        return false;
    }


    vector<int> getNums(int i, int j) {
        vector<int> res;
        int k = 3 * (i / 3) + j / 3;
        for (int ch = 1; ch <= 9; ch++) {
            if (row[i][ch] == 0 && (col[j][ch] == 0) && (mini[k][ch] == 0)) {
                res.push_back(ch);
            }
        }
        return res;
    }
};
// @lc code=end


/*
Time Limit Exceeded
1/7 cases passed (N/A)
Testcase
[[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]
Expected Answer
[["5","1","9","7","4","8","6","3","2"],["7","8","3","6","5","2","4","1","9"],["4","2","6","1","3","9","8","7","5"],["3","5","7","9","8","6","2","4","1"],["2","6","4","3","1","7","5","9","8"],["1","9","8","5","2","4","3","6","7"],["9","7","5","8","6","3","1","2","4"],["8","3","2","4","9","1","7","5","6"],["6","4","1","2","7","5","9","8","3"]]
Stdout
dotCnt=54 findCnt=20



*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
