/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-18
 * @tag    greedy,math
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
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 *
 * https://leetcode.cn/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (50.84%)
 * Likes:    519
 * Dislikes: 0
 * Total Accepted:    155.1K
 * Total Submissions: 300.1K
 * Testcase Example:  '10'
 *
 * 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
 *
 * 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
 *
 *
 *
 * 示例 1:
 * 输入: n = 10
 * 输出: 9
 *
 *
 * 示例 2:
 * 输入: n = 1234
 * 输出: 1234
 *
 *
 * 示例 3:
 * 输入: n = 332
 * 输出: 299
 *
 *
 *
 *
 * 提示:
 * 0 <= n <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int len = num.size();
        int pp = -1;
        for (int i = 0; i < len - 1; i++) {
            if (num[i] > num[i+1]) {
                pp = i;
                break;
            }
        }
        if (pp == -1) {
            return n;
        }

        int lowerValue = num[pp] - 1;
        int j = 0;
        for (; j <= pp; j++) {
            if (num[j] > lowerValue) {
                num[j] = lowerValue;
                j++;
                break;
            }
        }
        while(j < len) {
            num[j] = '9';
            j++;
        }
        int res = stoi(num);
        return res;
    }
};
// @lc code=end

/*
 * 输入: n = 332
 * 输出: 299

 3 32   PP=3
 2 99

 54321  PP=5
 49999

 44321  PP=4
 39999

 56721  PP=7
ERROR 49999
WANT  56699


 56621  PP=6
 55999

 35988  PP=9
 35899

 35955
 35899


 PeakPoint 相当于单调性中断的点
  错误的思路
 lowerPoint=PP+1
 from 0-PP, find the first > lowerPoint,  -1, then tail to 999...

正确的
 lowerValue=PP-1
 尝试降低1位，同时保持全局有序
 from 0-PP, find the first > lowerValue,   set first=lowerValue, then tail to 999...

 startPoint= theFirst


解答错误
253 / 308 个通过的测试用例

官方题解
输入
n =
120

添加到测试用例
输出
99
预期结果
119


120
PP=2
LowPoint=0
first>LP = 1

099

123450
123449


123430
123399


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
