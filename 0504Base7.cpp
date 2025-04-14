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
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode.cn/problems/base-7/description/
 *
 * algorithms
 * Easy (51.85%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    103K
 * Total Submissions: 198K
 * Testcase Example:  '100'
 *
 * 给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
 *
 *
 *
 * 示例 1:
 * 输入: num = 100
 * 输出: "202"
 *
 *
 * 示例 2:
 * 输入: num = -7
 * 输出: "-10"
 *
 *
 * 提示：
 * -10^7 <= num <= 10^7
 *
 *
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        string res = "";
        string signo = "";
        if (num < 0) {
            signo = '-';
            num = -num;
        }
        while (num>0) {
            int low = num % 7;
            res += char(low + '0');
            num = num / 7;
        }
        reverse(res.begin(), res.end());
        res = signo + res;
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


