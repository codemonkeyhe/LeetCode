/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-15
 * @tag   dynamicProgramming
 * @similar   198, 740
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 *
 * https://leetcode.cn/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (60.58%)
 * Likes:    1148
 * Dislikes: 0
 * Total Accepted:    175.5K
 * Total Submissions: 291.6K
 * Testcase Example:  '[3,4,2]'
 *
 * 给你一个整数数组 nums ，你可以对它进行一些操作。
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和
 * nums[i] + 1 的元素。
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [3,4,2]
 * 输出：6
 * 解释：
 * 删除 4 获得 4 个点数，因此 3 也被删除。
 * 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
 *
 *
 * 示例 2：
 * 输入：nums = [2,2,3,3,3,4]
 * 输出：9
 * 解释：
 * 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
 * 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
 * 总共获得 9 个点数。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 2 * 104
 * 1 <= nums[i] <= 104
 *
 *
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxV = *max_element(nums.begin(), nums.end());
        vector<int> val(maxV+1, 0);
        for (auto &v : nums) {
            val[v] += v;
        }
        // 打家劫舍
        // dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        // dp[0] = nums[0]
        // dp[1] = max(nums[0] ,nums[1])
        vector<int> dp(maxV+1, 0);
        dp[0] = val[0];
        dp[1] = max(val[0], val[1]);
        for (int i = 2; i <= maxV; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + val[i]);
        }
        return dp[maxV];
    }
};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
