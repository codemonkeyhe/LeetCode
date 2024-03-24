/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-03-12
 * @tag
 * @similar
 */

/*
请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。

示例 1：
输入：s = "42"
输出：42


示例 2：
输入：s = "   -42"
输出：-42


示例 3：
输入：s = "4193 with words"
输出：4193


提示：
0 <= s.length <= 200
s 由英文字母（大写和小写）、数字（0-9）、' '、'+'、'-' 和 '.' 组成

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
   public:
    int myAtoi(string s) {
        unsigned long long res = 0;
        bool plus = true;
        int i = 0;
        for (i = 0; i < s.length(); i++) {
            char& cur = s[i];
            if (cur != ' ') {
                break;
            }
        }
        if (s[i] == '-') {
            plus = false;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        for (; i < s.length(); i++) {
            char& cur = s[i];
            if (cur < '0' || cur > '9') {
                break;
            }
            if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && cur > '7')) {
                return plus ? INT_MAX : INT_MIN;
            }

            int val = cur - '0';
            res = res * 10 + val;
        }
        if (!plus) {
            return -res;
        }
        return res;
    }
};

int main() {
    Solution s;
    if (0) {
        string in = "42";
        auto res = s.myAtoi(in);
        cout << res << endl;
    }

    // INT_MIN=-2147483648
    // INT_MAX=2147483647
    cout << "INT_MIN=" << INT_MIN << endl;
    cout << "INT_MAX=" << INT_MAX << endl;

    if (0) {
        // 大于 unsigned long long
        string in = "18446744073709551617";
        auto res = s.myAtoi(in);
        // want : 2147483647
        cout << res << endl;
    }

    if (0) {
        // 大于 unsigned long long
        string in =
            "100000000000000000000000000000000000000000000000000000000000000000"
            "00000000000000000000000000000000000000522545459";
        auto res = s.myAtoi(in);
        // want : 2147483647
        cout << res << endl;
    }

    if (1) {
        string in = "-2147483649";
        auto res = s.myAtoi(in);
        // want : -2147483648
        cout << res << endl;
    }
}

/*
Tips

M1 普通转换法

M2 状态机【较为复杂】

核心： 对于越界的处理
本题可能产生溢出的步骤在于推入、乘以 101010 操作和累加操作都可能造成溢出。对于溢出的处理方式通常可以转换为 INT_MAX 的逆操作。比如判断某数乘以 101010 是否会溢出，那么就把该数和 INT_MAX 除以 101010 进行比较。

    // INT_MIN=-2147483648 = 214748364*10+8
    // INT_MAX=2147483647  = 214748364*10+7

因此，如果 res>214748364 ，下一轮扩充末尾的数字时，必然越界
因此，如果 res=214748364 ，下一轮扩充末尾的数字时，大于7则必然越界
如果是正数，则返回 INT_MAX
如果是负数，要么越界，要么等于 INT_MIN，此时返回 INT_MIN都对


long long的最大值：9223372036854775807  // 19位
long long的最小值：-9223372036854775808

unsigned long long的最大值：18446744073709551615  //20位

18446744073709551615
18446744073709551617



        cout << "i = " << i << " res=" << res << endl;
*/
