/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-19
 * @tag math
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
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 *
 * https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/description/
 *
 * algorithms
 * Easy (70.32%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    91.1K
 * Total Submissions: 129.1K
 * Testcase Example:  '[1,2,3,3]'
 *
 * 给你一个整数数组 nums ，该数组具有以下属性：
 *
 *
 *
 *
 * nums.length == 2 * n.
 * nums 包含 n + 1 个 不同的 元素
 * nums 中恰有一个元素重复 n 次
 *
 *
 * 找出并返回重复了 n 次的那个元素。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,3,3]
 * 输出：3
 *
 *
 * 示例 2：
 * 输入：nums = [2,1,2,5,3,2]
 * 输出：2
 *
 *
 * 示例 3：
 * 输入：nums = [5,1,5,2,5,3,5,4]
 * 输出：5
 *
 *
 *
 * 提示：
 * 2 <= n <= 5000
 * nums.length == 2 * n
 * 0 <= nums[i] <= 10^4
 * nums 由 n + 1 个 不同的 元素组成，且其中一个元素恰好重复 n 次
 *
 *
 */

// @lc code=start
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len-1; i+=2) {
            if (nums[i] != nums[i+1]) {
                continue;
            }
            return nums[i];
        }
        // i == len-1
        if (nums[len-1] == nums[len-3] || (nums[len-1] == nums[len-4])) {
            return  nums[len-1];
        }
        return nums[len-2];
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


