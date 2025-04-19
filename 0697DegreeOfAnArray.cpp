/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-18
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
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 *
 * https://leetcode.cn/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (59.04%)
 * Likes:    522
 * Dislikes: 0
 * Total Accepted:    110.6K
 * Total Submissions: 187K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。
 *
 * 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,2,3,1]
 * 输出：2
 * 解释：
 * 输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
 * 连续子数组里面拥有相同度的有如下所示：
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,2,3,1,4,2]
 * 输出：6
 * 解释：
 * 数组的度是 3 ，因为元素 2 重复出现 3 次。
 * 所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。
 *
 *
 *
 *
 * 提示：
 * nums.length 在 1 到 50,000 范围内。
 * nums[i] 是一个在 0 到 49,999 范围内的整数。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> ic;
        unordered_map<int, pair<int, int> > idx;
        int maxCnt = -1;
        for (int i = 0; i < nums.size(); i++) {
            ic[nums[i]]++;
            if (ic[nums[i]] > maxCnt) {
                maxCnt = ic[nums[i]];
            }
            if (idx.count(nums[i])) {
                idx[nums[i]].second = i;
            } else {
                idx[nums[i]] = tie(i, i);
            }
        }
        int minS = INT_MAX;
        for (auto [val, cnt] : ic) {
            if (cnt == maxCnt) {
                int dis = idx[val].second -  idx[val].first +1;
                if (dis < minS) {
                    minS = dis;
                }
            }
        }
        return minS;
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


