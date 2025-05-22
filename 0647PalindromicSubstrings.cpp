/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-22
 * @tag dynamicProgramming
 * @similar  5, 516
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (67.34%)
 * Likes:    1439
 * Dislikes: 0
 * Total Accepted:    393.7K
 * Total Submissions: 578.8K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 *
 * 回文字符串 是正着读和倒过来读一样的字符串。
 *
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 *
 *
 *
 * 示例 1：
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 *
 *
 * 示例 2：
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    // d[i][j]=1 means s.substr(i, j-i+1)  is a palindrome
    int countSubstringsM1(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] != s[j]) {
                    //dp[i][j] = 0;
                    continue;
                }
                // s[i] == s[j]
                if (i + 1 >= j) {  // means i ==j or i+1 ==j
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }


    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += expand(s, i, i);
            res += expand(s, i, i+1);
        }
        return res;
    }

    int expand(string& s, int i, int j) {
        int n = s.size();
        int ans = 0;
        while ((i >= 0) && (j < n) && (s[i] == s[j])) {
            i--;
            j++;
            ans++;
        }
        return ans;
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


