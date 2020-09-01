/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-28
 * @tag   DP
 * @similar  122 123
 */

/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "common.h"

using namespace std;

class Solution {
public:
    //TLE
    int maxProfitFool(vector<int>& prices) {
        int maxp = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    continue;
                }
                profit = prices[j] - prices[i];
                if (profit > maxp) {
                    maxp = profit;
                }
            }
        }
        return maxp;
    }

/*
//BUG for (int i = 0; i < prices.size() - 1; i++) {
    当prices.size()==0 时， (size_t)0 - 1为一个很大的数字，导致越界，要加上(int)强制转换或者复制到int len

Runtime: 12 ms, faster than 79.52% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 13.3 MB, less than 10.82% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
    int maxProfitM0(vector<int>& prices) {
        int maxp = 0;
        int profit = 0;
        int len = prices.size();
        for (int i = 0; i < len - 1; i++) {
            if (prices[i] >= prices[i+1]) {
                continue;
            }
            for (int j = i + 1; j < len; j++) {
                if (prices[j] <= prices[i]) {
                    continue;
                }
                profit = prices[j] - prices[i];
                if (profit > maxp) {
                    maxp = profit;
                }
            }
        }
        return maxp;
    }

/*
Runtime: 8 ms, faster than 97.29% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 13.2 MB, less than 29.02% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
    int maxProfitM1(vector<int>& prices) {
        int maxp = 0;
        int profit = 0;
        int len = prices.size();
        for (int i = 0; i < len - 1; i++) {
            if (prices[i] >= prices[i+1]) {
                continue;
            }
            for (int j = i + 1; j < len; j++) {
                if (prices[j] <= prices[i]) {
                    i = j - 1;  //说明j是新的买入点 ,-1是为了外层for循环i++后正好为j
                    break;
                } else {
                    profit = prices[j] - prices[i];
                    if (profit > maxp) {
                        maxp = profit;
                    }
                }
            }
        }
        return maxp;
    }

    //第i天卖出时 依赖的是[0 .. i-1]的最小值，而不是[0..i]的最小值
 //   Runtime: 12 ms, faster than 79.52% of C++ online submissions for Best Time to Buy and Sell Stock.
//   Memory Usage: 13 MB, less than 86.01% of C++ online submissions for Best Time to Buy and Sell Stock.
    int maxProfitM2(vector<int>& prices) {
        int maxp = 0;
        int profit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            profit = prices[i] - minPrice;
            if (profit > maxp) {
                maxp = profit;
            }
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
        }
        return maxp;
    }

/*
Runtime: 16 ms, faster than 47.10% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 13.4 MB, less than 5.99% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
    int maxProfitM3(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<int>  dp(len, 0);
        dp[0] = 0;
        int minP = prices[0];
        int i = 1;
        for (; i < prices.size(); i++) {
            dp[i] = max(dp[i-1], prices[i]-minP);
            minP = min(minP, prices[i]);
        }
        return  dp[i-1];
    }

};



int maxProfit(int* prices, int pricesSize){

}


int main() {

    Solution s;

    return 0;
}


/*
Tips
错误思路:最小值买，最大值卖
卖的下标要大于买的下标

M0 暴力法  TLE
O(n^2)
i依次指向所有的买入点
j指向[i+1..n]所有的卖出点
计算最大profit

暴力法的优化版
O(N^2)
指针i: 找到所有的拐点作为买入点
指针j=i+1;指向所有的右侧大于买入点的值作为卖出点，算出profit。

M1 双指针版
O(N)
暴力法的优化版是在暴力版的基础上优化了 买入点i
双指针则进一步优化，当寻找卖出点j时，如果卖出点的时小于买入点i，那么这个j就是新的买入点 i=j。

M2 逻辑推导法 本质是DP
O(N)
在i天卖出时，想要获取maxprofit，应该在历史最低点买入。
也就是要寻找[0 .. i-1]天的最小值minPrice，然后在第i天卖出，才能获得最大profit。
假设已经计算了[0.. i]天的最小值minPrice，现在要在第i+1天卖出，问题同上。由此可推导DP的公式如下

M3 DP
O(N)
记 [0..i-1]的最小值为 minP[i-1],  记maxPrifit为f[i-1] = P[X] - minP[i-1]
则第i天的获利为下面2种情况的最大值:
1.第i天卖出的获利
 profit(i) = P[i]-minP[i-1], if(P[i]>minP[i-1])
2.第i天不卖，则第i天的获利等于第i-1天的获利
 profit(i) = f[i-1], if(P[i]<=minP[i-1])
即 f[n] = max(f[n-1], P[n] - minP[n-1]);

记f[0]=0
f[1] = max(f[0], p[1]-minP[0]) = max(f[0], P[1]-P[0]) = max(0, p[1]-p[0])

*/
