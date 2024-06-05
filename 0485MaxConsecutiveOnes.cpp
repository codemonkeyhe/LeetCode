/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-06-05
 * @tag array;
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 *
 * https://leetcode.cn/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (61.29%)
 * Likes:    437
 * Dislikes: 0
 * Total Accepted:    242.9K
 * Total Submissions: 396.2K
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * 给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,1,0,1,1,1]
 * 输出：3
 * 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 *
 *
 * 示例 2:
 * 输入：nums = [1,0,1,1,0,1]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 10^5
 * nums[i] 不是 0 就是 1.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int i = 0;
        int len = nums.size();
        while(i<len) {
            int cnt = 0;
            while((i<len) && (nums[i] == 1)) {
                i++;
                cnt++;
            }
            if (cnt> maxCnt) {
                maxCnt = cnt;
            }
            i++;
        }

        return maxCnt;
    }
};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1 遍历统计

M2 双指针-负责

*/


