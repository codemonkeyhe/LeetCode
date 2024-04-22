/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-22
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode.cn/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (55.64%)
 * Likes:    594
 * Dislikes: 0
 * Total Accepted:    198.3K
 * Total Submissions: 356.3K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
 *
 * 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
 *
 *
 *
 * 示例 1:
 * 输入:s = "abccccdd"
 * 输出:7
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 *
 *
 * 示例 2:
 * 输入:s = "a"
 * 输出:1
 *
 *
 * 示例 3：
 * 输入:s = "aaaaaccc"
 * 输出:7
 *
 *
 *
 * 提示:
 * 1 <= s.length <= 2000
 * s 只由小写 和/或 大写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int arr[128] = {0};
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'A';
            arr[c]+=1;
        }
        int cnt = 0;
        int odd = 0;
        for (int i = 0; i < 128; i++) {
            if (arr[i] == 0 ) continue;
            if (arr[i]%2 == 0) {
                cnt+=arr[i];
            } else {
                cnt+=arr[i]-1;
                odd = 1;
            }
        }
        return cnt+odd;
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


