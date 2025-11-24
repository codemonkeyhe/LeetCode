/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-24
 * @tag  dp
 * @similar  1092, 1143
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 *
 * https://leetcode.cn/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (57.85%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    24K
 * Total Submissions: 42.8K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * 给你两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为 子序列 的最短字符串。如果答案不止一个，则可以返回满足条件的 任意一个
 * 答案。
 *
 * 如果从字符串 t 中删除一些字符（也可能不删除），可以得到字符串 s ，那么 s 就是 t 的一个子序列。
 *
 *
 *
 * 示例 1：
 * 输入：str1 = "abac", str2 = "cab"
 * 输出："cabac"
 * 解释：
 * str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。
 * str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
 * 最终我们给出的答案是满足上述属性的最短字符串。
 *
 *
 * 示例 2：
 * 输入：str1 = "aaaaaaaa", str2 = "aaaaaaaa"
 * 输出："aaaaaaaa"
 *
 *
 *
 *
 * 提示：
 * 1 <= str1.length, str2.length <= 1000
 * str1 和 str2 都由小写英文字母组成。
 *
 *
 */

// @lc code=start
class Solution {
public:
    string shortestCommonSupersequenceMLE29_50(string& str1, string& str2) {
        if (str1 == "") {
            return str2;
        }
        if (str2 == "") {
            return str1;
        }
        auto s1 = str1;
        auto s2 = str2;
        if (str1.back() == str2.back()) {
            s1.pop_back();
            s2.pop_back();
            auto res = shortestCommonSupersequence(s1, s2);
            return res + str1.back();
        }
        // not equal
        auto s1Last = s1.back();
        auto s2Last = s2.back();
        s1.pop_back();
        auto res1 = shortestCommonSupersequence(s1, str2) + s1Last;
        s2.pop_back();
        auto res2 = shortestCommonSupersequence(str1, s2)+ s2Last;
        if (res1.size() <= res2.size()) {
            return res1;
        }
        return res2;
    }



    string shortestCommonSupersequenceTLE47(string& str1, string& str2) {
        return SCSCache(str1, str2);
    }


    // s1[0..i] s2[0..j]
    unordered_map<string, string> cache;
    string SCSCache(string &str1, string &str2) {
        if (str1 == "") {
            return str2;
        }
        if (str2 == "") {
            return str1;
        }
        // ERROR string key = str1 + str2;
        string key = str1 + "|" + str2;
        if (cache.count(key)) {
            return cache[key];
        }
        auto s1 = str1;
        auto s2 = str2;
        if (str1.back() == str2.back()) {
            s1.pop_back();
            s2.pop_back();
            auto res = shortestCommonSupersequence(s1, s2) + str1.back();
            cache[key] = res;
            return res;
        }
        // not equal
        auto s1Last = s1.back();
        auto s2Last = s2.back();
        s1.pop_back();
        auto res1 = shortestCommonSupersequence(s1, str2) + s1Last;
        s2.pop_back();
        auto res2 = shortestCommonSupersequence(str1, s2)+ s2Last;
        if (res1.size() <= res2.size()) {
            cache[key] = res1;
            return res1;
        }
        cache[key] = res2;
        return res2;
    }

    string shortestCommonSupersequence(string& str1, string& str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        for (int i = 0; i <= len1; i++ ) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; j++ ) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        int p1 = len1;
        int p2 = len2;
        string res = "";
        while(p1 >=1 && p2 >=1) {
            if (str1[p1-1] == str2[p2-1]) {
                res += str1[p1-1];
                p1--;
                p2--;
                continue;
            }
            if (dp[p1][p2] == dp[p1-1][p2] + 1) {
                res += str1[p1-1];
                p1--;
            } else if (dp[p1][p2] == dp[p1][p2-1] + 1) {
                res += str2[p2-1];
                p2--;
            }
        }
        while (p1 >= 1)  {
            res += str1[p1 - 1];
            p1--;
        }

        while (p2 >= 1)  {
            res += str2[p2 - 1];
            p2--;
        }
        reverse(res.begin(), res.end());
        return res;
    }

};
// @lc code=end

/*

Memory Limit Exceeded
29/50 cases passed (N/A)

Wrong Answer
44/50 cases passed (N/A)
Testcase
"abaaccbcaa"
"acacaaab"
Answer
"acbacabcaaab"
Expected Answer
"abaaccbacaaab"

dp[i][j]表示s1[0..i-1]和s2[0..j-1]的SCS的长度
ans=dp[N1][N2]

if (s1[i-1] == s2[j-1]) {
    dp[i][j] = dp[i-1][j-1] + 1
}

dp[i][0] = i
dp[0][j] = j


if (s1[i-1] != s2[j-1]) {
    去掉s1[i]，考虑s1[0..i-2]和s2[0..j]的SCS的长度，然后再加上s1[i-1]因此要+1
    dp[i][j] = dp[i-1][j]+1
    去掉s2[j]，考虑s1[0..i]和s2[0..j-2]的SCS的长度，然后再加上s2[j-1]因此要+1
    dp[i][j] = dp[i][j-1] + 1

    因此，通过比对 dp[i][j]和dp[i][j-1]可以还原
}


*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
