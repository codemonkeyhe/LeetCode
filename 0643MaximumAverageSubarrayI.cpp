/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-15
 * @tag   slideWindow
 * @similar 644
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 *
 * https://leetcode.cn/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (43.13%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    180.8K
 * Total Submissions: 412.2K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * 给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
 *
 * 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
 *
 * 任何误差小于 10^-5 的答案都将被视为正确答案。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,12,-5,-6,50,3], k = 4
 * 输出：12.75
 * 解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 *
 *
 * 示例 2：
 * 输入：nums = [5], k = 1
 * 输出：5.00000
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= k <= n <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    // better: fixed window's size = k
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int len = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;
        while(i < len && j < len) {
            while(j < len) {
                sum+=nums[j];
                j++;
                if (j-i >=k) {
                    break;
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
            sum  = sum - nums[i];
            i++;
        }
        return double(maxSum)/double(k);
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


