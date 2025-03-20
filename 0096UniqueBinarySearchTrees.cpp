/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-20
 * @tag DFS
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode.cn/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (71.10%)
 * Likes:    2618
 * Dislikes: 0
 * Total Accepted:    498.2K
 * Total Submissions: 697.6K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 *
 *
 *
 * 示例 1：
 * 输入：n = 3
 * 输出：5
 *
 *
 * 示例 2：
 * 输入：n = 1
 * 输出：1
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, int> cache;

    int numTrees(int n) {
        int res = 0;
        res = bt(1, n);
        return res;
    }


    int btTimeLimitExeeded(int le, int ri) {
        if (le > ri) {
            return 1;
        }

        int res = 0;
        for (int i = le; i <= ri; i++) {
            // i is root
            // build root->leftTree
            int leftTCnt = bt(le, i-1);

            //build root->rightTree
            int rightTCnt =  bt(i+1, ri);

            res = res+ leftTCnt * rightTCnt;
        }
        return res;
    }

    int bt(int le, int ri) {
        if (le > ri) {
            return 1;
        }

        int dis = ri- le +1;
        if (cache.count(dis)) {
            return cache[dis];
        }

        int res = 0;
        for (int i = le; i <= ri; i++) {
            int leftTCnt = bt(le, i-1);
            int dis = i- le;
            cache[dis]=leftTCnt;

            int rightTCnt =  bt(i+1, ri);
            int dd = ri-i;
            cache[dd]=rightTCnt;

            res = res+ leftTCnt * rightTCnt;
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


