/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-01
 * @tag BST
 * @similar 530
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 *
 * https://leetcode.cn/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (60.34%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    95.9K
 * Total Submissions: 158.2K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 *
 * 差值是一个正数，其数值等于两值之差的绝对值。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 *
 *
 * 示例 2：
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 树中节点的数目范围是 [2, 100]
 * 0 <= Node.val <= 10^5
 *
 *
 *
 *
 * 注意：本题与
 * 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * 相同
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
    int minDiffInBST(TreeNode* root) {
        int pre = -1000000;
        int md = INT_MAX;
        inorder(root, pre, md);
        return md;
    }


    void inorder(TreeNode* root, int& pre,  int& md) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, pre, md);

        int diff = root->val - pre;
        if (diff < md ) {
            md = diff;
        }
        pre = root->val;

        inorder(root->right, pre, md);
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


