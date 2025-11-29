/**
 * @file
 * @brief BOP 2.4
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-04-11
 */

/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example:
Input: 13
Output: 6

Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n<=0) {
            return 0;
        }
        unsigned int lowNum = 0;
        unsigned int curNum = 0;
        unsigned int highNum = 0;
        unsigned int factor = 1;
        unsigned int res = 0;
        while(n>=factor) {
       // while(n/factor!=0) {
            curNum =  (n/factor)%10;
            lowNum = n%factor;
            highNum = n/factor/10;
            if(curNum == 0) {
                res += highNum*factor;
            } else if (curNum == 1) {
                res += highNum*factor + lowNum+1;
            } else {  // >=2
                res += (highNum+1)*factor;
            }
            if (highNum ==0) { //XXX factor*10 will overflow max int
                break;
            }
            factor *=10;
        }
        return res;
    }

};



int main() {

    Solution s;
    cout << s.countDigitOne(1410065408) << endl;
    // 1737167499
   // cout << s.countDigitOne(123) << endl;
    // 57

    return 0;
}


/*
M0 暴力法 超时

M1 规律法
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Digit One.
Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Number of Digit One.

abcd
记 count(X1XX)=[1 .. a0cd]序列中百位1的数目
case0  b=0　a0cd
count(X1XX) = a*100
Exp: 100-199  1100-1199  ..  (a-1)100-(a-1)199

case1  b=1　a1cd
count(X1XX) = a*100 +  cd +1
Exp: 100-199  1100-1199  ..  (a-1)100-(a-1)199
a100-a1cd

case2  b>1  a2cd
count(X1XX) = (a+1) * 100
Exp: 100-199  1100-1199  ..  a100-a199


十位，个位同理



*/