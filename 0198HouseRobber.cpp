/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-14
 * @tag dynamicProgramming
 * @similar   198, 213, 337, 740, 2140, 2560
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode.cn/problems/house-robber/description/
 *
 * algorithms
 * Medium (55.05%)
 * Likes:    3258
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,3,1]'
 *
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 *
 *
 *
 * 示例 1：
 * 输入：[1,2,3,1]
 * 输出：4
 * 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * 示例 2：
 * 输入：[2,7,9,3,1]
 * 输出：12
 * 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> cache;

    int robM1(vector<int>& nums) {
        return robdp(nums, nums.size()-1);
    }

    int robdp(vector<int>& nums, int i) {
        if (i < 0) {
            return 0;
        }
        if (i == 0) {
            return nums[0];
        }
        if (cache.count(i)) {
            return cache[i];
        }

        int maxVal = max(robdp(nums, i-2) + nums[i], robdp(nums, i-1));
        cache[i] = maxVal;
        return maxVal;
    }

    //偏移offset的好处，不用考虑很多边界条件，写起来简单
    // 但是思维较复杂，
    int robOffset2(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len + 2, 0);
        for (int i = 0; i < len; i++) {
            // i = 1, i-2 = -1
            // nums不变， res往右偏移2个单位
            // res[i] = max(res[i-2]+nums[i], res[i-1]);
            res[i + 2] = max(res[i] + nums[i], res[i + 1]);
        }
        // answer= res[LEN-1]，偏移2个单位后，为res[LEN+1]
        return res[len + 1];
    }

    int robNoOffset(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        vector<int> res(len, 0);
        res[0] = nums[0];
        // res[1] = max(res[-1] + nums[1], res[0]);
        res[1] = max(nums[1], nums[0]);
        for (int i = 2; i < len; i++) {
            res[i] = max(res[i - 2] + nums[i], res[i - 1]);
        }
        return res[len - 1];
    }

    int robM1v3(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        //vector<int> res(len, 0);
        //res[0] = nums[0];
        // res[1] = max(res[-1] + nums[1], res[0]);
        int r0 = nums[0];
        int r1 = max(nums[1], nums[0]);
        // 有可能没进入for循环，nums.size=2，则r2就是r1
        int r2 = r1;
        for (int i = 2; i < len; i++) {
           // res[i] = max(res[i - 2] + nums[i], res[i - 1]);
           r2 = max(r0 + nums[i], r1);
           r0 = r1;
           r1 = r2;
        }
        return r2;
    }


    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        vector<int> dp(len, 0);
        dp[len-1] = nums[len-1];
        dp[len-2] = max(nums[len-1], nums[len-2]);

        for (int i = len - 3; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }


};
// @lc code=end

/*
1 2 3 1
1 3 = 4
1 1 = 2
2 1 = 3
Max=1+3=4

V1 从右往左考虑
f(i)表示到第i间房子打劫的最大金额，即nums[0..i]的最大金额
考虑最后一间nums[i]
偷的话， 价值为nums[i]+f(i-2)
不偷的话，价值为f(i-1)
f(i) = max{nums[i]+f(i-2), f(i-1)}
f(0)= max{nums[0]+f(-2), f(-1)} = max{nums[0], 0} = nums[0]
f(1) = max{nums[1]+f(1-2), f(1-1)} = max{nums[1]+f(-1), f{0}} = max{nums[1],
nums[0]}

dp[i] = max(nums[i]+dp[i-2], dp[i-1])


V2 从左往右考虑
dp[i]表示从第i间房子开始打劫,一直到末尾的的最大金额，即nums[i..N-1]的最大金额

偷第i间房子  nums[i]，则金额为  nums[i]+dp[i+2]
不偷第i间房子  nums[i]，则金额为  dp[i+1]

dp[i] = max(nums[i]+dp[i+2], dp[i+1])

i依赖于i+1,i+2, 所以 for i = N-1开始计算
dp[N-1] = max(nums[N-1]+ dp[N-1 +2], dp[N]不存在)  = nums[N-1] + dp[N+1] = nums[N-1]
dp[N-2] = max(nums[N-2]+ dp[N-2 +2], dp[N-2+1])  = max(nums[N-2], nums[N-1])




Runtime Error
2/70 cases passed (N/A)
Error
Testcase
[0]
Expected Answer
0

Wrong Answer
66/70 cases passed (N/A)
Testcase
[1,1]
Answer
0
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


