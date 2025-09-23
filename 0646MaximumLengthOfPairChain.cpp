/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-23
 * @tag   dynamicProgramming
 * @similar   435, 646
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 *
 * https://leetcode.cn/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (63.06%)
 * Likes:    472
 * Dislikes: 0
 * Total Accepted:    94.3K
 * Total Submissions: 146.9K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]'
 *
 * 给你一个由 n 个数对组成的数对数组 pairs ，其中 pairs[i] = [lefti, righti] 且 lefti < righti 。
 * 现在，我们定义一种 跟随 关系，当且仅当 b < c 时，数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面。我们用这种形式来构造数对链 。
 * 找出并返回能够形成的 最长数对链的长度 。
 * 你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
 *
 *
 *
 * 示例 1：
 * 输入：pairs = [[1,2], [2,3], [3,4]]
 * 输出：2
 * 解释：最长的数对链是 [1,2] -> [3,4] 。
 *
 *
 * 示例 2：
 * 输入：pairs = [[1,2],[7,8],[4,5]]
 * 输出：3
 * 解释：最长的数对链是 [1,2] -> [4,5] -> [7,8] 。
 *
 *
 *
 * 提示：
 * n == pairs.length
 * 1 <= n <= 1000
 * -1000 <= lefti < righti <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:

    static bool cmpFn(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return true;
        }
        return false;
    }


    int findLongestChainM1(vector<vector<int>>& pairs) {
        int len = pairs.size();
        sort(pairs.begin(), pairs.end(), cmpFn);

        int cnt = 1;
        //int preLeft = pairs[0][0];
        int preRight = pairs[0][1];
        for (int i = 1; i < len; i++) {
            vector<int>& cur = pairs[i];
            if (cur[0] > preRight) { // not overlap
                cnt++;
                //preLeft = cur[0];
                preRight = cur[1];
                continue;
            }
            preRight = min(preRight, cur[1]); // 贪心，取右端点较早结束，这样为后面的区间预留更长的空间
        }
        return cnt;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int len = pairs.size();
        sort(pairs.begin(), pairs.end(), cmpFn);

        vector<int> dp(len, 1);
        dp[0] = 1;

        for (int i = 1; i < len; i++) {
            int maxV = 0;
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] >= pairs[i][0]) {
                    continue;
                }
                maxV = max(maxV, dp[j]);
            }
            dp[i] = maxV + 1;
        }
        return dp[len-1];
    }


};
// @lc code=end

/*

DP
按leftPoint排序


dp[i]表示 pairs[0 .. i] 中 以区间pairs[i]结尾的 最长数对链的长度


考虑最后一个区间 pairs[i]
它可以拼接在前面任意一个区间，只要满足 pairs[j][1] < pairs[i][0]
易得
dp[i] = max(dp[j]) + 1
  0 <= j < i 并且  pairs[j][1] < pairs[i][0]

ans= dp[len(pairs)-1]

dp[0] = 1;


DP
Wrong Answer
43/206 cases passed (N/A)
Testcase
[[-6,9],[1,6],[8,10],[-1,4],[-6,-2],[-9,8],[-5,3],[0,3]]
Answer
4
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
