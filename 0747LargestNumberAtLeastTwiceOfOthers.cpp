/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-18
 * @tag array
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
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 *
 * https://leetcode.cn/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (46.85%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    106.3K
 * Total Submissions: 224.7K
 * Testcase Example:  '[3,6,1,0]'
 *
 * 给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
 *
 * 请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [3,6,1,0]
 * 输出：1
 * 解释：6 是最大的整数，对于数组中的其他整数，6 至少是数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,3,4]
 * 输出：-1
 * 解释：4 没有超过 3 的两倍大，所以返回 -1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 50
 * 0 <= nums[i] <= 100
 * nums 中的最大元素是唯一的
 *
 *
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n1 = INT_MIN;
        int idx = -1;
        int n2 = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int& cur = nums[i];
            if (cur >= n1) {
                n2 = n1;
                n1 = cur;
                idx = i;
            } else if (cur >= n2) {
                n2 = cur;
            }
        }
        if (n1 != INT_MIN && (n1 >= 2*n2)) {
            return idx;
        }
        return -1;
    }
};
// @lc code=end


/*
题目有误解
最大数至少是其它数目的两倍大而已，不一定是成倍的关系

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


