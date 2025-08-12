/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-12
 * @tag  floyd, shortestPath
 * @similar   399, 1334
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 *
 * https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
 *
 * algorithms
 * Medium (61.72%)
 * Likes:    225
 * Dislikes: 0
 * Total Accepted:    37.2K
 * Total Submissions: 58.6K
 * Testcase Example:  '4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4'
 *
 * 有 n 个城市，按从 0 到 n-1 编号。给你一个边数组 edges，其中 edges[i] = [fromi, toi, weighti] 代表
 * fromi 和 toi 两个城市之间的双向加权边，距离阈值是一个整数 distanceThreshold。
 * 返回在路径距离限制为 distanceThreshold 以内可到达城市最少的城市。如果有多个这样的城市，则返回编号最大的城市。
 *
 * 注意，连接城市 i 和 j 的路径的距离等于沿该路径的所有边的权重之和。
 *
 *
 *
 * 示例 1：
 * 输入：n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
 * 输出：3
 * 解释：城市分布图如上。
 * 每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
 * 城市 0 -> [城市 1, 城市 2] 
 * 城市 1 -> [城市 0, 城市 2, 城市 3] 
 * 城市 2 -> [城市 0, 城市 1, 城市 3] 
 * 城市 3 -> [城市 1, 城市 2] 
 * 城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。
 *
 *
 * 示例 2：
 * 输入：n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]],
 * distanceThreshold = 2
 * 输出：0
 * 解释：城市分布图如上。 
 * 每个城市阈值距离 distanceThreshold = 2 内的邻居城市分别是：
 * 城市 0 -> [城市 1] 
 * 城市 1 -> [城市 0, 城市 4] 
 * 城市 2 -> [城市 3, 城市 4] 
 * 城市 3 -> [城市 2, 城市 4]
 * 城市 4 -> [城市 1, 城市 2, 城市 3] 
 * 城市 0 在阈值距离 2 以内只有 1 个邻居城市。
 *
 *
 *
 *
 * 提示：
 * 2 <= n <= 100
 * 1 <= edges.length <= n * (n - 1) / 2
 * edges[i].length == 3
 * 0 <= fromi < toi < n
 * 1 <= weighti, distanceThreshold <= 10^4
 * 所有 (fromi, toi) 都是不同的。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // 不能初始化为0，不可达应为无穷大，为了避免计算溢出，初始化为INT_MAX/2，因为最大值是10^4
        //vector<vector<int> > g(n, vector<int>(n, 0));
        vector<vector<int> > g(n, vector<int>(n, INT_MAX/2));
        for (int i = 0; i < edges.size(); i++) {
            auto& ed = edges[i];
            int from = ed[0];
            int to = ed[1];
            int weight = ed[2];
            g[from][to] = weight;
            g[to][from] = weight;
        }

        // V1
        for (int k = 0; k < n; k++) {// 中间节点k
            for (int i = 0; i < n; i++) {
                if (i == k) {
                    continue;
                }
                if (g[i][k] == INT_MAX/2) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if (j == i) {
                        continue;
                    }
                    if (g[i][j] > g[i][k] + g[k][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }

        // V2 no skip
        /*
        for (int k = 0; k < n; k++) {
            g[k][k] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][j] > g[i][k] + g[k][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
        */

        int minCnt = INT_MAX;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
              //  cout << "i=" << i << " j=" << j << " th=" << g[i][j] << endl;
                if (g[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= minCnt) {
                minCnt = cnt;
                idx = i;
            }
        }
        return idx;
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
