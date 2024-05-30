/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-28
 * @tag array
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=163 lang=cpp
 *
 * [163] 缺失的区间
 *
 * https://leetcode.cn/problems/missing-ranges/description/
 *
 * algorithms
 * Easy (36.02%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 60.8K
 * Testcase Example:  '[0,1,3,50,75]\n0\n99'
 *
 * 给你一个闭区间 [lower, upper] 和一个 按从小到大排序 的整数数组 nums ，其中元素的范围在闭区间 [lower, upper]
 * 当中。
 *
 * 如果一个数字 x 在 [lower, upper] 区间内，并且 x 不在 nums 中，则认为 x 缺失。
 *
 * 返回 准确涵盖所有缺失数字 的 最小排序 区间列表。也就是说，nums 的任何元素都不在任何区间内，并且每个缺失的数字都在其中一个区间内。
 *
 *
 * 示例 1：
 * 输入: nums = [0, 1, 3, 50, 75], lower = 0 , upper = 99
 * 输出: [[2,2],[4,49],[51,74],[76,99]]
 * 解释：返回的区间是：
 * [2,2]
 * [4,49]
 * [51,74]
 * [76,99]
 *
 * 示例 2：
 * 输入： nums = [-1], lower = -1, upper = -1
 * 输出： []
 * 解释： 没有缺失的区间，因为没有缺失的数字。
 *
 *
 *
 * 提示：
 * -10^9 <= lower <= upper <= 10^9
 * 0 <= nums.length <= 100
 * lower <= nums[i] <= upper
 * nums 中的所有值 互不相同
 *
 *
 */

// @lc code=start
class Solution {
public:
    // M1
    vector<vector<int>> findMissingRangesM1(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len == 0) {
            vector<int> rg = {lower, upper};
            res.push_back(rg);
            return res;
        }

        // first range
        int first = nums[0];
        if (first != lower) {
            vector<int> rg = {lower, first - 1};
            res.push_back(rg);
        }

        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            if (cur == (nums[i - 1] + 1)) {
                continue;
            }
            int left = nums[i - 1] + 1;
            int right = cur - 1;
            vector<int> rg = {left, right};
            res.push_back(rg);
        }
        // last range
        if ((len > 0) && nums[len - 1] != upper && (lower != upper)) {
            vector<int> rg = {nums[len - 1] + 1, upper};
            res.push_back(rg);
        }
        return res;
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


