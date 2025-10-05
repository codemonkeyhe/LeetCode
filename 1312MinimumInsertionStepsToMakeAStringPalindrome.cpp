/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-05
 * @tag    dynamicProgramming
 * @similar   1312, 2193
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 *
 * https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (69.94%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    46.6K
 * Total Submissions: 65.6K
 * Testcase Example:  '"zzazz"'
 *
 * 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
 * 请你返回让 s 成为回文串的 最少操作次数 。
 * 「回文串」是正读和反读都相同的字符串。
 *
 *
 *
 * 示例 1：
 * 输入：s = "zzazz"
 * 输出：0
 * 解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
 *
 *
 * 示例 2：
 * 输入：s = "mbadm"
 * 输出：2
 * 解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
 *
 *
 * 示例 3：
 * 输入：s = "leetcode"
 * 输出：5
 * 解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 500
 * s 中所有字符都是小写字母。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
                }
            }
        }
        return dp[0][len-1];
    }
};
// @lc code=end

/*
dp[i][j] 表示 s[i..j]变成回文的minInsertCnt
answer = dp[0][Len-1]

if (i>j) dp[i][j] = 0
if (i==j) dp[i][j] = 0
if (i<j)
    case1 s[i]==s[j]
        dp[i][j] = dp[i+1][j-1]
    case2 s[i]!=s[j]
        op1 在s[i]左边插入s[j]，因此消去s[j]
            dp[i][j] = dp[i][j-1] +1
        op2 在s[j]右边插入s[i]，因此消去s[i]
            dp[i][j] = dp[i+1][j] +1
        综合 dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1


不用管初值，自适应
dp[0][0] = 0
dp[i][0] = 0
dp[0][j] = ???

i: len-1 ->0
j: i+1 -> len-1
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
