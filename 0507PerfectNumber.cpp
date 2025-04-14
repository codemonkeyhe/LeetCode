/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-14
 * @tag math
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
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 *
 * https://leetcode.cn/problems/perfect-number/description/
 *
 * algorithms
 * Easy (49.19%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    94.8K
 * Total Submissions: 191.9K
 * Testcase Example:  '28'
 *
 * 对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。
 *
 * 给定一个 整数 n， 如果是完美数，返回 true；否则返回 false。
 *
 *
 *
 * 示例 1：
 * 输入：num = 28
 * 输出：true
 * 解释：28 = 1 + 2 + 4 + 7 + 14
 * 1, 2, 4, 7, 和 14 是 28 的所有正因子。
 *
 * 示例 2：
 * 输入：num = 7
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num <= 10^8
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // better max = sqrt(num)
        //  因子成对出现
        int max = num / 2;
        int sum = 0;
        for (int i = 1; i <= max; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        if (sum == num) {
            return true;
        }
        return false;
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


