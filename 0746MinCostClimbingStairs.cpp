/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-09
 * @tag   dynamicProgramming
 * @similar  70,746
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 *
 * https://leetcode.cn/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (66.66%)
 * Likes:    1651
 * Dislikes: 0
 * Total Accepted:    557.4K
 * Total Submissions: 820.7K
 * Testcase Example:  '[10,15,20]'
 *
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
 * 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
 * 请你计算并返回达到楼梯顶部的最低花费。
 *
 *
 *
 * 示例 1：
 * 输入：cost = [10,15,20]
 * 输出：15
 * 解释：你将从下标为 1 的台阶开始。
 * - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
 * 总花费为 15 。
 *
 *
 * 示例 2：
 * 输入：cost = [1,100,1,1,1,100,1,1,100,1]
 * 输出：6
 * 解释：你将从下标为 0 的台阶开始。
 * - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
 * 总花费为 6 。
 *
 *
 *
 *
 * 提示：
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 *
 *
 */

// @lc code=start
class Solution {
public:
    // stupid
    int minCostClimbingStairsM1(vector<int>& cost) {
        // start from step0
        int s0 = dp(cost);
        cost.erase(cost.begin());
        // start from step1
        int s1 = dp(cost);
        return min(s0, s1);
    }

    int dp(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = cost[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }

    // stupid * 2
    int minCostClimbingStairsM2(vector<int>& cost) {
        int s0 = dp2(cost, 0);
        int s1 = dp2(cost, 1);
        return min(s0, s1);
    }

    int dp2(vector<int>& cost, int start) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        /* still work
        for (int i = 0; i < start; i++) {
            cost[i] = INT_MAX/2;
        }
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        // 可以从第0或者第1个台阶出发
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }


};
// @lc code=end

/*
dp[i]为爬完 nums[0 .. i-1]的最小花费，即到达位置=i
answer = dp[n], 到达位置=n,爬完数组 nums[0.. n-1]

dp[i] =  min(dp[i-1] + nums[i-1], dp[i-2] + nums[i-1])

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


