/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-14
 * @tag  twoPointers,hashmap
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
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (50.26%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    118.7K
 * Total Submissions: 233.7K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s
 * 中的某些字符得到。
 *
 * 如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
 *
 *
 *
 * 示例 1：
 * 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * 输出："apple"
 *
 *
 * 示例 2：
 * 输入：s = "abpcplea", dictionary = ["a","b","c"]
 * 输出："a"
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 1000
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 1000
 * s 和 dictionary[i] 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int lenS = s.size();
        int maxLen = 0;
        int maxIdx = 0;
        for (int k = 0; k < dictionary.size(); k++) {
            string &w = dictionary[k];
            int i = 0;
            int j = 0;
            while (i < lenS && j < w.size()) {
                if (s[i] == w[j]) {
                    i++;
                    j++;
                } else {
                    i++;
                }
            }
            if (j == w.size()) { // means find
                if (w.size() > maxLen) {
                    maxLen = w.size();
                    maxIdx = k;
                } else if (w.size() ==  maxLen) {
                    if (w < dictionary[maxIdx]) {
                        maxIdx = k;
                    }
                }
            }
        }
        if (maxLen == 0) {
            return "";
        }
        return dictionary[maxIdx];
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
