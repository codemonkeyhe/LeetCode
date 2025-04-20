/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-20
 * @tag
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
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 *
 * https://leetcode.cn/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (39.82%)
 * Likes:    248
 * Dislikes: 0
 * Total Accepted:    100.5K
 * Total Submissions: 250.7K
 * Testcase Example:  '[2,1]'
 *
 * 给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。
 *
 * 让我们回顾一下，如果 arr 满足下述条件，那么它是一个山脉数组：
 *
 *
 * arr.length >= 3
 * 在 0 < i < arr.length - 1 条件下，存在 i 使得：
 *
 * arr[0] < arr[1] < ... arr[i-1] < arr[i]
 * arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：arr = [2,1]
 * 输出：false
 *
 *
 * 示例 2：
 * 输入：arr = [3,5,5]
 * 输出：false
 *
 *
 * 示例 3：
 * 输入：arr = [0,3,2,1]
 * 输出：true
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();
        if (len < 3) {
            return false;
        }

        int i = 0;
        while (i < len - 1 && (arr[i] < arr[i + 1])) {
            i++;
        }
        if (i == 0 || (i == len - 1)) {
            return false;
        }

        while (i < len - 1 && (arr[i] > arr[i + 1])) {
            i++;
        }

        if (i == len - 1) {
            return true;
        }
        return false;
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


