/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-20
 * @tag hashtable, string
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
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 *
 * https://leetcode.cn/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (34.88%)
 * Likes:    323
 * Dislikes: 0
 * Total Accepted:    78.3K
 * Total Submissions: 222.7K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * 给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。
 * 交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。
 * 例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
 *
 * s只需要交换一次就可以得到goal，不用多次
 *
 *
 * 示例 1：
 * 输入：s = "ab", goal = "ba"
 * 输出：true
 * 解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
 *
 * 示例 2：
 * 输入：s = "ab", goal = "ab"
 * 输出：false
 * 解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
 *
 * 示例 3：
 * 输入：s = "aa", goal = "aa"
 * 输出：true
 * 解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length, goal.length <= 2 * 10^4
 * s 和 goal 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {
            vector<int> wc(26, 0);
            for (auto& ch : s) {
                int idx = ch - 'a';
                wc[idx]++;
                if (wc[idx] >= 2) {
                    return true;
                }
            }
            return false;
        }

        char s1 = '~';
        char s2 = '~';
        char g1 = '+';
        char g2 = '+';

        int diffCnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == goal[i]) {
                continue;
            }
            if (diffCnt == 0) {
                s1 = s[i];
                g1 = goal[i];
            } else if (diffCnt == 1) {
                s2 = s[i];
                g2 = goal[i];
            } else {
                return false;
            }
            diffCnt++;
        }
        if (s1 == g2 && (s2 == g1)) {
            return true;
        }
        return false;
    }
};
// @lc code=end

/*
35/39 cases passed (N/A)
Testcase
"ab"
"ab"
Answer
true
Expected Answer
falss

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


