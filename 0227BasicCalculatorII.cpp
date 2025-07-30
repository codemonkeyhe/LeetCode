/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-30
 * @tag   stack,math
 * @similar 224, 227, 241, 772
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode.cn/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (44.90%)
 * Likes:    848
 * Dislikes: 0
 * Total Accepted:    194.1K
 * Total Submissions: 423.8K
 * Testcase Example:  '"3+2*2"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 * 整数除法仅保留整数部分。
 * 你可以假设给定的表达式总是有效的。所有中间结果将在 [-2^31, 2^31 - 1] 的范围内。
 * 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
 *
 *
 *
 * 示例 1：
 * 输入：s = "3+2*2"
 * 输出：7
 *
 *
 * 示例 2：
 * 输入：s = " 3/2 "
 * 输出：1
 *
 *
 * 示例 3：
 * 输入：s = " 3+5 / 2 "
 * 输出：5
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 3 * 10^5
 * s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
 * s 表示一个 有效表达式
 * 表达式中的所有整数都是非负整数，且在范围 [0, 2^31 - 1] 内
 * 题目数据保证答案是一个 32-bit 整数
 *
 *
 */

// @lc code=start
class Solution {
public:
    int calculateStupid(string s) {
        stack<int> st;
        stack<char> stop;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            char& ch = s[i];
            if (ch == ' ') {
                continue;
            }
            if (ch == '+' || ch == '-') {
                stop.push(ch);
                continue;
            }
            if (ch == '*' || ch == '/') {
                if (!st.empty()) {
                    int op1 = st.top();
                    st.pop();
                    // skip space
                    int k = i+1;
                    while (k < len && s[k] == ' ') {
                        k++;
                    }
                    int j = k;
                    while (j < len && isdigit(s[j])) {
                        j++;
                    }
                    int len = j - k;
                    string snum = s.substr(k, len);
                    int op2 = stoi(snum);
                    i = j - 1;
                    int res = 0;
                    if (ch == '*') {
                        res = op1 * op2;
                    } else {
                        res = op1 / op2;
                    }
                    //cout << "ch=" << ch << " op1=" << op1 << " op2=" << op2 << endl;
                    st.push(res);
                }
                continue;
            }
            int j = i;
            while(j < len && isdigit(s[j])) {
                j++;
            }
            int len = j - i;
            string snum = s.substr(i, len);
            st.push(stoi(snum));
            i = j - 1;
        }
        //错误， 加减法只能从左往右计算
        while(!stop.empty()) {
            char ch = stop.top();
            stop.pop();
            if (st.size() < 2) {
                break;
            }
            int tmp = 0;
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            if (ch == '+') {
                tmp = op1 + op2;
            } else { // '-'
                tmp = op1 - op2;
            }
            st.push(tmp);
            //cout << "22 ch=" << ch << " op1=" << op1 << " op2=" << op2 << endl;
        }
        int total = 0;
        if (!st.empty()) {
            total = st.top();
            st.pop();
        }
        return total;
    }


    // 2 stacks is too  complicated
    int calculateM1(string s) {
        vector<int> st;
        vector<char> stop;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            char& ch = s[i];
            if (ch == ' ') {
                continue;
            }
            if (ch == '+' || ch == '-') {
                stop.push_back(ch);
                continue;
            }
            if (ch == '*' || ch == '/') {
                if (!st.empty()) {
                    int op1 = st.back();
                    st.pop_back();
                    // skip space
                    int k = i+1;
                    while (k < len && s[k] == ' ') {
                        k++;
                    }
                    int j = k;
                    while (j < len && isdigit(s[j])) {
                        j++;
                    }
                    int len = j - k;
                    string snum = s.substr(k, len);
                    int op2 = stoi(snum);
                    i = j - 1;
                    int res = 0;
                    if (ch == '*') {
                        res = op1 * op2;
                    } else {
                        res = op1 / op2;
                    }
                    //cout << "ch=" << ch << " op1=" << op1 << " op2=" << op2 << endl;
                    st.push_back(res);
                }
                continue;
            }
            int j = i;
            while(j < len && isdigit(s[j])) {
                j++;
            }
            int len = j - i;
            string snum = s.substr(i, len);
            st.push_back(stoi(snum));
            i = j - 1;
        }
        //错误， 加减法只能从左往右计算
        if (st.size() != stop.size() + 1) { // Error
            return -100;
        }
        int total = st[0];
        for (int i = 0; i < stop.size(); i++) {
            if (stop[i] == '+') {
                total += st[i+1];
            } else {
                total -= st[i+1];
            }
        }
        return total;
    }

    // one stack
    int calculateM2(string s) {
        vector<string> st;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            char& ch = s[i];
            if (ch == ' ') {
                continue;
            }
            if (ch == '+' || ch == '-') {
                st.push_back(string(1,ch));
                continue;
            }
            if (ch == '*' || ch == '/') {
                if (!st.empty()) {
                    string sop1 = st.back();
                    st.pop_back();
                    int op1 = stoi(sop1);
                    // skip space
                    int k = i+1;
                    while (k < len && s[k] == ' ') {
                        k++;
                    }
                    int j = k;
                    while (j < len && isdigit(s[j])) {
                        j++;
                    }
                    int len = j - k;
                    string snum = s.substr(k, len);
                    int op2 = stoi(snum);
                    i = j - 1;
                    int res = 0;
                    if (ch == '*') {
                        res = op1 * op2;
                    } else {
                        res = op1 / op2;
                    }
                    st.push_back(to_string(res));
                }
                continue;
            }
            int j = i;
            while(j < len && isdigit(s[j])) {
                j++;
            }
            int len = j - i;
            string snum = s.substr(i, len);
            st.push_back(snum);
            i = j - 1;
        }
        int total = stoi(st[0]);
        for (int i = 1; i < st.size(); i+=2) {
            if (st[i] == "+") {
                total += stoi(st[i+1]);
            } else if (st[i] == "-") {
                total -= stoi(st[i+1]);
            }
        }
        return total;
    }


    // M1V2
    int calculateM1v2(string s) {
        vector<int> st;
        vector<char> stop;
        int len = s.size();
        char preop = 'X';
        for (int i = 0; i < len; i++) {
            char& ch = s[i];
            if (ch == ' ') {
                continue;
            }
            if (ch == '+' || ch == '-') {
                stop.push_back(ch);
                continue;
            }
            if (ch == '*' || ch == '/') {
                preop = ch;
                continue;
            }
            int j = i;
            while(j < len && isdigit(s[j])) {
                j++;
            }
            int num = stoi(s.substr(i, j-i));
            i = j - 1;
            if (preop == '*') {
                st.back() *= num;
                preop='X';
            } else if (preop == '/') {
                st.back() /= num;
                preop='X';
            } else {
                st.push_back(num);
            }
        }
        //错误， 加减法只能从左往右计算
        if (st.size() != stop.size() + 1) { // Error
            return -100;
        }
        int total = st[0];
        for (int i = 0; i < stop.size(); i++) {
            if (stop[i] == '+') {
                total += st[i+1];
            } else {
                total -= st[i+1];
            }
        }
        return total;
    }

    //M3 one stack 借鉴官方解法
    int calculate(string s) {
        vector<int> st;
        int len = s.size();
        char preop = '@';
        for (int i = 0; i < len; i++) {
            char& ch = s[i];
            if (ch == ' ') {
                continue;
            }
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                preop = ch;
                continue;
            }
            int j = i;
            while(j < len && isdigit(s[j])) {
                j++;
            }
            int num = stoi(s.substr(i, j-i));
            i = j - 1;
            // * / 就地算，+-先入栈
            if (preop == '*') {
                st.back() *= num;
            } else if (preop == '/') {
                st.back() /= num;
            } else if (preop == '-'){
                st.push_back(-num);
            } else if (preop == '+') {
                st.push_back(num);
            } else {
                st.push_back(num);
            }
        }
        return accumulate(st.begin(), st.end(), 0);
    }
};
// @lc code=end

/*
Wrong Answer
87/111 cases passed (N/A)
Testcase
"1-1+1"
Answer
-1
Expected Answer
1


加减法只能从左往右计算
1-1+1 = 0+1=1
Error
1-1+1 = 1 - (1+1) = 1 - 2 = -1

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


