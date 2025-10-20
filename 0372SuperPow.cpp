/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-19
 * @tag   math, recursion
 * @similar  50, 372
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 *
 * https://leetcode.cn/problems/super-pow/description/
 *
 * algorithms
 * Medium (56.72%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 94.8K
 * Testcase Example:  '2\n[3]'
 *
 * 你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 *
 *
 *
 * 示例 1：
 * 输入：a = 2, b = [3]
 * 输出：8
 *
 *
 * 示例 2：
 * 输入：a = 2, b = [1,0]
 * 输出：1024
 *
 *
 * 示例 3：
 * 输入：a = 1, b = [4,3,3,8,5,2]
 * 输出：1
 *
 *
 * 示例 4：
 * 输入：a = 2147483647, b = [2,0,0]
 * 输出：1198
 *
 *
 *
 *
 * 提示：
 * 1 <= a <= 231 - 1
 * 1 <= b.length <= 2000
 * 0 <= b[i] <= 9
 * b 不含前导 0
 *
 *
 */

// @lc code=start
class Solution {
public:
    const static int MOD = 1337;

    int pow(int a, int n) {
        if (n == 0) {
            return 1;
        }
        /* duplicated
        if (n == 1) {
            return a;
        }
        */
        if (n % 2 == 1) {
            long lackOne = pow(a, n - 1) % MOD;
            return (lackOne * a)%MOD;
        }
        int half = pow(a, n >> 1) % MOD;
        return (half * half) % MOD;
    }

    int pow1(int a, int n) {
        if (n == 0) {
            return 1;
        }
        long half = pow1(a, n >> 1) % MOD;
        long res = (half * half) % MOD;
        if (n % 2) {
            return (res * a) % MOD;
        }
        return res;
    }

    // x^8 = (x^4)^2
    // n: 8 4 2 1
    // x^9 = (x^8)*x
    // n: 9 8 4 2 1
    int pow2(int a, int n) {
        long res = 1;
        while(n > 0) {
            if (n % 2) { // odd
                n = n - 1;
                res = (res * a) % MOD;
                continue;
            }
            a = (long)a * a % MOD;
            n = n >> 1;
        }
        return res;
    }

    int pow3(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2) {
                res = (long) res * x % MOD;
            }
            x = (long) x * x % MOD;
            n /= 2;
        }
        return res;
    }


    int superPow(int a, vector<int>& b) {
        if (b.size() == 0) {
            return 1;
        }
        int res = 1;
        int last = b.back();
        b.pop_back();
        int head = superPow(a, b) % MOD;
        // recursion
        //int tail = pow(a, last) % MOD;
        //res = (pow(head, 10) % MOD) * tail;

        // recursion v1
        //int tail = pow1(a, last) % MOD;
        //res = (pow1(head, 10) % MOD) * tail;


        // iteration
        int tail = pow2(a, last) % MOD;
        res = (pow2(head, 10) % MOD) * tail;
        return res % MOD;
    }
};
// @lc code=end

/*

a^1234 = a^(123*10+4) = a^(123*10) * a^4 = (a^123)^10 * a^4


Runtime Error
23/57 cases passed (N/A)
Error
Line 14: Char 28: runtime error: signed integer overflow: 1226 * 1931497 cannot be represented in type 'int' (solution.cpp)
Line 14: Char 28: runtime error: signed integer overflow: 1226 * 1931497 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:23:28
Testcase
1931497
' +
  '[2,3,5,8,0,0,1,8,6,4,4,7,1,9,0,9,8,3,1,8,0,1,6,2,3,4,8,7,0,5,4,0,8,9,0,1,1,3,9,0,0,5,7,1,5,9,0,5,3,4,3,3,5,2,7,0,8,5,7,8,1,3,0,1,5,2,2,6,6,3,6,6,9,6,9,6,5,1,3,8,5,6,4,1,0,1,3,0,9,1,9,0,6,1,3,1,4,6,0,2,1,8,0,2,4,9,8,0,2,1,0,8,0,4,1,2,8,4,3,7,7,4,9,4,5,2,5,1,0,5,5,2,4,5,4,0,6,5,2,9,8,3,9,0,9,0,3,9,6,8,8,4,4,7,0,9,2,5,3,2,3,8,6,9,6,3,9,2,8,4,3,8,7,2,9,8,4,4,0,3,4,8,9,8,6,9,9,8,6,2,2,1,3,9,0,9,2,2,3,2,6,7,0,5,1,1,3,6,7,3,9,1,4,8,1,0,9,1,0,5,5,2,7,0,1,9,9,5,1,5,7,7,2,0,4,5,1,0,3,9,5,2,2,9,2,4,9,3,5,9,9,2,4,8,3,7,7,4,3,9,9,2,8,3,2,3,9,6,3,2,7,8,7,9,8,1,5,9,5,2,1,6,5,5,4,8,2,1,4,7,2,4,0,1,7,4,6,8,0,1,3,7,1,0,9,1,3,4,1,8,7,4,4,4,9,0,4,3,2,8,1,6,2,3,9,2,7,5,2,8,8,5,7,0,5,8,1,9,5,4,9,4,8,6,8,9,6,2,5,0,0,6,7,5,1,6,9,8,4,1,8,2,7,8,4,2,8,8,3,3,2,3,7,3,9,7,2,7,1,7,8,4,5,7,9,8,5,0,7,1,1,7,6,8,5,0,3,6,8,6,9,3,1,9,6,2,8,8,2,0,8,0,4,5,9,5,4,4,5,3,6,8,0,2,7,8,4,0,4,3,8,5,6,2,6,2,6,5,2,8,7,2,0,3,8,9,0,4,6,7,7,4,5,9,6,2,7,2,4,3,5,5,9,3,9,7,7,5,2,2,6,1,4,6,4,4,8,6,8,4,3,5,8,9,5,6,1,4,8,8,8,6,5,9,9,4,8,7,1,1,9,7,4,5,4,1,0,4,7,0,8,1,8,8,0,5,4,3,9,2,1,9,8,6,0,0,2,9,9,4,2,0,1,8,5,7,9,7,3,7,8,1,8,8,9,0,3,5,3,4,8,7,6,8,5,6,8,8,7,7,2,1,9,5,0,5,5,9,4,8,6,2,2,6,0,3,6,5,9,0,0,7,7,6,7,4,4,8,2,2,7,6,3,7,4,3,2,1,5,6,1,1,1,3,8,3,7,6,9,6,6,1,5,5,7,2,0,1,0,4,5,8,1,1,5,7,4,9,8,1,7,9,3,8,5,3,2,2,9,3,0,8,4,5,3,3,9,5,4,2,2,2,2,3,3,9,2,9,8,0,1,7,1,4,6,6,9,0,8,8,5,0,8,9,5,4,2,7,9,8,9,1,0,3,6,3,2,8,5,2,0,6,9,2,2,5,8,1,7,9,1,2,9,0,3,7,4,7,6,5,6,5,9,8,0,5,4,2,6,9,4,8,5,3,0,9,1,1,0,0,2,3,5,3,5,8,2,9,8,8,7,4,5,6,2,5,3,8,7,9,7,3,0,4,9,0,3,2,3,5,2,7,9,7,1,4,8,5,6,6,4,3,2,1,9,6,7,4,5,6,6,2,0,6,7,1,8,2,3,2,8,5,9,7,5,2,3,5,8,1,3,4,4,5,5,5,3,4,0,8,1,6,3,3,4,2,4,2,4,9,4,2,6,6,1,1,0,7,8,0,8,1,4,3,8,0,0,4,6,2,2,7,0,7,2,4,9,8,7,4,7,3,6,4,1,0,7,4,7,8,4,5,9,9,0,0,1,3,4,7,5,8,5,8,6,9,2,5,8,1,1,7,7,8,3,0,0,1,4,7,9,9,4,0,8,7,2,9,0,8,6,7,7,3,5,5,5,8,2,3,1,4,2,0,4,6,1,4,7,5,3,8,4,7,0,2,4,3,3,6,1,2,4,0,5,9,7,0,9,0,5,3,4,8,3,0,4,4,4,3,0,9,3,4,6,3,9,3,6,2,9,0,4,5,0,2,5,8,4,6,0,2,9,6,0,3,6,6,9,2,1,9,1,4,6,9,7,5,4,6,9,6,6,6,1,6,8,8,6,4,5]
Expected Answer
1184
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
