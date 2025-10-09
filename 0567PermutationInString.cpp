/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-09
 * @tag   slidingWindow, twoPointers, hashmap
 * @similar 30, 242, 438, 567
 * @trick diffArray
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode.cn/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (45.08%)
 * Likes:    1051
 * Dislikes: 0
 * Total Accepted:    320.7K
 * Total Submissions: 699.3K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的 排列。如果是，返回 true ；否则，返回 false 。
 * 换句话说，s1 的排列之一是 s2 的 子串 。
 *
 *
 *
 * 示例 1：
 * 输入：s1 = "ab" s2 = "eidbaooo"
 * 输出：true
 * 解释：s2 包含 s1 的排列之一 ("ba").
 *
 *
 * 示例 2：
 * 输入：s1= "ab" s2 = "eidboaoo"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 * 1 <= s1.length, s2.length <= 10^4
 * s1 和 s2 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool checkInclusionM1(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) {
            return false;
        }
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for (auto ch : s1) {
            cnt1[ch - 'a']++;
        }
        for (int i = 0; i < len1; i++) {
            char& ch = s2[i];
            cnt2[ch - 'a']++;
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = len1; i < len2; i++) {
            // s2[i] in  s2[i-len1] out
            char& ch = s2[i];
            cnt2[ch - 'a']++;
            char& oldch = s2[i-len1];
            cnt2[oldch - 'a']--;
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }


    // diffArray
    // diff[i] = s2.ch - s1.ch
    // i==0 means s2 has equal chi with s1
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) {
            return false;
        }
        vector<int> diff(26, 0);
        int allDiff = 0;
        for (int i = 0; i < len1; i++) {
            int ch1 = s1[i] - 'a';
            int ch2 = s2[i] - 'a';
            diff[ch2]++;
            diff[ch1]--;
        }
        for (int i = 0; i < 26; i++) {
            if (diff[i] != 0) {
                allDiff++;
            }
        }
        if (allDiff == 0) {
            return true;
        }

        for (int i = len1; i < len2; i++) {
            // s2[i] in  s2[i-len1] out
            int ch = s2[i] - 'a';
            int v1 = diff[ch];
            diff[ch]++;
            if (v1 == -1) {
                allDiff--;
            } else if (v1 == 0) {
                allDiff++;
            }

            int oldch = s2[i-len1] - 'a';
            int v2 = diff[oldch];
            diff[oldch]--;
            if (v2 == 1) {
                allDiff--;
            } else if (v2 == 0) {
                allDiff++;
            }
            if (allDiff == 0) {
                return true;
            }
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
