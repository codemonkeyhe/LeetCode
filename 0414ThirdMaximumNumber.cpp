/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-18
 * @tag array, tricky
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode.cn/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (40.29%)
 * Likes:    463
 * Dislikes: 0
 * Total Accepted:    167.6K
 * Total Submissions: 415.7K
 * Testcase Example:  '[3,2,1]'
 *
 * 给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
 *
 *
 *
 * 示例 1：
 * 输入：[3, 2, 1]
 * 输出：1
 * 解释：第三大的数是 1 。
 *
 * 示例 2：
 * 输入：[1, 2]
 * 输出：2
 * 解释：第三大的数不存在, 所以返回最大的数 2 。
 *
 *
 * 示例 3：
 * 输入：[2, 2, 3, 1]
 * 输出：1
 * 解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
 * 此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 104
 * -231 <= nums[i] <= 231 - 1
 *
 *
 * 进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
 *
 */

// @lc code=start
class Solution {
public:
    int thirdMaxM4(vector<int>& nums) {
        long n1 = LONG_MIN;
        long n2 = LONG_MIN;
        long n3 = LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == n1 || nums[i] == n2 || nums[i] == n3) {
                continue;
            }
            if (nums[i] > n1) {
                n3 = n2;
                n2 = n1;
                n1 = nums[i];
            } else if (nums[i] > n2) {
            // < n1, means not max, probably 2nd
                n3 = n2;
                n2 = nums[i];
            } else if (nums[i] > n3) {
                n3 = nums[i];
            }
        }
        if (n3 == LONG_MIN ) {
            return n1;
        }
        return n3;
    }


    int thirdMax(vector<int>& nums) {
        int* n1 = NULL;
        int* n2 = NULL;
        int* n3 = NULL;
        for (int i = 0; i < nums.size(); i++) {
            if ( (n1 && nums[i] == *n1) || (n2 && (nums[i] == *n2)) || (n3 && (nums[i] == *n3))) {
                continue;
            }

            if ((n1 == NULL)  || (nums[i] > *n1)) {
                n3 = n2;
                n2 = n1;
                n1 = &nums[i];
            } else if ( (n2 == NULL) || (nums[i] > *n2)) {
            // < n1, means not max, probably 2nd
                n3 = n2;
                n2 = &nums[i];
            } else if ( (n3 == NULL) || (nums[i] > *n3)) {
                n3 = &nums[i];
            }
        }
        if (n3 == NULL ) {
            return *n1;
        }
        return *n3;
    }

};
// @lc code=end

/*
M1 sort 取第3

M2 第K大的数，分治

M3 连续3次找最大的数，标记前两次最大的数，并且skip


ErrorCase

[1,-2147483648,2]
Expected Answer: -2147483648

[1,1,2]
Expected Answer:  2

[1,2,-2147483648]
Expected Answer: -2147483648

核心点
默认值 INT_MIN 和数值范围重复
解决办法
M4 用 LONG_MIN解决
M5 用指针来解决

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


