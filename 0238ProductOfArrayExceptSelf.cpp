/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-04
 * @tag prefixSum
 * @similar  152
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode.cn/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (75.60%)
 * Likes:    1791
 * Dislikes: 0
 * Total Accepted:    456.3K
 * Total Submissions: 602.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 *
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
 *
 * 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]
 *
 *
 * 示例 2:
 * 输入: nums = [-1,1,0,-3,3]
 * 输出: [0,0,9,0,0]
 *
 *
 *
 *
 * 提示：
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
 *
 *
 *
 *
 * 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelfV1(vector<int>& nums) {
        int len = nums.size();
        vector<int> pre(len+1, 0);
        vector<int> suf(len+2, 0);
        pre[0] = 1;
        suf[len] = 1;
        for (int i = 1; i < len; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for (int i = len - 1; i > 0; i--) {
            suf[i] = nums[i] * suf[i + 1];
        }
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {
            // pre move right 1 offset ,so i-1  equal i
            res[i] = pre[i] * suf[i+1];
        }
        return res;
    }

    vector<int> productExceptSelfV2(vector<int>& nums) {
        int len = nums.size();
        vector<int> pre(nums);
        vector<int> suf(nums);
        for (int i = 1; i < len; i++) {
            pre[i] = pre[i - 1] * pre[i];
        }
        for (int i = len - 2; i > 0; i--) {
            suf[i] = suf[i] * suf[i + 1];
        }
        vector<int> res(len, 0);
        for (int i = 0; i < len; i++) {
            // pre move right 1 offset ,so i-1  equal i
            int left = (i < 1) ? 1: pre[i-1];
            int right = (i >= len -1) ? 1 : suf[i + 1];
            res[i] = left * right;
        }
        return res;
    }


    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> pre(nums);
        vector<int> suf(nums);
        for (int i = 1; i < len; i++) {
            pre[i] = pre[i - 1] * pre[i];
        }
        for (int i = len - 2; i > 0; i--) {
            suf[i] = suf[i] * suf[i + 1];
        }
        vector<int> res(len, 0);
        res[0] = suf[1];
        res[len - 1] = pre[len - 2];
        for (int i = 1; i < len -1; i++) {
            res[i] = pre[i-1] * suf[i+1];
        }
        return res;
    }
};
// @lc code=end

/*
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]

      1 2 3 4

pre 1 1 2  6 24
suf 1 24 12 4 1

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


