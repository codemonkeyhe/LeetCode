/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-12
 */

/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n==1) {
            return 1;
        }
        int fn = 0;
        int fn1 = 1;
        int fn2 = 1;
        for (int i = 2; i <= n; ++i) {
            fn = fn1 + fn2;
            fn1 = fn2;
            fn2 = fn;
        }
        return fn;
    }
};


int climbStairs(int n){


}


int main() {
    int n = 7;
    printf("%d\n", climbStairs(n));
    Solution s;
    cout <<  s.climbStairs(n) << endl;
    return 0;
}


/*
Tips
斐波那契数列
3-3
4-5
5-8
6-13

M1  递归法  N太大则爆炸
M2  for递推过去
M3  通项公式 引入无理数 缺乏精度

*/
