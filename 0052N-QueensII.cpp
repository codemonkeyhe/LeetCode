/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-09
 * @tag
 */

/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if (n == 0)
            return 0;
        vector<int> board(n, 0);
        vector<int> col(n,0);
        vector<int> line45(2*n-1,0);
        vector<int> line135(2*n-1,0);
        return m3(n, board, 0, col, line45, line135);
    }


/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-Queens II.
Memory Usage: 6.3 MB, less than 33.44% of C++ online submissions for N-Queens II.
*/
    int m3(int n, vector<int>& board, int r, vector<int>& col, vector<int>& line45, vector<int>& line135) {
        if(r == n) {
            return 1;
        }
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (col[j] || line45[r+j] || line135[n-1+j-r]) {
                continue;
            }
            board[r] = j;
            col[j] = line45[r+j] = line135[n-1+j-r] = 1;
            res += m3(n, board, r + 1, col, line45, line135);
            col[j] = line45[r+j] = line135[n-1+j-r] = 0;
            board[r] = 0;
        }
        return res;
    }
};


int totalNQueens(int n){

}





int main() {
    Solution s;
    cout << s.totalNQueens(4) << endl;
}

/*
Tips
M3 同0051
启用空间换时间


*/