/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-20
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
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode.cn/problems/word-pattern/description/
 *
 * algorithms
 * Easy (44.58%)
 * Likes:    643
 * Dislikes: 0
 * Total Accepted:    176.8K
 * Total Submissions: 396.5K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
 *
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
 *
 * 示例1:
 * 输入: pattern = "abba", s = "dog cat cat dog"
 * 输出: true
 *
 * 示例 2:
 * 输入:pattern = "abba", s = "dog cat cat fish"
 * 输出: false
 *
 * 示例 3:
 * 输入: pattern = "aaaa", s = "dog cat cat dog"
 * 输出: false
 *
 *
 *
 * 提示:
 * 1 <= pattern.length <= 300
 * pattern 只包含小写英文字母
 * 1 <= s.length <= 3000
 * s 只包含小写英文字母和 ' '
 * s 不包含 任何前导或尾随对空格
 * s 中每个单词都被 单个空格 分隔
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hm1;
        unordered_map<string, char> hm2;
        auto wordList =  splitStr(s);

        if (pattern.size() != wordList.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++) {
            char& c = pattern[i];
            string& word = wordList[i];
            auto it1 =  hm1.find(c);
            auto it2 =  hm2.find(word);
            if (it1 != hm1.end() && it1->second != word) {
                return false;
            }
            if (it2 != hm2.end() && it2->second != c) {
                return false;
            }
            hm1[c] = word;
            hm2[word] = c;
        }

        return true;

    }

    vector<string>  splitStr(string s) {
        vector<string> res;
        int len = s.size();
        int i =0;
        int j =0;
        while(j < len) {
            if(s[j] != ' ') {
                j++;
                continue;
            }
            auto ss = s.substr(i, j-i);
            res.push_back(ss);
            j++;
            i=j;
        }
        if (j == len) {
            auto ss = s.substr(i, j-i);
            res.push_back(ss);
        }
        return res;
    }

};
// @lc code=end

/*
pattern   S
aa       cat dog
ab       cat cat

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


