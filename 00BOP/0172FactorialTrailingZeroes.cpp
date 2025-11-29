/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-31
 */

/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:
   int trailingZeroes(int n) {
       int res = 0;
       int tmp = 0;
       while(n>0) {
           tmp = n/5;
           res += tmp;
           n=tmp;
       }
       return res;
    }
};



int main() {

    Solution s;
    cout << s.trailingZeroes(5) << endl;
    return 0;
}


