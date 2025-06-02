/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-01
 * @tag dynamicProgramming
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
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode.cn/problems/target-sum/description/
 *
 * algorithms
 * Medium (48.28%)
 * Likes:    2139
 * Dislikes: 0
 * Total Accepted:    556.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给你一个非负整数数组 nums 和一个整数 target 。
 * 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
 * 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
 * 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,1,1,1,1], target = 3
 * 输出：5
 * 解释：一共有 5 种方法让最终目标和为 3 。
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * 示例 2：
 * 输入：nums = [1], target = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWaysDP(vector<int>& nums, int target) {
        int sum = 0;
        for (auto& val: nums) {
            sum += val;
        }
        int s1 = (target+sum);
        if ((s1 & 1) || (s1 < 0)) { // key step
            return 0;
        }
        s1 >>= 1;

        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int>(s1 + 1, 0));
        // key step
        dp[0][0] = 1;
        for (int i = 1; i <= len; i++) {
            int& cur = nums[i - 1];
            for (int j = 0; j <= s1; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= cur) {
                    dp[i][j] += dp[i - 1][j - cur];
                }
            }
        }
        return dp[len][s1];
    }


    // backtracing
    int findTargetSumWays(vector<int>& nums, int target) {
        int res= 0;
        bt(nums, target,0, 0, res);
        return res;
    }


    void bt(vector<int>& nums, int target, int idx, int sum, int& res) {
        if (idx >=  nums.size()) {
            if (sum == target) {
                res++;
            }
            return;
        }

        int& cur = nums[idx];

        bt(nums, target, idx + 1, sum + cur, res);

        bt(nums, target, idx + 1, sum - cur, res);
    }
};
// @lc code=end

/*
sum{+a1,+a2,..ak} = S1
sum{Am,Am+1,..An} = S2  (S2>0) 添加-号
S1-S2=target
S1+S2=TotalSum
2*S1=target+TotalSum
S1=(targt+TotalSum)/2
从nums中选取N个数，使得和为S1
0-1背包
背包容量是S1
物品是nums
dp[i][j] 表示 nums[0...i]的目标和为j的种类数目


Wrong Answer
113/141 cases passed (N/A)
Testcase
[1]
2
Answer
1
Expected Answer
0


Runtime Error
138/141 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::length_error'
terminate called after throwing an instance of 'std::length_error'
  what():  cannot create std::vector larger than max_size()
Testcase
[100]
-200
Expected Answer
0
*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


