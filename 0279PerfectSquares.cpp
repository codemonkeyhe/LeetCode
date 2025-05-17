/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-17
 * @tag  dynamicProgramming
 * @similar   322
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (66.87%)
 * Likes:    2172
 * Dislikes: 0
 * Total Accepted:    701.5K
 * Total Submissions: 1M
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11
 * 不是。
 *
 *
 *
 * 示例 1：
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 示例 2：
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 *
 * 提示：
 * 1 <= n <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:

    unordered_map<int, int> cache;


    int numSquaresM1(int n) {
        vector<int> squa;
        for (int i = 1; i * i <= n; i++) {
            squa.push_back(i*i);
        }
        return numSquaBT(n, squa);
    }


    int numSquaBT(int n, vector<int>& squa) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (cache.count(n)) {
            return cache[n];
        }
        int minCnt = INT_MAX/2;
        for (int i = 0; i < squa.size(); i++) {
            if (squa[i] > n) {
                continue;
            }
            int cnt = numSquaBT(n - squa[i], squa) + 1;
            minCnt = min(minCnt, cnt);
        }
        cache[n] = minCnt;
        return minCnt;
    }


    int numSquaresM2V1(int n) {
        vector<int> squa;
        for (int i = 1; i * i <= n; i++) {
            squa.push_back(i*i);
        }
        //vector<int>dp (n+1, 0);
        vector<int>dp (n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (auto& num: squa) {
                if (i < num) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
        return dp[n];
    }

    int numSquares(int n) {
        //vector<int>dp (n+1, 0);
        vector<int>dp (n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

/*
类似322 零钱兑换

coins=[完全平方数] = [1,4,9,16, ...  k]
k<n且下一个完全平方数大于n
coins可重复利用,coins求最少的coins，这里求最少的完全平方数

最小的完全平方数是1
因此，任意一个数都可以是1的和，即必然存在解

f(n) 表示和为n的最小完全平方数的数量
例如 n=12， f(n)=3
coins=[1,4,9]
f(n) = min( 1+f(n-1), 1+f(n-4), 1+ f(n-9))
n=1时  f(1)=1
n=2时 f(2)=0
n=3时 f(3)=0
n=4时 f(4)=min(1+f(3), 1+f(0), 1+f(-5)) = min(1, 1, 1) = 1
n=5   f(5)=min(1+f(4), 1+f(1), ) = min(2, 2) = 2


没加CacheTLE
加了Cache Your runtime beats 6.22 % of cpp submissions
Time Limit Exceeded
53/589 cases passed (N/A)
Testcase
52
Expected Answer
2


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


