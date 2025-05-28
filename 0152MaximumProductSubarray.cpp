/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-28
 * @tag dynamicProgramming
 * @similar  53, 152
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode.cn/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (43.20%)
 * Likes:    2442
 * Dislikes: 0
 * Total Accepted:    567.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 *
 * 测试用例的答案是一个 32-位 整数。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 *
 * 示例 2:
 * 输入: nums = [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 *
 *
 * 提示:
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * nums 的任何子数组的乘积都 保证 是一个 32-位 整数
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<int> dpMax(len, 0);
        vector<int> dpMin(len, 0);

        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        for (int i = 1; i < len; i++) {
            dpMax[i] = max({nums[i], nums[i]*dpMax[i-1], nums[i]*dpMin[i-1]});
            dpMin[i] = min({nums[i], nums[i]*dpMax[i-1], nums[i]*dpMin[i-1]});
        }

        return *max_element(dpMax.begin(), dpMax.end());
    }
};
// @lc code=end

/*
 * 输入: nums = [2,3,-2,4]
 2 3 -2 4
 2 3 -2
 2 3
 2

 ErrorThought
 dp[i]表示以nums[i]结尾的乘积最大的子数组
例如
-1 ,2, 3, -2
answer=12
如果以上述DP推导，
dp[2] = 6
dp[3] = max{-2, -2*6} = -2
核心原因 dp[3]不能只是由dp[2]推导出来， nums[3]是负数，需要乘以nums[0]来修正符号
因为会变号，所以还需要维护一个最小值，如果前面有负数，最小值就会包含这种case，因此，

dp[3] = max{-2, -2*6, -2* dp[2]MIN } = max{-2, -2*6, -2* -6} = 12 符合预期

dp一分为2
dpMax[i]表示以nums[i]结尾的乘积最大的子数组
dpMin[i]表示以nums[i]结尾的乘积最小的子数组

dpMax[i] = max{nums[i], nums[i]*dpMax[i-1], nums[i]*dpMin[i-1]}
dpMin[i] = min{nums[i], nums[i]*dpMax[i-1], nums[i]*dpMin[i-1]}

answer = max(dpMax[0...i])

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


