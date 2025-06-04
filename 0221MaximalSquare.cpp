/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-03
 * @tag dynamicProgramming, matrix
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
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode.cn/problems/maximal-square/description/
 *
 * algorithms
 * Medium (50.34%)
 * Likes:    1786
 * Dislikes: 0
 * Total Accepted:    387.9K
 * Total Submissions: 755.5K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 *
 *
 *
 * 示例 1：
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 *
 *
 * 示例 2：
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 *
 *
 * 示例 3：
 * 输入：matrix = [["0"]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] 为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maximalSquareV1(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp (row, vector<int>(col, 0));

        int maxW = 0;
        for(int i = 0; i < row; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                maxW = 1;
            }
        }

        for(int j = 0; j < col; j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                maxW = 1;
            }
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                //cout << "i=" << i << " j=" << j << " dp=" << dp[i][j] << endl;
                if (dp[i][j] > maxW) {
                    maxW = dp[i][j];
                }
            }
        }
        //cout << "w=" <<  maxW << endl;
        return maxW * maxW;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp (row, vector<int>(col, 0));

        int maxW = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                // from here, matrix[i][j] == '1'
                if (i == 0 || j == 0) { // begin value
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                if (dp[i][j] > maxW) {
                    maxW = dp[i][j];
                }
            }
        }
        //cout << "w=" <<  maxW << endl;
        return maxW * maxW;
    }
};
// @lc code=end


/*
dp[i][j] 表示以 matrix[i][j]为右下角的最大正方形的面积
分析如下：
exp1
1 1 1 1
1 4 4 4
1 4 9 9
1 4 9 16

exp2
16 16
16 25

正方形的面积=边长^2
因此，只能是 1 4 9 16 25

易得

最近3元素的最小边长
near3Width = min( dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) 的开方

dp[i][j] = (near3Width  + 1) ^ 2

这样太麻烦了，
重新修改dp的定义

dp[i][j] 表示以 matrix[i][j]为右下角的最大正方形的边长，最后答案就是 最大边长的平方

此时有

dp[i][j] = min( dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1, if maxtrix[i][j] = 1

在遍历dp[i][j]时保存最大边长



Wrong Answer
64/80 cases passed (N/A)
Testcase
[["0","1"],["1","0"]]
Answer
0
Expected Answer
1
*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


