/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-14
 * @tag hashmap
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
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode.cn/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (56.55%)
 * Likes:    420
 * Dislikes: 0
 * Total Accepted:    102.3K
 * Total Submissions: 179.9K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
 *
 * 给你一个整数数组 nums ，请你在所有可能的 子序列 中找到最长的和谐子序列的长度。
 *
 * 数组的 子序列 是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,3,2,2,5,2,3,7]
 * 输出：5
 * 解释：
 * 最长和谐子序列是 [3,2,2,2,3]。
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,3,4]
 * 输出：2
 *
 * 解释：
 * 最长和谐子序列是 [1,2]，[2,3] 和 [3,4]，长度都为 2。
 *
 *
 * 示例 3：
 * 输入：nums = [1,1,1,1]
 * 输出：0
 * 解释：
 * 不存在和谐子序列。
 *
 *
 * 提示：
 * 1 <= nums.length <= 2 * 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> n2cnt;
        for (int i = 0; i < nums.size(); i++) {
            n2cnt[nums[i]]++;
        }

        int maxLen = 0;
        for (auto pa : n2cnt) {
            int nextV = pa.first+1;
            if (n2cnt.count(nextV) == 0) {
                continue;
            }
            int cnt = n2cnt[nextV] + pa.second;
            if (cnt > maxLen) {
                maxLen = cnt;
            }
        }
        return maxLen;
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


