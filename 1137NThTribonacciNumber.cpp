/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-28
 * @tag
 * @similar  70, 509, 1137
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 *
 * https://leetcode.cn/problems/n-th-tribonacci-number/description/
 *
 * algorithms
 * Easy (60.91%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    265.4K
 * Total Submissions: 435.4K
 * Testcase Example:  '4'
 *
 * 泰波那契序列 Tn 定义如下： 
 * T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
 * 给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
 *
 *
 *
 * 示例 1：
 * 输入：n = 4
 * 输出：4
 * 解释：
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 *
 *
 * 示例 2：
 * 输入：n = 25
 * 输出：1389537
 *
 *
 *
 *
 * 提示：
 * 0 <= n <= 37
 * 答案保证是一个 32 位整数，即 answer <= 2^31 - 1。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int tribonacciM1(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        if (n >= 1) {
            dp[1] = 1;
        }
        if (n >= 2) {
            dp[2] = 1;
        }
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }


    vector<int> cache;
    int tribonacci(int n) {
        cache = vector<int>(n+1, -1);
        return tri(n);
    }

    int tri(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int& r = cache[n];
        if (r != -1) {
            return r;
        }
        int v = tri(n - 3) + tri(n - 2) + tri(n - 1);
        r = v;
        return v;
    }

};
// @lc code=end

/*
Runtime Error
9/38 cases passed (N/A)

Testcase
0
Expected Answer
0

without Cache
Time Limit Exceeded
34/38 cases passed (N/A)
Testcase
34
Expected Answer
334745777

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
