/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-03
 * @tag newbie
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
 * @lc app=leetcode.cn id=2236 lang=cpp
 *
 * [2236] 判断根结点是否等于子结点之和
 *
 * https://leetcode.cn/problems/root-equals-sum-of-children/description/
 *
 * algorithms
 * Easy (84.71%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    94.4K
 * Total Submissions: 114.2K
 * Testcase Example:  '[10,4,6]'
 *
 * 给你一个 二叉树 的根结点 root，该二叉树由恰好 3 个结点组成：根结点、左子结点和右子结点。
 *
 * 如果根结点值等于两个子结点值之和，返回 true ，否则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [10,4,6]
 * 输出：true
 * 解释：根结点、左子结点和右子结点的值分别是 10 、4 和 6 。
 * 由于 10 等于 4 + 6 ，因此返回 true 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,3,1]
 * 输出：false
 * 解释：根结点、左子结点和右子结点的值分别是 5 、3 和 1 。
 * 由于 5 不等于 3 + 1 ，因此返回 false 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树只包含根结点、左子结点和右子结点
 * -100 <= Node.val <= 100
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
    bool checkTree(TreeNode* root) {
        return (root->val == (root->left->val + root->right->val));
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


