/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-21
 * @tag  dynamicProgramming
 * @similar  121,122,123,188, 309
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (49.87%)
 * Likes:    1296
 * Dislikes: 0
 * Total Accepted:    341.2K
 * Total Submissions: 638.4K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 *
 * 示例 1：
 * 输入：k = 2, prices = [2,4,1]
 * 输出：2
 * 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 *
 * 示例 2：
 * 输入：k = 2, prices = [3,2,6,5,0,3]
 * 输出：7
 * 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
 * ⁠    随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 =
 * 3 。
 *
 *
 *
 * 提示：
 * 1 <= k <= 100
 * 1 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:

    // M1 DP
    int maxProfitM1(int k, vector<int>& prices) {
        int len = prices.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(k+1, 0)));

        dp[0][0][0] = 0; //第0天 第0笔交易 不持有股票
        dp[0][1][0] = -prices[0]; //第0天 第0笔交易 持有股票

        for (int c = 1; c <= k; c++) { //设置为非法状态，不会影响结果
            dp[0][0][c] = INT_MIN/2;
            dp[0][1][c] = INT_MIN/2;
        }

        for (int i = 1; i < len; i++) {
            for (int c = 0; c <= k; c++) {
                if (c >= 1) {
                    dp[i][0][c] = max(dp[i - 1][0][c], dp[i - 1][1][c - 1] + prices[i]); // dayi-1 sell
                }
                /* still work
                 else {
                    dp[i][0][c] = dp[i - 1][0][c];
                }
                */
                dp[i][1][c] = max(dp[i - 1][1][c], dp[i - 1][0][c] - prices[i]); // dayi-1 buy
            }
        }
        auto& lastDay = dp[len-1][0];
        int maxP = *max_element(lastDay.begin(), lastDay.end());
        return maxP;
    }


    // M2 DFS
    vector<vector<vector<int>>> cache;
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        int maxP = 0;
        cache = vector<vector<vector<int>>>(
            len, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        for (int i = 0; i <= k; i++) {
            int res = dfs(prices, len - 1, 0, i);
            //cout << "i=" << i << " res=" << res << endl;
            maxP = max(res, maxP);
        }
        return maxP;
    }


    int dfs(vector<int>& prices, int day, int hold, int k) {
        if (day == 0) {
            if (hold) {
                if (k == 0) {
                    return -prices[0];
                }
                return  INT_MIN/2;
            } else {
                if (k == 0) {
                    return 0;
                }
                return INT_MIN/2;
            }
        }
        if (day < 0 || k < 0) {
            return INT_MIN/2;
        }
        int& res = cache[day][hold][k];
        if (res != -1) {
            return res;
        }

        if (hold) {
            int v1 = dfs(prices, day-1, 1, k);
            int v2 = dfs(prices, day-1, 0, k) - prices[day]; //buy
            int maxV = max(v1, v2);
            res = maxV;
            return  maxV;
        }
        // not hold
        int v3 = dfs(prices, day - 1, 0, k);
        int v4 = dfs(prices, day - 1, 1, k - 1) + prices[day]; // sell
        int maxV = max(v3, v4);
        res = maxV;
        return maxV;
    }

};
// @lc code=end

/*

M2 无Cache
Time Limit Exceeded
205/210 cases passed (N/A)

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
