/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-18
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
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode.cn/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (30.70%)
 * Likes:    4025
 * Dislikes: 0
 * Total Accepted:    451.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。
 *
 * 示例 1：
 * 输入：s = "aa", p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 *
 *
 * 示例 2:
 * 输入：s = "aa", p = "a*"
 * 输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 *
 *
 * 示例 3：
 * 输入：s = "ab", p = ".*"
 * 输出：true
 * 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 20
 * 1 <= p.length <= 20
 * s 只包含从 a-z 的小写字母。
 * p 只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isMatchM1(string s, string p) {
        int lenS = s.size();
        int lenP = p.size();
        vector<vector<int>> dp (lenS+1, vector<int>(lenP+1, 0));

        dp[0][0] = 1;
        // dp[i][0] = 0
        // dp[0][j] = 1 when (nums(*) >= nums(.)+nums(a-z))

        int cntStar = 0;
        int cntDot = 0;
        int cntAlp = 0;
        for (int j = 1; j <= lenP; j++) {
            if (p[j-1] == '.') {
                cntDot++;
            } else if (p[j-1] == '*') {
                cntStar++;
            } else {
                cntAlp++;
            }
            if (cntStar >= (cntDot+cntAlp)) {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenP; j++) {
                if (p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    //题目保证，有*时前面必有合法字符，因此必然存在p[j-2]
                    if (p[j-2] == '.') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    } else { // p[j-2] = a-z
                        if (p[j-2] != s[i-1]) {
                            dp[i][j] =  dp[i][j-2];
                        } else {
                            dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                        }
                    }
                } else { // a-z
                    dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        return dp[lenS][lenP];
    }


    bool isMatch(string s, string p) {
        int lenS = s.size();
        int lenP = p.size();
        vector<vector<int>> dp (lenS+1, vector<int>(lenP+1, 0));

        dp[0][0] = 1;
        // dp[i][0] = 0
        // dp[0][j] = 1 when (nums(*) >= nums(.)+nums(a-z))
        /* i == 0 Case 也适用于j=1  把外层for循环去掉，化简如下 */
        for (int j = 1; j <= lenP; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        // dp[0][1] = 0;  still work
        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenP; j++) {
                if (p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    //题目保证，有*时前面必有合法字符，因此必然存在p[j-2]
                    if (p[j-2] == '.') {
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    } else { // p[j-2] = a-z
                        if (p[j-2] != s[i-1]) {
                            dp[i][j] =  dp[i][j-2];
                        } else {
                            dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                        }
                    }
                } else { // a-z
                    dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        return dp[lenS][lenP];
    }
};
// @lc code=end


/*
非法用例
Case1
a
**

Case2
a
* (*不能单独出现 )


dp[i][j] means whether  s[0..i-1] and  p[0..j-1] is wildcard match , 1:match 0:notMatch

Case1 p[j-1] != .|*, 即p[j-1]=a-z
case1.1  s[i-1] == p[j-1]
  dp[i][j] =  dp[i-1][j-1]
case1.2  s[i-1] != p[j-1]
  dp[i][j] =  0
Case1 总结成
  dp[i][j] = (s[i-1]==p[j-1]) && dp[i-1][j-1]

Case2 p[j-1] = .
    s[i-1]只能与.强行匹配，别无选择
   dp[i][j] =  dp[i-1][j-1]

Case3 p[j-1] = *
case3.1 p[j-2]=='.' 即 p=XXXX.*
    不用.*，即*把.干掉， 则有 dp[i][j] =  dp[i][j-2] , 例如(s=a p=a.*)
    用.*，即.*和s[j-1]匹配， 则有 dp[i][j] =  dp[i-1][j] , 例如(s=aaa, p=a.*)
    综上， dp[i][j] = dp[i][j-2] || dp[i-1][j]

case3.2 p[j-2]=='a-z'，即 p=XXXXXa*,
    if (s[i-1] != p[j-2])  s= bbb
        只能用*把p[j-2]干掉
        dp[i][j] = dp[i][j-2]
    if (s[i-1] == p[j-2])  s= aaa [相当于Case3.1]
        OP1 用a*匹配
        dp[i][j] = dp[i-1][j]
        例如(p=bbba*  s=bbbaaa)
        例如(p=bbba*  s=bbbaa)
        例如(p=bbba*  s=bbba)
        注意： 不能是 dp[i][j] = dp[i-1][j-2],因为a*保留继续使用

        OP2 不用a*
        dp[i][j] = dp[i][j-2]
        综上， dp[i][j] = dp[i][j-2] || dp[i-1][j]

case3.3 p[j-2] == '*'
     非法情况，无需考虑

初始值
dp[0][0] = TRUE , 表示 两个空字符串 相匹配
dp[i][0] = False 表示 p为空串，肯定不匹配
dp[0][j]  S为空串，  p[0..j-1]只有*的数量>= .和字母的数量才匹配
例如
a*a*a* 匹配空串
a*.*.* 匹配空串
a*.*.*a 不匹配空串
a*.*. 不匹配空串

此时有两种实现
V1 强行计数统计* . 字母数量
V2 推导
当p[j-1] == "." 或者字母时
dp[0][j]表示 p[0.. j-1]必然不匹配，因为末尾的.和字母 和空串矛盾
当p[j-1] == "*" 时，要与空串匹配，
只有一种情况， *把前面的字符一起干掉
此时有dp[0][j]=dp[0][j-2]
dp[0][1] 表示p[0]与空串是否匹配,p[0]只能是.或者字母，不能是*，所以，必然不匹配
换句话说， dp[0][1]=0



*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
