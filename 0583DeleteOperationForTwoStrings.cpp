/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-01
 * @tag dynamicProgramming
 * @similar   72,  583, 712
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 *
 * https://leetcode.cn/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (67.34%)
 * Likes:    742
 * Dislikes: 0
 * Total Accepted:    208.8K
 * Total Submissions: 304.5K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
 *
 * 每步 可以删除任意一个字符串中的一个字符。
 *
 *
 *
 * 示例 1：
 * 输入: word1 = "sea", word2 = "eat"
 * 输出: 2
 * 解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
 *
 *
 * 示例  2:
 * 输入：word1 = "leetcode", word2 = "etco"
 * 输出：4
 *
 *
 *
 *
 * 提示：
 * 1 <= word1.length, word2.length <= 500
 * word1 和 word2 只包含小写英文字母
 *
 *
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int> > dp(len1+1, vector<int>(len2+1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= len2; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end

/*
dp[i][j] 表示  w1[0..i-1] 和  w2[0...j-1]的删除字符相等后的 minStep

if( w1[i-1] == w2[j-1])
    dp[i][j] = dp[i-1][j-1]

if( w1[i-1] != w2[j-1])
op1 删除 w1[i-1]
    dp[i][j] = dp[i-1][j] + 1
op2 删除 w2[j-1]
    dp[i][j] = dp[i][j-1] + 1
综合
    dp[i][j] =min(dp[i-1][j], dp[i][j-1])  + 1


dp[0][0] = 0
dp[0][j] = len(j)
dp[i][0] = len(i)

answer=dp[len1][len2]

abc  abc
bce   bcee


Wrong Answer
816/1306 cases passed (N/A)
Testcase
"a"
"a"
Answer
1
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
