/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-03
 * @tag binaryTree,dfs
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
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
 *
 * https://leetcode.cn/problems/sum-of-nodes-with-even-valued-grandparent/description/
 *
 * algorithms
 * Medium (81.75%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    23.3K
 * Total Submissions: 28.3K
 * Testcase Example:  '[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]'
 *
 * 给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：
 * 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
 * 如果不存在祖父节点值为偶数的节点，那么返回 0 。
 *
 *
 *
 * 示例：
 * 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * 输出：18
 * 解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
 *
 *
 *
 *
 * 提示：
 * 树中节点的数目在 1 到 10^4 之间。
 * 每个节点的值在 1 到 100 之间。
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
    int sum = 0;

    int sumEvenGrandparent(TreeNode* root) {
        sumG(root, NULL, NULL);
        return sum;
    }


    void sumG(TreeNode* root, TreeNode* fa, TreeNode* gp) {
        if (root == NULL) {
            return;
        }
        if (gp != NULL && ((gp->val & 1) == 0)) {
            sum += root->val;
        }
        sumG(root->left, root, fa);
        sumG(root->right, root, fa);
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


