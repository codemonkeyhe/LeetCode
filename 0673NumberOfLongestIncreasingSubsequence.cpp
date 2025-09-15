/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-12
 * @tag    dynamicProgramming
 * @similar   300, 673
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (44.80%)
 * Likes:    957
 * Dislikes: 0
 * Total Accepted:    128.6K
 * Total Submissions: 281.4K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
 *
 * 注意 这个数列必须是 严格 递增的。
 *
 *
 *
 * 示例 1:
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 *
 *
 * 示例 2:
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 *
 *
 *
 *
 * 提示: 
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 *
 *
 */

// @lc code=start
class Solution {
public:
    // M1v1
    int findNumberOfLISM1v1(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0); //
        vector<int> cnt(len, 1);
        for (int i = 0; i < len; i++) {
            int maxLen = 0;  // CORE STEP, can not use -1
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] > maxLen) {
                        maxLen = dp[j];
                        // CORE STEP
                        cnt[i] = cnt[j];
                    } else if (dp[j] == maxLen) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            dp[i] = maxLen + 1;
            //cout << "XXX i=" << i << " cnt="<< cnt[i] << " dpi=" << dp[i] << endl;
        }

        int lcs = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (dp[i] > lcs) {
                lcs = dp[i];
            }
        }
       // cout << "LCS=" << lcs  << endl;
        for (int i = 0; i < len; i++) {
            if (dp[i] == lcs) {
                ans += cnt[i];
            }
        }
        return ans;
    }


    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0); //
        vector<int> cnt(len, 1);
        for (int i = 0; i < len; i++) {
            int maxLen = 0;  // CORE STEP, can not use -1
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] > maxLen) {
                        maxLen = dp[j];
                        // CORE STEP
                        cnt[i] = cnt[j];
                    } else if (dp[j] == maxLen) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            dp[i] = maxLen + 1;
            //cout << "XXX i=" << i << " cnt="<< cnt[i] << " dpi=" << dp[i] << endl;
        }

        int lcs = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (dp[i] > lcs) {
                lcs = dp[i];
                ans = cnt[i];
            } else if (dp[i] == lcs){
                ans += cnt[i];
            }
        }
       // cout << "LCS=" << lcs  << endl;
        return ans;
    }
};
// @lc code=end

/*
dp[i] 表示 以nums[i]结尾的LCS的长度
dp[i] = max(dp[j]) + 1  ( if (nums[i] > nums[j]))


Wrong Answer
56/223 cases passed (N/A)
Testcase
[2,2,2,2,2]
Answer
0
Expected Answer
5
*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
