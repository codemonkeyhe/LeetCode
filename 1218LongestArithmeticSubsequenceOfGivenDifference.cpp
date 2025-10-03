/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-03
 * @tag        dynamicProgramming
 * @similar     1027, 1218
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 *
 * https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/description/
 *
 * algorithms
 * Medium (50.53%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    63.7K
 * Total Submissions: 128.8K
 * Testcase Example:  '[1,2,3,4]\n1'
 *
 * 给你一个整数数组 arr 和一个整数 difference，请你找出并返回 arr 中最长等差子序列的长度，该子序列中相邻元素之间的差等于
 * difference 。
 *
 * 子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 arr 派生出来的序列。
 *
 *
 *
 * 示例 1：
 * 输入：arr = [1,2,3,4], difference = 1
 * 输出：4
 * 解释：最长的等差子序列是 [1,2,3,4]。
 *
 * 示例 2：
 * 输入：arr = [1,3,5,7], difference = 1
 * 输出：1
 * 解释：最长的等差子序列是任意单个元素。
 *
 *
 * 示例 3：
 * 输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
 * 输出：4
 * 解释：最长的等差子序列是 [7,5,3,1]。
 *
 *
 *
 *
 * 提示：
 * 1 <= arr.length <= 105
 * -104 <= arr[i], difference <= 104
 *
 *
 */

// @lc code=start
class Solution {
public:
    // 用offset解决负值问题
    int longestSubsequenceM1(vector<int>& arr, int difference) {
        int maxV = *max_element(arr.begin(), arr.end());
        int minV = *min_element(arr.begin(), arr.end());
        int offset = 0;
        if (minV < 0) {
            offset = -minV;
        }
        vector<int> dp(maxV + 1 + offset, 0);
        int res = 0;
        for (auto v: arr) {
            int offsetV = v + offset;
            int preV = offsetV - difference;
            if (preV < (minV + offset) || preV > (maxV + offset)) {
                dp[offsetV] = 1;
                continue;
            }
            dp[offsetV] = dp[preV] + 1;
            res = max(dp[offsetV], res);
        }
        return res;
    }

    // 直接用hashmap存储DP
    int longestSubsequenceM2v1(vector<int>& arr, int difference) {
        int maxV = *max_element(arr.begin(), arr.end());
        int minV = *min_element(arr.begin(), arr.end());
        unordered_map<int, int> dp;
        int res = 0;
        for (auto v: arr) {
            int preV = v - difference;
            if (preV < (minV ) || preV > (maxV)) {
                dp[v] = 1;
                continue;
            }
            dp[v] = dp[preV] + 1;
            res = max(dp[v], res);
        }
        return res;
    }

    int longestSubsequence(vector<int> &arr, int difference) {
        unordered_map<int, int> dp;
        int res = 0;
        for (auto v: arr) {
            int preV = v - difference;
            dp[v] = dp[preV] + 1;
            res = max(dp[v], res);
        }
        return res;
    }
};
// @lc code=end

/*
Runtime Error
3/41 cases passed (N/A)
Error
Line 1122: Char 34: runtime error: addition of unsigned offset to 0x504000000090 overflowed to 0x504000000084 (stl_vector.h)
Line 1122: Char 34: runtime error: addition of unsigned offset to 0x504000000090 overflowed to 0x504000000084 (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_vector.h:1131:34
Testcase
[3,4,-3,-2,-4]
-5
Expected Answer
2
*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
