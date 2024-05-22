/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-22
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 *
 * https://leetcode.cn/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (54.66%)
 * Likes:    302
 * Dislikes: 0
 * Total Accepted:    72.4K
 * Total Submissions: 132.4K
 * Testcase Example:  '26'
 *
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 *
 * 注意:
 *
 *
 * 十六进制中所有字母(a-f)都必须是小写。
 *
 * 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
 * 给定的数确保在32位有符号整数范围内。
 * 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
 *
 *
 * 示例 1：
 * 输入:
 * 26
 *
 * 输出:
 * "1a"
 *
 *
 * 示例 2：
 * 输入:
 * -1
 *
 * 输出:
 * "ffffffff"
 *
 *
 */

// @lc code=start
class Solution {
public:

    string toHex(int num) {
        string res;
        if (num==0)  {return "0";}
        // 复杂了，可以用   string pos = "0123456789abcdef";
        char n2s[17] = {'0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

        int i = 1;
        while (i <= 8) {
            int low = num & 0x0000000F;
            res = n2s[low] + res;
            num = num >> 4;
            i++;
        }
        int j = 0;
        while (res[j] == '0') {
            j++;
        }
        int leng = res.size() - j;
        return res.substr(j, leng);
    }
};
// @lc code=end

/*

M1 每4bit转换
补=原取反+1
-1 原  = 1000 0000 0000 0000 0000 0000 0000 0001
-1 补  = 1111 1111 1111 1111 1111 1111 1111 1110 + 0x00000001 =  0xFFFF FFFF


-26 原        = 1000 0000 0000 0000 0000 0000 0001 1010
-26 补码表示   = 1111 1111 1111 1111 1111 1111 1110 0101 + 0x00000001 =  0xFFFF FFE6

～(-26) = 0x00000019  = 19



M2
位权 16^2 16^1 16^0
26 % 16 = 1 ...10



0x123 =  16^2 * 1 + 16^1 * 2 + 16^0 * 3 = 256 + 32 + 3   = 291

291%16=3  等于16进制的最低位
291/16=18   18%16=2 等于16进制的倒数第2位
18/16 = 1   1%16=1 等于16进制的倒数第3位

n每次取模16 ,相当于丢弃最低位。等同于10进制每次模10，相当于丢弃个位

0x123=291
0x12=18
0x1=1


12345%10=1234
0x12345%16=0x1234
0x1234%16=0x123




*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


