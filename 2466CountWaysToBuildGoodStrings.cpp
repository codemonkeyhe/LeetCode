/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-29
 * @tag         dynamicProgramming
 * @similar    70, 2466
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 *
 * https://leetcode.cn/problems/count-ways-to-build-good-strings/description/
 *
 * algorithms
 * Medium (49.35%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    38.4K
 * Total Submissions: 78.4K
 * Testcase Example:  '3\n3\n1\n1'
 *
 * 给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：
 *
 *
 * 将 '0' 在字符串末尾添加 zero  次。
 * 将 '1' 在字符串末尾添加 one 次。
 *
 *
 * 以上操作可以执行任意次。
 * 如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为 好 字符串。
 *
 * 请你返回满足以上要求的 不同 好字符串数目。由于答案可能很大，请将结果对 10^9 + 7 取余 后返回。
 *
 *
 *
 * 示例 1：
 * 输入：low = 3, high = 3, zero = 1, one = 1
 * 输出：8
 * 解释：
 * 一个可能的好字符串是 "011" 。
 * 可以这样构造得到："" -> "0" -> "01" -> "011" 。
 * 从 "000" 到 "111" 之间所有的二进制字符串都是好字符串。
 *
 *
 * 示例 2：
 * 输入：low = 2, high = 3, zero = 1, one = 2
 * 输出：5
 * 解释：好字符串为 "00" ，"11" ，"000" ，"110" 和 "011" 。
 *
 *
 *
 *
 * 提示：
 * 1 <= low <= high <= 10^5
 * 1 <= zero, one <= low
 *
 *
 */

// @lc code=start
class Solution {
public:
    const int mod = 1000000007;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            int zeroPart = 0;
            if (i >= zero) {
                zeroPart = dp[i - zero];
            }
            int onePart = 0;
            if (i >= one) {
                onePart = dp[i - one];
            }
            //dp[i] = dp[i-zero] + dp[i-one];
            dp[i] = (zeroPart + onePart) % mod;
        }
        long long res = 0;
        for (int i = low; i <= high; i++) {
            res += dp[i];
        }
        return res%mod;
    }
};
// @lc code=end

/*
dp[i]表示  str[0..i-1]满足好字符串的方案数
answer = dp[low] + dp[low+1] + ... dp[high]

zero = 0*Zero
one = 1*one

考虑最后一个字符 str[i-1]
op1 str[i-1] == '0'
 说明是由 zero个0构成的
 因此有 dp[i] = dp[i-zero]
 即 dp[i-zero]有N个方案，每个方案后面追加 zero个0

op2 str[i-1] == '1'
 说明是由 one个1构成的
 因此有 dp[i] = dp[i-one]
 即 dp[i-one]有N个方案，每个方案后面追加 one个1

综上所述
    dp[i] = dp[i-zero] + dp[i-one]

    dp[0] 为空字符串 ， 方案为1
    dp[0] = 1


Runtime Error
14/36 cases passed (N/A)
Error
Line 16: Char 30: runtime error: signed integer overflow: 403762843 + 2044456796 cannot be represented in type 'int' (solution.cpp)
Line 16: Char 30: runtime error: signed integer overflow: 403762843 + 2044456796 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:25:30
Testcase
200
200
10
1
Expected Answer
764262396


由于答案可能很大，请将结果对 109 + 7 取余 后返回。
Wrong Answer
15/36 cases passed (N/A)
Testcase
200
200
10
1
Answer
1215149850
Expected Answer
764262396

运算过程中也需要取mod
Runtime Error
16/36 cases passed (N/A)
Error
Line 17: Char 30: runtime error: signed integer overflow: 3234693454208063175 + 6115352580783416565 cannot be represented in type 'long long' (solution.cpp)
Line 17: Char 30: runtime error: signed integer overflow: 3234693454208063175 + 6115352580783416565 cannot be represented in type 'long long' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:26:30
Testcase
500
500
5
2
Expected Answer
873327137




*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
