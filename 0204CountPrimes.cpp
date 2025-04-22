/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-22
 * @tag math
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
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode.cn/problems/count-primes/description/
 *
 * algorithms
 * Medium (37.01%)
 * Likes:    1154
 * Dislikes: 0
 * Total Accepted:    276.6K
 * Total Submissions: 747.3K
 * Testcase Example:  '10'
 *
 * 给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
 *
 *
 *
 * 示例 1：
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 *
 * 示例 2：
 * 输入：n = 0
 * 输出：0
 *
 *
 * 示例 3：
 * 输入：n = 1
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * 0 <= n <= 5 * 10^6
 *
 *
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        auto v = makePrime(n);
        for (int i  = 2; i < n; i++) {
            if (v[i]) {
                res++;
            }
        }
        return res;
    }


    vector<bool> makePrime(int n) {
        vector<bool> pt(n + 1, true);
        for (int i = 2; i <= n; ++i) {
            if (!pt[i]) {
                continue;
            }
            if ((long long)i * i > n) // prevent overflow
                continue;
            for (int j = i * i; j <= n; j += i) {
                pt[j] = false;
            }
        }
        return pt;
    }

};
// @lc code=end

/*
Time Limit Exceeded
20/66 cases passed (N/A)
Testcase
5000000
Expected Answer
348513

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


