/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-19
 * @tag twoPointers
 * @similar 922
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 *
 * https://leetcode.cn/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (71.11%)
 * Likes:    405
 * Dislikes: 0
 * Total Accepted:    143.6K
 * Total Submissions: 201.2K
 * Testcase Example:  '[3,1,2,4]'
 *
 * 给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。
 *
 * 返回满足此条件的 任一数组 作为答案。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [3,1,2,4]
 * 输出：[2,4,3,1]
 * 解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
 *
 *
 * 示例 2：
 * 输入：nums = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5000
 * 0 <= nums[i] <= 5000
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        int j = len-1;
        while (i<j) {
            while (i < len && (nums[i] % 2 == 0)) {
                i++;
            }

            while (j > 0 && (nums[j] % 2 == 1)) {
                j--;
            }
            if (i>=j) {
                break;
            }
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return nums;
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


