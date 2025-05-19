/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-19
 * @tag  DFS,dynamicProgramming
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 *
 * https://leetcode.cn/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (42.26%)
 * Likes:    302
 * Dislikes: 0
 * Total Accepted:    73.8K
 * Total Submissions: 174.6K
 * Testcase Example:  '8'
 *
 * 给定一个正整数 n ，你可以做如下操作：
 *
 *
 * 如果 n 是偶数，则用 n / 2替换 n 。
 * 如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
 *
 *
 * 返回 n 变为 1 所需的 最小替换次数 。
 *
 *
 *
 * 示例 1：
 * 输入：n = 8
 * 输出：3
 * 解释：8 -> 4 -> 2 -> 1
 *
 *
 * 示例 2：
 * 输入：n = 7
 * 输出：4
 * 解释：7 -> 8 -> 4 -> 2 -> 1
 * 或 7 -> 6 -> 3 -> 2 -> 1
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 4
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        return cacheBT(n);
    }


    unordered_map<int, int> cache;

    // 还没来得及加cache 就过了
    // Your runtime beats 43.55 % of cpp submissions
    // 加了 cache . Your runtime beats 38.88 % of cpp submissions
    int cacheBT(long long  n) {
        if (n == 1) {
            return 0;
        }
        if (cache.count(n)) {
            return cache[n];
        }
        int res = 0;
        if (n & 1) {  //
            res = min(cacheBT(n + 1), cacheBT(n - 1)) + 1;
        } else {
            res = cacheBT(n >> 1) + 1;
        }
        cache[n] = res;
        return res;
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


