/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-25
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (71.80%)
 * Likes:    522
 * Dislikes: 0
 * Total Accepted:    95.5K
 * Total Submissions: 133.1K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j])
 * 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。
 *
 *
 *
 * 示例 1：
 * 输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出：16
 * 解释：这两个单词为 "abcw", "xtfn"。
 *
 * 示例 2：
 * 输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出：4
 * 解释：这两个单词为 "ab", "cd"。
 *
 * 示例 3：
 * 输入：words = ["a","aa","aaa","aaaa"]
 * 输出：0
 * 解释：不存在这样的两个单词。
 *
 *
 * 提示：
 *
 *
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
public:
    int getMask(string w) {
        int mask = 0;
        for (int i = 0; i < w.size(); i++) {
            int c = w[i]-'a';
            mask=mask| (1<<c);
        }
        return mask;
    }

    int maxProduct(vector<string>& words) {
        vector<int> wordMask;
        for (int i = 0; i < words.size(); i++) {
            string& w = words[i];
            auto mask = getMask(w);
            wordMask.push_back(mask);
        }


        int maxLen = 0;
        for (int i = 0; i < wordMask.size(); i++) {
            for (int j = i + 1; j < wordMask.size(); j++) {
                if ((wordMask[i] & wordMask[j]) == 0) {
                    int len = words[i].size() * words[j].size();
                    if (len > maxLen) {
                        maxLen = len;
                    }
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


