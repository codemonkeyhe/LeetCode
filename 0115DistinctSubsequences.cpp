/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-10
 * @tag   dynamicProgramming
 * @similar
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode.cn/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (51.99%)
 * Likes:    1367
 * Dislikes: 0
 * Total Accepted:    236.2K
 * Total Submissions: 442.1K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
 *
 * 测试用例保证结果在 32 位有符号整数范围内。
 *
 *
 *
 * 示例 1：
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 *
 * 示例 2：
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length, t.length <= 1000
 * s 和 t 由英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> cache;
    int numDistinctM1(string s, string t) {
        if (s == t) {
            return 1;
        }
        int lenS = s.size();
        int lenT = t.size();
        if (lenS < lenT) {
            return 0;
        }
        string key = s + "|" + t;
        if (cache.count(key)) {
            return cache[key];
        }

        int sum = 0;
        char& lastCh = t.back();
        string ts = t.substr(0, lenT-1);
        for (int i = lenT-1; i < lenS; i++) {
            if (s[i] == lastCh) {
                if (ts.size() > 0) {
                    sum += numDistinct(s.substr(0, i), ts);
                } else {
                    sum += 1;
                }
            }
        }
        cache[key] = sum;
        return sum;
    }


    // DFS
    int numDistinctM2(string s, string t) {
        if (t.size() == 0 || (s == t)) {
            return 1;
        }
        int lenS = s.size();
        int lenT = t.size();
        if (lenS < lenT) {
            return 0;
        }
        string key = s + "|" + t;
        if (cache.count(key)) {
            return cache[key];
        }

        int sum = 0;
        char& lastCh = t.back();
        string ts = t.substr(0, lenT-1);
        for (int i = lenT-1; i < lenS; i++) {
            if (s[i] == lastCh) {
                sum += numDistinct(s.substr(0, i), ts);
            }
        }
        cache[key] = sum;
        return sum;
    }


    int numDistinct(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        if (t.size() == 0 || (s == t)) {
            return 1;
        }
        // Runtime Error
        //vector<vector<int>> dp(lenS, vector<int>(lenT, 0));
        //vector<vector<long long>> dp(lenS, vector<long long>(lenT, 0));
        vector<vector<unsigned long long>> dp(lenS, vector<unsigned  long long>(lenT, 0));

        // dp[0][0] = 0;
        int cnt = 0;
        for (int i = 0; i < lenS; i++) {
            if (s[i] == t[0]) {
                cnt++;
            }
            dp[i][0] = cnt;
        }
        /* duplicate logic
        for (int j = 1; j < lenT; j++) {
            dp[0][j] = 0;
        }
        */

        for(int i = 1; i < lenS; i++) {
            for (int j = 1; j < lenT; j++) {
                if (s[i] == t[j]) {
                    dp[i][j] =  dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] =   dp[i-1][j];
                }
            }
        }

        return dp[lenS-1][lenT-1];
    }
};
// @lc code=end

/*
超出时间限制
55 / 66 个通过的测试用例
最后执行的输入
添加到测试用例
s =
"adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc"
t =
"bcddceeeebecbc"



dp[i][j] 表示  s[0..i] 和 t[0..j]，s[0..i]的子序列等于t[0..j]的次数


case1 当 s[i] == t[j]时，
有2种选择，
OP1 用s[i]匹配t[j]，此时子问题为 s[0..i-1]和t[0..j-1]的子序列次数，即dp[i-1][j-1]
OP2 不用S[i]去匹配t[j]， 此时子问题为 s[0..i-1]和t[0..j]的子序列次数，即dp[i-1][j]

不存在dp[i][j-1]，因为是s的子序列等于t，t的末尾字母t[j]无法被跳过，必须被匹配

因此，当 s[i]==t[j]时，
dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

Case2 当 s[i] != t[j]时，等同于上面的OP2
有dp[i][j] = dp[i-1][j]


初始值
dp[0][0] =  (s[0] == t[0]) ? 1: 0;


dp[i][0] 表示 s[0..i]和t[0]的匹配次数，相当于统计s[0..i]有多少个字符等于t[0]
dp[0][j] j>=1 表示 s[0]和t[0..j]的匹配次数，明显不可能，全部为0



Runtime Error
62/66 cases passed (N/A)
Error
Line 86: Char 46: runtime error: signed integer overflow: 1474397256 + 891953512 cannot be represented in type 'value_type' (aka 'int') (solution.cpp)
Line 86: Char 46: runtime error: signed integer overflow: 1474397256 + 891953512 cannot be represented in type 'value_type' (aka 'int') (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:95:46
Testcase
"xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo"
' +
  '"rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys"
Expected Answer
543744000


untime Error
63/66 cases passed (N/A)
Error
Line 88: Char 46: runtime error: signed integer overflow: 4472995859186094240 + 5516694892996182896 cannot be represented in type 'value_type' (aka 'long long') (solution.cpp)
Line 88: Char 46: runtime error: signed integer overflow: 4472995859186094240 + 5516694892996182896 cannot be represented in type 'value_type' (aka 'long long') (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:97:46
Testcase
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
' +
  '"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
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
