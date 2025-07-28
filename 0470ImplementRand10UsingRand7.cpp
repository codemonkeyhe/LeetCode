/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-28
 * @tag probability,math
 * @similar  470, 808, 837
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 *
 * https://leetcode.cn/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (55.14%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    127.1K
 * Total Submissions: 229.7K
 * Testcase Example:  '1'
 *
 * 给定方法 rand7 可生成 [1,7] 范围内的均匀随机整数，试写一个方法 rand10 生成 [1,10] 范围内的均匀随机整数。
 *
 * 你只能调用 rand7() 且不能调用其他方法。请不要使用系统的 Math.random() 方法。
 *
 *
 * 每个测试用例将有一个内部参数 n，即你实现的函数 rand10() 在测试时将被调用的次数。请注意，这不是传递给 rand10() 的参数。
 *
 *
 *
 * 示例 1:
 * 输入: 1
 * 输出: [2]
 *
 *
 * 示例 2:
 * 输入: 2
 * 输出: [2,8]
 *
 *
 * 示例 3:
 * 输入: 3
 * 输出: [3,8,10]
 *
 *
 * 提示:
 * 1 <= n <= 10^5
 *
 *
 *
 *
 * 进阶:
 * rand7()调用次数的 期望值 是多少 ?
 * 你能否尽量少调用 rand7() ?
 *
 *
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:

    int rand10V1() {
        int rr = 0;
        do {
            int r1 = rand7(); // 0-6  0-42
            int r2 = rand7();
            rr = (r1 - 1) * 7 + r2; //(0-42) + (1-7) = (1-49)
        } while (rr > 40);
        // ERROR LOGIC
        //return (rr % 10 + 1);
        return ((rr-1) % 10 + 1);
    }


    int rand10() {
        int rr = 0;
        while(1) {
            int r1 = rand7(); // 0-6  0-42
            int r2 = rand7();
            rr = (r1 - 1) * 7 + r2; //(0-42) + (1-7) = (1-49)
            if (rr <=40) {
                return ((rr-1) % 10 + 1);
            }
            // rr > 40
            int r3 = rand7();
            rr = ((rr-40)-1)*7+r3; // (0-8) * 7 + (1-7) = (1-63)
            if (rr <= 60) {
                return ((rr - 1) % 10 + 1);
            }
            // rr > 60
            int r4 = rand7();
            rr = ((rr-60)-1)*7+r3; // (0-2) * 7 + (1-7) = (1-21)
            if (rr <= 20) {
                return ((rr - 1) % 10 + 1);
            }
        }
        return -1;
    }
};
// @lc code=end

/*
Wrong Answer
6/12 cases passed (N/A)
Testcase
100


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


