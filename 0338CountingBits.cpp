/**
 * @file
 * @brief  TODO
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-23
 * @tag  bitManipulation, DP
 * @similar 191,762
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 *
 * https://leetcode.cn/problems/counting-bits/description/
 *
 * algorithms
 * Easy (78.69%)
 * Likes:    1313
 * Dislikes: 0
 * Total Accepted:    333.7K
 * Total Submissions: 424K
 * Testcase Example:  '2'
 *
 * 给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans
 * 作为答案。
 *
 *
 * 示例 1：
 * 输入：n = 2
 * 输出：[0,1,1]
 * 解释：
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 *
 * 示例 2：
 * 输入：n = 5
 * 输出：[0,1,1,2,1,2]
 * 解释：
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 *
 *
 *
 * 提示：
 * 0 <= n <= 10^5
 *
 *
 *
 * 进阶：
 * 很容易就能实现时间复杂度为 O(n log n) 的解决方案，你可以在线性时间复杂度 O(n) 内用一趟扫描解决此问题吗？
 * 你能不使用任何内置函数解决此问题吗？（如，C++ 中的 __builtin_popcount ）
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:



    vector<int> countBitsM1(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int k = i;
            int cnt = 0;
            while (k > 0) {
                // k = k & (k - 1);

                // LowBit
                k = k - (k & (-k));
                // Error Ver: k = k - k & (-k);
                cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 0;
        for (int i = 1; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
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


