/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-06-05
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
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode.cn/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (38.19%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    103.6K
 * Total Submissions: 271.5K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 *
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 *
 * 示例:
 *
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        int i = 0;
        int len = s.size();
        while (i < len) {
            // remove head space
            while (s[i] == ' ') {
                i++;
            }
            if (i < len) {
                while ((i < len) && (s[i] != ' ')) {
                    i++;
                }
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1 字符流处理

M2 找特征-单词分割点
该下标对应的字符不为空格；
该下标为初始下标或者该下标的前下标对应的字符为空格；

*/


/*
TestCase
allSpace
         abc


*/