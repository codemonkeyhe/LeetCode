/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-14
 * @tag string
 * @similar 541, 344
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (73.66%)
 * Likes:    602
 * Dislikes: 0
 * Total Accepted:    338.1K
 * Total Submissions: 458.6K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 *
 *
 *
 * 示例 1：
 * 输入：s = "Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 *
 *
 * 示例 2:
 * 输入： s = "Mr Ding"
 * 输出："rM gniD"
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 5 * 10^4
 * s 包含可打印的 ASCII 字符。
 * s 不包含任何开头或结尾空格。
 * s 里 至少 有一个词。
 * s 中的所有单词都用一个空格隔开。
 *
 *
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int i = 0;
        int j = 0;
        while (i < len) {
            while (j < len && (s[j] != ' ')) {
                j++;
            }
            int n = i;
            int m = j - 1;
            while (n < m) {
                char tmp = s[n];
                s[n] = s[m];
                s[m] = tmp;
                n++;
                m--;
            }
            i = j + 1;
            j = i;
        }
        return s;
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


