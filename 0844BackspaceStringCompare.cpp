/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-20
 * @tag string,stack,twoPointers
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
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 *
 * https://leetcode.cn/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (47.78%)
 * Likes:    813
 * Dislikes: 0
 * Total Accepted:    282.9K
 * Total Submissions: 589.1K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
 *
 * 注意：如果对空文本输入退格字符，文本继续为空。
 *
 *
 *
 * 示例 1：
 * 输入：s = "ab#c", t = "ad#c"
 * 输出：true
 * 解释：s 和 t 都会变成 "ac"。
 *
 *
 * 示例 2：
 * 输入：s = "ab##", t = "c#d#"
 * 输出：true
 * 解释：s 和 t 都会变成 ""。
 *
 *
 * 示例 3：
 * 输入：s = "a#c", t = "b"
 * 输出：false
 * 解释：s 会变成 "c"，但 t 仍然是 "b"。
 *
 *
 *
 * 提示：
 * 1 <= s.length, t.length <= 200
 * s 和 t 只含有小写字母以及字符 '#'
 *
 *
 *
 *
 * 进阶：
 * 你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
 *
 *
 */

// @lc code=start
class Solution {
public:

    bool backspaceCompareTP(string s, string t) {
        int lenS = s.size();
        int lenT = t.size();
        int i = lenS-1;
        int j = lenT-1;
        while (i >= 0 || j >= 0) {
            int skipS = 0;
            while (i >= 0 && (skipS >= 0)) {
                if (s[i] != '#') {
                    if (skipS > 0) {
                        skipS--;
                        i--;
                    } else {
                        break;
                    }
                } else {
                    skipS++;
                    i--;
                }
            }

            int skipT = 0;
            while (j >= 0 && (skipT >= 0)) {
                if (t[j] != '#') {
                    if (skipT > 0) {
                        skipT--;
                        j--;
                    } else {
                        break;
                    }
                } else {
                    skipT++;
                    j--;
                }
            }

            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            }
            if (i >=0 && j < 0) {
                return false;
            }

            if (i <0 && j >= 0) {
                return false;
            }

            i--;
            j--;
        }
        return true;
    }

    // string ns 当作stack使用
    string cleanStr(string s) {
        string ns = "";
        for(auto& ch: s) {
            if (ch == '#') {
                if (ns.size() > 0) {
                    ns.pop_back();
                }
            } else {
                ns += ch;
            }
        }
        return ns;
    }

    bool backspaceCompareStack(string s, string t) {
        return (cleanStr(s) == cleanStr(t));
    }

    // also is a stack , take p1  as stack top pointer
    void tidyStr(string& s) {
        int len = s.size();
        int p1 = 0;
        int p2 = 0;
        while(p2<len) {
            if (s[p2]!= '#') {
                s[p1++] = s[p2];
            } else {
                if (p1 > 0) {
                    p1--;
                }
            }
            p2++;
        }
        s.resize(p1);
    }

    bool backspaceCompare(string s, string t) {
        tidyStr(s);
        tidyStr(t);
        return (s==t);
    }

};
// @lc code=end

/*

82/115 cases passed (N/A)
Testcase
"ab##"
"c#d#"

Answer
false

Expected Answer
true


Testcase
"a##c"
"#a#c"
Expected Answer
true
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


