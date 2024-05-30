/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-30
 * @tag array; OneShot
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=243 lang=cpp
 *
 * [243] 最短单词距离
 *
 * https://leetcode.cn/problems/shortest-word-distance/description/
 *
 * algorithms
 * Easy (67.62%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 26.9K
 * Testcase Example:  '["practice", "makes", "perfect", "coding", "makes"]\n"coding"\n"practice"'
 *
 * 给定一个字符串数组 wordDict 和两个已经存在于该数组中的不同的字符串 word1 和 word2 。返回列表中这两个单词之间的最短距离。
 *
 *
 *
 * 示例 1:
 * 输入: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 =
 * "coding", word2 = "practice"
 * 输出: 3
 *
 *
 * 示例 2:
 * 输入: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 =
 * "makes", word2 = "coding"
 * 输出: 1
 *
 *
 *
 * 提示:
 * 1 <= wordsDict.length <= 3 * 10^4
 * 1 <= wordsDict[i].length <= 10
 * wordsDict[i] 由小写英文字母组成
 * word1 和 word2 在 wordsDict 中
 * word1 != word2
 *
 *
 */

// @lc code=start
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int len = wordsDict.size();
        int i = 0;
        int j = 0;
        int i1 = -1;
        int i2 = -1;
        int dis = len;
        while (i < len) {
            string& w = wordsDict[i];
            if (w == word1) {
                i1 = i;
            } else if (w == word2) {
                i2 = i;
            } else {
            // (w != word1 && w != word2)
                i++;
                continue;
            }
            // find w1 or w2
            if (i1 >=0 && i2 >=0) {
                int curDis = 0;
                if (i2 > i1) {
                    curDis = i2-i1;
                    i1 = -1;
                } else {
                    curDis = i1-i2;
                    i2 = -1;
                }
                if (curDis < dis) {
                    dis = curDis;
                }
            }
            i++;
        }
        return dis;
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


