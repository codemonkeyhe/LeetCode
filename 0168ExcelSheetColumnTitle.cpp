/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-29
 * @tag math
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode.cn/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (44.70%)
 * Likes:    684
 * Dislikes: 0
 * Total Accepted:    156.7K
 * Total Submissions: 350.4K
 * Testcase Example:  '1'
 *
 * 给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
 *
 * 例如： 本质是27进制，但是没有0,退化成26进制
 * A -> 1
 * B -> 2
 * C -> 3
 * Z -> 26
 * AA -> 27
 * AB -> 28
 *
 * 示例 1：
 * 输入：columnNumber = 1
 * 输出："A"
 *
 *
 * 示例 2：
 * 输入：columnNumber = 28
 * 输出："AB"
 *
 *
 * 示例 3：
 * 输入：columnNumber = 701
 * 输出："ZY"
 *
 *
 * 示例 4：
 * 输入：columnNumber = 2147483647
 * 输出："FXSHRXW"
 *
 *
 *
 *
 * 提示：
 * 1 <= columnNumber <= 231 - 1
 *
 *
 *
 */

// @lc code=start
class Solution {
public:

    //   In a mess
    string convertToTitleWTF(int columnNumber) {
        // 0 is placeholder
        string i2a = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res = "";
        /*
        if (columnNumber <= 26) {
            res += i2a[columnNumber];
            return res;
        }
        */
        int n = columnNumber;
        while (n != 0) {
            int p = n/26;
            if (p *26 == n) { //整除
                res+='Z';
                n = n / 26;
                continue;
            }
            int low = n % 26;
            res += i2a[low];
            n = n / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string convertToTitle(int columnNumber) {
        string i2a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res = "";
        int n = columnNumber;
        while (n > 0) {
            n = n-1;
            int low = (n)%26;
            res += i2a[low];
            n = n / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }

};
// @lc code=end


/*
16进制从0开始计数， 0～15
0
1
2
...
9
10 A
11 B
12 C
13 D
14 E
15 F
16 A0
17 A1

EF = 14*16+15

 * 例如： 本质是27进制，但是没有0,退化成26进制
 * A -> 1
 * B -> 2
 * C -> 3
 * Y    25
 * Z -> 26  27进制理论上是A0
 * AA -> 27
 * AB -> 28
 * ...
 * AY    51  = 1*26+Y = 1*26+25
 * AZ -> 52  = 1*26+Z = 1*26+26
 * B1 -> 53  = 2*26+1 =
 *
 * ZY -> 701 = 26*26+25=


 * A -> 1  0
 * B -> 2  1
 * C -> 3  2
 * Y -> 25 24
 * Z -> 26  25
 * AA -> 27  26
 * AB -> 28  27


10  3进制   3进制字母表示   3进制无0
 0   0       a (=0)
 1   1       b (=1)     a(=1)
 2   2       c (=2)     b(=2)
 3   10      ba         c(=3)
 4   11      bb         aa(=4) = 3*1+1
 5   12      bc         ab(=5) = 3*1+2
 6   20      ca         ac(=6) = 3*1+3
 7   21      cb         ba=7   = 3*2+1
 8   22      cc         bb=8   = 3*2+2
 9   100     baa        bc=9   = 3*2+3
 10  101     bab        ca=10  = 3*3+1
 11  102     bac        cb=11  = 3*3+2
 12  110     bba        cc=12  = 3*3+3
                        aaa=13

从上可以看出，
3进制无0的特点，因为没有0的存在，所以 余数是1，2，3，看起来应该%4，但是余数不存在0
同时权重位的确是3，感觉应该是%3才合理

10进制的权重位是10，16进制的权重位是16，权重位肯定是金标准，因此，必然是%3，也就是3进制，只是余数从1～3，把余数偏移一位，也就是-1，让余数落到0～2的范围，这样符合%3的要求，也和权重位对其，因此，出现了下面的变体



n        str
 1        a(=1)  0   + 1
 2        b(=2)  1   + 1
 3        c(=3)  2   + 1
 4        aa=4 = 3*1+0 +1
 5        ab=5 = 3*1+1 +1
 6        ac=6 = 3*1+2 +1
 7        ba=7   = 3*2+0 +1
 8        bb=8   = 3*2+1 +1
 9        bc=9   = 3*2+2 + 1
 10       ca=10   = 3*3+0 +1
 11       cb=11  = 3*3+1 +1
 12       cc=12  = 3*3+2 +1

 由上可以发现
 n = 3*x + y +1 ( y=n%3) ,其中3是进制
 因此可以发现
 n-1 = 3*x+y 就是典型的3进制套路

存在字母表 0-a 1-b 2-c
当n=4时，期望得到aa，
n-1=3
3%3=0 最低位是0,  因此是a
n=n/3 = 4/3=1
1-1=0,0%3=0，依然是 a



*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


