/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-25
 * @tag bfs,dfs,unionFind
 * @similar
 * @todo  use bfs and unionFind
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 *
 * https://leetcode.cn/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (62.18%)
 * Likes:    1198
 * Dislikes: 0
 * Total Accepted:    347.3K
 * Total Submissions: 555.1K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 *
 *
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c
 * 间接相连。
 * 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而
 * isConnected[i][j] = 0 表示二者不直接相连。
 * 返回矩阵中 省份 的数量。
 *
 *
 *
 * 示例 1：
 * 输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * 输出：2
 *
 *
 * 示例 2：
 * 输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] 为 1 或 0
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { // j don't need from 0
                if (isConnected[i][j])  { // i j
                    markCon(isConnected, i, j);
                    res++;
                }
            }

        }
        return res;
    }


    void markCon(vector<vector<int>>& isConnected, int i , int j) {
        int n = isConnected.size();
        if (isConnected[i][j] == 0) {
            return;
        }
        isConnected[i][j] = 0;

        for (int k = 0; k < n; k++) {
            if (isConnected[i][k] == 1) {
                markCon(isConnected, i, k);
            }
            if (isConnected[k][j] == 1) {
                markCon(isConnected, k, j);
            }
        }
    }

};
// @lc code=end

/*
      0 1 2 3
0     1 1 0 0
1     1 1 0 1
2     0 0 1 0
3     0 1 0 1

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


