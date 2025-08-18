/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-18
 * @tag dynamicProgramming, monotonicQueue
 * @similar 53, 152, 918
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-circular-subarray/description/
 *
 * algorithms
 * Medium (41.91%)
 * Likes:    814
 * Dislikes: 0
 * Total Accepted:    119.3K
 * Total Submissions: 264.8K
 * Testcase Example:  '[1,-2,3,-2]'
 *
 * 给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。
 *
 * 环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i]
 * 的前一个元素是 nums[(i - 1 + n) % n] 。
 *
 * 子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j]
 * ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,-2,3,-2]
 * 输出：3
 * 解释：从子数组 [3] 得到最大和 3
 *
 *
 * 示例 2：
 * 输入：nums = [5,-3,5]
 * 输出：10
 * 解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
 *
 *
 * 示例 3：
 * 输入：nums = [3,-2,2,-3]
 * 输出：3
 * 解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
 *
 *
 *
 *
 * 提示：
 * n == nums.length
 * 1 <= n <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4​​​​​​​
 *
 *
 */

// @lc code=start
class Solution {
public:
    // M1 转为最小子数组和
    int maxSubarraySumCircularM1v1(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        vector<int> mp(len, 0);
        dp[0] = nums[0];
        mp[0] = nums[0];
        int sumS = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            mp[i] = min(nums[i], mp[i - 1] + nums[i]);
            sumS += nums[i];
        }
        int maxV = *max_element(dp.begin(), dp.end());
        int minV = *min_element(mp.begin(), mp.end());
        if (minV == sumS) {
            return maxV;
        }
        return max(maxV, sumS - minV);
    }

    // M1v2
    int maxSubarraySumCircularM1v2(vector<int>& nums) {
        int len = nums.size();
        int maxS = nums[0];
        int minS = nums[0];
        int sumS = nums[0];
        int maxV = maxS;
        int minV = minS;
        for (int i = 1; i < len; i++) {
            maxS = max(nums[i], maxS + nums[i]);
            maxV = max(maxV, maxS);
            minS = min(nums[i], minS + nums[i]);
            minV = min(minV, minS);
            sumS += nums[i];
        }
        if (minV == sumS) {
            return maxV;
        }
        return max(maxV, sumS - minV);
    }

    // M2 固定后缀  寻找最大前缀和
    int maxSubarraySumCircular(vector<int>& nums) {
        //Case1 sameas LC53
        int len = nums.size();
        int maxS = nums[0];
        int maxV = maxS;
        vector<int> prefixSum(len, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < len; i++) {
            maxS = max(nums[i], maxS + nums[i]);
            maxV = max(maxV, maxS);
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        //Case2 MMS跨越首尾两端
        // preSumMax[i] = max{ prefixSum[0], .... prefixSum[i]} ,即范围[0..i]内的最大的前缀和
        vector<int> preSumMax(len, 0);
        preSumMax[0] = prefixSum[0];
        for (int i = 1; i < len; i++ ) {
            preSumMax[i] = max(preSumMax[i-1],  prefixSum[i]);
        }

        int rightSum = 0;
        int maxV2 = INT_MIN;
        for (int i = len - 1; i > 0; i--) {
            rightSum += nums[i];
            int total = rightSum + preSumMax[i-1];
            maxV2 = max(maxV2, total);
        }

        return max(maxV, maxV2);
    }




};
// @lc code=end

/*
M1 最大和 最小和
dp[i] 是以nums[i]结尾的MaxSubarraySum
dp[i] = max{nums[i], dp[i-1]+nums[i]}
dp[0] = nums[0]
maxV = max{dp[0..N-1]}


mp[i] 是以nums[i]结尾的MinSubarraySum
mp[i] = min{nums[i], mp[i-1]+nums[i]}
mp[0] = nums[0]
minV = min{mp[0..N-1]}

answer = max{maxV, SumS - minV}



忽略了minV==SumS的情况
Wrong Answer
107/112 cases passed (N/A)
Testcase
[-3,-2,-3]
Answer
0
Expected Answer
-2

*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
