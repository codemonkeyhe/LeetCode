/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-24
4 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 *
 * https://leetcode.cn/problems/number-complement/description/
 *
 * algorithms
 * Easy (69.41%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    89K
 * Total Submissions: 128.2K
 * Testcase Example:  '5'
 *
 * 对整数的二进制表示取反（0 变 1 ，1 变 0）后，再转换为十进制表示，可以得到这个整数的补数。
 *
 *
 * 例如，整数 5 的二进制表示是 "101" ，取反后得到 "010" ，再转回十进制表示得到补数 2 。
 *
 *
 * 给你一个整数 num ，输出它的补数。
 *
 * 示例 1：
 * 输入：num = 5
 * 输出：2
 * 解释：5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
 *
 *
 * 示例 2：
 * 输入：num = 1
 * 输出：0
 * 解释：1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
 *
 * 提示：
 * 1 <= num < 2^31
 *
 *
 *
 *
 * 注意：本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/
 * 相同
 *
 */

// @lc code=start
class Solution {
public:
    int findComplementV1(int num) {
        int pos = 1;
        int n = num;
        int i = 31;
        while (i>= 0) {
            if ((n & (1 << i)) ) {
                break;
            }
            pos++;
            i--;
        }
        int mask = 0;
        int limit = 32-pos;
        for (int i = 0; i <= limit; i++) {
            mask = mask | (1<<i);
        }
        int op = ~num;
        return op&mask;
    }


    int findComplement(int num) {
        int pos = 1;
        int n = num;
        int i = 31;
        int ma = 0x40000000;
        while (ma>= 0) {
            if ((n & ma) ) {
                break;
            }
            pos++;
            ma = ma >> 1;
        }
        //cout << "pos=" << pos << " ma=" << ma << endl;
        int mask = 0;
        int limit = 32-pos;
        for (int i = 0; i < limit; i++) {
            mask = mask | (1<<i);
        }

// way1
        //int op = ~num;
        //return op&mask;

// way2
        return num^mask;
    }
};
// @lc code=end


/*
Tips

num:5   = 0000 0000 0000 0000 0000 0000 0000 0101
op:~5   = 1111 1111 1111 1111 1111 1111 1111 1010  = 0xFFFFFFFA = 按照补码去理解，相当于 -6 即对5取反，结果为-6
mask    = 0000 0000 0000 0000 0000 0000 0000 0111



way1: op&mask =  010 = 2
way2: num&mask =  010 = 2


对负数进行取反操作
1 .... 0101 原  = 1 .... 1010 + 0X00000001 = 1 .... 1011 补

num:-5   = 1111 1111 1111 1111 1111 1111 1111 1011 补  = 0xFFFFFFFB
 op:~(-5)   = 0000 0000 0000 0000 0000 0000 0000 0100 =  0x00000004  = 4
 对-5进行按位取反操作 = 4

XXX 按位取反，无视符号位

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


