/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-06-05
 * @tag OneShot; hash-table
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=266 lang=cpp
 *
 * [266] 回文排列
 *
 * https://leetcode.cn/problems/palindrome-permutation/description/
 *
 * algorithms
 * Easy (70.92%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    15.5K
 * Total Submissions: 21.9K
 * Testcase Example:  '"code"'
 *
 * 给你一个字符串 s ，如果该字符串的某个排列是 回文串 ，则返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：s = "code"
 * 输出：false
 *
 *
 * 示例 2：
 * 输入：s = "aab"
 * 输出：true
 *
 *
 * 示例 3：
 * 输入：s = "carerac"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 5000
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int charCnt[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            charCnt[ch]++;
        }
        int evenCnt = 0;
        for (int i = 0; i < 26; i++)  {
            int cnt = charCnt[i];
            if (cnt == 0 || cnt%2==0) {
                continue;
            }
            evenCnt++;
            if (evenCnt > 1) {
                return false;
            }
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


