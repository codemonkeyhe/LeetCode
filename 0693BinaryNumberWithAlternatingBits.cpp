/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-22
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
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 *
 * https://leetcode.cn/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (65.26%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    83.5K
 * Total Submissions: 127.9K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
 *
 *
 *
 * 示例 1：
 * 输入：n = 5
 * 输出：true
 * 解释：5 的二进制表示是：101
 *
 *
 * 示例 2：
 * 输入：n = 7
 * 输出：false
 * 解释：7 的二进制表示是：111.
 *
 * 示例 3：
 * 输入：n = 11
 * 输出：false
 * 解释：11 的二进制表示是：1011.
 *
 *
 *
 * 提示：
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:

    // m1
    bool hasAlternatingBitsM1(int n) {
        if (n <= 2) {return true;}
        int mask = 0x00000001;
        int lowBit = n&mask;
        int exp = 1- lowBit;
        n = n >> 1;
        while(n>0) {
            lowBit = n&mask;
            if(lowBit != exp) {
                return false;
            }
            exp = 1- lowBit;
            n = n >> 1;
        }
        return true;
    }


    bool hasAlternatingBits(int n) {
        if (n <= 2) {return true;}
        unsigned int a = n^(n>>1);
        if ((a & (a+1)) == 0) {
            return true;
        }
        return false;
    }
};
// @lc code=end

/*



M1
mask=0X00000001
n&mask == 1 然后>>1 再次&mask应该为0

M2
1 =  0000 0001  T
2 =  0000 0010  T
4 =  0000 0100  F
5  = 0000 0101  T
7  = 0000 0111  F
11 = 0000 1011  F
17 = 0001 0001  F

Mask1 = 0101 0101  =  0x55555555
Mask2 = 1010 1010  =  0xAAAAAAAA

M1 & M2 = FFFF FFFF 全F


0101 ^ (0010) = (0111) 全1
(0111) & (0111+1) = 0



*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


