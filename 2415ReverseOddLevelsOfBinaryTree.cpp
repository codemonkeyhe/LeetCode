/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-03
 * @tag binaryTree,dfs,bfs
 * @similar  101
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
 *
 * https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/description/
 *
 * algorithms
 * Medium (79.62%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    31.9K
 * Total Submissions: 39.8K
 * Testcase Example:  '[2,3,5,8,13,21,34]'
 *
 * 给你一棵 完美 二叉树的根节点 root ，请你反转这棵树中每个 奇数 层的节点值。
 * 例如，假设第 3 层的节点值是 [2,1,3,4,7,11,29,18] ，那么反转后它应该变成 [18,29,11,7,4,3,1,2] 。
 * 反转后，返回树的根节点。
 * 完美 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。
 * 节点的 层数 等于该节点到根节点之间的边数。
 *
 *
 *
 * 示例 1：
 * 输入：root = [2,3,5,8,13,21,34]
 * 输出：[2,5,3,8,13,21,34]
 * 解释：
 * 这棵树只有一个奇数层。
 * 在第 1 层的节点分别是 3、5 ，反转后为 5、3 。
 *
 *
 * 示例 2：
 * 输入：root = [7,13,11]
 * 输出：[7,11,13]
 * 解释：
 * 在第 1 层的节点分别是 13、11 ，反转后为 11、13 。
 *
 *
 * 示例 3：
 * 输入：root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
 * 输出：[0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
 * 解释：奇数层由非零值组成。
 * 在第 1 层的节点分别是 1、2 ，反转后为 2、1 。
 * 在第 3 层的节点分别是 1、1、1、1、2、2、2、2 ，反转后为 2、2、2、2、1、1、1、1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数目在范围 [1, 2^14] 内
 * 0 <= Node.val <= 10^5
 * root 是一棵 完美 二叉树
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int dep = 1;
        swapOdd(root->left, root->right, dep);
        return root;
    }


    void swapOdd(TreeNode* r1, TreeNode* r2, int dep) {
        if (r1 == NULL || (r2 == NULL)) {
            return;
        }
        if (dep&1) { //odd
            swap(r1->val , r2->val);
        }
        dep++;
        swapOdd(r1->left, r2->right, dep);
        swapOdd(r1->right, r2->left, dep);
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


