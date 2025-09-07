/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-06
 * @tag simulation,math
 * @similar  592, 640
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 *
 * https://leetcode.cn/problems/solve-the-equation/description/
 *
 * algorithms
 * Medium (44.40%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    40.6K
 * Total Submissions: 91.5K
 * Testcase Example:  '"x+5-3+x=6+x-2"'
 *
 * 求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。
 * 如果方程没有解或存在的解不为整数，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。
 * 题目保证，如果方程中只有一个解，则 'x' 的值是一个整数。
 *
 *
 *
 * 示例 1：
 * 输入: equation = "x+5-3+x=6+x-2"
 * 输出: "x=2"
 *
 *
 * 示例 2:
 * 输入: equation = "x=x"
 * 输出: "Infinite solutions"
 *
 *
 * 示例 3:
 * 输入: equation = "2x=x"
 * 输出: "x=0"
 *
 *
 *
 *
 * 提示:
 * 3 <= equation.length <= 1000
 * equation 只有一个 '='. 
 * 方程由绝对值在 [0, 100]  范围内且无任何前导零的整数和变量 'x' 组成。​​​
 *
 *
 */

// @lc code=start
class Solution {
public:
    pair<int, int> parseStr(string& ss) {
        int len = ss.size();
        int x = 0;
        int sum = 0;
        int sign = 1; // + 1 - 0
        for (int i = 0; i < len; i++) {
            char& cur = ss[i];
            if (cur == '+') {
                sign = 1;
            } else if (cur == '-') {
                sign = 0;
            } else if (cur == 'x') {
                if (sign) {
                    x++;
                } else {
                    x--;
                }
            } else { // num
                int j = i;
                while(j < len && isdigit(ss[j])) {
                    j++;
                }
                int slen = j - i;
                int num = stoi(ss.substr(i, slen));
                if (j < len && ss[j] == 'x') {
                    if (sign) {
                        x += num;
                    } else {
                        x -= num;
                    }
                    i = j;
                } else {
                    if (sign) {
                        sum += num;
                    } else {
                        sum -= num;
                    }
                    i = j - 1;
                }
            }
        }
        return make_pair(x, sum);
    }


    string solveEquation(string equation) {
        int len = equation.size();
        int idx = equation.find('=', 0);
        string leftPart = equation.substr(0, idx);
        string rightPart = equation.substr(idx + 1);
        auto [leftX, leftSum] = parseStr(leftPart);
        auto [rightX, rightSum] = parseStr(rightPart);
        int a = leftX - rightX;
        int b = rightSum - leftSum;
        // ax = b; x = b/a
        if (a == 0) {
            if (b != 0) {
                return "No solution";
            }
            return "Infinite solutions";
        }
        if (b%a != 0) {
            return "No solution";
        }
        string res = "x=";
        res += to_string(b/a);
        return  res;
    }
};
// @lc code=end

/*
Wrong Answer
42/59 cases passed (N/A)
Testcase
"x=x+2"
Answer
"Infinite solutions"
Expected Answer
"No solution"
Stdout
ss=x
ss=x+2

Wrong Answer
50/59 cases passed (N/A)
Testcase
"1+1=x"
Answer
"No solution"
Expected Answer
"x=2"
Stdout
ss=1+1
ss=x


2=x

-x=-2
a=-1
b=-2


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
