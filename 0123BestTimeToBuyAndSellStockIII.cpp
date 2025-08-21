/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-20
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
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (60.63%)
 * Likes:    1849
 * Dislikes: 0
 * Total Accepted:    421.6K
 * Total Submissions: 677.3K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 *
 * 示例 1:
 * 输入：prices = [3,3,5,0,0,3,1,4]
 * 输出：6
 * 解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
 * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
 *
 * 示例 2：
 * 输入：prices = [1,2,3,4,5]
 * 输出：4
 * 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 。  
 * 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。  
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 *
 *
 * 示例 3：
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
 *
 * 示例 4：
 * 输入：prices = [1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * 1 <= prices.length <= 105
 * 0 <= prices[i] <= 105
 *
 *
 */

// @lc code=start
class Solution {
public:

    // M1V1 卖出才算1笔交易，买入不算
    int maxProfitM1v1(vector<int>& prices) {
        int len = prices.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(4, 0)));

        dp[0][0][0] = 0; //第0天 第0笔交易 不持有股票
        dp[0][1][0] = -prices[0]; //第0天 第0笔交易 持有股票

        for (int k = 1; k <= 2; k++) { //设置为非法状态，不会影响结果
            //Line 24: Char 68: runtime error: signed integer overflow: -2147483648 - 3 cannot be represented in type
            dp[0][0][k] = INT_MIN/2;
            dp[0][1][k] = INT_MIN/2;
        }

        for (int i = 1; i < len; i++) {
            for (int k = 0; k <= 2; k++) {
                if (k>=1) {
                    dp[i][0][k] = max(dp[i - 1][0][k], dp[i - 1][1][k - 1] + prices[i]); // dayi-1 sell
                }
                dp[i][1][k] = max(dp[i - 1][1][k], dp[i - 1][0][k] - prices[i]); // dayi-1 buy
            }
        }
        int maxP = max({dp[len - 1][0][0], dp[len - 1][0][1], dp[len - 1][0][2]});
        return maxP;
        //ErrorLogic return  dp[len - 1][0][2];
    }

    // M1v2  买入算一笔交易，卖出不算
    // 关键在于初始值设定
    int maxProfitM1v2(vector<int>& prices) {
        int len = prices.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(4, 0)));

        dp[0][0][0] = 0; //第0天 第0笔交易 不持有股票
        for (int k = 1; k <= 2; k++) { //设置为非法状态，不会影响结果
            dp[0][0][k] = INT_MIN/2;
        }

        dp[0][1][0] = INT_MIN/2;  //第0天  持有股票 0笔交易 非法
        dp[0][1][1] = -prices[0];  //第0天  持有股票 1笔交易 合法， 买入prices[0]
        dp[0][1][2] = INT_MIN/2;  //第0天  持有股票 2笔交易 非法


        for (int i = 1; i < len; i++) {
            for (int k = 0; k <= 2; k++) {
                dp[i][0][k] = max(dp[i - 1][0][k],
                                  dp[i - 1][1][k] + prices[i]); // dayi-1 sell
                if (k>=1) {
                    dp[i][1][k] = max(dp[i - 1][1][k], dp[i - 1][0][k-1] - prices[i]); // dayi-1 buy
                } else {
                    dp[i][1][k] = dp[i - 1][1][k];
                }
            }
        }
        int maxP = max({dp[len - 1][0][0], dp[len - 1][0][1], dp[len - 1][0][2]});
        return maxP;
    }

    //M2
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> hold(len, vector<int>(3, 0));
        vector<vector<int>> empty(len, vector<int>(3, 0));

        hold[0][0] = -prices[0];
        empty[0][0] = 0;

        for (int k = 1; k <= 2; k++) { //设置为非法状态，不会影响结果
            empty[0][k] = INT_MIN/2;
            hold[0][k] = INT_MIN/2;
        }

        for (int i = 1; i < len; i++) {
            for (int k = 0; k <= 2; k++) {
                if (k>=1) {
                    empty[i][k] = max(empty[i - 1][k], hold[i - 1][k - 1] + prices[i]); // dayi-1 sell
                }
                hold[i][k] = max(hold[i - 1][k], empty[i - 1][k] - prices[i]); // dayi-1 buy
            }
        }
        int last = len -1;
        int maxP = max({empty[last][0], empty[last][1], empty[last][2]});
        return maxP;
    }


};
// @lc code=end

/*

From LC122
dp[i][1] = max{dp[i-1][1], dp[i-1][0] - prices[i]}
dp[i][0] = max{dp[i-1][0], dp[i-1][1] + prices[i]}

i=0
dp[0][1] =  - prices[0], 合乎逻辑？ yes,第0天买入一只股票，利润是-Prices[0]
dp[0][0] =  + prices[0]，不合逻辑，dp[0][0] = 0才合理 ,第0天不持有股票，利润就是0

买入卖出算一笔交易，
只买入不卖出，绝对不是最大利润，因此这不是答案范围
即K位交易次数，以卖出时交易次数+1
二维DP变成3纬DP，
dp[i][1][k]表示在第i天 持有股票且 完成了k笔交易的最大利润
dp[i][0][k]表示在第i天 不持有股票 完成了k笔交易的最大利润


M1v1
BUY
dp[i][1][k] = max{dp[i-1][1][k], dp[i-1][0][k] - prices[i]}
SELL
dp[i][0][k] = max{dp[i-1][0][k], dp[i-1][1][k-1] + prices[i]}
answer = max( dp[N-1][0][0..k])

M1v2
BUY
dp[i][1][k] = max{dp[i-1][1][k], dp[i-1][0][k-1] - prices[i]}
SELL
dp[i][0][k] = max{dp[i-1][0][k], dp[i-1][1][k] + prices[i]}
answer = max( dp[N-1][0][0..k])

M2
把三维DP拆分成2维
BUY
dp[i][1][k] = hold[i][k]
hold[i][k] = max{hold[i-1][k], empty[i-1][k] - prices[i]}

SELL
dp[i][0][k] = empty[i][k]
empty[i][k] = max{empty[i-1][k], hold[i-1][k-1] + prices[i]}




answer = dp[i][0][2]

i=0
dp[0][1][0] =  - prices[0]
dp[0][0][0] =   0
不存在 dp[0][0][1] ，设置为 INT_MAX/2
也不存在 dp[0][1][1] ,设置为  INT_MAX/2


Wrong Answer
109/214 cases passed (N/A)
Testcase
[1,2,3,4,5]
Answer
5
Expected Answer
4

Wrong Answer
124/214 cases passed (N/A)
Testcase
[1,2,3,4,5]
Answer
3
Expected Answer
4

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
