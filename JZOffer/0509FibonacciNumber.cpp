/**
 * @file
 * @brief  P9   similar-70 91 62
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-17
 */

/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

Example 1:
Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Note:
0 ≤ N ≤ 30.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

class Solution {
public:
    //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
    //Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Fibonacci Number.

    int fib(int N) {
        if (N<2) return N;
        int i=0;
        int j=1;
        int res = 0;
        for (int k = 2; k<=N; ++k) {
            res = i+j;
            i = j;
            j = res;
        }
        return res;
    }

};

//A=A*B
void multiply(int (*A)[2], int (*B)[2]) {
    int a00 = A[0][0] * B[0][0] + A[0][1]*B[1][0];
    int a01 = A[0][0] * B[0][1] + A[0][1]*B[1][1];
    int a10 = A[1][0] * B[0][0] + A[1][1]*B[1][0];
    int a11 = A[1][0] * B[0][1] + A[1][1]*B[1][1];
    A[0][0] = a00;
    A[0][1] = a01;
    A[1][0] = a10;
    A[1][1] = a11;
}

//A=A^k
/*
if k%N==0
    A^k = A^(k/2) * A(k/2)
if k%N==1
    A^k = A^(k/2) * A(k/2) * A
*/
void power(int (*A)[2], int k) {
    if (k==1) {
        return;
    }
    int res;
    power(A, k>>1);
    multiply(A, A);
    if (k&0x01) {
        int B[2][2]= {1,1,1,0}; // same as the original A
        multiply(A, B);
    }
}

//非递归版 T=O(lgk)  参照BOP2.9
void powerK(int (*A)[2], int k) {
    if (k==1) {
        return;
    }
    int R[2][2]= {1,0,0,1}; //单位矩阵
    for (; k; k>>=1) {
        if (k&0x01) {
            multiply(R, A);
        }
        multiply(A,A);
    }
    //copy Res to A
    A[0][0] = R[0][0];
    A[0][1] = R[0][1];
    A[1][0] = R[1][0];
    A[1][1] = R[1][1];
}

/*  fool
    if (k&0x01) {
        power(A, (k-1)>>1);
    } else {
        power(A, k>>1);
    }
*/

//Runtime: 0 ms, faster than 100.00% of C online submissions for Fibonacci Number.
//Memory Usage: 5.2 MB, less than 100.00% of C online submissions for Fibonacci Number.
int fib(int N){
    if (N<2) return N;
    int A[2][2]= {1,1,1,0};
    powerK(A, N-1);
    return A[0][0];
}

int main() {

    int r1 = fib(6);
    printf("%d\n", r1);

    Solution s;
    cout << s.fib(6) << endl;



    return 0;
}

/*
M0 打表法
0 ≤ N ≤ 30.
https://leetcode.com/problems/fibonacci-number/discuss/216245/Java-O(1)-time

M1 递归法
O(2^N)

M2 动态规划 -DP数组
T-O(N)
S-O(N)

M3 迭代法
T-O(N)
S-O(1)

M4 矩阵计算法
T-O(lgN)
由 (Fn  Fn-1) = (Fn-1 Fn-2) *A
可得
A=( 1 1 )
  ( 1 0 )
递推可得
(Fn Fn-1)=(F1 F0) * A^(n-1)
令 A^(n-1)为
  ( a00 a01 )
  ( a10 a11 )

(Fn Fn-1)=(F1 F0) * A^(n-1)  = (a00  a10)
所以有 Fn=a00
问题变为计算A的n-1次方后，a00即为Fn。
利用二分法去计算A的n-1次方,时间复杂度为 O(lgN)。

M5 通项公式法
T=O(1)



*/
