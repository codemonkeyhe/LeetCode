/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-01
 * @tag BST
 * @similar 1038
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode.cn/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Medium (77.41%)
 * Likes:    1045
 * Dislikes: 0
 * Total Accepted:    314.8K
 * Total Submissions: 402.3K
 * Testcase Example:  '[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]'
 *
 * 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node
 * 的新值等于原树中大于或等于 node.val 的值之和。
 *
 * 提醒一下，二叉搜索树满足下列约束条件：
 *
 *
 * 节点的左子树仅包含键 小于 节点键的节点。
 * 节点的右子树仅包含键 大于 节点键的节点。
 * 左右子树也必须是二叉搜索树。
 *
 *
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
 * 相同
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
 * 示例 3：
 * 输入：root = [1,0,2]
 * 输出：[3,3,2]
 *
 *
 * 示例 4：
 * 输入：root = [3,2,4,1]
 * 输出：[7,9,4,10]
 *
 *
 *
 *
 * 提示：
 * 树中的节点数介于 0 和 10^4^ 之间。
 * 每个节点的值介于 -10^4 和 10^4 之间。
 * 树中的所有值 互不相同 。
 * 给定的树为二叉搜索树。
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
class SolutionLXR {
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> nlist;
        LXRsum(root, nlist);
        for(int i = nlist.size()-2; i >= 0; i--) {
            nlist[i]->val = nlist[i]->val + nlist[i+1]->val;
        }
        return root;
    }

    void LXRsum(TreeNode* root, vector<TreeNode*>& nlist) {
        if (root == NULL) {
            return;
        }

        LXRsum(root->left, nlist);

        nlist.push_back(root);

        LXRsum(root->right, nlist);
    }

};


class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
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


