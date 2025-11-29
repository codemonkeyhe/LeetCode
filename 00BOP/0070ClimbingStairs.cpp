/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-12,2025-06-09
 * @similar  70,746
 */

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (54.57%)
 * Likes:    3833
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 3.4M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 *
 *
 * 示例 1：
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 *
 * 示例 2：
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 45
 *
 *
 */

// @lc code=start
class Solution {
public:
    // TLE
    int climbStairsM1(int n) {
        if (n==0) {
            return 1;
        }
        if (n==1) {
            return 1;
        }
        return climbStairs(n - 2) + climbStairs(n - 1);
    }


    unordered_map<int, int> cache;
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        if (cache.count(n)) {
            return cache[n];
        }
        int res = climbStairs(n - 2) + climbStairs(n - 1);
        cache[n] = res;
        return  res;
    }
};
// @lc code=end



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

class SolutionOld {
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
    SolutionOld s;
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
