/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-18
 * @tag string, hashtable
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
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 *
 * https://leetcode.cn/problems/most-common-word/description/
 *
 * algorithms
 * Easy (45.62%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    70.7K
 * Total Submissions: 154.4K
 * Testcase Example:  '"Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]'
 *
 * 给你一个字符串 paragraph 和一个表示禁用词的字符串数组 banned ，返回出现频率最高的非禁用词。题目数据 保证
 * 至少存在一个非禁用词，且答案 唯一 。
 *
 * paragraph 中的单词 不区分大小写 ，答案应以 小写 形式返回。
 *
 *
 *
 * 示例 1：
 * 输入：paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.",
 * banned = ["hit"]
 * 输出："ball"
 * 解释：
 * "hit" 出现了 3 次，但它是禁用词。
 * "ball" 出现了两次（没有其他单词出现这么多次），因此它是段落中出现频率最高的非禁用词。
 * 请注意，段落中的单词不区分大小写，
 * 标点符号会被忽略（即使它们紧挨着单词，如 "ball,"），
 * 并且尽管 "hit" 出现的次数更多，但它不能作为答案，因为它是禁用词。
 *
 *
 * 示例 2：
 * 输入：paragraph = "a.", banned = []
 * 输出："a"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= paragraph.length <= 1000
 * paragraph 由英文字母、空格 ' '、和以下符号组成："!?',;."
 * 0 <= banned.length <= 100
 * 1 <= banned[i].length <= 10
 * banned[i] 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:

    string mostCommonWord(string paragraph, vector<string>& banned) {
        string res = "";
        set<string> ban(banned.begin(), banned.end());
        int maxCnt = -1;
        unordered_map<string, int> wc;
        int len = paragraph.size();
        int diff = 'a' - 'A';

        int i = 0;
        string tidy = "";
        while (i <= len) {
            if ((i==len) || isSign(paragraph[i])) {
                if (tidy.size() > 0 && !ban.count(tidy)) {
                    wc[tidy]++;
                    if (wc[tidy] > maxCnt) {
                        maxCnt = wc[tidy];
                        res = tidy;
                    }
                }
                tidy = "";
            } else {
                char& cur = paragraph[i];
                if (cur >= 'A' && cur <= 'Z') {
                    tidy += char(cur + diff);
                } else {
                    tidy += cur;
                }
            }
            i++;
        }
        return res;
    }

    bool isSign(char ch) {
        string table = "!?',;. ";
        for (int i = 0; i < table.size(); i++) {
            if (ch == table[i]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

/*
Testcase
"a, a, a, a, b,b,b,c, c"
["a"]
Answer
"bbbc"
Expected Answer
"b"

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


