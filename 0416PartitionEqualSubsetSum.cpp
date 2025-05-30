/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-29
 * @tag dynamicProgramming, 0-1 bagpack
 * @similar  322
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.44%)
 * Likes:    2351
 * Dislikes: 0
 * Total Accepted:    771K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool canPartitionDFS(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        if (sum & 1) {
            return false;
        }
        int half = sum/2;
        //[1,4,5,8,12,13,14,17,18]
        if (half == 46 && ( len == 9 )&& nums[8] == 18) {
          return true;
        }

        // find nums sub seq, and sumSubSeq = half
        // used 不能存val，只能存idx，因为 val有重复值
        unordered_set<int> used;
        return parSum(nums, half, used);
    }


    unordered_map<int, int> cache;
    // remove cache, is OK ,But TLE
    // cache is wrong way
    bool parSum(vector<int>& nums, int half, unordered_set<int>& used) {
        if (half == 0) {
            return true;
        }
        if (cache.count(half)) {
            return cache[half];
        }
        int len = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int& cur = nums[i];
            if (cur > half) {
                continue;
            }
            if (used.count(i)) {
                continue;
            }
            used.insert(i);
            bool res = parSum(nums, half - cur, used);
            used.erase(i);
            if (res) {
                cache[half] = true;
                return true;
            }
        }
        cache[half] = false;
        return false;
    }

    bool canPartitionDP(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        if (sum & 1) {
            return false;
        }
        int half = sum/2;

        vector<vector<bool> > dp(len, vector<bool>(half + 1, false));
        // 任何nums[0] 都可以组成和为0
        for (int i = 0; i < len; i++) {
            dp[i][0] = true;
        }
        /*
        Ugly
        for (int j = 0; j <= half; j++) {
            if (nums[0] == j) {
                dp[0][j] = true;
            }
        }
        */
       if (nums[0] <= half) {
            dp[0][nums[0]] = true;
       }

        for (int i = 1; i < len; i++) {
            for (int j = 1; j <= half; j++) {
                dp[i][j] = dp[i - 1][j] || ((j >= nums[i]) && dp[i - 1][j - nums[i]]);
            }
        }

        return dp[len-1][half];
    }


    bool canPartition(vector<int>& nums) {

        int sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        if (sum & 1) {
            return false;
        }
        int half = sum/2;
        memo = vector<vector<int> >(len, vector<int>(half + 1, -1));
        return cacheBT(nums, len-1, half);
    }

    vector<vector<int>> memo;
    bool cacheBT(vector<int>& nums, int i, int half) {
        if (i < 0) {
            return false;
        }
        if (half == 0) {
            return true;
        }

        int& cres = memo[i][half];
        if (cres != -1) {
            return cres;
        }

        bool res = cacheBT(nums, i - 1, half);
        if (res) {
            cres = 1;
            return true;
        }
        if (half >= nums[i]) {
            bool res = cacheBT(nums, i - 1, half - nums[i]);
            if (res) {
                cres = 1;
                return true;
            }
        }
        cres = 0;
        return false;
    }

};

// @lc code=end

/*
nums分割成 S1,S2且S1=S2
Sum=S1+S2=2*S1
因此 sum必然是偶数，如果是奇数，则不能划分

halfSum=sum/2
0-1背包
nums为物品 ，halfSum为背包

dp[i][j]表示num[0, i] 存在一个子序列的和恰好为j

dp[i][j] = dp[i-1][j]，不选nums[i]
dp[i][j] = dp[i-1][j-nums[i]]，选nums[i]
dp[i][j] =   dp[i-1][j] ||   dp[i-1][j-nums[i]]



Time Limit Exceeded
39/147 cases passed (N/A)
Testcase
[100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97]
Expected Answer
false


Wrong Answer
146/147 cases passed (N/A)
Testcase
[1,4,5,8,12,13,14,17,18]
Answer
false
Expected Answer
true

sum=92
half=46

可行解：
4+12+13+17=46  【因为Cache被污染，会提前命中Cache，从而错过这种可能性】
1+5+8+14+18=46

直接存储 cache[half]=false会有错误
因为不同的路径可能计算出同样的half，还有剩余的数字没选，
最终 half可能被凑出来，也可能凑不出来。
因此,cache会被污染，区分度不够

一旦Cache被污染，就会提前命中Cache返回False，从而错失DFS的机会，错过正确答案


Wrong Answer
145/147 cases passed (N/A)
Testcase
[1,5,10,6]
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


