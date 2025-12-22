/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-22
 * @tag   string
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
 * @lc app=leetcode.cn id=186 lang=cpp
 *
 * [186] 反转字符串中的单词 II
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string-ii/description/
 *
 * algorithms
 * Medium (76.24%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 31.9K
 * Testcase Example:  '["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]'
 *
 * 给你一个字符数组 s ，反转其中 单词 的顺序。
 * 单词 的定义为：单词是一个由非空格字符组成的序列。s 中的单词将会由单个空格分隔。
 * 必须设计并实现 原地 解法来解决此问题，即不分配额外的空间。
 *
 *
 *
 * 示例 1：
 * 输入：s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * 输出：["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 *
 *
 * 示例 2：
 * 输入：s = ["a"]
 * 输出：["a"]
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 10^5
 * s[i] 可以是一个英文字母（大写或小写）、数字、或是空格 ' ' 。
 * s 中至少存在一个单词
 * s 不含前导或尾随空格
 * 题目数据保证：s 中的每个单词都由单个空格分隔
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    void reverseWordsM1(vector<char>& s) {
        vector<string> words;
        string str = "";
        for (auto& ch : s) {
            if (ch != ' ') {
                str += ch;
            } else {
                words.push_back(str);
                str = "";
            }
        }
        words.push_back(str);
        s.push_back(' ');
        int i = 0;
        for (int j = words.size()-1; j >= 0; j--) {
            auto& ss = words[j];
            for (auto& ch: ss) {
                s[i++] = ch;
            }
            s[i++] = ' ';
        }
        s.pop_back();
    }


    void reverseWords(vector<char>& s) {
        int slen = s.size();
        int i = 0;
        int j = slen -1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        for (int k = 0; k < slen;) {
            int r = k;
            while (r < slen && (s[r] != ' ')) {
                r++;
            }
            // reverse [k, r-1]
            reverse(s.begin() + k, s.begin() + r);
            k = r + 1;
        }
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
