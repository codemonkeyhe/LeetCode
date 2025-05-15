/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-15
 * @tag bfs,dfs
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
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 *
 * https://leetcode.cn/problems/jump-game-iii/description/
 *
 * algorithms
 * Medium (58.58%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    42.7K
 * Total Submissions: 71.8K
 * Testcase Example:  '[4,2,3,0,3,1,2]\n5'
 *
 * 这里有一个非负整数数组 arr，你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i -
 * arr[i]。
 * 请你判断自己是否能够跳到对应元素值为 0 的 任一 下标处。
 * 注意，不管是什么情况下，你都无法跳到数组之外。
 *
 *
 *
 * 示例 1：
 * 输入：arr = [4,2,3,0,3,1,2], start = 5
 * 输出：true
 * 解释：
 * 到达值为 0 的下标 3 有以下可能方案：
 * 下标 5 -> 下标 4 -> 下标 1 -> 下标 3
 * 下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3
 *
 *
 * 示例 2：
 * 输入：arr = [4,2,3,0,3,1,2], start = 0
 * 输出：true
 * 解释：
 * 到达值为 0 的下标 3 有以下可能方案：
 * 下标 0 -> 下标 4 -> 下标 1 -> 下标 3
 *
 *
 * 示例 3：
 * 输入：arr = [3,0,2,1,2], start = 2
 * 输出：false
 * 解释：无法到达值为 0 的下标 1 处。
 *
 *
 *
 *
 * 提示：
 * 1 <= arr.length <= 5 * 10^4
 * 0 <= arr[i] < arr.length
 * 0 <= start < arr.length
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return canReachBT(arr, start);
    }

    unordered_set<int> visited; // avoid deadloop

    // Your runtime beats 5.01 % of cpp submissions
    bool canReachBTV0(vector<int>& nums, int idx) {
        if (idx >= nums.size() || (idx < 0)) {
            return false;
        }
        if (nums[idx] == 0) {
            return true;
        }

        if (visited.count(idx)) { // dup
            return false;
        }
        visited.insert(idx);

        int cur = nums[idx];
        if (idx - cur >= 0) {
            bool leftCan = canReachBT(nums, idx - cur);
            if (leftCan) {
                return true;
            }
        }
        if (idx + cur < nums.size()) {
            bool rightCan = canReachBT(nums, idx + cur);
            if (rightCan) {
                return true;
            }
        }
        return false;
    }

    bool canReachBT(vector<int>& nums, int idx) {
        if (idx >= nums.size() || (idx < 0)) {
            return false;
        }
        if (nums[idx] == 0) {
            return true;
        }

        if (visited.count(idx)) { // dup
            return false;
        }
        visited.insert(idx);

        int cur = nums[idx];
        return (canReachBT(nums, idx - cur) || canReachBT(nums, idx + cur));
    }
};
// @lc code=end


/*
Runtime Error
2/56 cases passed (N/A)
Error
Line 18: Char 19: AddressSanitizer: stack-overflow on address 0x7ffed9966ff8 (pc 0x55de5adbfc5c bp 0x7ffed9967050 sp 0x7ffed9967000 T0)
Line 18: Char 19:
AddressSanitizer:DEADLYSIGNAL
=================================================================
==21==ERROR: AddressSanitizer: stack-overflow on address 0x7ffed9966ff8 (pc 0x55de5adbfc5c bp 0x7ffed9967050 sp 0x7ffed9967000 T0)
...
Testcase
[3,0,2,1,2]
2
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


