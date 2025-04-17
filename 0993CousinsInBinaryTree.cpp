/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-17
 * @tag binaryTree
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 *
 * https://leetcode.cn/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (58.95%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    86.2K
 * Total Submissions: 145.1K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
 * 如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。
 * 我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。
 * 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4], x = 4, y = 3
 * 输出：false
 *
 *
 * 示例 2：
 * 输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
 * 输出：true
 *
 *
 * 示例 3：
 * 输入：root = [1,2,3,null,4], x = 2, y = 3
 * 输出：false
 *
 *
 *
 * 提示：
 * 二叉树的节点数介于 2 到 100 之间。
 * 每个节点的值都是唯一的、范围为 1 到 100 的整数。
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
    // M1 BFS 且记录父节点

    // M2 DFS 记录父节点
    bool isCousinsDFS(TreeNode* root, int x, int y) {
        int f1 = -1;
        int f2 = -1;
        int d1 = findDep(root, x, 0, 0, f1);
        int d2 = findDep(root, y, 0, 0, f2);
      //  cout << "d1=" << d1 << "d2=" << d2 << " f1=" << f1 << " f2=" << f2 << endl;
        if (d1==d2 && (f1 != f2)) {
            return true;
        }
        return false;
    }

    int findDep(TreeNode* root, int x, int dep, int from, int& fa) {
        if (root == NULL) {
            return -1;
        }

        if (root->val == x) {
            fa = from;
            return dep;
        }
        dep+=1;
        from = root->val;
        int leD = findDep(root->left, x, dep, from, fa);
        if (leD >= 0) {
            return leD;
        }
        int riD = findDep(root->right, x, dep, from, fa);
        return riD;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int> > que;
        que.emplace(root, 0);
        int depX = -1;
        int depY = -1;
        int faX = -1;
        int faY = -1;
        int dep = 0;
        while (!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                auto [node, fa] = que.front();
                que.pop();
                if (node->val == x) {
                    depX = dep;
                    faX = fa;
                } else if (node->val == y) {
                    depY = dep;
                    faY = fa;
                }
                if (node->left) {
                    que.emplace(node->left, node->val);
                }

                if (node->right) {
                    que.emplace(node->right, node->val);
                }
            }
            if (depX != -1 && depY != -1) {
                break;
            }
            dep++;
        }
        if (depX  == depY && (faX != faY)) {
            return true;
        }
        return false;
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


