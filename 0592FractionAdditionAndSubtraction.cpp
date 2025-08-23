/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-23
 * @tag  simulation
 * @similar  537, 592, 640
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 *
 * https://leetcode.cn/problems/fraction-addition-and-subtraction/description/
 *
 * algorithms
 * Medium (59.71%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 51.4K
 * Testcase Example:  '"-1/2+1/2"'
 *
 * 给定一个表示分数加减运算的字符串 expression ，你需要返回一个字符串形式的计算结果。 
 * 这个结果应该是不可约分的分数，即 最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2
 * 应该被转换为 2/1。
 *
 *
 *
 * 示例 1:
 * 输入: expression = "-1/2+1/2"
 * 输出: "0/1"
 *
 *
 * 示例 2:
 * 输入: expression = "-1/2+1/2+1/3"
 * 输出: "1/3"
 *
 *
 * 示例 3:
 * 输入: expression = "1/3-1/2"
 * 输出: "-1/6"
 *
 *
 *
 * 提示:
 * 输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
 * 输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
 * 输入只包含合法的 最简分数，每个分数的分子与分母的范围是 [1,10]。 如果分母是 1，意味着这个分数实际上是一个整数。
 * 输入的分数个数范围是 [1,10]。
 * 最终结果 的分子与分母保证是 32 位整数范围内的有效整数。
 *
 *
 */

// @lc code=start
class Solution {
public:

    string fractionAddition(string expression) {
        int len = expression.size();
        bool sign = true; //true:+ false: -
        int isUp = 1;
        vector<int> up;
        vector<int> down;

        for (int i = 0; i < len; i++) {
            char& cur = expression[i];
            if (cur >= '0' && cur <= '9') {
                int j = i;
                while (j < len && isdigit(expression[j])) {
                    j++;
                }
                int nl = j - i;
                string ss = expression.substr(i, nl);
                int num = stoi(ss);
                if (isUp) { //分子带符号，分母无符号
                    if (!sign) {
                        num = -num;
                    }
                    up.push_back(num);
                    isUp = 0;
                } else {
                    down.push_back(num);
                    isUp = 1;
                }
                i = j - 1;
                continue;
            }
            if (cur == '+') {
                sign = true;
            } else if(cur == '-') {
                sign = false;
            } else if (cur == '/') {
                //BUG isUp = ~isUp;  ~ 按位取反
                // isUp 是bool类型，
            }
        }

        int downAll = 1;
        //反正要化简，不用求所有 down的最大公倍数
        for (int i = 0; i < down.size(); i++) {
            downAll = downAll * down[i];
        }
        int upAll = 0;
        for (int i = 0; i < up.size(); i++) {
            int p = downAll/down[i];
            upAll += up[i] * p;
        }
        // upAll/downAll
        int common = gcd(abs(upAll), downAll);
        upAll = upAll/common;
        downAll = downAll/common;
        string res = to_string(upAll) + "/" + to_string(downAll);
        return res;
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a%b);
    }
};
// @lc code=end

/*
6 9
gcd=3
6*9/3=18


-1/2+1/2

不存在下面这种格式 ？？
-1/-2+1/2


-1/2+1/2+1/3

-1 1 1
2  2  3

-6 6  4
12 12 12

4
12

1
3


8
36


输入
expression =
"1/3-1/2"
输出
"1/-6"
预期结果
"-1/6"


1  -1
3   2
2  -3
6  6

-1 6


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
