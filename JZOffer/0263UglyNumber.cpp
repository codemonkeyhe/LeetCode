/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2022-06-22
 * @tag
 * @similar
 */

/*
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:
Input: 6
Output: true
Explanation: 6 = 2 × 3

Example 2:
Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2

Example 3:
Input: 14
Output: false
Explanation: 14 is not ugly since it includes another prime factor 7.

Note:
1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−231,  231 − 1].
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
 bool isUgly(int num) {
     if (num == 0)
        return false;
     vector<int> factor = {2, 3, 5};
     bool res = helper(factor, num);
     return res;
 }

 bool helper(vector<int> &factor, int u) {
     if (u == 1) {
         return true;
     }
     for (int i = 0; i < 3; i++) {
         int cur = factor[i];
         if (u % cur == 0) {
             int newU = u / cur;
           //  cout << "i=" << i << " cur= " << cur << " newU=" << newU << endl;
             bool res = helper(factor, newU);
             if (res) {
                 return true;
             }
         }
     }
     return false;
 }




};

bool isUgly(int num) {
    if (num <= 0) {
        return false;
    }
    while (num % 2 == 0) {
        num = num / 2;
    }
    while (num % 3 == 0) {
        num = num / 3;
    }
    while (num % 5 == 0) {
        num = num / 5;
    }
    if (num == 1)
        return true;
    return false;
}

int main() {
    Solution s;
    bool res1 = s.isUgly(0);
    cout << "res1=" << res1 << endl;
}

/*
Tips
M1  回溯法 太慢了
Runtime: 3 ms, faster than 56.98% of C++ online submissions for Ugly Number.
Memory Usage: 6.1 MB, less than 20.74% of C++ online submissions for Ugly
Number.

M2  数学-循环法
一直除
Runtime: 0 ms, faster than 100.00% of C online submissions for Ugly Number.
Memory Usage: 5.7 MB, less than 22.82% of C online submissions for Ugly Number.

*/
