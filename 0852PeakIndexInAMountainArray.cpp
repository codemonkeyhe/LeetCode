/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-12
 * @tag binarySearch
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
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 *
 * https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Medium (68.40%)
 * Likes:    446
 * Dislikes: 0
 * Total Accepted:    187.2K
 * Total Submissions: 274.6K
 * Testcase Example:  '[0,1,0]'
 *
 * 给定一个长度为 n 的整数 山脉 数组 arr ，其中的值递增到一个 峰值元素 然后递减。
 *
 * 返回峰值元素的下标。
 *
 * 你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。
 *
 *
 *
 * 示例 1：
 * 输入：arr = [0,1,0]
 * 输出：1
 *
 *
 * 示例 2：
 * 输入：arr = [0,2,1,0]
 * 输出：1
 *
 *
 * 示例 3：
 * 输入：arr = [0,10,5,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 3 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^6
 * 题目数据 保证 arr 是一个山脉数组
 *
 *
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (arr[mid] < arr[mid+1]) {
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        return left;
    }
};
// @lc code=end

/*

 * 输入：arr = [0,10,5,2]
 * 输出：1
 *
 *

arr[i]  < arr[i+1] peakIdx  > i
arr[i]  > arr[i+1] peakIdx  <= i , maybe i is peakIdx


blueArea: [intMIN, left)   arr[i] < arr[i+1]
redArea: (right, intMAX]  arr[i] >= arr[i+1]
answer= right+1 or left



*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


