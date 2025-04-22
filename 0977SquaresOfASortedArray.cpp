/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-21
 * @tag twoPointers,sort
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
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (68.03%)
 * Likes:    1098
 * Dislikes: 0
 * Total Accepted:    836.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 *
 * 示例 2：
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 已按 非递减顺序 排序
 *
 *
 *
 *
 * 进阶：
 * *
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int ltzero = -1;
        int len = nums.size();
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {
            if (nums[i] < 0) {
                ltzero = i;
            }
            nums[i] = nums[i] * nums[i];
        }
        if (ltzero == -1) {
            return nums;
        }
        int i = ltzero;
        int j = ltzero + 1;
        int k = 0;
        while (i >= 0 && j < len) {
            if (nums[i] <= nums[j]) {
                res[k++] = nums[i];
                i--;
            } else {
                res[k++] = nums[j];
                j++;
            }
        }
        while (i >= 0) {
            res[k++] = nums[i--];
        }
        while (j < len) {
            res[k++] = nums[j++];
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


