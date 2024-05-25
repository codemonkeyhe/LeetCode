/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-25
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
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 *
 * https://leetcode.cn/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (54.52%)
 * Likes:    512
 * Dislikes: 0
 * Total Accepted:    90.3K
 * Total Submissions: 165.6K
 * Testcase Example:  '5\n7'
 *
 * 给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right
 * 端点）。
 *
 *
 *
 * 示例 1：
 * 输入：left = 5, right = 7
 * 输出：4
 *
 *
 * 示例 2：
 * 输入：left = 0, right = 0
 * 输出：0
 *
 *
 * 示例 3：
 * 输入：left = 1, right = 2147483647
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * 0 <= left <= right <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:

    int rangeBitwiseAndM2(int left, int right) {
        int sum = left ^ right;
        int mask = 0x40000000;
        int i = 2;
        while (i <= 32) {
            if ((sum & mask) > 0) {
                break;
            }
            mask = mask >> 1;
            i++;
        }
        int diffLen = 32 - i + 1;
        int tmp = right >> diffLen;
        return tmp << diffLen;
    }


    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (left != right) {
            left = left >> 1;
            right = right >> 1;
            cnt++;
        }
        return left << cnt;
    }


};
// @lc code=end

/*
5 6  7 8

5  0101
6  0110
7  0111
8  1000
9  1001
10 1010

规律
从left到right的按位与 等于 寻找 left和right的两个数的二进制公共前缀

变成 异或操作，相同的bit为0，不同的bit为1

5 0b0000...0101
7 0b0000...0111

^ 0b0000...0010  从左往右，第1个为1的bit为差异点
寻找差异点可以用0x40000000去测试，也可以用n&(n-1)来统计1的个数，并且保存清除最后1个1时的数字，该数字为差异点

M1
把left或者right最后2个bits设置为0，需要构造如下mask，然后right&maskDiff 即可
  maskDiff=0b1111...1100

0b 0000 0000 0000 0000 0000 0000 0000 0010


M2 直接把right先右移2bit，再左移2bit

M3 left 和 right每次一起右移，直到2个数值相当，说明找到了公共前缀，再左移回来即可
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


