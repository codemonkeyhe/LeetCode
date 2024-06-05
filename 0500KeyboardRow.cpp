/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-06-05
 * @tag array;
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode.cn/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (73.89%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    78.9K
 * Total Submissions: 106.8K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
 *
 * 美式键盘 中：
 * 第一行由字符 "qwertyuiop" 组成。
 * 第二行由字符 "asdfghjkl" 组成。
 * 第三行由字符 "zxcvbnm" 组成。
 *
 *
 * 示例 1：
 * 输入：words = ["Hello","Alaska","Dad","Peace"]
 * 输出：["Alaska","Dad"]
 *
 *
 * 示例 2：
 * 输入：words = ["omk"]
 * 输出：[]
 *
 *
 * 示例 3：
 * 输入：words = ["adsdf","sfd"]
 * 输出：["adsdf","sfd"]
 *
 *
 *
 *
 * 提示：
 * 1 <= words.length <= 20
 * 1 <= words[i].length <= 100
 * words[i] 由英文字母（小写和大写字母）组成
 *
 */

// @lc code=start
class Solution {
public:
    //  misUnderstanding
    vector<string> findWordsWTF(vector<string>& words) {
        map<int, vector<string> > ln2word;
        for (int i = 0; i < words.size(); i++)  {
            string& cur = words[i];
            int ln = getLn(cur);
            if (ln == 0) {
                continue;
            }
            ln2word[ln].push_back(cur);
        }
        for (auto it = ln2word.begin(); it != ln2word.end(); it++) {
            if (it->second.size() > 0) {
                return it->second;
            }
        }
        return vector<string>();
    }

     vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (int i = 0; i < words.size(); i++)  {
            string& cur = words[i];
            int ln = getLn(cur);
            if (ln == 0) {
                continue;
            }
            res.push_back(cur);
        }
        return res;
    }

    int getLn(string w) {
        int dis = 'a' - 'A';
        // string rowIdx = "12210111011122000010020202";
        // 'a'/'A' ->2
        int chLn[26] = {2,3,3,2,1,2,2,
            2,1,2,2,2,3,3,
            1,1,1,1,2,1,
            1,3,1,3,1,3};


        int firstLn = -1;
        for (int i = 0; i < w.size(); i++) {
            int ch = w[i];
            if (ch > 'Z') {  // means small
                ch = ch - 'a';
            } else {
                ch = ch - 'A';
            }
            if (i == 0) {
                firstLn = chLn[ch];
            } else {
                if (chLn[ch] != firstLn) {
                    return 0;
                }
            }
        }
        return firstLn;
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


