/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-24
 * @tag
 */

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:
Coud you solve it without converting the integer to a string?
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 12 ms, faster than 82.75% of C++ online submissions for Palindrome Number.
Memory Usage: 6 MB, less than 50.95% of C++ online submissions for Palindrome Number.

x: 12521  ->  252  ->  5
w: 10000  ->  100  ->  1
left: 1   ->  2
right: 1  ->  2
*/
    bool isPalindromeM2(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        long long w = 1;
        while (x >= w) {
            w*=10;
        }
        w = w / 10;
        int right = 0;
        int left = 0;
        while (x) {
            left = x/w;
            right = x % 10;
            if (left != right) {
                return false;
            }
            x = x - w * left; //砍掉最左边的数字
            x = x / 10;      //砍掉最右边的数字
            w = w / 100;
        }
        return true;
    }

/*
Runtime: 12 ms, faster than 82.75% of C++ online submissions for Palindrome Number.
Memory Usage: 6.1 MB, less than 32.09% of C++ online submissions for Palindrome Number.
*/
    bool isPalindromeM1(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        long long w = 1;
        int len = 0;
        while (x >= w) {
            w*=10;
            len++;
        }
        int right = 0;
        for (int i = 0; i < len/2; ++i) {
            right = right * 10 + x % 10;
            x /= 10;
        }
        if (len & 0x01) {  // len是奇数
            x /= 10;
        }
        return x == right;
    }

/*
最右边是0的一定不是回文，因为正数不可能以0打头
Runtime: 4 ms, faster than 99.05% of C++ online submissions for Palindrome Number.
Memory Usage: 6.1 MB, less than 26.50% of C++ online submissions for Palindrome Number.
Next challenge
*/
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        if (x < 10)
            return true;
        int right = 0;
        //BUG  while (x >= right) {
        while (x > right) {
            right = right * 10 + x % 10;
            x /= 10;
        }
        return (x == right) || (x == right / 10);
    }

};



int main() {
    Solution s;
}


/*
Tips
M1 逆序比较是否相等
逆序只需要逆后半部的序，比较相等即可
整个逆序会越界，例如2 345 678 999 逆序的话会大于INT_MAX
12531
13!=12
135!=125

不管怎样，都得计算一下数字长度
关键点在于避免计算数字长度
12521   0
1252    1
125     12
12      125

M2

*/


