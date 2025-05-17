/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-17
 * @tag backtracing, DP??
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
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode.cn/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (58.95%)
 * Likes:    785
 * Dislikes: 0
 * Total Accepted:    110K
 * Total Submissions: 182.3K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序
 * 返回所有这些可能的句子。
 *
 * 注意：词典中的同一个单词可能在分段中被重复使用多次。
 *
 *
 *
 * 示例 1：
 * 输入:s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * 输出:["cats and dog","cat sand dog"]
 *
 *
 * 示例 2：
 * 输入:s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * 输出:["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * 解释: 注意你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 * 输入:s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * 输出:[]
 *
 *
 *
 *
 * 提示：
 *
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s 和 wordDict[i] 仅有小写英文字母组成
 * wordDict 中所有字符串都 不同
 *
 *
 */

// @lc code=start
class Solution {
public:

    vector<string> res;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> path;
        wordBT(s, wordDict, path);
        return  res;
    }


    void wordBT(string s, vector<string>& wordDict, vector<string>& path) {
        int slen = s.size();
        if (slen == 0) {
            //find one anwser
            string ss = "";
            for (auto it = path.rbegin(); it != path.rend(); it++) {
                ss += *it + " ";
            }
            ss.pop_back();
            res.push_back(ss);
            return ;
        }
        for (auto& word : wordDict) {
            int wl = word.size();
            if (wl > slen) {
                continue;
            }
            if (s.substr(slen-wl, wl) != word) {
                continue;
            }
            path.push_back(word);
            wordBT(s.substr(0, slen-wl), wordDict, path);
            path.pop_back();
        }
        return ;
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


