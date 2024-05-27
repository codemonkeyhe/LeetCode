/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-27
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode.cn/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (44.94%)
 * Likes:    575
 * Dislikes: 0
 * Total Accepted:    274.9K
 * Total Submissions: 611.7K
 * Testcase Example:  '16'
 *
 * 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
 *
 * 完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
 *
 * 不能使用任何内置的库函数，如  sqrt 。
 *
 *
 *
 * 示例 1：
 * 输入：num = 16
 * 输出：true
 * 解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
 *
 *
 * 示例 2：
 * 输入：num = 14
 * 输出：false
 * 解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
 *
 *
 * 提示：
 * 1 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        int left = 0;
        int right = num / 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
           // int sq = mid*mid; // overflow
            long sq = (long)mid*(long)mid;
            if ( sq == num) {
                return true;
            }
            if (sq > num) {
                right = mid - 1;
            } else {
                left = mid +1;
            }
        }
        return false;
    }

     bool isPerfectSquareM2(int num) {
        if (num == 1) {
            return true;
        }
        int left = 0;
        int right = num / 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int res = num / mid;
            if ((res == mid) && (num%mid == 0)) {
                return true;
            }
            if (res < mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left * left == num) {
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


