/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-26
 * @tag  binaryTree
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
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
 *
 * https://leetcode.cn/problems/binary-tree-pruning/description/
 *
 * algorithms
 * Medium (72.58%)
 * Likes:    385
 * Dislikes: 0
 * Total Accepted:    69.5K
 * Total Submissions: 96.3K
 * Testcase Example:  '[1,null,0,0,1]'
 *
 * 给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。
 * 返回移除了所有不包含 1 的子树的原二叉树。
 * 节点 node 的子树为 node 本身加上所有 node 的后代。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,null,0,0,1]
 * 输出：[1,null,0,null,1]
 * 解释：
 * 只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
 *
 *
 * 示例 2：
 * 输入：root = [1,0,1,0,0,0,1]
 * 输出：[1,null,1,null,1]
 *
 *
 * 示例 3：
 * 输入：root = [1,1,0,1,1,0,1,0]
 * 输出：[1,1,0,1,1,null,1]
 *
 *
 *
 *
 * 提示：
 * 树中节点的数目在范围 [1, 200] 内
 * Node.val 为 0 或 1
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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* pLeft = pruneTree(root->left);
        TreeNode* pRight = pruneTree(root->right);
        root->left = pLeft;
        root->right = pRight;
        if (pLeft == NULL && pRight == NULL) {
            if (root->val == 0) {
                return NULL;
            }
        }

        return root;
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


