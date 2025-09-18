/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-17
 * @tag   dynamicProgramming
 * @similar  10, 44
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode.cn/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (34.02%)
 * Likes:    1200
 * Dislikes: 0
 * Total Accepted:    169.8K
 * Total Submissions: 495.4K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符序列（包括空字符序列）。
 *
 *
 * 判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）。
 *
 *
 *
 *
 * 示例 1：
 * 输入：s = "aa", p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 *
 *
 * 示例 2：
 * 输入：s = "aa", p = "*"
 * 输出：true
 * 解释：'*' 可以匹配任意字符串。
 *
 *
 * 示例 3：
 * 输入：s = "cb", p = "?a"
 * 输出：false
 * 解释：'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 *
 *
 *
 *
 * 提示：
 * 0 <= s.length, p.length <= 2000
 * s 仅由小写英文字母组成
 * p 仅由小写英文字母、'?' 或 '*' 组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    // M1 Works, but too  Complicated
    bool isMatchM1(string s, string p) {
        int lenS = s.size();
        int lenP = p.size();
        vector<vector<int> > dp(lenS, vector<int>(lenP, 0));
        //dp[0][0] =

        if (lenS == 0) {
            for (int j = 0; j < lenP; j++) {
                if (p[j] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (lenP == 0) {
            return false;
        }

        if (p[0] == '*') {
            for (int i = 1; i < lenS; i++) {
                dp[i][0] = 1;
            }
        }

        if ((s[0] == p[0]) || (p[0] == '?') || (p[0] == '*')) {
            dp[0][0] = 1;
        }

        int cntQue = 0;
        int cntStar = 0;
        int cntAlp = 0;
        bool matchOne = false;
        for (int j = 0; j < lenP; j++) {
            if (p[j] == '?') {
                cntQue++;
            } else if (p[j] == '*'){
                cntStar++;
            } else {
                cntAlp++;
                if (p[j] == s[0]) {
                    matchOne = true;
                }
            }
            if (cntAlp == 0 && cntQue == 0 && cntStar == (j+1)) {
                dp[0][j] = 1;
            } else if (cntAlp == 0 && cntQue == 1 && cntStar == (j)) {
                dp[0][j] = 1;
            } else if (cntAlp == 1 && cntQue == 0 && cntStar == (j) &&
                       matchOne) {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < lenS; i++) {
            for (int j = 1; j < lenP; j++) {
                if (p[j] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else { // p[j] is alpabet
                    dp[i][j] = (s[i] == p[j]) && dp[i - 1][j - 1];
                }
            }
        }

        return dp[lenS-1][lenP-1];
    }



     bool isMatch(string s, string p) {
        int lenS = s.size();
        int lenP = p.size();
        vector<vector<int> > dp(lenS+1, vector<int>(lenP+1, 0));
        dp[0][0] = true;
        /* duplicate
        for (int i = 1; i <= lenS; i++) {
            dp[i][0] = 0;
        }
        */
        int cntStar = 0;
        for (int j = 1; j <= lenP; j++) {
            if (p[j-1] == '*'){
                cntStar++;
            }
            if (cntStar == j) {
                dp[0][j] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenP; j++) {
                if (p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                } else { // p[j] is alpabet
                    dp[i][j] = (s[i-1] == p[j-1]) && dp[i - 1][j - 1];
                }
            }
        }
        return dp[lenS][lenP];
    }
};
// @lc code=end

/*
M1
dp[i][j] means whether  s[0..i] and  p[0..j] is wildcard match , 1:match 0:notMatch
answer = dp[lenS-1][lenP-1]

Case1 p[j] != ?|*
case1.1  s[i] == p[j]
  dp[i][j] =  dp[i-1][j-1]
case1.2  s[i] != p[j]
  dp[i][j] =  0

Case1 总结成
  dp[i][j] = (s[i]==p[j]) && dp[i-1][j-1]

Case2 p[j] = ?
    s[i]只能与?强行匹配，别无选择
   dp[i][j] =  dp[i-1][j-1]

Case3 p[j] = *
case3.1 不用*
   dp[i][j] =  dp[i][j-1]

case3.2 使用*
    s[i]与*匹配
   dp[i][j] =  dp[i-1][j]

   不存在 Case3.3 , 即 s[i]与*匹配后，废除掉*，因为这种情况是冗余的，可以由Case3.2的dp[i-1][j]推导出来
   dp[i][j] =  dp[i-1][j-1]


初始值太复杂了，包含了Case 1 Case2 的情况
初始值
dp[0][0] = 1 when (s[0] == p[0] || p[0]=="?/*") | else dp[0][0] = 0
 (i>=1) dp[i][0] = 1  when p[0] = * , else dp[i][0] = 0
 (j>=1) dp[0][j] = 1 when p[0..j] = *** | ****?***  最多只能有1个问号或者s[0],其余全* ｜ 否则 dp[0][j] = 0


Wrong Answer
10/1811 cases passed (N/A)
Testcase
"adceb"
"*a*b"
Answer
false
Expected Answer
true

Runtime Error
11/1811 cases passed (N/A)
Error
Line 1122: Char 9: runtime error: reference binding to null pointer of type 'std::vector<int>' (stl_vector.h)
Line 1122: Char 9: runtime error: reference binding to null pointer of type 'std::vector<int>' (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_vector.h:1131:9
Testcase
""
"******"
Expected Answer
true


M2
dp[i][j] means whether  s[0..i-1] and  p[0..j-1] is wildcard match , 1:match 0:notMatch
answer = dp[lenS][lenP]

Case1 p[j-1] != ?|*
case1.1  s[i-1] == p[j-1]
  dp[i][j] =  dp[i-1][j-1]
case1.2  s[i-1] != p[j-1]
  dp[i][j] =  0

Case1 总结成
  dp[i][j] = (s[i-1]==p[j-1]) && dp[i-1][j-1]

Case2 p[j-1] = ?
    s[i-1]只能与?强行匹配，别无选择
   dp[i][j] =  dp[i-1][j-1]

Case3 p[j-1] = *
case3.1 不用*
   dp[i][j] =  dp[i][j-1]

case3.2 使用*
    s[i-1]与*匹配
   dp[i][j] =  dp[i-1][j]
Case3 总结
   dp[i][j] =  dp[i][j-1] || dp[i-1][j]

初始值
dp[0][0] = TRUE , 表示 两个空字符串 相匹配
dp[i][0] = False 表示 p为空串，肯定不匹配
dp[0][j]  S为空串，  p[0..j-1]只能为全*才匹配


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
