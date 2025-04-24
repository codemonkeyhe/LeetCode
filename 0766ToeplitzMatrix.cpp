/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-24
 * @tag matrix, trick
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
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 *
 * https://leetcode.cn/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (69.89%)
 * Likes:    327
 * Dislikes: 0
 * Total Accepted:    77.2K
 * Total Submissions: 110.5K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * 给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。
 *
 * 如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。
 *
 *
 *
 * 示例 1：
 * 输入：matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * 输出：true
 * 解释：
 * 在上述矩阵中, 其对角线为:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
 * 各条对角线上的所有元素均相同, 因此答案是 True 。
 *
 *
 * 示例 2：
 * 输入：matrix = [[1,2],[2,2]]
 * 输出：false
 * 解释：
 * 对角线 "[1, 2]" 上的元素不同。
 *
 *
 *
 * 提示：
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 20
 * 0 <= matrix[i][j] <= 99
 *
 *
 *
 *
 * 进阶：
 * 如果矩阵存储在磁盘上，并且内存有限，以至于一次最多只能将矩阵的一行加载到内存中，该怎么办？
 * 如果矩阵太大，以至于一次只能将不完整的一行加载到内存中，该怎么办？
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        // left down
        for (int k = 0; k < r; k++) {
            for (int i = k; i < r; i++) {
                int j = i - k;
                if ((i + 1 < r) && (j + 1 < c) &&
                    (matrix[i][j] != matrix[i + 1][j + 1])) {
                    return false;
                }
            }
        }

        // right up
        for (int k = 1; k < c; k++) {
            for (int j = k; j < c; j++) {
                int i = j - k;
                if ((i + 1 < r) && (j + 1 < c) &&
                    (matrix[i][j] != matrix[i + 1][j + 1])) {
                    return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end


/*
better solution
 bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }

作者：力扣官方题解
链接：https://leetcode.cn/problems/toeplitz-matrix/solutions/613732/tuo-pu-li-ci-ju-zhen-by-leetcode-solutio-57bb/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


