/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-26
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
 * @lc app=leetcode.cn id=951 lang=cpp
 *
 * [951] 翻转等价二叉树
 *
 * https://leetcode.cn/problems/flip-equivalent-binary-trees/description/
 *
 * algorithms
 * Medium (67.43%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    23.7K
 * Total Submissions: 35.3K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]'
 *
 * 我们可以为二叉树 T 定义一个 翻转操作 ，如下所示：选择任意节点，然后交换它的左子树和右子树。
 * 只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转 等价 于二叉树 Y。
 * 这些树由根节点 root1 和 root2 给出。如果两个二叉树是否是翻转 等价 的函数，则返回 true ，否则返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
 * [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * 输出：true
 * 解释：我们翻转值为 1，3 以及 5 的三个节点。
 *
 *
 * 示例 2:
 * 输入: root1 = [], root2 = []
 * 输出: true
 *
 *
 * 示例 3:
 * 输入: root1 = [], root2 = [1]
 * 输出: false
 *
 *
 *
 *
 * 提示：
 * 每棵树节点数在 [0, 100] 范围内
 * 每棵树中的每个值都是唯一的、在 [0, 99] 范围内的整数
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && (root2 == NULL)) {
            return true;
        }
        if ((root1 == NULL) || (root2 == NULL)) {
            return false;
        }

        if (root1->val != root2->val) {
            return false;
        }

        bool leftOk = flipEquiv(root1->left, root2->left);
        bool rightOk = flipEquiv(root1->right, root2->right);
        if (leftOk && rightOk) {
            return true;
        }

        bool leftSwapOk = flipEquiv(root1->left, root2->right);
        bool rightSwapOk = flipEquiv(root1->right, root2->left);

        if (leftSwapOk && rightSwapOk) {
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


