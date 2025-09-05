/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-02
 * @tag  twoPointers
 * @similar 367, 633
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 *
 * https://leetcode.cn/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (38.01%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    173.5K
 * Total Submissions: 450.7K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
 *
 *
 *
 * 示例 1：
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 *
 *
 * 示例 2：
 * 输入：c = 3
 * 输出：false
 *
 *
 *
 *
 * 提示：
 * 0 <= c <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<long long> nums;
        //for (int i = 0; i * i <= c; i++) {
        for (long long i = 0; i * i <= c; i++) {
            nums.insert(i*i);
        }
        for (auto& n: nums) {
            if (nums.count(c-n)) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

/*

Runtime Error
98/127 cases passed (N/A)
Error
Line 5: Char 27: runtime error: signed integer overflow: 46341 * 46341 cannot be represented in type 'int' (solution.cpp)
Line 5: Char 27: runtime error: signed integer overflow: 46341 * 46341 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:14:27
Testcase
2147482647
Expected Answer
false
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
