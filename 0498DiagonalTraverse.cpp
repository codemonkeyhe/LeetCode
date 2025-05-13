/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-12
 * @tag matrix,simulation
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
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 *
 * https://leetcode.cn/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (55.90%)
 * Likes:    513
 * Dislikes: 0
 * Total Accepted:    140.4K
 * Total Submissions: 249.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,4,7,5,3,6,8,9]
 *
 *
 * 示例 2：
 * 输入：mat = [[1,2],[3,4]]
 * 输出：[1,2,3,4]
 *
 *
 *
 *
 * 提示：
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrderUgly(vector<vector<int>>& mat) {
        vector<int> res;
        int row = mat.size();
        int col = mat[0].size();
        // left up triangle
        int dep = 1;
        for (int i = 0; i < row; i++) {
            int k = i;
            vector<int> rev;
            for (int j = 0; j < col; j++) {
                if (dep%2==0) {
                    rev.push_back(mat[k][j]);
                } else {
                    res.push_back(mat[k][j]);
                }
                k--;
                if (k<0) {
                    break;
                }
            }
            if(!rev.empty()) {
                for (auto it = rev.rbegin(); it != rev.rend(); it++) {
                    res.push_back(*it);
                }
            }
            dep++;
        }
        // right bottom triangle
        dep++;
        for (int j = 1; j < col; j++) {
            int k = j;
            vector<int> rev;
            for (int i = row-1; i >= 0; i--) {
                if (dep % 2 == 1) {
                    rev.push_back(mat[i][k]);
                } else {
                    res.push_back(mat[i][k]);
                }
                k++;
                if (k >= col) {
                    break;
                }
            }
            if (!rev.empty()) {
                for (auto it = rev.rbegin(); it != rev.rend(); it++) {
                    res.push_back(*it);
                }
            }
            dep++;
        }
        return res;
    }


    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int row = mat.size();
        int col = mat[0].size();
        int dep = 1;
        int line = row + col - 1;
        for (int i = 0; i < line; i++) {
            if (i % 2) {  // rightup to leftdown  下 row++, col--
                int n = min(i, col - 1);
                int m = i - n;
                while (n >= 0 && (m < row)) {
                    res.push_back(mat[m][n]);
                    m++;
                    n--;
                }
            } else {  // leftdown to rightup  上  row--, col++
                int m = min(i, row - 1);
                int n = i - m;
                while (m >= 0 && (n < col)) {
                    res.push_back(mat[m][n]);
                    m--;
                    n++;
                }
            }
        }
        return res;
    }


};
// @lc code=end

/*
输入：mat =
[
    [1,2,3],
    [4,5,6],
    [7,8,9]]

输出：[1,2,4,7,5,3,6,8,9]

row=m  i = 0-2
col=n  j = 0-2


// left up triangle
1       00
4 2     10 01
7 5 3   20 11 02


// left up triangle and reverse
1       00
2 4     01 10
7 5 3   20 11 02


i = 0-2

// right bottom triangle
8 6    21  12
9      22


Wrong Answer
22/32 cases passed (N/A)
Testcase
[[2,3]]
Answer
[2]
Expected Answer
[2,3]


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


