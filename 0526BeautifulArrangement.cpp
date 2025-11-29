/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-28
 * @tag  backtracing,dp,bitmask
 * @similar  526, 667
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 *
 * https://leetcode.cn/problems/beautiful-arrangement/description/
 *
 * algorithms
 * Medium (72.42%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    61.1K
 * Total Submissions: 84.5K
 * Testcase Example:  '2'
 *
 * 假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），只要满足下述条件 之一 ，该数组就是一个 优美的排列
 * ：
 * perm[i] 能够被 i 整除
 * i 能够被 perm[i] 整除
 *
 *
 * 给你一个整数 n ，返回可以构造的 优美排列 的 数量 。
 *
 *
 *
 * 示例 1：
 * 输入：n = 2
 * 输出：2
 * 解释：
 * 第 1 个优美的排列是 [1,2]：
 * ⁠   - perm[1] = 1 能被 i = 1 整除
 * ⁠   - perm[2] = 2 能被 i = 2 整除
 * 第 2 个优美的排列是 [2,1]:
 * ⁠   - perm[1] = 2 能被 i = 1 整除
 * ⁠   - i = 2 能被 perm[2] = 1 整除
 *
 *
 * 示例 2：
 * 输入：n = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 15
 *
 *
 */

// @lc code=start
class Solution {
public:

    int countArrangement(int n) {
        vector<int> path;
        int res = 0;
        unordered_set<int> used;
        bt(n, 1, path, used, res);
        return res;
    }

    void bt(int n, int cur, vector<int>& path, unordered_set<int>& used, int& res) {
        if (path.size() == n) {
            // check meet sta
            res++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (used.count(i)) {
                continue;
            }
            int nextIdx = path.size() + 1;
            if (i % nextIdx == 0 || nextIdx % i == 0) {
                used.insert(i);
                path.push_back(i);
                bt(n, i, path, used, res);
                path.pop_back();
                used.erase(i);
            }
        }
    }

    // merge used and path
    void bt2(int n, unordered_set<int> &used, int &res) {
        if (used.size() == n) {
            // check meet sta
            res++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (used.count(i)) {
                continue;
            }
            int nextIdx = used.size() + 1;
            if (i % nextIdx == 0 || nextIdx % i == 0) {
                used.insert(i);
                bt2(n, used, res);
                used.erase(i);
            }
        }
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
