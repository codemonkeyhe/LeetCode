/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-28
 * @tag binary-search
 * @TODO two-pointers
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 *
 * https://leetcode.cn/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (52.46%)
 * Likes:    1042
 * Dislikes: 0
 * Total Accepted:    435.9K
 * Total Submissions: 830.8K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 *
 *
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 *
 * 进阶：
 *
 * 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 *
 * 致谢：
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 *
 *
 *
 * 示例 1：
 * 输入：s = "abc", t = "ahbgdc"
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：s = "axc", t = "ahbgdc"
 * 输出：false
 *
 *
 *
 * 提示：
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * 两个字符串都只由小写字符组成。
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {

        return isSubM2(s, t);
       //  return isSubM1(s, t);
    }

   // M1

    bool isCntMatch(string s, string t) {
        int cntS[26] = {0};
        int cntT[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            cntS[a]++;
        }

        for (int i = 0; i < t.size(); i++) {
            int a = t[i] - 'a';
            cntT[a]++;
        }
        for (int i = 0; i < 26; i++) {
            if (cntS[i] > 0 && cntT[i] < cntS[i]) {
                return false;
            }
        }
        return true;
    }


    bool isSubM1(string s, string t) {
        if (s == t) {
            return true;
        }
        if (!isCntMatch(s, t)) {
            return false;
        }

        int len = t.size();
        for (int i = 0; i < len; i++) {
            string ss = t.substr(0,i) + t.substr(i+1, len-i-1);
            if (isSubM1(s, ss)) {
                return true;
            }
        }
        return false;
    }

    bool isSubM2(string s, string t) {
        if (!isCntMatch(s, t)) {
            return false;
        }
        int i = 0;
        int j = 0;
        int ls = s.size();
        int lt = t.size();
        int pos = 0;
        while(i < ls) {
            char a = s[i];
            int idx = t.find(a, pos);
            if (idx == string::npos) {
                return false;
            }
            i++;
            pos = idx+1;
        }
        return true;
    }

};
// @lc code=end

/*
M1  BFS
单纯BFS  Time Limit Exceeded
使用hashtable加速，依然 Time Limit Exceeded
11/20 cases passed (N/A)
"rjufvjafbxnbgriwgokdgqdqewn"
' +
  '"mjmqqjrmzkvhxlyruonekhhofpzzslupzojfuoztvzmmqvmlhgqxehojfowtrinbatjujaxekbcydldglkbxsqbbnrkhfdnpfbuaktupfftiljwpgglkjqunvithzlzpgikixqeuimmtbiskemplcvljqgvlzvnqxgedxqnznddkiujwhdefziydtquoudzxstpjjitmiimbjfgfjikkjycwgnpdxpeppsturjwkgnifinccvqzwlbmgpdaodzptyrjjkbqmgdrftfbwgimsmjpknuqtijrsnwvtytqqvookinzmkkkrkgwafohflvuedssukjgipgmypakhlckvizmqvycvbxhlljzejcaijqnfgobuhuiahtmxfzoplmmjfxtggwwxliplntkfuxjcnzcqsaagahbbneugiocexcfpszzomumfqpaiydssmihdoewahoswhlnpctjmkyufsvjlrflfiktndubnymenlmpyrhjxfdcq"

M2 双指针find


M3 双指针 不用find

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


