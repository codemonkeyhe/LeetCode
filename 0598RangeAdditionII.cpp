/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-15
 * @tag matrix, IQ
 * @similar 370
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 区间加法 II
 *
 * https://leetcode.cn/problems/range-addition-ii/description/
 *
 * algorithms
 * Easy (58.29%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    74.9K
 * Total Submissions: 122.7K
 * Testcase Example:  '3\n3\n[[2,2],[3,3]]'
 *
 * 给你一个 m x n 的矩阵 M 和一个操作数组 op 。矩阵初始化时所有的单元格都为 0 。ops[i] = [ai, bi] 意味着当所有的 0
 * <= x < ai 和 0 <= y < bi 时， M[x][y] 应该加 1。
 *
 * 在 执行完所有操作后 ，计算并返回 矩阵中最大整数的个数 。
 *
 *
 *
 * 示例 1:
 * 输入: m = 3, n = 3，ops = [[2,2],[3,3]]
 * 输出: 4
 * 解释: M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4。
 *
 *
 * 示例 2:
 * 输入: m = 3, n = 3, ops =
 * [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
 * 输出: 4
 *
 *
 * 示例 3:
 * 输入: m = 3, n = 3, ops = []
 * 输出: 9
 *
 *
 *
 *
 * 提示:
 * 1 <= m, n <= 4 * 10^4
 * 0 <= ops.length <= 10^4
 * ops[i].length == 2
 * 1 <= ai <= m
 * 1 <= bi <= n
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int r = m;
        int c = n;
        for (int i = 0; i < ops.size(); i++) {
            if (r > ops[i][0]) {
                r = ops[i][0];
            }

            if (c > ops[i][1]) {
                c = ops[i][1];
            }
        }
        return r*c;
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


