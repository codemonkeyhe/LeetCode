/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-11
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
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.55%)
 * Likes:    2000
 * Dislikes: 0
 * Total Accepted:    537.1K
 * Total Submissions: 717.4K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 *
 *
 *
 * 示例 1：
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 16
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:

    vector<vector<string>> partition(string s) {
        vector<vector<string> >  res;
        vector<string> path;
        bt(s, 0, path, res);
        return res;
    }


    void bt(string s, int idx, vector<string>& path, vector<vector<string> >& res) {
        if (idx == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            int ssLen =  i - idx +1;
            string ss = s.substr(idx, ssLen);
            if (!isPalindrome(ss)) {
                continue;
            }
            path.push_back(ss);
            bt(s, i+1, path, res);
            path.pop_back();
        }
        return;
    }

    bool isPalindrome(string ss) {
        int i = 0;
        if (ss.size() == 1) {
            return true;
        }
        int j = ss.size() -1;
        while (i<=j) {
            if (ss[i] != ss[j]) {
                return false;
            }
            i++;
            j--;
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
trick
使用DP提前把所有子串的回文计算存储好，然后查表法判断子串回文

M1

M2

*/


