/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-02-25
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
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 *
 * https://leetcode.cn/problems/add-digits/description/
 *
 * algorithms
 * Easy (70.53%)
 * Likes:    673
 * Dislikes: 0
 * Total Accepted:    195.8K
 * Total Submissions: 277.6K
 * Testcase Example:  '38'
 *
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
 *
 *
 *
 * 示例 1:
 * 输入: num = 38
 * 输出: 2
 * 解释: 各位相加的过程为：
 * 38 --> 3 + 8 --> 11
 * 11 --> 1 + 1 --> 2
 * 由于 2 是一位数，所以返回 2。
 *
 *
 * 示例 2:
 * 输入: num = 0
 * 输出: 0
 *
 *
 *
 * 提示：
 * 0 <= num <= 2^31 - 1
 *
 *
 * 进阶：你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？
 *
 */

// @lc code=start
class Solution {
public:
    int addDigitsV2(int num) {
        while (num > 9) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num = num / 10;
            }
            num = sum;
        }
        return num;
    }



    // 同余
    int addDigits(int num) {
        if (num == 0) return 0;
        int res = num%9;
        if (res == 0) return 9;
        return res;
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


