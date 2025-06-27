/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-26
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
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (54.02%)
 * Likes:    2142
 * Dislikes: 0
 * Total Accepted:    550.2K
 * Total Submissions: 994.7K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
 * ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 *
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 *
 * 示例 2：
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 *
 *
 *
 * 提示：
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 *
 *
 */

// @lc code=start
class Solution {
public:

    /*
        WORK BUT NOT makesence
        依赖顺序搞反了
        [5, 3] 想要学5，先要学3， 拓扑排序预期， 3 ，5

        有向图 5 -->  3 错误， 因为拓扑排序优先从入度为0的点开始执行，第一个节点是5，不符合预期

        正确的有向图
        3  -->  5 ， 5的inDegree=1 ， 3的inDegree=0 ，因此，先选3，再选5

    */
    bool canFinishACButLogicFalse(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> que;
        vector<vector<int> > nodes(numCourses, vector<int>());
        vector<int> inCnt(numCourses, 0);
        //vector<int> order;
        int topocnt = 0;
        for (auto& v : prerequisites) {
            nodes[v[0]].push_back(v[1]);
            inCnt[v[1]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (inCnt[i] == 0) {
                que.push(i);
            }
        }

        while(!que.empty()) {
            int& cur = que.front();
            que.pop();
            //order.push_back(cur);
            topocnt++;
            auto& neis = nodes[cur];
            for (auto& ne : neis) {
                inCnt[ne]--;
                if (inCnt[ne] == 0) {
                    que.push(ne);
                }
            }
        }
        //if (order.size() == numCourses) {
        if (topocnt == numCourses) {
            return true;
        }

        return  false;
    }


    // BFS
    bool canFinishM1(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> que;
        vector<vector<int> > nodes(numCourses, vector<int>());
        vector<int> inCnt(numCourses, 0);
        //vector<int> order;
        int topocnt = 0;
        for (auto& v : prerequisites) {
            nodes[v[1]].push_back(v[0]);
            inCnt[v[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (inCnt[i] == 0) {
                que.push(i);
            }
        }

        while(!que.empty()) {
            //BUG int& cur = que.front();
            int cur = que.front();
            que.pop();
            //order.push_back(cur);
            topocnt++;
            auto& neis = nodes[cur];
            for (auto& ne : neis) {
                inCnt[ne]--;
                if (inCnt[ne] == 0) {
                    que.push(ne);
                }
            }
        }
        return (topocnt == numCourses);
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > nodes(numCourses, vector<int>());
        int topocnt = 0;
        for (auto& v : prerequisites) {
            nodes[v[1]].push_back(v[0]);
        }

        set<int> visited;
        set<int> path;
        for (int i = 0; i < numCourses; i++) {
            if (false == dfs(nodes, i, path, visited)) {
                return false;
            }
        }
        return true;
    }

    //Case1: 1 -> 2 -> 3 -> 4 , 3-> 2   6->5
    //Case2: 1->2->3  3->1
    // if exists loop, return false
    bool dfsV1(vector<vector<int>>& nodes, int start, vector<int>& path, set<int>& visited) {
        if (visited.count(start)) {
            return true;
        }
        visited.insert(start);
        path.push_back(start);

        auto& neis = nodes[start];
        bool res = true;
        for (auto& ne: neis) {
            for (int i = 0; i < path.size(); i++) {
                if (path[i] == ne) {
                    return false;
                }
            }
            res = dfsV1(nodes, ne, path, visited);
            if (res == false) {
                return false;
            }
        }
        path.pop_back();
        return true;
    }


    // if exists loop, return false
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
        path.erase(start);
        return true;
    }


};
// @lc code=end

/*
有向图里面寻找环，
1 这个有向图不存在自环，  from : prerequisites[i] 中的所有课程对 互不相同
2 有向图可能存在多个连同分量，即多个互不相连的子图

M1 拓扑排序 BFS
入度为0 入que
直到que为空为止
如果还有节点没遍历到，相当于有环


M2 DFS+BT
必然存在入度为0的点
否则肯定是环
DFS时，区分visited和path，只有path上重复的才是环，而 visited重复的则跳过
path本质上是BT的标配，做选择时记录path，退出时弹出path，代表出发点到当前DFS节点的路径

M3 DFS+三色标记
M2的visited和path合二为一，变成3色标记法
没有访问过，flag=0
如果是visited，flag=2
当前正在访问，flag=1 ，相当于path，


M4 sameAs LC210


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


