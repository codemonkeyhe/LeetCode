/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-
 * @tag
 */

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

/*
陷阱 溢出的数要返回0
1534236469
处理最后一位时溢出了
 964632435 * 10 cannot be represented in type 'int'

 Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
Memory Usage: 5.9 MB, less than 94.66% of C++ online submissions for Reverse Integer.
*/
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        bool positive = true;
        if (x < 0) {
            positive =  false;
            x = -x;
        }
        int res = 0;
        int num = 0;
        while (x != 0) {
            num = x % 10;
            //BUG if (res * 10 > INT_MAX) {
            if (res  > INT_MAX/10) {
                return 0;
            }
            res = res * 10 + num;
            x /=10;
        }
        return positive ? res : -res;
    }

};



int main() {
    Solution s;
}



/*
Tips
M1

M2

*/


