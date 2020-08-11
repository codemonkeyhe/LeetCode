/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-17; 2020-08-09
 */

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.

Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 2^31 − 1 when the division result overflows.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Error Case-Runtime Error
2147483647
1
Line 19: Char 25: runtime error: shift exponent 32 is too large for 32-bit type 'unsigned int' (solution.cpp)

BUG:
long dvd = dividend > 0 ? dividend : -dividend;
Line 12: Char 46: runtime error: negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself (solution.cpp)
当dividend＝-2147483648时，-dividend便越界，超出了int范围

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
Memory Usage: 5.9 MB, less than 75.91% of C++ online submissions for Divide Two Integers.
*/
    int divide(int dividend, int divisor) {
        if (divisor == -1 && dividend == INT_MIN) {
            //dvd=INT_MIN, dvs=-1,  ret=2^31，overflow, 因此ret=2^31-1
            return INT_MAX;
        }
        //同号结果为正 sign=1 异号结果为负 sign=0
        int sign = (dividend > 0) == (divisor > 0);
        long count = 0;
        long dvd = dividend;
        long dvs = divisor;
        if (dvd < 0 ) dvd = -dvd;
        if (dvs < 0 ) dvs = -dvs;
        while (dvd >= dvs) {
            long c = 1;
            //BUG int tmp = dvs;
            long tmp = dvs;
            while ((tmp << 1) <= dvd) {
                c <<= 1;
                tmp <<= 1;
            }
            count += c;
            dvd -= tmp;
        }
        return sign ? count : -count;
    }

};

int divide(int dividend, int divisor){

}

int main() {
    int a = 1;
    cout << (a << 31) << endl;
    cout << (a << 30 << 1) << endl;
    cout << (a << 32) << endl;
    cout << (a << 31 << 1) << endl;
    return 0;
    // int dvd = -10;
    // int dvs = 3;
    int dvd = 2147483647;
    int dvs = 1;
    Solution s;
    cout << s.divide(dvd, dvs) << endl;

    return 0;
}


/*
Tips
因为题目不允许用 * / %
只能用 + - <<

陷阱
abs(INT_MIN)= undefined behavior
INT_MIN=-2^31 的处理
法1  转为正数时用long 或者 unsigned int
法2  全部转为负数处理
法3 [已失效]  tricky skill: a - (b << x << 1) >= 0
https://leetcode.com/problems/divide-two-integers/discuss/142849/C%2B%2BJavaPython-Should-Not-Use-%22long%22-Int
b << m << n 等于  ((b<<m) <<n)

特殊情况
dvd=INT_MIN, dvs=-1,        ret=2^31，overflow, 因此ret=2^31-1
dvd=INT_MIN, dvs=INT_MIN,   ret=1
dvd!=INT_MIN, dvs=INT_MIN,   ret=0
dvd=INT_MIN, dvs!=INT_MIN,   ret=0


M1 朴素减法
dvd - dvs*n, n=1,2,3,4...
必然超时


M2 指数增长的减法[本质上是二分法]
new_dvd=dvd - dvs* 2^n,  n=k, k-1,...2,1;每次尽可能的减去最多数目的2^n。
2^n == 1<<n
dvs* 2^n === dvs<<n
https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations
https://leetcode-cn.com/problems/divide-two-integers/solution/yong-fu-shu-yun-suan-jian-hua-bian-jie-chu-li-by-g/

M3 O(32)
https://leetcode.com/problems/divide-two-integers/discuss/142849/C%2B%2BJavaPython-Should-Not-Use-%22long%22-Int
  int divide(int A, int B) {
        if (A == INT_MIN && B == -1) return INT_MAX;
        int a = abs(A), b = abs(B), res = 0;
        for (int x = 31; x >= 0; x--)
            if ((signed)((unsigned)a >> x) - b >= 0)
                res += 1 << x, a -= b << x;
        return (A > 0) == (B > 0) ? res : -res;
    }
https://leetcode.com/problems/divide-two-integers/discuss/13420/32-times-bit-shift-operation-in-C-with-O(1)-solution
B/A=ret,  [A*ret==B]
记ret = a0 + a1*2 + a2*2^2 + ...... + a29*2^29 + a30*2^30 + a31*2^31; 其中ai = 0 or 1, i = 0......31
the dividend B and divisor A is non-negative, then
A * (a0 + a1*2 + a2*2^2 + ...... + a29*2^29 + a30*2^30 + a31*2^31) = B; 记为Eq1
(1) when Eq1 divided by 2^31, we can get A*a31 = B>>31; then a31 = (B>>31)/A;
if (B>>31) > A, then a31 = 1; else a31 = 0;
(2) when Eq1 divided by 2^30, we can get A*a30 + A*a31*2 = B>>30; then a30 = ((B>>30) - a31*A*2)/A;
and (B>>30) - a31*A*2 can be rewritten by (B-a31*A<<31)>>30,
so we make B' = B-a31*A<<31, the formula simplified to a30 = (B'>>30)/A

辅助分析
当B/A=ret时,(这里的/是程序的除法，即舍弃余数),则有 A*ret 约等于 B，记为式子eq1:  A*ret ~=~ B
由基本原理可知， 当 A==C时，  有 A*B==C*B , A/B==C/B
当 A==C时，  有 A<<B==C<<B , A>>B==C>>B
回到 Eq1,  把等号==变成约等号~=~时， 依然满足移位运算符。
当 A*ret ~=~ B时，有  (A*ret) / 2^31 ~=~ B/ 2^31  即  A * (ret/2^31) ~=~ B/2 ^31 ， A *(ret>>31)　~=~ B>>31
ret>>31 为 ret的二进制的第31位的a31， 即 A*a31 ~=~ B>>31


*/
