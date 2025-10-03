/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-02
 * @tag    dynamicProgramming
 * @similar 1027, 1218, 2453
 */

/*
Tricky
dp[i] 不再是nums[i]的下标
而是 nums[i]本身

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 *
 * https://leetcode.cn/problems/longest-arithmetic-subsequence/description/
 *
 * algorithms
 * Medium (49.64%)
 * Likes:    414
 * Dislikes: 0
 * Total Accepted:    60.4K
 * Total Submissions: 118.9K
 * Testcase Example:  '[3,6,9,12]'
 *
 * 给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。
 *
 * 回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ...
 * < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1)
 * 的值都相同，那么序列 seq 是等差的。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [3,6,9,12]
 * 输出：4
 * 解释：
 * 整个数组是公差为 3 的等差数列。
 *
 *
 * 示例 2：
 * 输入：nums = [9,4,7,2,10]
 * 输出：3
 * 解释：
 * 最长的等差子序列是 [4,7,10]。
 *
 *
 * 示例 3：
 * 输入：nums = [20,1,15,3,10,5,8]
 * 输出：4
 * 解释：
 * 最长的等差子序列是 [20,15,10,5]。
 *
 *
 *
 *
 * 提示：
 * 2 <= nums.length <= 1000
 * 0 <= nums[i] <= 500
 *
 *
 */

// @lc code=start
class Solution {
public:
    // M1
    int longestArithSeqLengthM1(vector<int>& nums) {
        int maxV = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (int d = -maxV; d <= maxV; d++) {
            vector<int> dp(maxV+1, 0);
            for (auto x : nums) {
                int y = x - d;
                if (y < 0 || y > maxV) {
                    dp[x] = 1;
                } else {
                    dp[x] = dp[y] + 1;
                }
                ans = max(ans, dp[x]);
            }
        }
        return ans;
    }

    // M1V2
    int longestArithSeqLength(vector<int> &nums) {
        int maxV = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (int d = -maxV; d <= maxV; d++) {
            //vector<int> dp(maxV+1, 0);
            unordered_map<int, int> dp;
            for (auto x : nums) {
                int y = x - d;
                if (y < 0 || y > maxV) {
                    dp[x] = 1;
                } else {
                    dp[x] = dp[y] + 1;
                }
                ans = max(ans, dp[x]);
            }
        }
        return ans;
    }

    int longestArithSeqLengthError15_65(vector<int>& nums) {
        int len = nums.size();
        int maxV = *max_element(nums.begin(), nums.end());
        //vector<int> dp(len + 1, 0);
        unordered_map<int, int> val2idx;
        for (int i = 0; i < len; i++) { //只考虑了最右边的下标，不一定对
            val2idx[nums[i]] = i;
        }

        int ans = 0;
        for (int d = -maxV; d <= maxV; d++) {
            vector<int> dp(len, 1);
            for (int i = 0; i < len; i++) {
                int numj = nums[i] - d;
                if (numj < 0 || numj > maxV) {
                    continue;
                }
                if (val2idx.count(numj) == 0) {
                    continue;
                }
                int idxJ = val2idx[numj];
                if (idxJ >= i) {
                    continue;
                }
                dp[i] = dp[idxJ] +1;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }


    // Works
    int longestArithSeqLengthM2(vector<int>& nums) {
        int len = nums.size();
        int maxV = *max_element(nums.begin(), nums.end());
        int minV = *min_element(nums.begin(), nums.end());
        int diff = maxV - minV;
        //vector<int> dp(len + 1, 0);
        unordered_map<int, vector<int>> val2idx;
        for (int i = 0; i < len; i++) {
            val2idx[nums[i]].push_back(i);
        }

        int ans = 0;
        for (int d = -diff; d <= diff; d++) {
            vector<int> dp(len, 1);
            for (int i = 0; i < len; i++) {
                int numj = nums[i] - d;
                if (numj < 0 || numj > maxV) {
                    continue;
                }
                if (val2idx.count(numj) == 0) {
                    continue;
                }
                auto &idxj = val2idx[numj];
                for (auto j : idxj) {
                    if (j >= i) {
                        continue;
                    }
                    dp[i] = max(dp[i], dp[j] +1);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
Wrong Answer
15/65 cases passed (N/A)
Testcase
[44,46,22,68,45,66,43,9,37,30,50,67,32,47,44,11,15,4,11,6,20,64,54,54,61,63,23,43,3,12,51,61,16,57,14,12,55,17,18,25,19,28,45,56,29,39,52,8,1,21,17,21,23,70,51,61,21,52,25,28]
Answer
4
Expected Answer
6

Wrong Answer
10/65 cases passed (N/A)
Testcase
[0,8,45,88,48,68,28,55,17,24]
Answer
3
Expected Answer
2

Wrong Answer
12/65 cases passed (N/A)
Testcase
[24,13,1,100,0,94,3,0,3]
Answer
3
Expected Answer
2

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
