/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-22
 * @tag  dynamicProgramming
 * @similar   198, 2140
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 *
 * [2140] 解决智力问题
 *
 * https://leetcode.cn/problems/solving-questions-with-brainpower/description/
 *
 * algorithms
 * Medium (44.54%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    45.8K
 * Total Submissions: 88K
 * Testcase Example:  '[[3,2],[4,3],[4,4],[2,5]]'
 *
 * 给你一个下标从 0 开始的二维整数数组 questions ，其中 questions[i] = [pointsi, brainpoweri] 。
 *
 * 这个数组表示一场考试里的一系列题目，你需要 按顺序 （也就是从问题 0 开始依次解决），针对每个问题选择 解决 或者 跳过 操作。解决问题 i 将让你
 * 获得  pointsi 的分数，但是你将 无法 解决接下来的 brainpoweri 个问题（即只能跳过接下来的 brainpoweri
 * 个问题）。如果你跳过问题 i ，你可以对下一个问题决定使用哪种操作。
 *
 *
 * 比方说，给你 questions = [[3, 2], [4, 3], [4, 4], [2, 5]] ：
 * 如果问题 0 被解决了， 那么你可以获得 3 分，但你不能解决问题 1 和 2 。
 * 如果你跳过问题 0 ，且解决问题 1 ，你将获得 4 分但是不能解决问题 2 和 3 。
 *
 * 请你返回这场考试里你能获得的 最高 分数。
 *
 *
 *
 * 示例 1：
 * 输入：questions = [[3,2],[4,3],[4,4],[2,5]]
 * 输出：5
 * 解释：解决问题 0 和 3 得到最高分。
 * - 解决问题 0 ：获得 3 分，但接下来 2 个问题都不能解决。
 * - 不能解决问题 1 和 2
 * - 解决问题 3 ：获得 2 分
 * 总得分为：3 + 2 = 5 。没有别的办法获得 5 分或者多于 5 分。
 *
 *
 * 示例 2：
 * 输入：questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
 * 输出：7
 * 解释：解决问题 1 和 4 得到最高分。
 * - 跳过问题 0
 * - 解决问题 1 ：获得 2 分，但接下来 2 个问题都不能解决。
 * - 不能解决问题 2 和 3
 * - 解决问题 4 ：获得 5 分
 * 总得分为：2 + 5 = 7 。没有别的办法获得 7 分或者多于 7 分。
 *
 *
 *
 *
 * 提示：
 * 1 <= questions.length <= 10^5
 * questions[i].length == 2
 * 1 <= pointsi, brainpoweri <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int len = questions.size();
        vector<long long> dp(len, 0);
        dp[len - 1] = questions[len - 1][0];
        for (int i = len - 2; i >= 0; i--) {
            int skip = questions[i][1] + 1;
            long long skipVal = 0;
            if (i+skip < len) {
                skipVal = dp[i+skip];
            }
            dp[i] = max(dp[i+1], questions[i][0]+ skipVal);
        }

        return dp[0];
    }
};
// @lc code=end

/*
dp[i] 表示解决 questions[i..len-1]的最高分

对于第i个问题，两种选择
1 解决第i个问题，得分：
questions[i][0]  + dp[i+skip], skip=questions[i][1]+1

2 忽略第i个问题,得分 dp[i+1]

dp[i] = max(dp[i+1],  questions[i][0]  + dp[i+skip])

i从i+1得到
因此 for i = len-1 .. 0
N=len
dp[N-1] = max(dp[N], questions[N-1][0]+ ?? ) = questions[N-1][0]
dp[N-2] = max(dp[N-1], questions[N-2][0]+  skip ) = questions[N-1][0]



Wrong Answer
26/54 cases passed (N/A)
Testcase
[[1,1],[2,2],[3,3],[4,4],[5,5]]
Answer
9
Expected Answer
7

Runtime Error
52/54 cases passed (N/A)
Error
Line 13: Char 49: runtime error: signed integer overflow: 100000 + 2147400000 cannot be represented in type 'int' (solution.cpp)
Line 13: Char 49: runtime error: signed integer overflow: 100000 + 2147400000 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:22:49
Testcase
[[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],[100000,1],1],'... 1090001 more character
Expected Answer
5000000000

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
