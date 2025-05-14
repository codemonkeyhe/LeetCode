/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-13
 * @tag binarySearch
 * @similar  1011(same)
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 *
 * https://leetcode.cn/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (60.44%)
 * Likes:    1052
 * Dislikes: 0
 * Total Accepted:    103.8K
 * Total Submissions: 171K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * 给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组，使得这 k 个子数组各自和的最大值 最小。
 * 返回分割后最小的和的最大值。
 * 子数组 是数组中连续的部份。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [7,2,5,10,8], k = 2
 * 输出：18
 * 解释：
 * 一共有四种方法将 nums 分割为 2 个子数组。
 * 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
 * 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 *
 * 示例 2：
 * 输入：nums = [1,2,3,4,5], k = 2
 * 输出：9
 *
 *
 * 示例 3：
 * 输入：nums = [1,4,4], k = 3
 * 输出：4
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= k <= min(50, nums.length)
 *
 *
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        return shipWithinDays(nums, k);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int minV = 0;
        int sumV = 0;
        for (auto val : weights) {
            minV = max(minV, val);
            sumV += val;
        }
        // cout << "minV=" << minV << " sumV=" << sumV << endl;
        int left = minV - 1;
        int right = sumV + 1;
        while (left + 1 < right) {  // 开区间非空 (left, right)
            int mid = left + ((right - left) >> 1);
            if (isBlue(weights, days, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

    bool isBlue(vector<int>& weights, int days, int mid) {
        int costDay = 0;
        for (int i = 0; i < weights.size(); i++) {
            int sum = 0;
            while (i < weights.size() && (sum + weights[i] <= mid)) {
                sum += weights[i];
                i++;
            }
            costDay++;
            i--;
        }
        if (costDay > days) {
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


