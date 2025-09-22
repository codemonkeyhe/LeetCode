/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-20
 * @tag   twoPointers
 * @similar   845, 852, 941
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 *
 * https://leetcode.cn/problems/longest-mountain-in-array/description/
 *
 * algorithms
 * Medium (42.42%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    61.4K
 * Total Submissions: 142.3K
 * Testcase Example:  '[2,1,4,7,3,2,5]'
 *
 * 把符合下列属性的数组 arr 称为 山脉数组 ：
 * arr.length >= 3
 * 存在下标 i（0 < i < arr.length - 1），满足
 *
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 *
 *
 * 给出一个整数数组 arr，返回最长山脉子数组的长度。如果不存在山脉子数组，返回 0 。
 *
 * 示例 1：
 * 输入：arr = [2,1,4,7,3,2,5]
 * 输出：5
 * 解释：最长的山脉子数组是 [1,4,7,3,2]，长度为 5。
 *
 *
 * 示例 2：
 * 输入：arr = [2,2,2]
 * 输出：0
 * 解释：不存在山脉子数组。
 *
 *
 * 提示：
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^4
 *
 *
 *
 *
 * 进阶：
 * 你可以仅用一趟扫描解决此问题吗？
 * 你可以用 O(1) 空间解决此问题吗？
 *
 *
 */

// @lc code=start
class Solution {
public:
    // two pointers
    int longestMountainM1v1(vector<int>& arr) {
        int len = arr.size();
        int maxLen = 0;
        for (int i = 0; i < len-1; i++) {
            while (i < len-1 && arr[i] >= arr[i+1]) {
                i++;
            }
            if (i == len - 1) {
                break;
            }
            // arr[i] < arr[i+1]
            int j = i;
            while (j < len-1 && arr[j] < arr[j+1]) {
                j++;
            }
            if (j == len - 1) {
                break;
            }
            if (j < len-1 && (arr[j] == arr[j+1])) {
                i = j;
                continue;
            }
            // arr[j] > arr[j+1]
            while (j < len-1 && arr[j] > arr[j+1]) {
                j++;
            }
            int curLen = j - i + 1;
            maxLen = max(maxLen, curLen);
            // arr[j] <= arr[j+1]
            i = j - 1;
        }
        return maxLen;
    }


    int longestMountain(vector<int>& arr) {
        int len = arr.size();
        int maxLen = 0;
        for (int i = 0; i < len-1; i++) {
            if (arr[i] >= arr[i+1]) {
                continue;
            }
            // find startPoint
            // arr[i] < arr[i+1]
            int j = i;
            while (j < len-1 && arr[j] < arr[j+1]) {
                j++;
            }
            if (j == len - 1) {
                break;
            }
            if (arr[j] == arr[j + 1]) {
                i = j;
                continue;
            }
            // find peak
            // arr[j] > arr[j+1]
            while (j < len - 1 && arr[j] > arr[j + 1]) {
                j++;
            }
            int curLen = j - i + 1;
            maxLen = max(maxLen, curLen);
            // arr[j] <= arr[j+1]
            i = j - 1;
        }
        return maxLen;
    }
};
// @lc code=end


/*
Wrong Answer
46/75 cases passed (N/A)
Testcase
[2,2,2]
Answer
1
Expected Answer
0

Wrong Answer
58/75 cases passed (N/A)
Testcase
[2,3]
Answer
2
Expected Answer
0

两座山脉的山脚相邻
arr =
[875,884,239,731,723,685]
输出
3
预期结果
4

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
