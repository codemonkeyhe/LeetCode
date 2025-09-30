/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-30
 * @tag     dynamicProgramming
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
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 *
 * https://leetcode.cn/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (52.89%)
 * Likes:    451
 * Dislikes: 0
 * Total Accepted:    54.1K
 * Total Submissions: 103.6K
 * Testcase Example:  '3'
 *
 * 有两种形状的瓷砖：一种是 2 x 1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。
 * 给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 10^9 + 7 取模 的值。
 * 平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。
 *
 *
 *
 * 示例 1:
 * 输出: 5
 * 解释: 五种不同的方法如上所示。
 *
 *
 * 示例 2:
 * 输入: n = 1
 * 输出: 1
 *
 *
 * 提示：
 * 1 <= n <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numTilings(int n) {
        int mod = 1000000007;
        vector<vector<long long> > dp(n+1, vector<long long>(4, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%mod;
            /* 等价写法
            if (i>=2) {
                dp[i][1] = (dp[i - 2][3] + dp[i - 1][2])%mod;
            } else {
                dp[i][1] = (dp[i - 1][2])%mod;
            }
            */
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%mod;

            dp[i][3] = (dp[i - 1][3] + dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%mod;
        }
        return dp[n][3];
    }
};
// @lc code=end

/*
给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 109 + 7 取模 的值。
给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 109 + 7 取模 的值。
给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 109 + 7 取模 的值。


作者：力扣官方题解
链接：https://leetcode.cn/problems/domino-and-tromino-tiling/solutions/1962465/duo-mi-nuo-he-tuo-mi-nuo-ping-pu-by-leet-7n0j/

在第 i 列前面的正方形都被瓷砖覆盖，在第 i 列后面的正方形都没有被瓷砖覆盖（i 从 1 开始计数）。那么第 i 列的正方形有四种被覆盖的情况：
一个正方形都没有被覆盖，记为状态 0；
只有上方的正方形被覆盖，记为状态 1；
只有下方的正方形被覆盖，记为状态 2；
上下两个正方形都被覆盖，记为状态 3。
使用 dp[i][s] 表示平铺到第 i 列时，各个状态 s 对应的平铺方法数量。

dp[i][0] = dp[i-1][3]
dp[i][1] = dp[i-1][0] + dp[i-1][2]  (等价 dp[i-2][3] + dp[i-1][2] ??)
dp[i][2] = dp[i-1][0] + dp[i-1][1]
dp[i][3] = dp[i-1][3] + dp[i-1][0] + dp[i-1][1] + dp[i-1][2]

初始值
dp[0][0] = 0
dp[0][1] = 0
dp[0][2] = 0
dp[0][3] = 0 ????
dp[1][0] == d[0][3]
dp[1][0] 相当于在2*1的面积上，保持为空的方案，理论上为1，因此 dp[0][3]=1

answer = dp[n][3]


Runtime Error
11/39 cases passed (N/A)
Error
Line 13: Char 37: runtime error: signed integer overflow: 1914332891 + 867954037 cannot be represented in type 'value_type' (aka 'int') (solution.cpp)
Line 13: Char 37: runtime error: signed integer overflow: 1914332891 + 867954037 cannot be represented in type 'value_type' (aka 'int') (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:22:37
Testcase
30
Expected Answer
312342182



*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
