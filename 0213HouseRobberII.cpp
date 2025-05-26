/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-24
 * @tag  dynamicProgramming
 * @similar   198, 213, 337, 2560
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode.cn/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (45.01%)
 * Likes:    1700
 * Dislikes: 0
 * Total Accepted:    491.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * 示例 3：
 * 输入：nums = [1,2,3]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    int robM1(vector<int>& nums) {
        //return cacheBT(nums, 0, nums.size()-1);

        int len = nums.size();
        int j = len - 1; // the last house
        // 偷最后一间（且不能偷第0间） 或者不偷最后一间
        int maxVal = max(
            cacheBT2(nums, 1, j - 2) + nums[j],
            cacheBT2(nums, 0,
                     j - 1));
        return maxVal;
    }

    unordered_map<int, int> cache;

    // cacheBT(nums, i, j) 表示偷取  nums[i...j] 的最高金额，算是区间DP
    int cacheBT(vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        }
        if (i > j) {
            return 0;
        }
        int key = i * 100 + j;
        if (cache.count(key)) {
            return cache[key];
        }
        if (i == 0 && (j == nums.size() - 1)) { //只有入口时调用一次
            int maxVal = max(cacheBT(nums, 1, j - 2) + nums[j], cacheBT(nums, 0,  j - 1));  //偷最后一间（且不能偷第0间） 或者不偷最后一间
            cache[key] = maxVal;
            return maxVal;
        }

        int maxVal = max(cacheBT(nums, i, j - 2) + nums[j], cacheBT(nums, i, j - 1));
        cache[key] = maxVal;
        return maxVal;
    }

   // cacheBT(nums, i, j) 表示偷取  nums[i...j] 的最高金额，算是区间DP
   // 其实 i没动，纯粹是上层调用区分起点需要
    int cacheBT2(vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        }
        if (i > j) {
            return 0;
        }
        int key = i * 100 + j;
        if (cache.count(key)) {
            return cache[key];
        }
        int maxVal =
            max(cacheBT2(nums, i, j - 2) + nums[j], cacheBT2(nums, i, j - 1));
        cache[key] = maxVal;
        return maxVal;
    }


    int rob(vector<int>& nums) {
        int len = nums.size();
        int j = len - 1;
        //int maxVal = max(robDP(nums, 1, j-2) + nums[j], robDP(nums, 0, j-1));
        //int maxVal = max(robDPV2(nums, 1, j-2) + nums[j], robDPV2(nums, 0, j-1));
        int maxVal = max(robDPV3(nums, 1, j-2) + nums[j], robDPV3(nums, 0, j-1));
        return maxVal;
    }


    // dp[i][j] = max(dp[i][j-2] + nums[j],   dp[i][j-1])  , i ,j - [0, len-1]
    // ij必须偏移+2,DP偏移，nums不变
    // dp[i+2][j+2] = max(dp[i+2][j] + nums[j],   dp[i+2][j+1])  , i,j  - [0, len-1]
    int robDP(vector<int>& nums, int left, int right) {
        int len = nums.size();
        if (left > right) {
            return 0;
        }
        vector<vector<int> > dp(len+2, vector<int>(len+2, 0));
        //dp[0][0] == nums[0];
        //dp[0][1] == max(dp[0][-1]+nums[1], dp[0][0]);
        //dp[0][1] == max(nums[1], nums[0]);
        for (int i = left; i <= right; i++) {
            for (int j = i; j <= right; j++) {
                if (i == j) {
                    dp[i+2][j+2] = nums[i];
                    continue;
                }
                dp[i+2][j+2] = max(dp[i+2][j] + nums[j], dp[i+2][j+1]);
            }
        }
        return dp[left+2][right+2];
    }

    int robDPV2(vector<int>& nums, int left, int right) {
        int len = nums.size();
        if (left > right) {
            return 0;
        }
        vector<int> dp(len + 2);
        for (int j = left; j <= right; j++) {
            dp[j + 2] = max(dp[j] + nums[j], dp[j + 1]);
        }
        return dp[right+2];
    }


    int robDPV3(vector<int>& nums, int left, int right) {
        int len = nums.size();
        if (left > right) {
            return 0;
        }
        //vector<int> dp(len + 2);
        int v0 = 0;
        int v1 = 0;
        int v2 = 0;
        for (int j = left; j <= right; j++) {
            //dp[j + 2] = max(dp[j] + nums[j], dp[j + 1]);
            v2 = max(v0 + nums[j], v1);
            v0 = v1;
            v1 = v2;
        }
        return v2;
    }

};
// @lc code=end

/*
Time Limit Exceeded
62/75 cases passed (N/A)
Testcase
[114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240]
Expected Answer
4077


Runtime Error
3/75 cases passed (N/A)
Error
Testcase
[0]
Expected Answer
0

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


