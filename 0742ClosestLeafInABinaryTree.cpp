/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2026-01-01
 * @tag   dfs,bfs,binaryTree
 * @similar 742, 863, 2385
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode.cn id=742 lang=cpp
 *
 * [742] 二叉树最近的叶节点
 *
 * https://leetcode.cn/problems/closest-leaf-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (49.40%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 7.1K
 * Testcase Example:  '[1,3,2]\n1'
 *
 * 给定一个 每个结点的值互不相同 的二叉树，和一个目标整数值 k，返回 树中与目标值 k  最近的叶结点 。 
 *
 * 与叶结点最近 表示在二叉树中到达该叶节点需要行进的边数与到达其它叶结点相比最少。而且，当一个结点没有孩子结点时称其为叶结点。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1, 3, 2], k = 1
 * 输出： 2
 * 解释： 2 和 3 都是距离目标 1 最近的叶节点。
 *
 *
 * 示例 2：
 * 输入：root = [1], k = 1
 * 输出：1
 * 解释：最近的叶节点是根结点自身。
 *
 *
 * 示例 3：
 * 输入：root = [1,2,3,4,null,null,null,5,null,6], k = 2
 * 输出：3
 * 解释：值为 3（而不是值为 6）的叶节点是距离结点 2 的最近结点。
 *
 *
 *
 *
 * 提示：
 * 二叉树节点数在 [1, 1000] 范围内
 * 1 <= Node.val <= 1000
 * 每个节点值都 不同
 * 给定的二叉树中有某个结点使得 node.val == k
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    //M1 treeToGraph + bfs
    int findClosestLeafM1(TreeNode* root, int k) {
        if (root->left == NULL && root->right == NULL) { // leaf
            return root->val;
        }
        // 无法区分叶子结点，不方便后续的逻辑
        // unordered_map<int, vector<int>> graph;
        unordered_map<TreeNode*, vector<TreeNode *>> graph;
        buildGraph(root, graph);

        // find StartPoint val=k
        queue<TreeNode*> que;
        unordered_set<TreeNode*> walked;

        for (auto &[tn, vec] : graph) {
            if (tn != NULL && tn->val == k) {
                que.push(tn);
                walked.insert(tn);
                break;
            }
        }

        while (!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                auto cur = que.front();
                que.pop();
                if (cur->left == NULL && cur->right == NULL) { // leaf
                    return cur->val;
                }
                auto neis = graph[cur];
                for (auto& ne : neis) {
                    if (walked.count(ne) == 1) {
                        continue;
                    }
                    que.push(ne);
                    walked.insert(ne);
                }
            }
        }
        return 0;
    }

    // 单节点时 graph为空
    void buildGraph(TreeNode*root, unordered_map<TreeNode*, vector<TreeNode*>> &graph) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            buildGraph(root->left, graph);
        }

        if (root->right != NULL) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            buildGraph(root->right, graph);
        }
    }

    int ans = 0;
    int minDis = INT_MAX;
    // M2 build Son2Fa, dfs FindMinDisLeaf
    int findClosestLeaf(TreeNode* root, int k) {
        if (root->left == NULL && root->right == NULL) { // leaf
            return root->val;
        }
        unordered_map<TreeNode*, TreeNode*> son2Fa;
        buildFa(root, son2Fa);
        son2Fa[root] = NULL;
        TreeNode* startP = NULL;
        for (auto& [s, f] : son2Fa )  {
            if (s != NULL && s->val == k) {
                startP = s;
                break;
            }
        }

        //bfs
        dfsFindLeaf(startP, NULL, 0, son2Fa);
        return ans;
    }


    void dfsFindLeaf(TreeNode* start, TreeNode* from, int dis, unordered_map<TreeNode*, TreeNode*>& son2Fa) {
        if (start == NULL) {
            return;
        }
        if (start->left == NULL && start->right == NULL) {
            if (dis < minDis) {
                ans = start->val;
                minDis = dis;
            }
            return;
        }
        int nextDis = dis+1;
        if (start->left != from) {
            dfsFindLeaf(start->left, start, nextDis,  son2Fa);
        }
        if (start->right != from) {
            dfsFindLeaf(start->right, start, nextDis,son2Fa);
        }

        TreeNode *parent = son2Fa[start];
        if (parent != from) {
            dfsFindLeaf(parent, start, nextDis, son2Fa);
        }
    }

    // if only root, son2Fa is empty
    void buildFa(TreeNode* root,  unordered_map<TreeNode*, TreeNode*>& son2Fa) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            son2Fa[root->left] = root;
            buildFa(root->left, son2Fa);
        }

        if (root->right) {
            son2Fa[root->right] = root;
            buildFa(root->right, son2Fa);
        }
    }

};
// @lc code=end



/*

Wrong Answer
319/336 cases passed (N/A)
Testcase
[1]
1
Answer
0
Expected Answer
1


//自身就是叶子结点 直接返回
Wrong Answer
320/336 cases passed (N/A)
Testcase
[1,2,3,4,5]
5
Answer
4
Expected Answer
5


Wrong Answer
306/336 cases passed (N/A)
Testcase
[1,2,3,4,null,null,null,5,null,6]
2
Answer
6
Expected Answer
3

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
