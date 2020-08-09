/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-09
 * @tag backtracking;
 */

/*
The n-queens puzzle is the problem of placing n queens on an  n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class SolutionM2V1 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n == 0)
            return res;
        vector<int> board(n, 0);
        string rowStr(n,'.');
        vector<string> path(n, rowStr);
        m2v1(n, board, 0, path, res);
        return res;
    }

    // check if valid to put Quuen at board[row][col]
    bool isValid(int n,  vector<int> board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            //??????
            int j = board[i];
            if (j == col) {
                return false;
            }
            //?????
            int disC = col - j;
            int disR = row - i;
            if (disC == disR || disC == -disR)  {
                return false;
            }
        }
        return true;
    }

/*
?????board??path??board??? m2v2
Runtime: 40 ms, faster than 24.96% of C++ online submissions for N-Queens.
Memory Usage: 15.3 MB, less than 17.30% of C++ online submissions for N-Queens.
*/
    void m2v1(int n,  vector<int> board, int row, vector<string> &path, vector<vector<string>> &res) {
        if (row == n) {
            res.push_back(path);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!isValid(n, board, row, j)) {
                continue;
            }
            board[row] = j;
            path[row][j] = 'Q';
            m2v1(n, board, row+1, path, res);
            path[row][j] = '.';
            board[row] = 0;
        }
    }

};

//M2V2
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n == 0)
            return res;
        string rowStr(n,'.');
        vector<string> board(n, rowStr);
        m2v2(n, board, 0,  res);
        return res;
    }

    // check if valid to put Quuen at board[row][col]
    bool isValid(int n,  vector<string> &board, int row, int col) {
        //??????
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        //????45°???
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }
        //????135°???
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

/*
Runtime: 4 ms, faster than 99.52% of C++ online submissions for N-Queens.
Memory Usage: 7.4 MB, less than 79.18% of C++ online submissions for N-Queens.
*/
    void m2v2(int n,  vector<string> &board, int row, vector<vector<string>> &res) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!isValid(n, board, row, j)) {
                continue;
            }
            board[row][j] = 'Q';
            m2v2(n, board, row+1, res);
            board[row][j] = '.';
        }
    }

};



int main() {

    Solution s;
    auto res = s.solveNQueens(4);
    print2DVector(res);

    return 0;
}


/*
Tips
int a[N]??N????????
a[k]???k??????a[k]?

ErrorCase: format-error
Input: 4
Output
[[".","Q",".",".",".",".",".","Q","Q",".",".",".",".",".","Q","."],
[".",".","Q",".","Q",".",".",".",".",".",".","Q",".","Q",".","."]]

Expected
[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

?????????????
. Q . . . . . Q Q . . . . . Q .
. . Q . Q . . . . . . Q . Q . .


M1 ????
???? 0123..k
??????????????????????????????????????O(N^2)
T=O(N!*N^2)
???????dd

M2 ??-??????
T=O(N! * N)
???isValid??O(3*N)??????????????????????isValid??O(1)????? O(N!)
???M3????M2????

M3 bitmask
????????????????
https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.
Use flag vectors as bitmask, 4ms:

The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is also 2 * n - 1. When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal No. is n - 1 + col - row. We can use three arrays to indicate if the column or the diagonal had a queen before, if not, we can put a queen in this position and continue.

NOTE: Please don't use vector<bool> flag to replace vector<int> flag in the following C++ code. In fact, vector<bool> is not a STL container. You should avoid to use it. You can also get the knowledge from here and here.
[?? 3????45?????5?,?2*n-1????????????0,1,2,3,4?
???k?45??????????(i,j)???????flag_45[k]=1???????k==i+j
]
   | | |                / / /             \ \ \
   O O O               O O O               O O O
   | | |              / / / /             \ \ \ \
   O O O               O O O               O O O
   | | |              / / / /             \ \ \ \
   O O O               O O O               O O O
   | | |              / / /                 \ \ \
  3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)

class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
};

*/
