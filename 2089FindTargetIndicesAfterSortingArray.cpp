/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-11
 * @tag binarySearch
 * @similar  744,875
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2089 lang=cpp
 *
 * [2089] 找出数组排序后的目标下标
 *
 * https://leetcode.cn/problems/find-target-indices-after-sorting-array/description/
 *
 * algorithms
 * Easy (77.28%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 34K
 * Testcase Example:  '[1,2,5,2,3]\n2'
 *
 * 给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。
 * 目标下标 是一个满足 nums[i] == target 的下标 i 。
 * 将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增
 * 顺序排列。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,5,2,3], target = 2
 * 输出：[1,2]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 2 的下标是 1 和 2 。
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,5,2,3], target = 3
 * 输出：[3]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 3 的下标是 3 。
 *
 *
 * 示例 3：
 * 输入：nums = [1,2,5,2,3], target = 5
 * 输出：[4]
 * 解释：排序后，nums 变为 [1,2,2,3,5] 。
 * 满足 nums[i] == 5 的下标是 4 。
 *
 *
 * 示例 4：
 * 输入：nums = [1,2,5,2,3], target = 4
 * 输出：[]
 * 解释：nums 中不含值为 4 的元素。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 100
 * 1 <= nums[i], target <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> targetIndicesM1(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>  res;
        int i = 0;
        while (i < nums.size() && (nums[i] != target)) {
            i++;
        }
        while (i < nums.size() && (nums[i] == target)) {
            res.push_back(i);
            i++;
        }
        return res;
    }




    vector<int> targetIndicesM2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        // first >=
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || (*it != target)) {
            return res;
        }
        int idx = it - nums.begin();
        while (idx < nums.size() && (nums[idx] == target)) {
            res.push_back(idx);
            idx++;
        }
        return res;
    }


/*
BlueArea:  [0, left] < target
RedArea:  [right, END] >= target
answer = right or left+1
*/

// find first >=
    int lowerBound(vector<int>& nums, int target) {
        int left = -1;
        int right = nums.size();
        while(left+1 < right) {// 开区间非空
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        // first >=
        //int it = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int it = lowerBound(nums, target);
        if (it == nums.size() || (nums[it] != target)) {
            return res;
        }
        while (it < nums.size() && (nums[it] == target)) {
            res.push_back(it);
            it++;
        }
        return res;
    }


    vector<int> targetIndicesM4(vector<int>& nums, int target) {
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto& val: nums) {
            if (val < target) {
                cnt1++;
            } else if (val == target) {
                cnt2++;
            }
        }
        vector<int> res;
        while (cnt2 > 0) {
            res.push_back(cnt1++);
            cnt2--;
        }
        return res;
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


