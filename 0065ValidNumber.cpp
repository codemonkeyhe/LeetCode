/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-08
 * @tag   dfa,simulation,string
 * @similar  8, 65
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 *
 * https://leetcode.cn/problems/valid-number/description/
 *
 * algorithms
 * Hard (27.67%)
 * Likes:    403
 * Dislikes: 0
 * Total Accepted:    82K
 * Total Submissions: 292.7K
 * Testcase Example:  '"0"'
 *
 * 给定一个字符串 s ，返回 s 是否是一个 有效数字。
 * 例如，下面的都是有效数字："2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3",
 * "3e+7", "+6e-1", "53.5e93", "-123.456e789"，而接下来的不是："abc", "1a", "1e", "e3",
 * "99e2.5", "--6", "-+3", "95a54e53"。
 *
 * 一般的，一个 有效数字 可以用以下的规则之一定义：
 * 一个 整数 后面跟着一个 可选指数。
 * 一个 十进制数 后面跟着一个 可选指数。
 * 一个 整数 定义为一个 可选符号 '-' 或 '+' 后面跟着 数字。
 * 一个 十进制数 定义为一个 可选符号 '-' 或 '+' 后面跟着下述规则：
 * 数字 后跟着一个 小数点 .。
 * 数字 后跟着一个 小数点 . 再跟着 数位。
 * 一个 小数点 . 后跟着 数位。
 *
 *
 * 指数 定义为指数符号 'e' 或 'E'，后面跟着一个 整数。
 * 数字 定义为一个或多个数位。
 *
 *
 *
 * 示例 1：
 * 输入：s = "0"
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：s = "e"
 * 输出：false
 *
 *
 * 示例 3：
 * 输入：s = "."
 * 输出：false
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 20
 * s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，或者点 '.' 。
 *
 *
 */

// @lc code=start


class Solution {
public:
    enum State {
        ST_START,
        ST_INT_SIGN, // + -
        ST_INT,  // digit
        ST_DOT,  // .
        ST_DOT_FIRST, //  -.9
        ST_FRACTION,  //
        ST_EXP, // e|E
        ST_EXP_SIGN,  //  e|E -> +|-
        ST_EXP_INT,
        ST_ENT,
    };

    enum CharType {
        CT_NUMBER,
        CT_SIGN,
        CT_EXP,
        CT_DOT,
        CT_ERROR,
    };

    CharType getCharType(char c) {
        if (c >= '0' && c <= '9') {
            return CT_NUMBER;
        }
        if (c == '+' || c == '-') {
            return CT_SIGN;
        }

        if (c == 'e' || c == 'E') {
            return CT_EXP;
        }
        if (c == '.') {
            return CT_DOT;
        }
        return CT_ERROR;
    }

    static unordered_map<State, unordered_map<CharType, State>> dfaTable;

    bool isNumberDFA(string s) {
        State st = ST_START;
        for (auto& ch: s) {
            CharType ct = getCharType(ch);
            if (ct == CT_ERROR) {
                return false;
            }
            if (dfaTable.count(st) == 0
            || (dfaTable[st].count(ct) == 0 )) {
                return false;
            }
            State next = dfaTable[st][ct];
            st = next;
        }

        if (st == ST_INT || st == ST_DOT || st == ST_FRACTION || st == ST_EXP_INT ) {
            return true;
        }
        return false;
    }


    bool isNumber(string s) {
        int expIdx = s.find('e', 0);
        if (expIdx == string::npos) {
            expIdx = s.find('E', 0);
        }
        if (expIdx == string::npos) {
            // no exp
            return checkIntOrFloat(s);
        }
        string leftPart = s.substr(0, expIdx);
        string rightPart = s.substr(expIdx + 1);
        if (leftPart.size() == 0 || rightPart.size() == 0) {
            return false;
        }
        if (checkIntOrFloat(leftPart) == false) {
            return false;
        }
        return checkInt(rightPart);
    }


    bool checkInt(string& s) {
        if (s.size() == 0) {
            return false;
        }
        int i = 0;
        if (s[0] == '+' || s[0] == '-') {
            i++;
        }
        int cntNum = 0;
        for (; i < s.size(); i++) {
            char& ch = s[i];
            CharType ct = getCharType(ch);
            if (ct != CT_NUMBER) {
                return false;
            }
            cntNum++;
        }
        return (cntNum > 0);
    }


    bool checkIntOrFloat(string& s) {
        bool findSign = false;
        bool findDot = false;
        int cntNum = 0;
        for (auto& ch : s) {
            CharType ct = getCharType(ch);
            if (ct == CT_ERROR || ct == CT_EXP) {
                return false;
            }
            if (ct == CT_SIGN) {
                if (cntNum > 0 || findDot) {
                    return false;
                }
                if (findSign) {
                    return false;
                }
                findSign = true;
                continue;
            }
            if (ct == CT_DOT) {
                if (findDot) {
                    return false;
                }
                findDot = true;
                continue;
            }
            cntNum++;
        }
        return (cntNum > 0);
    }

};

//unordered_map<State, unordered_map<CharType, State>> dfaTable = {
// static 成员 必须类外初始化
unordered_map<Solution::State, unordered_map<Solution::CharType, Solution::State>> Solution::dfaTable = {
    {
        ST_START,
        {
            {CT_SIGN, ST_INT_SIGN},
            {CT_NUMBER, ST_INT},
            {CT_DOT, ST_DOT_FIRST}
        }
    },
    {
        ST_INT_SIGN, {
            {CT_NUMBER, ST_INT},
            {CT_DOT, ST_DOT_FIRST}
        }
    },
    {
        ST_INT, {
            {CT_NUMBER, ST_INT},
            {CT_DOT, ST_DOT},
            {CT_EXP, ST_EXP}
        }
    },
    {
        ST_DOT, {
            {CT_NUMBER, ST_FRACTION},
            {CT_EXP, ST_EXP}
        }
    },
    {
        ST_DOT_FIRST, {
            {CT_NUMBER, ST_FRACTION}
        }
    },
    {
        ST_FRACTION, {
            {CT_NUMBER, ST_FRACTION},
            {CT_EXP, ST_EXP}
        }
    },
    {
        ST_EXP, {
            {CT_SIGN, ST_EXP_SIGN},
            {CT_NUMBER, ST_EXP_INT}
        }
    },
    {
        ST_EXP_SIGN, {
            {CT_NUMBER, ST_EXP_INT}
        }
    },
    {
        ST_EXP_INT, {
            {CT_NUMBER, ST_EXP_INT}
        }
    }
};

// @lc code=end

/*

Wrong Answer
1460/1498 cases passed (N/A)
Testcase
"6+1"
Answer
true
Expected Answer
false

Wrong Answer
1496/1498 cases passed (N/A)
Testcase
".-4"
Answer
true
Expected Answer
false

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
