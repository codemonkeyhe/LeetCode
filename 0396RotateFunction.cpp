/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-26
 * @tag   math
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
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 *
 * https://leetcode.cn/problems/rotate-function/description/
 *
 * algorithms
 * Medium (52.76%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    59.5K
 * Total Submissions: 113.2K
 * Testcase Example:  '[4,3,2,6]'
 *
 * 给定一个长度为 n 的整数数组 nums 。
 * 假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：
 * F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
 * 返回 F(0), F(1), ..., F(n-1)中的最大值 。
 *
 * 生成的测试用例让答案符合 32 位 整数。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [4,3,2,6]
 * 输出: 26
 * 解释:
 * F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
 * F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
 * F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
 * F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
 * 所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
 *
 *
 * 示例 2:
 * 输入: nums = [100]
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 * n == nums.length
 * 1 <= n <= 10^5
 * -100 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int lenn = nums.size();
        int sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        int f0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            f0 += i * nums[i];
        }
        int fk = 0;
        int res = f0;
        for (int k = 1; k < nums.size(); k++) {
            fk = f0 + sum - lenn * nums[lenn - k];
            f0 = fk;
            res = max(res, fk);
        }
        return res;
    }
};
// @lc code=end

/*

f(k) = f(k-1) + Sum  - n * nums[n-k]
Sum = nums[0] + ... nums[n-1]

Wrong Answer
3/58 cases passed (N/A)
Testcase
[1,2,3,4,5,6,7,8,9,10]
Answer
285
Expected Answer
330

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
