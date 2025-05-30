/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-19
 * @tag twoPointers
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
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 *
 * https://leetcode.cn/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (59.36%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    83.3K
 * Total Submissions: 140.3K
 * Testcase Example:  '"ab-cd"'
 *
 * 给你一个字符串 s ，根据下述规则反转字符串：
 *
 *
 * 所有非英文字母保留在原有位置。
 * 所有英文字母（小写或大写）位置反转。
 *
 *
 * 返回反转后的 s 。
 *
 *
 *
 *
 * 示例 1：
 * 输入：s = "ab-cd"
 * 输出："dc-ba"
 *
 *
 *
 * 示例 2：
 * 输入：s = "a-bC-dEf-ghIj"
 * 输出："j-Ih-gfE-dCba"
 *
 *
 *
 * 示例 3：
 * 输入：s = "Test1ng-Leet=code-Q!"
 * 输出："Qedo1ct-eeLg=ntse-T!"
 *
 *
 *
 *
 * 提示
 *
 *
 * 1 <= s.length <= 100
 * s 仅由 ASCII 值在范围 [33, 122] 的字符组成
 * s 不含 '\"' 或 '\\'
 *
 *
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len  = s.size();
        int i = 0;
        int j = len - 1;
        while(i<j) {
            while (i < len && !isalpha(s[i])) {
                i++;
            }

            while (j > 0 && !isalpha(s[j])) {
                j--;
            }
            if (i < j) {
                swap(s[i], s[j]);
            }
            i++;
            j--;
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


