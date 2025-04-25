/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-25
 * @tag bfs,dfs,hashmap
 * @similar 138
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 *
 * https://leetcode.cn/problems/clone-graph/description/
 *
 * algorithms
 * Medium (70.41%)
 * Likes:    705
 * Dislikes: 0
 * Total Accepted:    142.9K
 * Total Submissions: 202.7K
 * Testcase Example:  '[[2,4],[1,3],[2,4],[1,3]]'
 *
 * 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
 *
 * 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
 *
 *
 * class Node {
 * ⁠   public int val;
 * ⁠   public List<Node> neighbors;
 * }
 *
 *
 *
 * 测试用例格式：
 *
 * 简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val =
 * 2），以此类推。该图在测试用例中使用邻接列表表示。
 *
 * 邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
 *
 * 给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。
 *
 *
 *
 * 示例 1：
 * 输入：adjList = [[2,4],[1,3],[2,4],[1,3]]
 * 输出：[[2,4],[1,3],[2,4],[1,3]]
 * 解释：
 * 图中有 4 个节点。
 * 节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
 * 节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
 * 节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
 * 节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
 *
 *
 * 示例 2：
 * 输入：adjList = [[]]
 * 输出：[[]]
 * 解释：输入包含一个空列表。该图仅仅只有一个值为 1 的节点，它没有任何邻居。
 *
 *
 * 示例 3：
 * 输入：adjList = []
 * 输出：[]
 * 解释：这个图是空的，它不含任何节点。
 *
 *
 *
 *
 * 提示：
 * 这张图中的节点数在 [0, 100] 之间。
 * 1 <= Node.val <= 100
 * 每个节点值 Node.val 都是唯一的，
 * 图中没有重复的边，也没有自环。
 * 图是连通图，你可以从给定节点访问到所有节点。
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        //因为保证节点元素唯一,可以用set<ing>去重，否则用set<Node*>去重
        unordered_map<int, Node*> visited;
        //auto res = dfs(node, visited);
        auto res = bfs(node, visited);
        return res;
    }

    Node* dfs(Node* cur, unordered_map<int, Node*>& visited) {
        if (visited.count(cur->val)) {
            // KEY Step
            return visited[cur->val];
        }
        Node* copy = new Node(cur->val);
        visited[cur->val] = copy;

        for (int i = 0; i < cur->neighbors.size(); ++i) {
            Node* tmp = dfs(cur->neighbors[i], visited);
            copy->neighbors.push_back(tmp);
        }
        return copy;
    }


    Node* bfs(Node* cur, unordered_map<int, Node*>& visited) {
        queue<Node*> que;
        que.push(cur);
        Node* start = new Node(cur->val);
        visited[cur->val] = start;

        while(!que.empty()) {
            auto cur = que.front();
            que.pop();
            auto curCopy = visited[cur->val];

            for (auto& ni: cur->neighbors) {
                if (visited.count(ni->val)) {
                    //Error cur->neighbors.push_back(visited[ni->val]);
                    // 双向的关系，所以这里也叫建立映射
                    curCopy->neighbors.push_back(visited[ni->val]);
                    continue;
                }
                // not visited, make copy
                Node* copy = new Node(ni->val);
                //  mark pair relation
                visited[ni->val] = copy;
                curCopy->neighbors.push_back(visited[ni->val]);
                que.push(ni);
            }
        }
        return  start;
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


