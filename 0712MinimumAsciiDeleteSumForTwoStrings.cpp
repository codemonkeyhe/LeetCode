/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-24
 * @tag  dynamicProgramming
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
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 *
 * https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (70.45%)
 * Likes:    441
 * Dislikes: 0
 * Total Accepted:    64.9K
 * Total Submissions: 89K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。
 *
 * 示例 1:
 * 输入: s1 = "sea", s2 = "eat"
 * 输出: 231
 * 解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
 * 在 "eat" 中删除 "t" 并将 116 加入总和。
 * 结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
 *
 *
 * 示例 2:
 * 输入: s1 = "delete", s2 = "leet"
 * 输出: 403
 * 解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
 * 将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
 * 结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
 * 如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
 *
 *
 *
 *
 * 提示:
 * 0 <= s1.length, s2.length <= 1000
 * s1 和 s2 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:

    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= len1; i++) {
            dp[i][0] = dp[i - 1][0] + int(s1[i - 1]);
        }

        for (int j = 1; j <= len2; j++) {
            dp[0][j] = dp[0][j-1] + int(s2[j - 1]);
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + int(s1[i - 1]), dp[i][j - 1] + int(s2[j - 1]));
                }
            }
        }
        return dp[len1][len2];
    }

};
// @lc code=end

/*
输入: s1 = "delete", s2 = "leet"
输出: 403
解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417
的结果，比答案更大。

delete
leet

dp[i][j]表示 s1[0..i]与s2[0..j]删除若干字符后的相等的最小ASCII删除和

case1
s1[i] == s2[j]   demo: (abc ,adc)  = (ab, ad)
不用删除，两个字符相等
dp[i][j] = dp[i-1][j-1]

case2
s1[i] != s2[j]  (abdc, abd) =>(abd, abd)
OP1 删除s1[i]
dp[i][j] = dp[i-1][j] + ASCII(i)


op2 删除s2[j]    (abc, abcd) =>(abc, abc)
dp[i][j] = dp[i][j-1] + ASCII(j)

OP3 同时删除s1[i] 和  s2[j]
dp[i][j] = dp[i-1][j-1]  + ASCII(i) + ASCII(j)
(冗余case，因为op1和op2会覆盖这种情况)
  (abc, abcd) =>(ab, abc)

dp[i][j] = min(dp[i-1][j]+ASCII(i) ,  dp[i][j-1]+ASCII(j) )

dp[0][0] = 0 if(s1[0] == s2[0])
 dp[0][0] =  min(ascii(s1[0]), ascii(s2[0]))

 dp[i][0] = 不好搞
 case abcd  d  => (abc, emptyStr) =>( ascii(a+b+c))
 case abcd  b  => (abc, b) or  (abcd, emptyStr) => ( ascii(a+b+c))

 当初值不好搞时，修正DP

dp[i][j]表示 s1[0..i-1]与s2[0..j-1]删除若干字符后的相等的最小ASCII删除和

case1
s1[i-1] == s2[j-1]
dp[i][j] = dp[i-1][j-1]

case2
s1[i-1] != s2[j-1]  (abdc, abd) =>(abd, abd)
dp[i][j] = min(dp[i-1][j]+ASCII(i-1) ,  dp[i][j-1]+ASCII(j-1) )

初值
dp[0][0] =  (empstrS1, empstrS2) = 0
dp[i][0]  = sumAscii(i)
dp[0][j]  = sumAscii(j)

answer=dp[lenS1][lenS2]





*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
