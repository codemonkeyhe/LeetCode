/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-29
 * @tag  greedy,math
 * @similar  812, 976
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 *
 * https://leetcode.cn/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (57.56%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    96.5K
 * Total Submissions: 167.6K
 * Testcase Example:  '[2,1,2]'
 *
 * 给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回
 * 0。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：nums = [2,1,2]
 * 输出：5
 * 解释：你可以用三个边长组成一个三角形:1 2 2。
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,1,10]
 * 输出：0
 * 解释：
 * 你不能用边长 1,1,2 来组成三角形。
 * 不能用边长 1,1,10 来构成三角形。
 * 不能用边长 1、2 和 10 来构成三角形。
 * 因为我们不能用任何三条边长来构成一个非零面积的三角形，所以我们返回 0。
 *
 *
 *
 * 提示：
 * 3 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
public:
    // Stupid  TLE
    int largestPerimeterV1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                for (int k = j-1; k >= 0; k--) {
                    if (nums[k] + nums[j] > nums[i]) {
                        return (nums[k]+nums[j]+nums[i]);
                    }
                }
            }
        }
        return 0;
    }

    int largestPerimeter(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = len - 1; i >= 2; i--) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return (nums[i - 2] + nums[i - 1] + nums[i]);
            }
        }
        return 0;
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


