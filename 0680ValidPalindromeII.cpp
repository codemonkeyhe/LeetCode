/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-13
 * @tag  string
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
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 *
 * https://leetcode.cn/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (40.23%)
 * Likes:    698
 * Dislikes: 0
 * Total Accepted:    173.5K
 * Total Submissions: 418.8K
 * Testcase Example:  '"aba"'
 *
 * 给你一个字符串 s，最多 可以从中删除一个字符。
 *
 * 请你判断 s 是否能成为回文字符串：如果能，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：s = "aba"
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：s = "abca"
 * 输出：true
 * 解释：你可以删除字符 'c' 。
 *
 *
 * 示例 3：
 * 输入：s = "abc"
 * 输出：false
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(const string& s, int le, int ri) {
        int i = le;
        int j = ri;
        while(i<j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }


    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<j) {
            if (s[i] != s[j]) {
                // del s[i] or s[j]
                break;
            }
            i++;
            j--;
        }
        if (i>=j) {
            return true;
        }

        // del s[i]
        //string s1 = s.substr(0, i) + s.substr(i+1, n-i-1);
        if (isPalindrome(s, i+1, j)) {
            return true;
        }

        // del s[j]
        //string s2 = s.substr(0, j) + s.substr(j+1, n-j-1);
        if (isPalindrome(s, i, j-1)) {
            return true;
        }
        return false;
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


