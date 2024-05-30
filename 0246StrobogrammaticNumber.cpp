/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-30
 * @tag string;
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=246 lang=cpp
 *
 * [246] 中心对称数
 *
 * https://leetcode.cn/problems/strobogrammatic-number/description/
 *
 * algorithms
 * Easy (47.63%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    12.3K
 * Total Submissions: 25.8K
 * Testcase Example:  '"69"'
 *
 * 中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
 *
 * 请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。
 *
 *
 *
 * 示例 1:
 * 输入: num = "69"
 * 输出: true
 *
 *
 * 示例 2:
 * 输入: num = "88"
 * 输出: true
 *
 * 示例 3:
 * 输入: num = "962"
 * 输出: false
 *
 * 示例 4：
 * 输入：num = "1"
 * 输出：true
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.size();
        for (int i = 0; i <= len/2; i++) {
            char& c = num[i];
            if ((c >= '2' && c <= '5') || (c == '7')) {
                return false;
            }
            int j = len -i-1;
            if (c == '6')  {
                if (num[j] != '9') {
                    return false;
                }
                continue;
            }
            if (c == '9')  {
                if (num[j] != '6') {
                    return false;
                }
                continue;
            }
            // 0 1 8
            if (num[i] != num[j]) {
                return false;;
            }
        }
        return true;
    }
};
// @lc code=end


/*
0  T  0
1  T  1
2  F
3  F
4  F
5  F
6  T  9
7  F
8  T  8
9  T  6
*/


int main() {
    Solution s;
}


/*
Tips
M1 首尾对应
优化点
i < len 改为 i <= len/2;

M2

*/


