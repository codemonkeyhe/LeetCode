/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-16
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
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
 *
 * https://leetcode.cn/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (73.80%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    87.6K
 * Total Submissions: 118.7K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * 给你一棵二叉搜索树的 root ，请你 按中序遍历
 * 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
 *
 *
 *
 * 示例 1：
 * 输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 *
 *
 * 示例 2：
 * 输入：root = [5,1,7]
 * 输出：[1,null,5,null,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数的取值范围是 [1, 100]
 * 0 <= Node.val <= 1000
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
    //
    TreeNode* increasingBSTErr(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* leftN = increasingBST(root->left);
        TreeNode* p = leftN;
        while(p &&  p->right != NULL) {
            p = p->right;
        }
        if (p) {
            p->right = root;
        }
        root->left = NULL;
        TreeNode* rightN = increasingBST(root->right);
        root->right = rightN;
        return leftN;
    }


    TreeNode* increasingBSTM1(TreeNode* root) {
        TreeNode* pre = new TreeNode(0);
        TreeNode* res = pre;
        LXR(root, pre);
        return res->right;
    }


    // XXX pre  must use &
    // Methor2: pre as class member
    void LXR(TreeNode* root, TreeNode*& pre) {
        if (root == NULL) {
            return ;
        }
        LXR(root->left, pre);
        root->left = NULL;
        //cout << "pre=" << pre->val << " root=" << root->val << endl;
        pre->right = root;
        pre = pre->right;
        LXR(root->right, pre);
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


