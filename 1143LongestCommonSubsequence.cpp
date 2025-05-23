/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-23
 * @tag  dynamicProgramming
 * @similar   72, 300
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode.cn/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (65.24%)
 * Likes:    1755
 * Dislikes: 0
 * Total Accepted:    634.9K
 * Total Submissions: 952.3K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 * 一个字符串的 子序列
 * 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 *
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
 *
 *
 *
 * 示例 1：
 * 输入：text1 = "abcde", text2 = "ace"
 * 输出：3
 * 解释：最长公共子序列是 "ace" ，它的长度为 3 。
 *
 *
 * 示例 2：
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc" ，它的长度为 3 。
 *
 *
 * 示例 3：
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= text1.length, text2.length <= 1000
 * text1 和 text2 仅由小写英文字符组成。
 *
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequenceV1(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        vector<vector<int> > dp(l1, vector<int>(l2, 0));

        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                if (text1[i] == text2[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    continue;
                }
                int v1 = (i == 0)? 0: dp[i-1][j];
                int v2 = (j == 0) ? 0 : dp[i][j - 1];
                //dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(v1, v2);
            }
        }
        return dp[l1 - 1][l2 - 1];
    }

    int longestCommonSubsequenceV2(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        vector<vector<int> > dp(l1, vector<int>(l2, 0));

        int val = 0;
        for (int i = 0; i < l1; i++) {
            if (text1[i] == text2[0]) {
                val = 1;
            }
            dp[i][0] = val;
        }

        val = 0;
        for (int j = 0; j < l2; j++) {
            if (text1[0] == text2[j]) {
                val = 1;
            }
            dp[0][j] = val;
        }

        for (int i = 1; i < l1; i++) {
            for (int j = 1; j < l2; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    continue;
                }
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[l1 - 1][l2 - 1];
    }

    //  下标偏移+1 Best
    // 旧 dp[i][j] = LCS(text1[0-i], text2[0-j])
    // 新 dp[i][j] = LCS(text1[0 - i-1], text2[0 - j-1])
    int longestCommonSubsequenceV3(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        // i - [0, l1-1]
        // i' = [1, l1] 偏移+1
        vector<vector<int> > dp(l1 + 1, vector<int>(l2 + 1, 0));

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    continue;
                }
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[l1][l2];
    }


    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        memo = vector<vector<int> >(l1, vector<int>(l2, -1));
        return cacheBT(text1, text2, l1-1, l2-1);
    }

    vector<vector<int> > memo;
    int cacheBT(string& text1, string& text2, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        int& cr = memo[i][j];
        if (cr != -1) {
            return cr;
        }

        if (text1[i] == text2[j]) {
            int res = cacheBT(text1, text2, i - 1, j - 1) + 1;
            cr = res;
            return res;
        }
        int v1 = cacheBT(text1, text2, i - 1, j);
        int v2 = cacheBT(text1, text2, i, j - 1);
        int res = max(v1, v2);
        cr = res;
        return res;
    }

};
// @lc code=end

/**
Time Limit Exceeded
17/47 cases passed (N/A)
Testcase
"pmjghexybyrgzczy"
"hafcdqbgncrcbihkd"
Expected Answer
4

加了memo
47/47 cases passed (47 ms)
Your runtime beats 11.21 % of cpp submissions
Your memory usage beats 5.13 % of cpp submissions (27.1 MB)

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


