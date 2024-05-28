/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-28
 * @tag binary-search; math
 * @TODO:  binary-search
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 *
 * https://leetcode.cn/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (45.04%)
 * Likes:    298
 * Dislikes: 0
 * Total Accepted:    134.5K
 * Total Submissions: 298.6K
 * Testcase Example:  '5'
 *
 * 你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。
 *
 * 给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。
 *
 *
 *
 * 示例 1：
 * 输入：n = 5
 * 输出：2
 * 解释：因为第三行不完整，所以返回 2 。
 *
 *
 * 示例 2：
 * 输入：n = 8
 * 输出：3
 * 解释：因为第四行不完整，所以返回 3 。
 *
 *
 * 提示：
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }

        long doub = 2*( long)n;
        long sq = sqrt(doub);

        long  sum =  sq*(sq+1);
        if (doub == sum) {
            return sq;
        }
        if (doub > sum) {
            return sq;
        }
       // long  sum2 =  sq*(sq-1);
        long  sum2 = sum - 2*sq;
        if (doub == sum2) {
            return (sq - 1);
        }
        return sq-1;
    }
};
// @lc code=end

/*
M1 公式法
1 2 3 4 ...k-1, k
S1 = 1      1       1
S2 = 3       2-3    2  2不满，实际res=1,3满，实际res=2
S3 = 6       4-6    3           8-12
S4 = 10      7-10  4            14-20
S5 = 15      11~15  都属于第5层   22-30  11-14的res=4,15的res=5
S6 = 21      16~21 都属于第6层    32-42

S(k-1) = (k)*(k-1)/2 = (k*k-k)/2
S(k) = (1+k)*k/2 = (k*k+k)/2
S(k)-S(k-1) = k
现在已知 S(k),求k
=S(k-1)  则在第k-1层
>S(k-1)  则在第k层
=S(k)  则在第k层
n >S(k)  则在第k+1层
2n > k*k+k  则在第k+1层
2n > k*k+k > k*k  则在第k+1层
2n >  k*k  则在第k+1层
sqrt(2n) > k



n=8
S(k) <= n




*/

int main() {
    Solution s;
}


/*
Tips
M1 一元二次方程组-求根公式

M2 基于S(n) = n(n+1)/2的方法来进行二分


*/


