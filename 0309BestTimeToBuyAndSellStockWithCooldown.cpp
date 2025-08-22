/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-22
 * @tag  dynamicProgramming
 * @similar  121,122,123,188, 309, 714
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (64.77%)
 * Likes:    1849
 * Dislikes: 0
 * Total Accepted:    375.9K
 * Total Submissions: 576.6K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 *
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 *
 * 示例 1:
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 *
 * 示例 2:
 * 输入: prices = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示：
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maxProfitM1v1(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n, 0);
        vector<int> empty(n, 0);

        hold[0] = - prices[0];
        empty[0] = 0;
        for (int i = 1; i < n; i++) {
            if (i>=2) {
                hold[i] = max(hold[i-1], empty[i-2] - prices[i]);
            } else {
                hold[i] = max(hold[i-1],  - prices[i]);
            }
            empty[i] = max(empty[i - 1], hold[i - 1] + prices[i]);
        }
        int ans = max(hold[n-1], empty[n-1]);
        return ans;
    }


    // M1 v2
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n, 0);
        vector<int> empty(n, 0);

        hold[0] = - prices[0];
        empty[0] = 0;

        if (n >= 2) {
            //hold[i] = max(hold[i-1], empty[i-2] - prices[i]);
            //empty[i] = max(empty[i - 1], hold[i - 1] + prices[i]);
            // KEY STEP, ,empty[-1] = 0
            // hold[1] = max(hold[0], empty[-1] - prices[1]);
            hold[1] = max(hold[0], - prices[1]);
            empty[1] = max(empty[0], hold[0] + prices[1]);
        }

        for (int i = 2; i < n; i++) {
            hold[i] = max(hold[i - 1], empty[i - 2] - prices[i]);
            empty[i] = max(empty[i - 1], hold[i - 1] + prices[i]);
        }
        //int ans = max(hold[n-1], empty[n-1]);
        //return ans;
        return empty[n-1];
    }


};
// @lc code=end

/*

DP
hold[i] = max{hold[i-1], empty[i-2] - prices[i]}; // day-i buy
empty[i] = max{empty[i-1], hold[i-1] + prices[i]}; // day-i sell

hold[0] = -prices[0]
empty[0] = 0;

T: sell  T+1: cold T+2: buy
T: buy T+1: sell
先buy再sell无冷冻期
先sell，需要冷冻一天，才能buy





边界条件错误
                hold[i] = max(hold[i-1],  - prices[i]);

Wrong Answer
147/210 cases passed (N/A)
Testcase
[2,1,4]
Answer
2
Expected Answer
3



*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
