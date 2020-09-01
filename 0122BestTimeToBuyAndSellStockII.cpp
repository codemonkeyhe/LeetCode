/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-31
 * @tag
 * @similar
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

class Solution {
public:
    int maxProfitM1(vector<int>& prices) {

    }

/*
Runtime: 16 ms, faster than 42.28% of C++ online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 13 MB, less than 96.16% of C++ online submissions for Best Time to Buy and Sell Stock II.
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
    Solution s;
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