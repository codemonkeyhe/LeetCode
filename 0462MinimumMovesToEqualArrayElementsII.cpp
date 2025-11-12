/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-12
 * @tag  math,sort
 * @similar  453, 462
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最小操作次数使数组元素相等 II
 *
 * https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (62.56%)
 * Likes:    328
 * Dislikes: 0
 * Total Accepted:    60.3K
 * Total Submissions: 96K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最小操作数。
 * 在一次操作中，你可以使数组中的一个元素加 1 或者减 1 。
 * 测试用例经过设计以使答案在 32 位 整数范围内。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,3]
 * 输出：2
 * 解释：
 * 只需要两次操作（每次操作指南使一个元素加 1 或减 1）：
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 *
 *
 * 示例 2：
 * 输入：nums = [1,10,2,9]
 * 输出：16
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int minMoves2M1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int middle = nums[nums.size()/2];
        int cnt = 0;
        for (auto num : nums) {
            cnt += abs(num - middle);
        }
        return cnt;
    }

    int minMoves2M2(vector<int>& nums) {
        int lenn = nums.size();
        sort(nums.begin(), nums.end());
        int middle = nums[lenn/2];
        if (lenn%2==0) {
            middle = (nums[lenn / 2] + nums[lenn / 2 - 1]) / 2;
        }
        int cnt = 0;
        for (auto num : nums) {
            cnt += abs(num - middle);
        }
        return cnt;
    }

    int minMoves2(vector<int>& nums) {
        int lenn = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = lenn - 1;
        int cnt = 0;
        while (i < j) {
            cnt += (nums[j] - nums[i]);
            j--;
            i++;
        }
       return cnt;
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
