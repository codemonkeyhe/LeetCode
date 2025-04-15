/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-15
 * @tag array, math
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (51.79%)
 * Likes:    497
 * Dislikes: 0
 * Total Accepted:    143.1K
 * Total Submissions: 276.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,3]
 * 输出：6
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,3,4]
 * 输出：24
 *
 *
 * 示例 3：
 * 输入：nums = [-1,-2,-3]
 * 输出：-6
 *
 *
 *
 *
 * 提示：
 * 3 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    // better version: not use sort find top3 and min2
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int maxV = nums[len-1] * nums[len-2] * nums[len-3];
        int v2 = nums[0]*nums[1]* nums[len-1]; // 2 - 1+
        if (maxV < v2) {
            maxV = v2;
        }
        return maxV;
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


