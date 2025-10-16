/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-15
 * @tag   dynamicProgramming
 * @similar 1155, 1775
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子等于目标和的方法数
 *
 * https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (63.29%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    53K
 * Total Submissions: 81.2K
 * Testcase Example:  '1\n6\n3'
 *
 * 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。
 *
 * 给定三个整数 n、k 和 target，请返回投掷骰子的所有可能得到的结果（共有 k^n 种方式），使得骰子面朝上的数字总和等于 target。
 *
 * 由于答案可能很大，你需要对 10^9 + 7 取模。
 *
 *
 *
 * 示例 1：
 * 输入：n = 1, k = 6, target = 3
 * 输出：1
 * 解释：你掷了一个有 6 个面的骰子。
 * 得到总和为 3 的结果的方式只有一种。
 *
 *
 * 示例 2：
 * 输入：n = 2, k = 6, target = 7
 * 输出：6
 * 解释：你掷了两个骰子，每个骰子有 6 个面。
 * 有 6 种方式得到总和为 7 的结果: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1。
 *
 *
 * 示例 3：
 * 输入：n = 30, k = 30, target = 500
 * 输出：222616187
 * 解释：返回的结果必须对 10^9 + 7 取模。
 *
 *
 *
 * 提示：
 * 1 <= n, k <= 30
 * 1 <= target <= 1000
 *
 *
 */

// @lc code=start

class Solution {
public:
// 109 + 7
    static const int MOD = 1000000007;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            // dp[i][t] = dp[i-1][t-1] + dp[i-1][t-2]  .. dp[i-1][t-k];
            //    (t>=k)
            for (int t = 1; t <= target; t++) {
                int cnt = 0;
                for (int j = 1; j <= k; j++) {
                    if (j > t) {
                        break;
                    }
                    cnt = (cnt + dp[i - 1][t - j]) % MOD;
                }
                dp[i][t] = cnt;
            }
        }

        return dp[n][target];
    }
};
// @lc code=end

/*
dp[i][t] 表示 i个骰子j个面形成target的方案数

第i个骰子
可能是 1-k

dp[i][t] = dp[i-1][t-1] + dp[i-1][t-2]  .. dp[i-1][t-k]   (t>=k)
answer = dp[n][target]

dp[0][0] = 1
dp[0][t] = 0
dp[i][0] = 1 or 0??



 * 输入：n = 1, k = 6, target = 3
 dp[1][3] = dp[0][2] + dp[0][1] + dp[0][0] = 0 + 0 + 1 = 1


 * 输入：n = 2, k = 6, target = 7
 dp[2][7] = dp[1][6] + dp[1][5] + dp[1][4] + dp[1][3] + dp[1][2] + dp[1][1]
         = 1+1 +1 + 1+ 1+ 1 =6

 dp[1][1] = dp[0][0] = 1

 Runtime Error
2/65 cases passed (N/A)
Error
Line 15: Char 25: runtime error: signed integer overflow: 2146080794 + 19836229 cannot be represented in type 'int' (solution.cpp)
Line 15: Char 25: runtime error: signed integer overflow: 2146080794 + 19836229 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:24:25
Testcase
30
30
500
Expected Answer
222616187



*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
