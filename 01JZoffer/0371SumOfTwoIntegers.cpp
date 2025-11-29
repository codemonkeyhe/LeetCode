/**
 * @file
 * @brief  P47
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-12
 * @tag  bitManipulation;
 * @similar
 */

/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = -2, b = 3
Output: 1
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Line 5: Char 26: runtime error: left shift of negative value -2147483648 (solution.cpp)
-1
1

Runtime: 4 ms, faster than 17.00% of C++ online submissions for Sum of Two Integers.
Memory Usage: 5.9 MB, less than 92.24% of C++ online submissions for Sum of Two Integers.
*/
    int getSum(int a, int b) {
        //BUG int carry = (a&b)<<1;
        //BUG long long carry = (a & b) << 1;
        //BUG unsigned int carry = (a & b) << 1;
        int carry = ((unsigned int)(a & b)) << 1;
        if (carry == 0) {
            return a^b;
        }
        return getSum(a^b, carry );
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Two Integers.
Memory Usage: 6.1 MB, less than 28.27% of C++ online submissions for Sum of Two Integers.
*/
    int getSum(int a, int b) {
        do {
            int carry = ((unsigned int)(a & b)) << 1;
            a = a^b;
            b = carry;
        } while (b != 0);
        return a;
    }

};


int getSum(int a, int b){

}


int main() {
    Solution s;
    int a = -1;
    int b = 1;
    printf("%x\n", a);
    printf("%x\n", b);
    printf("%x\n", a^b);
    printf("%x\n", a&b);
   // return 0;

    cout << s.getSum(a,b) << endl;
}


/*
Tips

M1  位操作  Recursion
a+b
从二进制角度来看，分为2部分
加法和进位
加法 用 a^b来代替
进位 0+1=1 1+0=1 0+0=0 1+1=1
只有二进制的两个位同时为1才有进位
进位可以用 (a&b)求出同时为1的位，这些位相加为产生进位，进位是向左进位 ，所以 (a&b)<<1 就是进位了
因此 res = (a^b) + ((a&b)<<1);
但是不能用加法  但是这是一个递归的问题， 技巧点在于递归终止条件不容易发现
直觉加分析可得，每次递归的进位一定会越来越少，直到某一次进位为0，res=A^B就是结果了。

负数的符号位不好搞
-1 + 1 = 0
-1 = [FFFFFFFF]补
+1 = [00000001]补

负数左移不支持？？
Line 6: Char 33: runtime error: left shift of negative value -16 (solution.cpp)
需要特别注意的是unsigned int的用法。
《Primer C++ 第五版》P33：
我们赋给带符号类型一个超出它表示范围的值时，结果是未定义的。此时，程序可能继续工作、可能崩溃、也可能生成垃圾数据。
当a & b的结果是负数时，左移就会造成符号位的溢出，所以此处需要转换为unsigned int来避免可能出现的左移越界行为。
作者：hawjk
链接：https://leetcode-cn.com/problems/sum-of-two-integers/solution/cliang-chong-jie-fa-tian-keng-wei-yun-suan-de-yue-/

M2  位操作  Iteration

*/


