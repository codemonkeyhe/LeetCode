/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-23
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
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (53.54%)
 * Likes:    1423
 * Dislikes: 0
 * Total Accepted:    419K
 * Total Submissions: 783.4K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 * 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *
 *
 *
 * 示例 1:
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
public:

    //  暴力法
    vector<int> findAnagramsM1(string s, string p) {
        int lenp = p.size();
        vector<int> res;
        int limit =  (s.size()-lenp);
        for (int i = 0; i <= limit; i++) {
            auto ss = s.substr(i, lenp);
            if (isMatch(ss, p)) {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isMatch(string s, string p) {
        int arr[27] = {0};
        for (int i = 0; i < p.size(); i++) {
            int c = p[i]  - 'a';
            arr[c] +=1;
        }
        for (int i = 0; i < s.size(); i++) {
            int c = s[i]  - 'a';
            arr[c] -=1;
        }
        for (int i = 0; i <= 26; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }



    // 滑动窗口
    // 用arr[26]较为繁琐，还是vector<int> arr(26) 更加方便，可以省略 isArrMatch函数

    vector<int> findAnagrams(string s, string p) {
        int lenp = p.size();
        vector<int> res;
        if (s.size() < lenp) {
            return res;
        }

        int arrp[26] = {0};
        for (int i = 0; i < p.size(); i++) {
            int c = p[i]  - 'a';
            arrp[c] +=1;
        }

        int arrs[26] = {0};
        for (int i = 0; i < lenp; i++) {
            int c = s[i]  - 'a';
            arrs[c] +=1;
        }

        if (isArrMatch(arrp, arrs)) {
            res.push_back(0);
        }


        int limit = s.size() - lenp;
        for (int i = 1; i <= limit; i++) {
            int c = s[i-1] - 'a';
            arrs[c] -=1;
            int nc = s[i-1+lenp] - 'a';
            arrs[nc] +=1;
            if (isArrMatch(arrs, arrp))  {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isArrMatch(int arrs[],  int arrp[]) {
        for (int i = 0; i <26; i++) {
            if (arrp[i] !=  arrs[i]) {
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


