/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-22
 * @tag prefixSum,hashTable
 * @similar 303,523
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.08%)
 * Likes:    2329
 * Dislikes: 0
 * Total Accepted:    450.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
 *
 * 子数组是数组中元素的连续非空序列。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */

// @lc code=start
class Solution {
public:
      int subarraySumError(vector<int>& nums, int k) {
        int n = nums.size();
        // preSum[i] =  nums[0] + .. nums[i-1]
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        unordered_map<int, int> sum2cnt;
        for (auto& ps: preSum) {
            sum2cnt[ps]++;
        }

       int cnt = 0;
        if (k == 0) {
            for (auto& [sum, m] : sum2cnt) {
                cnt += m - 1;
            }
            return cnt;
        }
        // ErrorLogic  可能得出 S1-S2=1  完全无意义，需要注意preSum的顺序
        for (auto& ps: preSum) {
            if (sum2cnt.count(ps+k)) {
                cnt += sum2cnt[ps + k];
            }
        }
        return cnt;
    }


    int subarraySumM1(vector<int>& nums, int k) {
        int n = nums.size();
        // preSum[i] =  nums[0] + .. nums[i-1]
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        // sum 2 idx
        unordered_map<int, vector<int> > sum2cnt;
        for (int i = 0; i <= n; i++) {
            sum2cnt[preSum[i]].push_back(i);
        }

        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            int& ps = preSum[i];
            if (!sum2cnt.count(ps+k)) {
                continue;
            }
            auto& idxs = sum2cnt[ps + k];
            for (int j = 0; j < idxs.size(); j++) {
                if (idxs[j] > i) { //means idxs from j to end all bigger than i
                    cnt += idxs.size() - j;
                    break;
                }
            }
        }
        return cnt;
      }


    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // preSum[i] =  nums[0] + .. nums[i-1]
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        unordered_map<int, int> sum2cnt;
        int ans = 0;
        for (auto& ps: preSum) {
            ans += sum2cnt[ps - k];
            sum2cnt[ps]++;
        }
        return ans;
    }
};
// @lc code=end

/*
需要保证
PSi + k = PSj, 其中 i< j
或者 PSj - PSi = k 其中 i<j
如果 PS3 - PS5 = k没有意义
PS3 = a0+a1+a2
PS5 = a0+a1+a2+a3+a4
相当于PS3-PS5= -a3-a4 = k ，不符合预期



输入：nums = [1,1,1], k = 2
输出：2


输入：nums = [1,1,-1, 1, 1], k = 2
输出：4
1 1
1 1 -1 1
1 1
1 -1 1 1

<k  moveRight, maybe >=k
>k  moveLeft,  maybe <=k
==k , if next >0, moveLeft,
==k , if next <0, moveRight,


59 / 93 个通过的测试用例
nums = [1]
k = 0
输出
2
预期结果
0


Wrong Answer
63/93 cases passed (N/A)
Testcase
[-1,-1,1]
1
Answer
4
Expected Answer
1

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


