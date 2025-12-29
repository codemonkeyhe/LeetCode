/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-29
 * @tag    prefixSum
 * @similar  325, 525
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=325 lang=cpp
 *
 * [325] 和等于 k 的最长子数组长度
 *
 * https://leetcode.cn/problems/maximum-size-subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (51.46%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 40.2K
 * Testcase Example:  '[1,-1,5,-2,3]\n3'
 *
 * 给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长连续子数组长度。如果不存在任意一个符合要求的子数组，则返回 0。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [1,-1,5,-2,3], k = 3
 * 输出: 4
 * 解释: 子数组 [1, -1, 5, -2] 和等于 3，且长度最长。
 *
 *
 * 示例 2:
 * 输入: nums = [-2,-1,2,1], k = 1
 * 输出: 2
 * 解释: 子数组 [-1, 2] 和等于 1，且长度最长。
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 2 * 10^5
 * -10^4 <= nums[i] <= 10^4
 * -10^9 <= k <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = nums.size();
        vector<long> ps(len+1 ,0);
        for (int i = 0; i < nums.size(); i++) {
            ps[i+1] = ps[i] + nums[i];
        }
        unordered_map<long, int> v2idx;
        int maxLen = 0;
        for (int j = 0; j < ps.size(); j++) {
            if (v2idx.count(ps[j]) == 0) {
                //同样的PS，只存第1个，这样保证最长
                v2idx[ps[j]] = j;
            }
            long want =  ps[j] - k;
            if (v2idx.count(want)) {
                int leftIdx = v2idx[want];
                int len = j - leftIdx;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
// @lc code=end

/*

Sum(i..j) = k
Sum(i..j)= ps[j+1]-ps[i]
len = j-i+1;
findAll Sum(i..j) = k and  maxLen

ps[j+1]-ps[i] = k
means ps[j+1] = k+ps[i] 固定i,查找j，不行。因为从左往右遍历ps
means ps[i] = ps[j+1]-k ; 固定j，查找i，可行


输入: nums = [1,-1,5,-2,3], k = 3

idx 0  1  2  3  4  5
num 1,-1, 5,-2, 3
ps  0  1  0  5  3  6


Runtime Error
35/37 cases passed (N/A)
Error
Line 16: Char 31: runtime error: signed integer overflow: 1147490000 - -1000000000 cannot be represented in type 'int' (solution.cpp)
Line 16: Char 31: runtime error: signed integer overflow: 1147490000 - -1000000000 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
