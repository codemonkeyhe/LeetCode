/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-23
 * @tag  array
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
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 *
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (57.25%)
 * Likes:    490
 * Dislikes: 0
 * Total Accepted:    295.2K
 * Total Submissions: 502.1K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
 *
 * 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l ，都有 nums[i] < nums[i + 1] ，那么子序列
 * [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,3,5,4,7]
 * 输出：3
 * 解释：最长连续递增序列是 [1,3,5], 长度为3。
 * 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
 *
 *
 * 示例 2：
 * 输入：nums = [2,2,2,2,2]
 * 输出：1
 * 解释：最长连续递增序列是 [2], 长度为1。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCISM1(vector<int>& nums) {
        int maxLen = 0;
        int len = 1;
        int i = 0;
        int nLen = nums.size();
        while (i < nLen) {
            if (i< nLen-1 && (nums[i] < nums[i+1])) {
                len++;
            } else {
                if (len > maxLen) {
                    maxLen = len;
                }
                len = 1;
            }
            i++;
        }
        return maxLen;
    }

    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 1;
        int len = 1;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] < nums[i+1]) {
                len++;
            } else {
                len = 1;
            }
            if (len > maxLen) {
                maxLen = len;
            }
        }
        return maxLen;
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


