/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-23
 * @tag
 */

/*
Reverse bits of a given 32 bits unsigned integer.
Example 1:
Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:
Input: 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

Note:
Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above the input represents the signed integer -3 and the output represents the signed integer -1073741825.

Follow up:
If this function is called many times, how would you optimize it?

Constraints:
The input must be a binary string of length = 32
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 4 ms, faster than 69.12% of C++ online submissions for Reverse Bits.
Memory Usage: 6.1 MB, less than 27.33% of C++ online submissions for Reverse Bits.
*/
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n&0x01) {
                res |= (1 << (31 - i));
            }
            n >>= 1;
        }
        return res;
    }

/*
Runtime: 8 ms, faster than 15.85% of C++ online submissions for Reverse Bits.
Memory Usage: 5.9 MB, less than 79.94% of C++ online submissions for Reverse Bits.
*/
    uint32_t reverseBits(uint32_t n) {
        int bitI = 0;
        int bitJ = 0;
        for (int i = 0; i <= 15; ++i) {
            bitI = n&(1<<i);
            bitJ = n&(1<<(31-i));
            if (!bitI && !bitJ)
                continue;
            if (!bitI || !bitJ)  { //bit-i ^ bit-j ==1
                //swap(bitI, bitJ)  用加减法实现swap
                //n_bitI=~bitI
                //n_bitJ=~bitJ
                if (bitI==0) {
                    n = n - bitJ + (1 << i);
                } else {
                    n = n - bitI + (1 << (31 - i));
                }
            }
        }
        return n;
    }



};


int main() {
    Solution s;
}



/*
Tips
M1 常规逻辑法
O(32)

M2 swap法
swap(bit-0, bit-31);
...
swap(bit-15, bit-16);
当swap(bit-i, bit-j)时，有四种情况,只有2种情况需要swap，就是 bit-i ^ bit-j == 0x01时才需要
bit-i bit-j
0 0   no-swap
1 1　 no-swap
0 1   need-swap   bit-i = ~bit-i   bit-j = ~bit-j
1 0   need-swap   same-as-before


M3 O(1)大法
https://leetcode.com/problems/reverse-bits/discuss/54741/O(1)-bit-operation-C%2B%2B-solution-(8ms)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
for 8 bit binary number abcdefgh, the process is as follow:

abcdefgh -> efghabcd -> ghefcdab -> hgfedcba


*/


