/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-16
 * @tag dynamicProgramming
 * @similar  239, 518
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (48.34%)
 * Likes:    3051
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 你可以认为每种硬币的数量是无限的。
 *
 *
 *
 * 示例 1：
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 示例 2：
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 示例 3：
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 *
 * 提示：
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> cache;


    int coinChangeM1(vector<int>& coins, int amount) {
        if (cache.count(amount)) {
            return cache[amount];
        }
        if (amount == 0) {
            return 0;
        }

        int minCoins = INT_MAX;
        for (auto& c: coins) {
            if (amount < c)  {
                continue;
            }
            int choice = coinChange(coins, amount - c);
            if (choice == -1) {
                continue;
            }
            minCoins = min(minCoins, choice + 1);
        }
        if (minCoins == INT_MAX) {
            minCoins = -1;
        }
        cache[amount] = minCoins;
        return minCoins;
    }

    //或者全部初始化为最大值 INT_MAX/2 这样代码中不用判定-1
    int coinChangeM2(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int minCoins = INT_MAX;
            for (auto& val : coins) {
                if (i < val) {
                    continue;
                }
                if (dp[i-val] == -1) {
                    continue;
                }
                minCoins = min(minCoins, dp[i - val]);
            }
            if (minCoins == INT_MAX) {
                dp[i] = -1;
            } else {
                dp[i] = minCoins + 1;
            }
        }
        return dp[amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX/2);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto& val : coins) {
                if (i < val) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - val] + 1);
            }
        }
        return (dp[amount] == INT_MAX/2) ? -1 : dp[amount];
    }

};
// @lc code=end

/*

BT
11 = 1*11
11 = 2 *5 + 1
11 = 5 + 5 +1
greedy
先用大的，再用小的，不行的话回溯

5-5-5
5-5-2
5-5-1

2-2
2
-1


DP
coins=[1,2,5]
f(a) 表示兑换金额a的最小硬币数目
f(a)=min( f(a-1)+1 , f(a-2)+1, f(a-5)+1 )
f(0)=0;
f(1)=1
f(2)=1
f(3)=min(f(2), f(1), f(-2)) +1 = min(1, 1, 0) +1 = 2

f(5)=1

Runtime Error
1/189 cases passed (N/A)
Error
Testcase
[2]
3
Expected Answer
-1


Wrong Answer
38/189 cases passed (N/A)
Testcase
[2]
3
Answer
0
Expected Answer
-1

Runtime Error
2/189 cases passed (N/A)
Error
Line 36: Char 21: AddressSanitizer: heap-buffer-overflow on address 0x502000000194 at pc 0x55beb4e3627d bp 0x7ffe6936aff0 sp 0x7ffe6936afe8
Line 36: Char 21:
Testcase
[1]
0
Expected Answer
0

Wrong Answer
48/189 cases passed (N/A)
Testcase
[186,419,83,408]
6249
Answer
-1
Expected Answer
20


[186,419,83,408]
6249

原因：
when amount= 186
    minCoins = INT_MAX
    val=186
    minCoins = min(minCoins, dp[i - val]);
    minCoins = min(minCoins, dp[186 - 186]) = min(INT_MAX, dp[0]) = 0

    val=83
    minCoins = min(minCoins, dp[i - val])= min(0, dp[186-83]) = min(0, dp[103]) = min(0, -1)  = -1

     最终导致 dp[186] = -1
    预期 dp[186]=1


本质原因是 当dp[X]=-1时，不应该参与minCoins的计算，在DFS时有这个逻辑，反而改成for循环时把这个逻辑漏掉了


*/







int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


