/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-19
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode.cn/problems/happy-number/description/
 *
 * algorithms
 * Easy (64.20%)
 * Likes:    1552
 * Dislikes: 0
 * Total Accepted:    503.8K
 * Total Submissions: 784.3K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 *
 * 「快乐数」 定义为：
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 *
 *
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 * 示例 2：
 * 输入：n = 2
 * 输出：false
 *

一定会循环 存在环则为false，否则是true
2^2 = 4
4^2 = 16
1^2+6^2=37
3^2+7^2=9+49=58
5^2+8^2=25+64=89
8^2+9^2=64+81=145
1^2+4^2+5^2=1+16+25=42
4^2+2^2=20
2^2+0^2=4



 * 提示：
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
 bool isHappy(int n) {
     unordered_set<int> dup;
     if (n <= 1) {
         return true;
     }
     dup.insert(n);

     int sum = 0;
     int a = n;
     while (true) {
         sum = 0;
         while (a > 0) {
             int cur = a % 10;
             sum += cur * cur;
             a = a / 10;
         }
         if (sum == 1) {
             return true;
         }
         if (dup.count(sum)) {
             return false;
         }
         dup.insert(sum);
         a = sum;
     }
     return true;
 }
};
// @lc code=end

int main() {
    Solution s;
}

/*
Tips
M1

M2

*/
