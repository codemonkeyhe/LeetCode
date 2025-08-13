/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-13
 * @tag  graph, shortestPath, dijkstra
 * @similar  399, 743,  1334
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 *
 * https://leetcode.cn/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (56.38%)
 * Likes:    842
 * Dislikes: 0
 * Total Accepted:    162.7K
 * Total Submissions: 280.3K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 n 个网络节点，标记为 1 到 n。
 * 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
 * wi 是一个信号从源节点传递到目标节点的时间。
 * 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
 *
 *
 *
 * 示例 1：
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * 输出：2
 *
 *
 * 示例 2：
 * 输入：times = [[1,2,1]], n = 2, k = 1
 * 输出：1
 *
 *
 * 示例 3：
 * 输入：times = [[1,2,1]], n = 2, k = 2
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * 所有 (ui, vi) 对都 互不相同（即，不含重复边）
 *
 *
 */

// @lc code=start
class Solution {
public:

    // M1 dijkstra
    int networkDelayTimeM1V1(vector<vector<int>>& times, int n, int k) {
        vector<vector<int> > g(n+1, vector<int>(n+1, INT_MAX/2));
        for (auto& time: times) {
            int& from = time[0];
            int& to = time[1];
            int& wi = time[2];
            g[from][to] = wi;
        }

        vector<int> dist(n+1, 0); //dist[j] means dist(k, j)
        vector<int> used(n+1, 0);

        for (int i = 1; i <= n; i++) {
            dist[i] = g[k][i];
        }
        dist[k] = 0; // dist(k,k) = 0
        //used[k] = 1;

        int cnt = 1;
        while(cnt++ < n) {
            int minDis = INT_MAX/2;
            int idx = -1;
            for (int i = 1; i < dist.size(); i++) {
                if (i == k) {
                    continue;
                }
                if (used[i] == 0 && dist[i] < minDis) {
                    minDis = dist[i];
                    idx = i;
                }
            }
            if (idx == -1) {
                break;
            }
            used[idx] = 1; //标记 dist(k, idx) 的最短路径已经找到
            // start from idx, update shortest path
            auto& neis = g[idx];
            for (int j = 1; j <= n; j++) {
                if (neis[j] == INT_MAX/2) {
                    continue;
                }
                if (minDis+neis[j] < dist[j]) { //  Dis(k -> idx -> j) < Dis(k, j)
                    dist[j] = minDis + neis[j];
                }
            }
        }

        int delay = -1;
        //for (auto& time: dist) {
        for (int i = 1; i < dist.size(); i++) {
            int &time = dist[i];
            if (time == INT_MAX/2) {
                return -1;
            }
            delay = max(delay, time);
        }
        return delay;
    }

    int networkDelayTimeM1v2(vector<vector<int>>& times, int n, int k) {
        vector<vector<int> > g(n, vector<int>(n, INT_MAX/2));
        for (auto& time: times) {
            int from = time[0] - 1;
            int to = time[1] - 1;
            int& wi = time[2];
            g[from][to] = wi;
        }

        vector<int> dist(n, INT_MAX/2); //dist[j] means dist(k, j)
        vector<int> used(n, 0);

        dist[k-1] = 0; // dist(k,k) = 0

        int cnt = 1;
        while(cnt++ < n) {
            int minDis = INT_MAX/2;
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (used[i] == 0 && dist[i] < minDis) {
                    minDis = dist[i];
                    idx = i;
                }
            }
            if (idx == -1) {
                break;
            }
            used[idx] = 1;
            auto& neis = g[idx];
            for (int j = 0; j < n; j++) {
                if (minDis+neis[j] < dist[j]) { //  Dis(k -> idx -> j) < Dis(k, j)
                    dist[j] = minDis + neis[j];
                }
            }
        }

        int delay = -1;
        for (int i = 0; i < n; i++) {
            int &time = dist[i];
            if (time == INT_MAX/2) {
                return -1;
            }
            delay = max(delay, time);
        }
        return delay;
    }

    //M2 priorityQueue
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int> > g(n, vector<int>(n, INT_MAX/2));
        for (auto& time: times) {
            int from = time[0] - 1;
            int to = time[1] - 1;
            int& wi = time[2];
            g[from][to] = wi;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;
        minHeap.push(make_pair(0, k-1)); //  dist(k,k) = 0

        vector<int> dist(n, INT_MAX/2); //dist[j] means dist(k, j)
        dist[k-1] = 0;

        while(!minHeap.empty()) {
            auto cur = minHeap.top();
            minHeap.pop();
            int minDis = cur.first;
            int idx = cur.second;
            if (dist[idx] < minDis) { // idx 之前出堆过，已经找到最小节点了
                continue;
            }

            auto& neis = g[idx];
            for (int j = 0; j < n; j++) {
                if (minDis+neis[j] < dist[j]) { //  Dis(k -> idx -> j) < Dis(k, j)
                    dist[j] = minDis + neis[j];
                    minHeap.push(make_pair(dist[j], j)); //节点j会多次入堆，每次的dist可能不同，但是最小的dist会上浮出来
                }
            }
        }

        int delay = -1;
        for (int i = 0; i < n; i++) {
            int &time = dist[i];
            if (time == INT_MAX/2) {
                return -1;
            }
            delay = max(delay, time);
        }
        return delay;
    }

};
// @lc code=end

/*
Wrong Answer
51/55 cases passed (N/A)
Testcase
[[1,2,1]]
2
2
Answer
0
Expected Answer
-1


题意理解错误，要一个点不可达，就是-1
Wrong Answer
53/55 cases passed (N/A)
Testcase
[[1,2,1],[2,3,2],[1,3,1]]
3
2
Answer
2
Expected Answer
-1

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
