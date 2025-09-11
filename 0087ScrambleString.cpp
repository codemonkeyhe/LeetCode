/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-11
 * @tag       dynamicProgramming
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
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 *
 * https://leetcode.cn/problems/scramble-string/description/
 *
 * algorithms
 * Hard (47.06%)
 * Likes:    607
 * Dislikes: 0
 * Total Accepted:    71.4K
 * Total Submissions: 151.3K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
 *
 * 如果字符串的长度为 1 ，算法停止
 * 如果字符串的长度 > 1 ，执行下述步骤：
 *
 * 在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y
 * 。
 * 随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y +
 * x 。
 * 在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
 *
 *
 *
 *
 * 给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：s1 = "great", s2 = "rgeat"
 * 输出：true
 * 解释：s1 上可能发生的一种情形是：
 * "great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
 * "gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
 * "gr/eat" --> "g/r / e/at" // 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割
 * "g/r / e/at" --> "r/g / e/at" // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
 * "r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
 * "r/g / e/ a/t" --> "r/g / e/ a/t" // 随机决定：「保持这两个子字符串的顺序不变」
 * 算法终止，结果字符串和 s2 相同，都是 "rgeat"
 * 这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，返回 true
 *
 *
 * 示例 2：
 * 输入：s1 = "abcde", s2 = "caebd"
 * 输出：false
 *
 *
 * 示例 3：
 * 输入：s1 = "a", s2 = "a"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 * s1.length == s2.length
 * 1 <= s1.length <= 30
 * s1 和 s2 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return reorder(s1, s2);
    }

    bool isDiff(string& s1, string& s2) {
        vector<int> cnt(26, 0);
        for (auto& ch: s1) {
            cnt[ch-'a']++;
        }
        for (auto& ch: s2) {
            cnt[ch-'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                return true;
            }
        }
        return false;
    }

    unordered_map<string, bool> cache;
    bool reorder(string& s1, string& s2) {
        if (s1 == s2) {
            return true;
        }
        int len = s2.size();
        if (len == 1) { // and s1 != s2
            return false;
        }
        if (isDiff(s1, s2)) {
            return false;
        }

        string key = s1 + "|" + s2;
        if (cache.count(key)) {
            return cache[key];
        }

        for (int i = 1; i < s1.size(); i++) {
            string s1left = s1.substr(0, i);
            string s1right= s1.substr(i);

            string s2left = s2.substr(0, i);
            string s2right= s2.substr(i);
            if (reorder(s1left, s2left) && reorder(s1right, s2right)) {
                cache[key] = true;
                return true;
            }
            string s2right2 = s2.substr(len - i, i);
            string s2left2 = s2.substr(0, len - i);
            if (reorder(s1left, s2right2) && reorder(s1right, s2left2)) {
                cache[key] = true;
                return true;
            }
        }
        cache[key] = false;
        return false;
    }

};
// @lc code=end


/*
Time Limit Exceeded
195/290 cases passed (N/A)
Testcase
"abcdefghijklmnopq"
"efghijklmnopqcadb"
Expected Answer
false

加了cache
Accepted
290/290 cases passed (227 ms)
Your runtime beats 5.07 % of cpp submissions
Your memory usage beats 5.07 % of cpp submissions (34.7 MB)

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
