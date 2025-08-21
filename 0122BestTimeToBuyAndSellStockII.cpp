/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-31, 2025-08-20
 * @tag  greedy, dynamicProgramming
 * @similar  121,122,123,188, 309
 */

/*
Say you have an array prices for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Constraints:
1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "common.h"

using namespace std;

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Medium (73.59%)
 * Likes:    2769
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 1.9M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
 * 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
 * 返回 你能获得的 最大 利润 。
 *
 * 示例 1：
 * 输入：prices = [7,1,5,3,6,4]
 * 输出：7
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
 * 最大总利润为 4 + 3 = 7 。
 *
 * 示例 2：
 * 输入：prices = [1,2,3,4,5]
 * 输出：4
 * 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
 * 最大总利润为 4 。
 *
 * 示例 3：
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。
 *
 *
 *
 * 提示：
 * 1 <= prices.length <= 3 * 10^4
 * 0 <= prices[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:

    // M1 greedy
   int maxProfitM1(vector<int>& prices) {
        int maxp = 0;
        int profit = 0;
        int len = prices.size();
        for (int i = 0; i < len - 1; i++) {
            while ((i+1 < len) &&  prices[i] >= prices[i+1]) {
                i++;
                continue;
            }
            int j = i;
            while ((j+1 < len) && (prices[j] <= prices[j+1])) {
                j++;
                continue;
            }
            profit = prices[j] - prices[i];
            maxp += profit;
            i = j;
        }
        return maxp;
    }

    // M2
    int maxProfit(vector<int> &prices) {
        int maxp = 0;
        int profit = 0;
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        //No OK return max(dp[len - 1][0], dp[len - 1][1]);
        return dp[len - 1][0];
    }
};
// @lc code=end


/*
定义状态
dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润，
dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）。

Case1 第i-1天没有股票dp[i-1][0]
  第i天买入 dp[i][1] = dp[i-1][0] - prices[i]
  第i天卖出 不可能
  第i天继续持有  dp[i][0] = dp[i-1][0]

Case2 第i-1天有股票dp[i-1][1]
  第i天买入  不可能
  第i天卖出    dp[i][0] =  dp[i-1][1]+ prices[i]
  第i天继续持有  dp[i][1] = dp[i-1][1]

综上
dp[i][1] = max{dp[i-1][1], dp[i-1][0] - prices[i]}
dp[i][0] = max{dp[i-1][0], dp[i-1][1] + prices[i]}

i=0
dp[0][1] =  - prices[0]  , 合乎逻辑？ yes,第0天买入一只股票，利润是-Prices[0]
dp[0][0] =  + prices[0]，不合逻辑，dp[0][0] = 0才合理 ,第0天不持有股票，利润就是0

//错误的想法
answer = max(dp[N-1][1], dp[N-1][0])


由于全部交易结束后，持有股票的收益一定低于不持有股票的收益，因此这时候 dp[n−1][0] 的收益必然是大于 dp[n−1][1] 的，最后的答案即为 dp[n−1][0]。




*/




class SolutionOld {
public:


/*
M1
Runtime: 16 ms, faster than 42.28% of C++ online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 13 MB, less than 96.16% of C++ online submissions for Best Time to Buy and Sell Stock II.
寻找折线图中的每一段连续递增线段，i是线段起点，j是线段终点
*/
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int profit = 0;
        int len = prices.size();
        for (int i = 0; i < len - 1; i++) {
            if (prices[i] >= prices[i+1]) {
                continue;
            }
            for (int j = i + 1; j < len; j++) {
                if (j < len - 1 && prices[j] <= prices[j + 1]) {
                    continue;
                }
                profit = prices[j] - prices[i];
                maxp += profit;
                i = j + 1;
            }
        }
        return maxp;
    }

};

int maxProfit(int* prices, int pricesSize){

}

int main() {
    const int len = 5;
    int nums[len] = {1,2,3,4,5};
    vector<int> prices(nums, nums + len);
    SolutionOld s;
    cout << s.maxProfit(prices) << endl;

    return 0;
}


/*
M0 峰谷法
每次谷底买入，波峰卖出，得到单次利润。
所有的单词利润之和就是最大利润


M1 连续上升的区间
峰谷法的本质是寻找一段连续上升区间的起点和终点
直接O(N)遍历即可确定这种起点和终点
作者：LeetCode
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode/
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}






*/