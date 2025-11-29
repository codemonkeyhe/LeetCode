/**
 * @file
 * @brief  P11
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-18
 * @tag   math, recursion
 * @similar  50, 372
 */

/*
Implement pow(x, n), which calculates x raised to the power n (x^n).

Example 1:
Input: 2.00000, 10
Output: 1024.00000

Example 2:
Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25

Note:
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:

    double pow(double x, long n) {
        if (n==0) {
            return 1;
        }
        if (n==1) {
            return x;
        }
        double res=pow(x, n>>1);
        res*=res;
        if (n&0x01) {
            res=res*x;
        }
        return res;
    }

    //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
    //Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Pow(x, n).
    /*
Runtime Error Message:
Line 24: Char 36: runtime error: signed integer overflow: -2147483648 * -1 cannot be represented in type 'int' (solution.cpp)
Last executed input:
1.00000
-2147483648
    */
    double myPow(double x, int n) {
        /*
        double res = 0;
        if (n>=0) {
            res = pow(x, n);
        } else {
            //BUG res = 1/pow(x, -n);
            res = 1.0/pow(x, (long)n*(long)-1);
        }
        */
        return (n>=0)? pow(x, n): 1.0/pow(x, n*(long)-1) ;
    }

};



double myPow(double x, int n){
    return 0;
}

int main() {

    Solution s;
    double x = 2.0;
    int n = 4;
    cout << s.myPow(x, n) << endl;

    return 0;
}


/*
M0 ???
O(N)

M1  ???
O(lgN)

M2 ???
BOP
https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/

https://leetcode.com/problems/powx-n/discuss/19544/5-different-choices-when-talk-with-interviewers
*/