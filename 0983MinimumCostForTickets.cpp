/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-27
 * @tag    dynamicProgramming
 * @similar  322, 983
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 *
 * https://leetcode.cn/problems/minimum-cost-for-tickets/description/
 *
 * algorithms
 * Medium (63.03%)
 * Likes:    702
 * Dislikes: 0
 * Total Accepted:    76.3K
 * Total Submissions: 119K
 * Testcase Example:  '[1,4,6,7,8,20]\n[2,7,15]'
 *
 * 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到
 * 365 的整数。
 *
 * 火车票有 三种不同的销售方式 ：
 * 一张 为期一天 的通行证售价为 costs[0] 美元；
 * 一张 为期七天 的通行证售价为 costs[1] 美元；
 * 一张 为期三十天 的通行证售价为 costs[2] 美元。
 *
 *
 * 通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4
 * 天、第 5 天、第 6 天、第 7 天和第 8 天。
 *
 * 返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费 。
 *
 *
 *
 * 示例 1：
 * 输入：days = [1,4,6,7,8,20], costs = [2,7,15]
 * 输出：11
 * 解释：
 * 例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
 * 在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
 * 在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
 * 在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
 * 你总共花了 $11，并完成了你计划的每一天旅行。
 *
 *
 * 示例 2：
 * 输入：days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * 输出：17
 * 解释：
 * 例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
 * 在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2, ..., 30 天生效。
 * 在第 31 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 31 天生效。
 * 你总共花了 $17，并完成了你计划的每一天旅行。
 *
 *
 *
 *
 * 提示：
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days 按顺序严格递增
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:

    int mincostTicketsM1(vector<int>& days, vector<int>& costs) {
        int n = days.back() + 1;
        unordered_set<int> out(days.begin(), days.end());
        vector<int> dp(n, INT_MAX/2);

        int lastDay = n - 1;
        if (out.count(lastDay) == 0) {
            dp[lastDay] = 0;
        } else {
            dp[lastDay] = min({costs[0], costs[1], costs[2]});
        }

        for (int i = n - 2; i >= 0; i--) {
            if (out.count(i) == 0) {
                dp[i] = dp[i + 1];
            } else {
                //dp[i] = min(costs[0]+dp[i+1], costs[1]+dp[i+7], costs[2]+dp[i+30])
                int v7 = 0;
                if (i + 7 < n) {
                    v7 = dp[i+7];
                }
                int v30 = 0;
                if (i + 30 < n) {
                    v30 = dp[i+30];
                }
                dp[i] = min({costs[0] + dp[i + 1], costs[1] + v7, costs[2] + v30});
            }
        }
        //return dp[0];
        return dp[days[0]];
    }

     int mincostTicketsM2(vector<int>& days, vector<int>& costs) {
        //int n = 366;
        int n = days.back() + 1;
        vector<int> out(n, 0);
        vector<int> dp(n, INT_MAX/2);
        for (int i = 0; i < days.size(); i++) {
            out[days[i]] = 1;
        }

        int lastDay = n - 1;
        if (out[lastDay] == 0) {
            dp[lastDay] = 0;
        } else {
            dp[lastDay] = min({costs[0], costs[1], costs[2]});
        }

        for (int i = n - 2; i >= 0; i--) {
            if (out[i] == 0) {
                dp[i] = dp[i + 1];
            } else {
                //dp[i] = min(costs[0]+dp[i+1], costs[1]+dp[i+7], costs[2]+dp[i+30])
                int v7 = 0;
                if (i + 7 < n) {
                    v7 = dp[i+7];
                }
                int v30 = 0;
                if (i + 30 < n) {
                    v30 = dp[i+30];
                }
                dp[i] = min({costs[0] + dp[i + 1], costs[1] + v7, costs[2] + v30});
            }
        }
        return dp[0];
       // return dp[days[0]];
    }

    unordered_map<int, int> cache;
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        unordered_set<int> out(days.begin(), days.end());
        int p = bt(1, out, costs);
        return p;
    }

     int bt(int di, unordered_set<int>& out, vector<int>& costs) {
        if (di > 365) {
            return 0;
        }
        if (cache.count(di)) {
            return cache[di];
        }

        if (out.count(di) == 0) {
            //Error return 0;
            int v = bt(di + 1, out, costs);
            cache[di] = v;
            return v;
        }
        int minPrice = costs[0] + bt(di + 1, out, costs);
        int op2 = costs[1] + bt(di + 7, out, costs);
        int op3 = costs[2] + bt(di + 30, out, costs);
        minPrice = min({minPrice, op2, op3});
        cache[di] = minPrice;
        return minPrice;
     }
};
// @lc code=end

/*
dp[i] 表示 days集合里面，从第i天到365天旅行的的minPrice
考虑第i天，
Case1 i 不在days里面，表示不用出行，则这天话费为0
      dp[i] = dp[i+1]
Case2  i在days里面，第i天需要出行
    op1 buy one-day pass
        dp[i] = costs[0] + dp[i+1]
    op2 buy 7-day pass  i i+6  i+7
        dp[i] = costs[1] + dp[i+7]
    op3 buy 30-day pass
        dp[i] = costs[2] + dp[i+30]

answer=dp[0]

dp[i] = min(costs[0]+dp[i+1], costs[1]+dp[i+7], costs[2]+dp[i+30])
注意  dp[i] 和 days[i]不是对等的，
dp[i]表示第i天，days里面的天数是离散的， 第i天不一定在days里面
取days的最大值， int N = days.back()
dp的长度为N+1

有2种办法记录第i天是否出行
M1  用hashset存储days

M2 days最多365天，用vector<int> out来记录是否出行





Wrong Answer
63/70 cases passed (N/A)
Testcase
[1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29]
[3,14,50]
Answer
55
Expected Answer
50



costs的1天票贵过周票
Wrong Answer
67/70 cases passed (N/A)
Testcase
[1,4,6,7,8,20]
[7,2,15]
Answer
11
Expected Answer
6










*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
