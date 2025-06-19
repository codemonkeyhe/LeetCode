/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-19
 * @tag slidingWindow,hashTable
 * @similar  76, 209, 239
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.63%)
 * Likes:    2882
 * Dislikes: 0
 * Total Accepted:    555.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 *
 *
 *
 * 注意：
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    // 20200914
    string minWindowUgly(string s, string t) {
        set<int> idxs;
        string res("");
        if (s.empty() || t.empty()) {
            return res;
        }
        unordered_map<char, int> hm; //char-> idx

        queue<char> que;
        int left = 0;
        int right = 0;
        int n = s.size();
        for (int i = 0; i < t.size(); i++) {
            hm[t[i]] = -1;
        }
        int minLen = INT_MAX;
        int count = 0;
        while (right < n) {
            auto it = hm.find(s[right]);
            if (it == hm.end()) {
                right++;
                if (count == 0) {
                    left++;
                }
                continue;
            }
            if (it->second == -1) { //first
                count++;
            } else { //second
                //首先从idxs删除旧的下标 it->second
                idxs.erase(it->second);
            }
            //修改hashmap里面旧的下标为新的下标
            it->second = right;
            idxs.insert(right);
            if (count == t.size() && !idxs.empty())  {
                left = *idxs.begin();
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    res = s.substr(left, len);
                }
                int minIdx = *idxs.begin();
                idxs.erase(minIdx); //删除第一个元素，即最小的下标
                //需要把最小的下标 的元素 在hashmap中置为-1
                hm[s[minIdx]] = -1;
                count--;
            }
            right++;
        }
        return res;
    }

    // m1 is cover m2
    bool isCover(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
        for (auto& [key, val]: m2) {
            if (m1[key] < val) {
                return false;
            }
        }
        return true;
    }

    string minWindowUgly2(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        unordered_map<char, int> ch2cnt;
        for (auto& ch: t) {
            ch2cnt[ch]++;
        }
        if (lenS < lenT) {
            return "";
        }

        unordered_map<char, int> scnt;
        int i = 0;
        int j = 0;
        int minS = lenS + 1;
        int st = -1;
        while (i < lenS) {
            while (j < lenS) {  // when uncover move right until cover
                if (isCover(scnt, ch2cnt)) {
                    break;
                }
                scnt[s[j]]++;
                j++;
            }
            // cover or j == lenS
            bool cover = true;
            if (j == lenS) {
                cover = isCover(scnt, ch2cnt);
            }
            if (cover) {
                // when cover move left until uncover
                int curL = j - i;
                if (curL < minS) {
                    minS = curL;
                    st = i;
                }
            }
            scnt[s[i]]--;
            i++;
        }
        if (st == -1) {
            return "";
        }

        return s.substr(st, minS);
    }

    // code tidy
    string minWindow(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        unordered_map<char, int> ch2cnt;
        for (auto& ch: t) {
            ch2cnt[ch]++;
        }
        unordered_map<char, int> scnt;
        int i = 0;
        int j = 0;
        int minS = lenS + 1;
        int st = -1;
        while (j < lenS) {
            scnt[s[j]]++;
            j++;
            while (isCover(scnt, ch2cnt) && (i < lenS)) {
                // when cover move left until uncover
                int curL = j - i ;
                if (curL < minS) {
                    minS = curL;
                    st = i;
                }
                scnt[s[i]]--;
                i++;
            }
        }
        return (st == -1) ? "" : s.substr(st, minS);
    }


};
// @lc code=end

/*

147 / 268 个通过的测试用例

输入
s = "aa"
t = "aa"

输出 ""
预期结果 "aa"


Wrong Answer
222/268 cases passed (N/A)
Testcase
"a"
"b"
Answer
"a"
Expected Answer
""


Wrong Answer
249/268 cases passed (N/A)
Testcase
"a"
"a"
Answer
""
Expected Answer
"a"


Time Limit Exceeded
266/268 cases passed (N/A)
Testcase
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'... 37430 more character
Expected Answer
"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ"


去掉cout,
Accepted
268/268 cases passed (133 ms)
Your runtime beats 7.9 % of cpp submissions
Your memory usage beats 54.12 % of cpp submissions (11.4 MB)

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


