/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-12
 * @tag  dynamicProgramming
 * @similar  39,40,216,322,377,518
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 *
 * https://leetcode.cn/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (52.95%)
 * Likes:    1145
 * Dislikes: 0
 * Total Accepted:    271.8K
 * Total Submissions: 505.9K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
 * 题目数据保证答案符合 32 位整数范围。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,3], target = 4
 * 输出：7
 * 解释：
 * 所有可能的组合为：
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 请注意，顺序不同的序列被视作不同的组合。
 *
 *
 * 示例 2：
 * 输入：nums = [9], target = 3
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 1000
 * nums 中的所有元素 互不相同
 * 1 <= target <= 1000
 *
 *
 *
 *
 * 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
 *
 */

// @lc code=start
class Solution {
public:

    // 组合数，顺序不同也算是一种答案，选和不选没考虑顺序
    // 本题本质是是计算排列数目，顺序不同也算一种答案
    /*
    d[i][j]表示 nums[0..i]凑成j的排列数目，
    不选nums[i]， dp[i-1][j]为nums[0..i-1]凑成j的排列数
    选nums[i]， dp[i-1][j-nums[i]]为nums[0..i-1]凑成j-nums[i]的排列数
    但是对于 j-nums[i]的排列数，如何把nums[i]插进去，构成新的排列，则难以找到答案
    因为，得知道每个排列的长度，每个长度中间的空位都可以插入nums[i]，所以这个DP定义错误

    这就是排列和组合的差异，如果是组合数，就不用考虑顺序，
    比如 已知 nums[0 .. i-1]的组合数， 要把nums[i]插进去时，直接放进去末尾就好了

    */
    int combinationSum4DPError(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(target + 1, 0));

        // key step
        dp[0][0] = 1;
        for (int j = 1; j <= target; j++) {
            if (j % nums[0] == 0) {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i]) {
                    dp[i][j] += dp[i-1][j - nums[i]];
                }
                cout << "i=" << i << " j=" << j << " dp=" << dp[i][j] << endl;
            }
        }
        return dp[n-1][target];
    }

    int combinationSum4BT(vector<int>& nums, int target) {
        return cacheBT(nums, target);
    }

    unordered_map<int, int> cache;
    int cacheBT(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }

        if (cache.count(target)) {
            return cache[target];
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int& cur = nums[i];
            if (target < cur) {
                continue;
            }
            res += cacheBT(nums, target - cur);
        }
        cache[target] = res;
        return res;
    }


    // 记忆化搜索翻译成 递推
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        // int 会类型错误
        vector<long> f(target + 1, 0);

        f[0] = 1;
        for (int j = 1; j <= target; j++) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                int& cur = nums[i];
                if (j < cur) {
                    continue;
                }
                res += f[j - cur];
            }
            f[j] = res;
        }
        return f[target];
    }

};
// @lc code=end


/*
d[i][j]表示 nums[0..i]凑成j的排列数目

和DFS一样分析
先用nums[0]，
则 d[i][j-nums[0]]表示 nums[0..i] 凑成 j-nums[0]的方案数，此时，在末尾追加nums[0]
同理，
则 d[i][j-nums[1]]表示 nums[0..i] 凑成 j-nums[1]的方案数，此时，在末尾追加nums[1]


则 d[i][j-nums[i]]表示 nums[0..i] 凑成 j-nums[i]的方案数，此时，在末尾追加nums[i]


上面的推导，说明了位置信息，在末尾轮流尝试nums[k]，变成子问题

因此，d[i][j] = d[i][j-nums[0]] + d[i][j-nums[1]] + .. d[i][j-nums[i]]
发现和i没关系
直接去掉i
因此，d[j] = d[j-nums[0]] + d[j-nums[1]] + .. d[j-nums[i]]
也就是combinationSum4BT2DP的实现

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


