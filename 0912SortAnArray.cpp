/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-07
 * @tag  sort
 * @similar 215, 912
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode.cn/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (49.20%)
 * Likes:    1134
 * Dislikes: 0
 * Total Accepted:    779.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 * 你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。
 *
 *
 * 示例 1：
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 解释：数组排序后，某些数字的位置没有改变（例如，2 和 3），而其他数字的位置发生了改变（例如，1 和 5）。
 *
 *
 * 示例 2：
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 解释：请注意，nums 的值不一定唯一。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:

    vector<int> sortArrayM1(vector<int>& nums) {
        int len = nums.size();
        auto [minV, maxV] = std::minmax_element(nums.begin(), nums.end());
        int dis = *maxV - *minV + 1;
        int minvv = *minV;
        vector<int> count(dis, 0);
        for (auto& num: nums) {
            count[num - minvv]++;
        }
        for (int i = 0; i < dis-1; i++) {
            count[i+1] += count[i];
        }

        vector<int> res(len, 0);
        for (int i = len - 1; i >= 0; i--) {
            int offset = nums[i] - minvv;
            count[offset]--; //先--,对齐下标0
            int& pos = count[offset];
            res[pos] = nums[i];
        }
        return res;
    }

    // TLE
    vector<int> sortArrayM2(vector<int>& nums) {
        qsort(nums, 0, nums.size()-1);
        return nums;
    }


    void qsort(vector<int>& nums, int left,  int right) {
        if (left >= right) {
            return;
        }
        int pivot = partitions(nums, left, right);
        qsort(nums, left, pivot-1);
        qsort(nums, pivot+1, right);
    }


    int partitions(vector<int>& nums, int left,  int right) {
        int cur = nums[left];
        int i = left;
        int j = right;
        while(i < j) {
            while (i < j && (nums[j] >= cur)) {
                j--;
            }

            while (i < j && (nums[i] <= cur)) {
                i++;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i], nums[left]);
        return i;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> help(n, 0);
        MSort(nums, 0, n - 1, help);
        return nums;
    }

    void MSort(vector<int>& a, int s, int e, vector<int>& help) {
        if (s >= e) {
            return;
        }
        int m = (s + e) >> 1;
        MSort(a, s, m, help);      // 递归左序列
        MSort(a, m + 1, e, help);  // 递归右序列
        MergeV1(a, s, m, e, help);
    }

    void MergeV1(vector<int>& a, int s, int m, int e, vector<int>& help) {
        int i = s;      // 用于遍历 a[s…m]
        int j = m + 1;  // 用于遍历 a[m+1…e]
        int k = s;
        while (i <= m && j <= e) {
            if (a[j] <= a[i])
                help[k++] = a[j++];
            else
                help[k++] = a[i++];
        }
        while (i <= m)
            help[k++] = a[i++];
        while (j <= e)
            help[k++] = a[j++];
        // 将有序的help[s..e]拷贝回a[s..e]
        for (int i = s; i <= e; ++i) {
            a[i] = help[i];
        }
    }
};
// @lc code=end

/*
官方快排解法 一样超时TLE
19 / 21 个通过的测试用例


TLE
[110, 100, 0]

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


