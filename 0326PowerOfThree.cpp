/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-06-05
 * @tag math;recursion
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 *
 * https://leetcode.cn/problems/power-of-three/description/
 *
 * algorithms
 * Easy (51.44%)
 * Likes:    333
 * Dislikes: 0
 * Total Accepted:    240.8K
 * Total Submissions: 467.8K
 * Testcase Example:  '27'
 *
 * 给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
 *
 * 整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3^x
 *
 *
 *
 * 示例 1：
 * 输入：n = 27
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：n = 0
 * 输出：false
 *
 *
 * 示例 3：
 *
 * 输入：n = 9
 * 输出：true
 *
 *
 * 示例 4：
 * 输入：n = 45
 * 输出：false
 *
 *
 * 提示：
 * -2^31 <= n <= 2^31 - 1
 *
 *
 * 进阶：你能不使用循环或者递归来完成本题吗？
 *
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if ( n <= 0 ) {
            return false;
        }
        if ( n == 1) {
            return true;
        }
        if ((n & 1) == 0 ) { // 偶数
            return false;
        }
        if (n % 3 != 0) {  // 21%3 == 0
            return false;
        }
        return isPowerOfThree(n/3);
    }
};
// @lc code=end

/*
必然是奇数

3^(-1) = - (1/3)

3^0=1
3
9
27
81
243


3
6
9
12
15
18
21
24
27



M1  递归
  N是3的幂 那么 n/3必然是3的幂



*/



/* TestCase
Wrong Answer
10562/21040 cases passed (N/A)
Testcase
45
Answer
true
Expected Answer
false


M2 递归改成非递归写法
*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


