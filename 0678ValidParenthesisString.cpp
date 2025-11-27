/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-26
 * @tag  stack,backtracing
 * @similar   20,22,32,301
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 *
 * https://leetcode.cn/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (39.42%)
 * Likes:    682
 * Dislikes: 0
 * Total Accepted:    87K
 * Total Submissions: 216.5K
 * Testcase Example:  '"()"'
 *
 * 给你一个只包含三种字符的字符串，支持的字符类型分别是 '('、')' 和 '*'。请你检验这个字符串是否为有效字符串，如果是 有效 字符串返回 true
 * 。
 *
 * 有效 字符串符合如下规则：
 * 任何左括号 '(' 必须有相应的右括号 ')'。
 * 任何右括号 ')' 必须有相应的左括号 '(' 。
 * 左括号 '(' 必须在对应的右括号之前 ')'。
 * '*' 可以被视为单个右括号 ')' ，或单个左括号 '(' ，或一个空字符串 ""。
 *
 *
 *
 *
 * 示例 1：
 * 输入：s = "()"
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：s = "(*)"
 * 输出：true
 *
 *
 * 示例 3：
 * 输入：s = "(*))"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 100
 * s[i] 为 '('、')' 或 '*'
 *
 *
 */

// @lc code=start
class Solution {
public:
    // M1 count
    bool checkValidStringM1(string s) {
        int leftNum = 0;
        int rightNum = 0;
        int starNum = 0;
        for (int i = 0; i < s.size(); i++) {
            auto& ch = s[i];
            if (ch == '(') {
                leftNum++;
            } else if (ch == ')') {
                rightNum++;
            } else { // *
                starNum++;
            }
            if (leftNum + starNum < rightNum) {
                return false;
            }
        }
        leftNum = 0;
        rightNum = 0;
        starNum = 0;
        for (int i = s.size(); i >=0; i--) {
            auto& ch = s[i];
            if (ch == '(') {
                leftNum++;
            } else if (ch == ')') {
                rightNum++;
            } else { // *
                starNum++;
            }
            if (rightNum + starNum < leftNum) {
                return false;
            }
        }
        return true;
    }

    bool checkValidStringError(string s) {
        stack<char> leftSta;
        stack<char> starSta;

        for (auto& ch: s) {
            if (ch == '(') {
                leftSta.push(ch);
            } else if (ch == '*') {
                starSta.push(ch);
            } else { // )
                if (!leftSta.empty()) {
                    leftSta.pop();
                    continue;
                }
                if (!starSta.empty()) {
                    starSta.pop();
                    continue;
                }
                return false;
            }
        }
        // ***(( still error; need to check idx
        if (leftSta.size() > starSta.size()) {
            return false;
        }
        return true;
    }

    // M2 stack
    bool checkValidStringM2(string s) {
        stack<int> leftSta;
        stack<int> starSta;

        for (int i = 0; i < s.size(); i++) {
            auto& ch = s[i];
            if (ch == '(') {
                leftSta.push(i);
            } else if (ch == '*') {
                starSta.push(i);
            } else { // )
                if (!leftSta.empty()) {
                    leftSta.pop();
                    continue;
                }
                if (!starSta.empty()) {
                    starSta.pop();
                    continue;
                }
                return false;
            }
        }
        // ***(( still error; need to check idx
        if (leftSta.size() > starSta.size()) {
            return false;
        }
        while(!leftSta.empty() && !starSta.empty()) {
            int curLeft = leftSta.top();
            leftSta.pop();
            int curStar = starSta.top();
            starSta.pop();
            if (curLeft >= curStar) {
                return false;
            }
        }
        return leftSta.empty();
    }


    bool checkValidString(string s) {
        return bt(s, 0, 0, 0);
    }

    unordered_map<int, bool> cache;
    bool bt(string& s, int idx, int leftNum, int rightNum) {
        if (idx == s.size()) {
            return (leftNum == rightNum);
        }
        if (leftNum < rightNum) {
            return false;
        }
        int key = leftNum * 10000 + rightNum * 100 + idx;
        if (cache.count(key)) {
            return cache[key];
        }

        auto &ch = s[idx];
        if (ch == '(') {
            auto res = bt(s, idx + 1, leftNum + 1, rightNum);
            cache[key] = res;
            return res;
        }
        if (ch == ')') {
            auto res = bt(s, idx + 1, leftNum, rightNum + 1);
            cache[key] = res;
            return res;
        }
        // star
        // op1 as ""
        auto res1 = bt(s, idx + 1, leftNum, rightNum);
        if (res1) {
            cache[key] = true;
            return true;
        }
        // op2 as (
        auto res2 = bt(s, idx + 1, leftNum + 1, rightNum);
        if (res2) {
            cache[key] = true;
            return true;
        }
        // op3 as )
        auto res3 = bt(s, idx + 1, leftNum, rightNum + 1);
        if (res3) {
            cache[key] = true;
            return true;
        }
        cache[key] = false;
        return false;
    }
};
// @lc code=end

/*
Wrong Answer
66/83 cases passed (N/A)
Testcase
"(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"
Answer
true
Expected Answer
false


核心思路
第一次验证（从左到右）：
        将 '*' 尽可能当作 '('
        确保在任何位置，右括号 ')' 的数量不超过左括号 '(' 和 '*' 的数量
第二次验证（从右到左）：
        反转字符串后，将 '*' 尽可能当作 ')'
        确保在任何位置，左括号 '(' 的数量不超过右括号 ')' 和 '*' 的数量
正确性证明
单向验证的局限性：
        只从左到右验证：可能过度使用 '*' 作为 '('，导致后面没有足够的 '*'
来匹配右括号 只从右到左验证：可能过度使用 '*' 作为 ')'，导致前面没有足够的 '*'
来匹配左括号 双向验证的完备性： 第一次验证确保：在任何前缀中，右括号数量 ≤
左括号+通配符数量 第二次验证确保：在任何后缀中，左括号数量 ≤ 右括号+通配符数量
        这两个条件共同保证了字符串的有效性

作者：Kelvin
链接：https://leetcode.cn/problems/valid-parenthesis-string/solutions/3810474/shuang-xiang-tan-xin-yan-zheng-zheng-que-0bot/
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
