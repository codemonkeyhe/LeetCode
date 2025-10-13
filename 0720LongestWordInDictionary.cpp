/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-13
 * @tag   hashMap, trie
 * @similar  524, 720
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 *
 * https://leetcode.cn/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Medium (52.09%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    72.3K
 * Total Submissions: 138.1K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * 给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。
 * 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。
 * 请注意，单词应该从左到右构建，每个额外的字符都添加到前一个单词的结尾。
 *
 *
 *
 * 示例 1：
 * 输入：words = ["w","wo","wor","worl", "world"]
 * 输出："world"
 * 解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
 *
 *
 * 示例 2：
 * 输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * 输出："apple"
 * 解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply"
 *
 *
 *
 *
 * 提示：
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 30
 * 所有输入的字符串 words[i] 都只包含小写字母。
 *
 *
 */

// @lc code=start
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> dic(words.begin(), words.end());
        int maxLen = 0;
        string maxWord = "";
        for (auto& w : words) {
            int i = w.size() -1;
            for (; i > 0; i--) {
                string &&tmp = w.substr(0, i);
                if (dic.count(tmp) == 0) {
                    break;
                }
            }
            if (i == 0) { // means find
                if (w.size() > maxLen) {
                    maxLen = w.size();
                    maxWord = w;
                } else if (w.size() == maxLen) {
                    if (w < maxWord) {
                        maxWord = w;
                    }
                }
            }
        }

        return maxWord;
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
