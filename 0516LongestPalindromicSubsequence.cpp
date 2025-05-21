/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-21
 * @tag dynamicProgramming
 * @similar  5, 647
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode.cn/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (67.10%)
 * Likes:    1336
 * Dislikes: 0
 * Total Accepted:    302.9K
 * Total Submissions: 448.4K
 * Testcase Example:  '"bbbab"'
 *
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 *
 *
 *
 * 示例 1：
 * 输入：s = "bbbab"
 * 输出：4
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 *
 *
 * 示例 2：
 * 输入：s = "cbbd"
 * 输出：2
 * 解释：一个可能的最长回文子序列为 "bb" 。
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 1000
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    Solution() {
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        memo = vector<vector<int> >(n, vector<int>(n, -1));
        return longPa2(s, 0, s.size()-1);
    }

    vector<vector<int> > memo;
    //换了种Cache
    // Your runtime beats 83.14 % of cpp submissions
    int longPa2(string& s, int i, int j) {
        if (i>j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
         int& res = memo[i][j]; // 注意这里是引用
         if (res != -1) {       // 之前计算过
             return res;
         }

        // i < j
        if (s[i] == s[j]) {
            int slen = longPa2(s, i + 1, j - 1) + 2;
            res = slen;
            return slen;
        }

        int len = max(longPa2(s, i + 1, j), longPa2(s, i, j - 1));
        res = len;
        return len;
    }

    //看来用hash作为cache太慢了，以后用Vector作为Cache
    unordered_map<int, int> cache;

    int longPa(string& s, int i, int j) {
        if (i>j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        int key = i * 1000 + j;
        if (cache.count(key)) {
            return cache[key];
        }
        // i < j
        if (s[i] == s[j]) {
            int res = longPa(s, i + 1, j - 1) + 2;
            cache[key] = res;
            return res;
        }

        int len = max(longPa(s, i + 1, j), longPa(s, i, j - 1));
        cache[key] = len;
        return len;
    }


    // dp[i][j] 表示 s.substr[i:j]中的最长回文子序列的长度
    int longestPalindromeSubseqM2(string s) {
        int len = s.size();
        vector<vector<int> > dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {// dp[i+1][j] is zero
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][len - 1];
    }
};
// @lc code=end

/*
不加Cache
Time Limit Exceeded
61/86 cases passed (N/A)
Testcase
"euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew"
Expected Answer
159

加了Cache
Your runtime beats 5.07 % of cpp submissions

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


