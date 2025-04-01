/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-01
 * @tag BST
 * @similar 538
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 *
 * https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/description/
 *
 * algorithms
 * Medium (83.61%)
 * Likes:    296
 * Dislikes: 0
 * Total Accepted:    72.3K
 * Total Submissions: 86.2K
 * Testcase Example:  '[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]'
 *
 * 给定一个二叉搜索树 root (BST)，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。
 *
 * 提醒一下， 二叉搜索树 满足下列约束条件：
 *
 *
 * 节点的左子树仅包含键 小于 节点键的节点。
 * 节点的右子树仅包含键 大于 节点键的节点。
 * 左右子树也必须是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 * 输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
 * 输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 *
 *
 * 示例 2：
 * 输入：root = [0,null,1]
 * 输出：[1,null,1]
 *
 *
 *
 *
 * 提示：
 * 树中的节点数在 [1, 100] 范围内。
 * 0 <= Node.val <= 100
 * 树中的所有值均 不重复 。
 *
 *
 *
 *
 * 注意：该题目与 538: https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 * 相同
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

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        RXLsum(root, sum);
        return root;
    }

    void RXLsum(TreeNode* root, int& sum) {
        if (root == NULL) {
            return;
        }

        RXLsum(root->right, sum);
        sum += root->val;
        root->val = sum;
        RXLsum(root->left, sum);
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


