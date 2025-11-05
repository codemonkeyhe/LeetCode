/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-05
 * @tag   prefixSum,hashTable,math
 * @similar 523, 560
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 *
 * https://leetcode.cn/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (28.83%)
 * Likes:    638
 * Dislikes: 0
 * Total Accepted:    123.6K
 * Total Submissions: 419.7K
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * 给你一个整数数组 nums 和一个整数 k ，如果 nums 有一个 好的子数组 返回 true ，否则返回 false：
 * 一个 好的子数组 是：
 * 长度 至少为 2 ，且
 * 子数组元素总和为 k 的倍数。
 *
 *
 * 注意：
 * 子数组 是数组中 连续 的部分。
 * 如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终 视为 k 的一个倍数。
 *
 *
 *
 *
 * 示例 1：
 * 输入：nums = [23,2,4,6,7], k = 6
 * 输出：true
 * 解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。
 *
 * 示例 2：
 * 输入：nums = [23,2,6,4,7], k = 6
 * 输出：true
 * 解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。
 * 42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
 *
 *
 * 示例 3：
 * 输入：nums = [23,2,6,4,7], k = 13
 * 输出：false
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= sum(nums[i]) <= 2^31 - 1
 * 1 <= k <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySumTLE95_102(vector<int>& nums, int k) {
        int lenn = nums.size();
        vector<int> presum (lenn+1, 0);
        for (int i = 0; i < lenn; i++) {
            presum[i+1] = presum[i] + nums[i];
        }

        for (int i = 0; i < lenn; i++) {
            for (int j = i+1; j < lenn; j++) {
                // subSum(nums, i, j)
                int subSum = presum[j + 1] - presum[i];
                if (subSum%k == 0) {
                    return true;
                }
            }
        }
        return false;
    }


    bool checkSubarraySumM1(vector<int>& nums, int k) {
        int lenn = nums.size();
        vector<int> presum (lenn+1, 0);
        unordered_map<int, set<int>> modIdx;
        for (int i = 0; i < lenn; i++) {
            presum[i+1] = presum[i] + nums[i];
            int mod = presum[i+1]%k;
            modIdx[mod].insert(i+1);
        }
        // KEY STEP
        modIdx[0].insert(0);

        for (auto &[mod, idxs] : modIdx) {
            int smallIdx = *idxs.begin();
            int maxIdx = *idxs.rbegin();
            if (maxIdx - smallIdx >= 2) {
                return true;
            }
        }
       return false;
    }


    bool checkSubarraySum(vector<int>& nums, int k) {
        int lenn = nums.size();
        vector<int> presum (lenn+1, 0);
        unordered_map<int, vector<int>> modIdx;
        for (int i = 0; i < lenn; i++) {
            presum[i+1] = presum[i] + nums[i];
            int mod = presum[i+1]%k;
            modIdx[mod].push_back(i+1);
        }
        // KEY STEP
        modIdx[0].push_back(0);

        for (auto &[mod, idxs] : modIdx) {
            auto [smallIdx, maxIdx] = minmax_element(idxs.begin(), idxs.end());
            if (*maxIdx - *smallIdx >= 2) {
                return true;
            }
        }
       return false;
    }


};
// @lc code=end

/*
    0 1 2
    3 2 4
    0 3 5 9
    ps(i) - ps(i-1) = nums[i-1]

    subSum(i, j) = ps[j+1]  - ps[i] = n*k

    (ps[j+1] - ps[i]) % k = 0
    有 ps[j+1]%k = ps[i]%k





Time Limit Exceeded
95/102 cases passed (N/A)
Testcase
[1617,4991,12564,3903,8881,19078,8583,1717,1829,13921,15174,4107,10415,15481,7904,1991,19477,5030,160,14071,16761,14050,8658,13497,15733,5139,18214,9705,13974,6813,4110,3072,1789,1663,1614,1293,6646,18194,17468,5979,19177,3269,2801,9339,8020,5700,18023,6344,15187,1236,11412,9714,15314,14423,1026,5194,14786,1204,1067,10848,11445,7689,10208,928,10631,16237,11890,15187,13066,488,d16222,12554,15'... 534496 more character
Expected Answer
false

Wrong Answer
90/102 cases passed (N/A)
Testcase
[23,2,4,6,6]
7
Answer
false
Expected Answer
true

*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
