/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-12
 * @tag
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
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 *
 * https://leetcode.cn/problems/detect-capital/description/
 *
 * algorithms
 * Easy (56.41%)
 * Likes:    298
 * Dislikes: 0
 * Total Accepted:    122.4K
 * Total Submissions: 213.3K
 * Testcase Example:  '"USA"'
 *
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 *
 *
 * 全部字母都是大写，比如 "USA" 。
 * 单词中所有字母都不是大写，比如 "leetcode" 。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
 *
 *
 * 给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：word = "USA"
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：word = "FlaG"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 * 1 <= word.length <= 100
 * word 由小写和大写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1) {
            return true;
        }
        bool firstLow = false;
        if (word[0] >= 'a') {
            firstLow = true;
        }
        bool expLow = true;
        if (firstLow) {
            expLow = true;
        } else {
            expLow = (word[1] >= 'a');
        }

        for (int i = 1; i < word.size(); i++) {
            bool isLow = (word[i] >= 'a');
            if (isLow != expLow) {
                return false;
            }
            /*
            if (word[i] < 'a') { // Upper
                if (expLow) {
                    return false;
                }
            } else {
                if (!expLow) {
                    return false;
                }
            }
            */
        }
        return true;
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


