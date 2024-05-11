/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-24
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
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode.cn/problems/power-of-four/description/
 *
 * algorithms
 * Easy (53.27%)
 * Likes:    371
 * Dislikes: 0
 * Total Accepted:    149.1K
 * Total Submissions: 279.7K
 * Testcase Example:  '16'
 *
 * 给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。
 *
 * 整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4^x
 *
 *
 *
 * 示例 1：
 * 输入：n = 16
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：n = 5
 * 输出：false
 *
 *
 * 示例 3：
 * 输入：n = 1
 * 输出：true
 *
 *
 * 提示：
 * -2^31 <= n <= 2^31 - 1
 *
 *
 *
 *
 * 进阶：你能不使用循环或者递归来完成本题吗？
 *
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }

        if ((n&(n-1)) != 0 ) {
            return false;
        }

        int cnt = 0;
        while (n) {
            if ((n & 1) == 1 ) {
                break;
            }
            cnt++;
            n = n >> 1;
        }
        if ((cnt%2) == 0) {
            return true;
        }
        return false;
    }
};
// @lc code=end


/*

1100

1011


只出现1个1，并且0的数目是偶数个
1
4          0100
16       1 0000
64     100 0000
256 1 0000 0000

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


