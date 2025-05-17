/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-17
 * @tag dynamicProgramming
 * @similar  322 518 139
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode.cn/problems/word-break/description/
 *
 * algorithms
 * Medium (55.58%)
 * Likes:    2748
 * Dislikes: 0
 * Total Accepted:    785.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
 *
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 *
 *
 *
 * 示例 1：
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 *
 *
 * 示例 2：
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 * 注意，你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s 和 wordDict[i] 仅由小写英文字母组成
 * wordDict 中的所有字符串 互不相同
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, bool> cache;

    bool wordBreakM1(string s, vector<string>& wordDict) {
        int slen = s.size();
        if (slen == 0) {
            return true;
        }
        if (cache.count(s)) {
            return cache[s];
        }
        for (auto& word : wordDict) {
            int wl = word.size();
            if (wl > slen) {
                continue;
            }
            if (s.substr(slen-wl, wl) != word) {
                continue;
            }
            bool ok = wordBreak(s.substr(0, slen-wl), wordDict);
            if (ok) {
                cache[s] = true;
                return true;
            }
        }
        cache[s] = false;
        return false;
    }


    //DP定义不好，频繁处理 i+1，需要重新定义
    //dp[i]表示s中的前i+1个字符[0~i]可以由wordDict拼接而成
    bool wordBreakM2(string s, vector<string>& wordDict) {
        int slen = s.size();
        vector<bool> dp(slen, false);
        for (int i = 0; i < slen; i++) {
            for (auto& word: wordDict) {
                int wl = word.size();
                if (wl > (i + 1)) {// i is index, wl is len
                    continue;
                }
                if (s.substr(i + 1 - wl, wl) != word) {
                    continue;
                }
                if (i + 1 == wl) {
                    dp[i] = true;
                } else {
                    //Error dp[i] = dp[i  - wl];
                    //OK dp[i] = dp[i] || dp[i  - wl];
                    if (dp[i - wl]) {
                        dp[i] = true;
                    }
                }
              //  cout << "i=" << i << " word=" << word << " dpi=" << dp[i] << endl;
            }
        }
        return dp[slen-1];
    }

    //dp[i]表示s中的[0~i-1]可以由wordDict拼接而成，换句话说，dp[i]中的i为len
    // anwer = dp[slen]
    bool wordBreak(string s, vector<string>& wordDict) {
        int slen = s.size();
        vector<bool> dp(slen+1, false);
        dp[0] = true;
        for (int i = 1; i <= slen; i++) {
            for (auto& word: wordDict) {
                int wl = word.size();
                if (wl > i) {// i and wl is len
                    continue;
                }
                if (s.substr(i - wl, wl) != word) {
                    continue;
                }
                if (dp[i - wl]) {
                    dp[i] = true;
                }
            }
        }
        return dp[slen];
    }

};
// @lc code=end


/*
 s = "applepenapple", wordDict = ["apple", "pen"]

dp[i]表示s中的前i+1个字符[0~i]可以由wordDict拼接而成

dp(i=13,applepenapple) = dp(i=8,applepen) + apple
dp(i=9, applepen) = dp(i=5,apple) +pen
dp(i=5,apple) = true


没加 cache超时，加了cache没问题
Time Limit Exceeded
37/47 cases passed (N/A)
Testcase
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
' +
  '["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
Expected Answer
false


Wrong Answer
43/47 cases passed (N/A)
Testcase
"dogs"
["dog","s","gs"]
Answer
false
Expected Answer
true

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


