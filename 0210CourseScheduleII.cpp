/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-27
 * @tag  topological,bfs,dfs,backtracking
 * @similar  207,208, 210, 994, 802
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 *
 * https://leetcode.cn/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (58.05%)
 * Likes:    1027
 * Dislikes: 0
 * Total Accepted:    275.4K
 * Total Submissions: 467.2K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中
 * prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
 * 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
 *
 *
 * 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
 *
 *
 *
 * 示例 1：
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：[0,1]
 * 解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
 *
 *
 * 示例 2：
 * 输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * 输出：[0,2,1,3]
 * 解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
 * 因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
 *
 * 示例 3：
 * 输入：numCourses = 1, prerequisites = []
 * 输出：[0]
 *
 *
 *
 * 提示：
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * 所有[ai, bi] 互不相同
 *
 *
 */

// @lc code=start
class Solution {
public:
    // BFS
    vector<int> findOrderM1(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nodes(numCourses, vector<int>());
        vector<int> inde(numCourses, 0);

        for (auto& v: prerequisites) {
            nodes[v[1]].push_back(v[0]);
            inde[v[0]]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (inde[i] == 0) {
                que.push(i);
            }
        }

        vector<int> topo;
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            topo.push_back(cur);
            auto& neis = nodes[cur];
            for (auto& ne: neis) {
                inde[ne]--;
                if (inde[ne] == 0) {
                    que.push(ne);
                }
            }
        }
        if (topo.size() == numCourses) {
            return topo;
        }
        return vector<int>();
    }


    // dfs
    vector<int> res;
    vector<int> findOrderM2(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > nodes(numCourses, vector<int>());
        int topocnt = 0;
        for (auto& v : prerequisites) {
            nodes[v[1]].push_back(v[0]);
        }

        set<int> visited;
        set<int> path;
        for (int i = 0; i < numCourses; i++) {
            if (false == dfs(nodes, i, path, visited)) {
                return vector<int>();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }


    bool dfs(vector<vector<int>>& nodes, int start, set<int>& path, set<int>& visited) {
        if (visited.count(start)) {
            return true;
        }
        visited.insert(start);
        path.insert(start);

        auto& neis = nodes[start];
        for (auto& ne: neis) {
            if (path.count(ne)) { // exit loop
                return false;
            }
            if (false == dfs(nodes, ne, path, visited)) {
                return false;
            }
        }
        res.push_back(start);
        path.erase(start);
        return true;
    }


    // DFS 三色标记法
    // 0 : unvisit 1: ing 2: already visited

    vector<int> topo;
    bool loop;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > nodes(numCourses, vector<int>());
        for (auto& v : prerequisites) {
            nodes[v[1]].push_back(v[0]);
        }

        loop = false;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            dfs3Color(nodes, i, visited);
        }
        if (loop) {
            return vector<int>();
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }


    void dfs3Color(vector<vector<int>>& nodes, int start, vector<int>& visited) {
        if (visited[start] == 1) { // mean cur dfs path  exits loop
            loop = true;
            return;
        }
        if (visited[start] != 0) { // must start from an unvisit node
            return;
        }
        visited[start] = 1; // begin visit, means path_push
        auto& neis = nodes[start];
        for (auto& ne: neis) {
            if (loop) {
                break;
            }
            dfs3Color(nodes, ne, visited);
        }
        visited[start] = 2; // end visit means path_pop
        topo.push_back(start);
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


