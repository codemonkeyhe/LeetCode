/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-25
 * @tag stack
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
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 *
 * https://leetcode.cn/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (42.68%)
 * Likes:    1124
 * Dislikes: 0
 * Total Accepted:    178.8K
 * Total Submissions: 411.2K
 * Testcase Example:  '"1 + 1"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 * 注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
 *
 *
 *
 * 示例 1：
 * 输入：s = "1 + 1"
 * 输出：2
 *
 *
 * 示例 2：
 * 输入：s = " 2-1 + 2 "
 * 输出：3
 *
 *
 * 示例 3：
 * 输入：s = "(1+(4+5+2)-3)+(6+8)"
 * 输出：23
 *
 *
 * 提示：
 * 1 <= s.length <= 3 * 10^5
 * s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
 * s 表示一个有效的表达式
 * '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
 * '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
 * 输入中不存在两个连续的操作符
 * 每个数字和运行的计算将适合于一个有符号的 32位 整数
 *
 *
 */

// @lc code=start
class Solution {
  public:
    // Ugly
    int calculateUgly(string s) {
        int res = 0;
        int len = s.size();
        stack<string> st;
        for (int i = 0; i < len; i++) {
            char &cur = s[i];
            if (cur == ' ') {
                continue;
            }
            if (cur == '(' || cur == '+' || cur == '-') {
                st.push(string(1, cur));
                continue;
            }
            if (cur == ')') { // pop until meet (
                int sum = 0;
                int preNum = 0;
                // ( A+B;  (A-B; ( -B
                while (!st.empty()) {
                    auto ss = st.top();
                    st.pop();
                    if (ss == "(") {
                        sum += preNum;
                        st.push(to_string(sum));
                        break;
                    }
                    if (ss == "+") {
                        sum += preNum;
                        preNum = 0;
                    } else if (ss == "-") {
                        sum -= preNum;
                        preNum = 0;
                    } else {
                        preNum = stoi(ss);
                    }
                }
                continue;
            }
            // num
            int j = i;
            while (j < len && isdigit(s[j])) {
                j++;
            }
            string num = s.substr(i, j - i);
            st.push(num);
            i = j-1; // beCareful, not i=j , as i will i++
        }
        int preNum = 0;
        while (!st.empty()) {
            auto ss = st.top();
            st.pop();
          //  cout << "ss=" << ss << endl;
            if (ss == "+") {
                res += preNum;
                preNum = 0;
            } else if (ss == "-") {
                res -= preNum;
                preNum = 0;
            } else {
                preNum = stoi(ss);
            }
        }
        res += preNum;
        return res;
    }

    int calculate(string s) {
        int res = 0;
        int len = s.size();
        int sign = 1;  // 1 means + , -1 means -
        stack<int> signs;
        signs.push(sign);
        for (int i = 0; i < len; i++) {
            char &cur = s[i];
            if (cur == ' ') {
                continue;
            }
            if (cur == '+') { // no need to change sign
                sign = signs.top();
            } else if (cur == '-') {
                sign = -signs.top();
            } else if (cur == '(') {
                signs.push(sign);
            } else if (cur == ')') {
                signs.pop();
            } else {
                /* still ok
                int j = i;
                while (j < len && isdigit(s[j])) {
                    j++;
                }
                int num = stoi(s.substr(i, j - i));
                i = j - 1;
                */
                long num = 0;
                while (i < len && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                res += sign * num;
                i--;
            }
        }
        return res;
    }
};
// @lc code=end

/*
TestCase

"6-(-((-2)))"
want: 6-2=4

"6-(-(-(-2)))"
Want: 6+2 = 8

Wrong Answer
1/47 cases passed (N/A)
Testcase
" 2-1 + 2 "
Answer
-1
Expected Answer
3


(1+3)-(6+8)  = 4-14=-10
stack1
8
6
3
1
stack2
)
+
(
-
)
+
(


(1+(4+5+2)-3)-(6+8)"
(1+(4+5+2)-3)-6+8"

(+A-B)


Runtime Error
2/47 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::invalid_argument'
terminate called after throwing an instance of 'std::invalid_argument'
  what():  stoi
Testcase
"(1+(4+5+2)-3)+(6+8)"
Expected Answer
23


Wrong Answer
39/47 cases passed (N/A)
Testcase
"1-(     -2)"
Answer
1
Expected Answer
3
Stdout
ss=0
ss=-
ss=1

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


