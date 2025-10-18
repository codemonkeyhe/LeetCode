/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-18
 * @tag    array
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
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 *
 * https://leetcode.cn/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (27.93%)
 * Likes:    813
 * Dislikes: 0
 * Total Accepted:    118.8K
 * Total Submissions: 422.5K
 * Testcase Example:  '[4,2,3]'
 *
 * 给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
 *
 * 我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [4,2,3]
 * 输出: true
 * 解释: 你可以通过把第一个 4 变成 1 来使得它成为一个非递减数列。
 *
 *
 * 示例 2:
 * 输入: nums = [4,2,1]
 * 输出: false
 * 解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 *
 *
 *
 *
 * 提示：
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        int cnt = 0;
        int peak = 0;
        for (int i = 0; i < len-1; i++) {
            if (nums[i] > nums[i+1]) {
                cnt++;
                peak = i;
            }
        }
        // ERROR return (cnt == 1);
        if (cnt >= 2) {
            return false;
        }
        if (peak == 0) {
            return true;
        }
        // ignore lowerPoint
        if (peak + 2 >= len) {
            return true;
        }
        if ((peak + 2 < len) && nums[peak] <= nums[peak + 2]) {
            return true;
        }
        // ignore peakpoint
        if ((peak + 1 < len) && nums[peak - 1] <= nums[peak + 1]) {
            return true;
        }
        return false;
    }
};
// @lc code=end

/*
Wrong Answer
293/335 cases passed (N/A)
Testcase
[3,4,2,3]
Answer
true
Expected Answer
false

Runtime Error
6/335 cases passed (N/A)
Error
Line 1122: Char 34: runtime error: addition of unsigned offset to 0x502000000410 overflowed to 0x502000000408 (stl_vector.h)
Line 1122: Char 34: runtime error: addition of unsigned offset to 0x502000000410 overflowed to 0x502000000408 (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_vector.h:1131:34
Testcase
[1]
Expected Answer
true


Wrong Answer
323/335 cases passed (N/A)
Testcase
[5,7,1,8]
Answer
false
Expected Answer
true


[5,7,1,8]
Case1 [5,7,7,8]
increase nums[P+1]; ignore lowerPoint

[5,7,6,8]
Case1 [5,6,6,8]
decrease nums[P]; ignore PeakPoint


[5,7,1,2]
false  two points < peak



origin: 1 2 3 3 3  4

TrueCase1
1, 2, 3, 1000,  3, 3,  4

TrueCase2
1 2 3 -1000  3 3  4



Wrong Answer
332/335 cases passed (N/A)
Testcase
[1,2,4,5,3]
Answer
false
Expected Answer
true


[1,2,4,5,3]
Peak=5

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
