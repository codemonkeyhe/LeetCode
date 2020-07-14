/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-07
 */

/*
Given a non-negative index k where k < 33, return the kth index row of the
Pascal's triangle. Note that the row index starts from 0. In Pascal's triangle,
each number is the sum of the two numbers directly above it.
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Example:
Input: 3
Output: [1,3,3,1]

Follow up:
Could you optimize your algorithm to use only O(k) extra space?

*/

#include <iostream>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class Solution {
   public:
   //Runtime: 0 ms
//  Memory Usage: 5.4 MB
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        for (int i = 0; i <= rowIndex; ++i) {
            res[i] = 1;
            for (int j = i - 1; j >= 1; --j) {
                res[j] = res[j - 1] + res[j];
            }
        }
        return res;
    }

/*
溢出了  21!用 unsigned long long 都无法表示
21 / 34 test cases passed.
Status: Wrong Answer
Submitted: 3 minutes ago
Input:
21
Output:
[1,5,58,369,1663,5654,15079,32312,56547,81679,98014,98014,81679,56547,32312,15079,5654,1663,369,58,5,1]
Expected:
[1,21,210,1330,5985,20349,54264,116280,203490,293930,352716,352716,293930,203490,116280,54264,20349,5985,1330,210,21,1]
*/
    vector<int> getRow2(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        vector<unsigned long long> fac(rowIndex+1, 0);
        fac[0] = 1;
        unsigned long long s = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            fac[i] = fac[i-1]*s;
            ++s;
        }
        int mid = rowIndex/2;
        for (int k = 0; k <= mid; ++k) {
            res[k] =  fac[rowIndex]/fac[k]/fac[rowIndex-k];
        }
        for (int i = mid+1; i <= rowIndex; ++i) {
            res[i] = res[rowIndex-i];
        }
        return res;
    }


    //getRow2思路   Cr:k = r!/k!(r-k)! , k =0..r
    //getRow3思路  Cr:k　＝　r*(r-1)*..(r-k+1)/ k!
    /* 依然溢出
   30 / 34 test cases passed.
Status: Wrong Answer
Submitted: 0 minutes ago
Input:
30
Output:
[1,30,435,4060,27405,142506,593775,2035800,5852925,14307150,30045015,54627300,86493225,119759850,145422675,14052247,145422675,119759850,86493225,54627300,30045015,14307150,5852925,2035800,593775,142506,27405,4060,435,30,1]
Expected:
[1,30,435,4060,27405,142506,593775,2035800,5852925,14307150,30045015,54627300,86493225,119759850,145422675,155117520,145422675,119759850,86493225,54627300,30045015,14307150,5852925,2035800,593775,142506,27405,4060,435,30,1]
    */
    vector<int> getRow3(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        int mid = rowIndex/2;
        vector<unsigned long long> fac(rowIndex+1, 0);
        fac[0] = 1;
        //first calc top
        for (int k = 1; k <= mid; ++k) {
            fac[k] = fac[k-1]*(rowIndex-k+1);
        }
        res[0] = 1;
        //second div bottom
        unsigned long long bottom = 1;
        for (int k = 1; k <= mid; ++k) {
            bottom *=  k;
            res[k] = fac[k]/bottom;
        }
        for (int i = mid+1; i <= rowIndex; ++i) {
            res[i] = res[rowIndex-i];
        }
        return res;
    }


};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int* res = (int*)malloc((rowIndex + 1) * sizeof(int));
    *returnSize =  rowIndex+1;
    for (int i = 0; i <= rowIndex; ++i) {
        res[i] = 1;
        for (int j = i - 1; j >= 1; --j) {
            res[j] = res[j - 1] + res[j];
        }
    }
    return res;
}

int main() {
    int ri = 21;
    int rs = 0;
    auto result = getRow(ri, &rs);
    for (int i = 0; i < rs; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);

    Solution s;
    auto res = s.getRow3(ri);
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
M1 常规递推法

M2 公式法
依然会溢出 放弃治疗
杨辉三角 = 二项式定理的系数
(a+b)^n = Cn:0*a^n + Cn:1 a^(n-1)b^1 + ... Cn:k*a^(n-k)*b^k  + Cn:n*b^n
rowIndex从0开始计算，正好对应n从0开始
第r行 就是    Cr:0 Cr:1  ... Cr:r
Cr:k = r!/k!(r-k)! , k =0..r
先算出r! 同时把r!阶乘的中间过程保存起来，直接可以得到k!和 r-k的阶乘!



M3 打表法
先把结果全算出来保存好
*/
