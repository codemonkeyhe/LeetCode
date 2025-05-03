/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-03
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
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
 *
 * https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (68.33%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 49.3K
 * Testcase Example:  '[2,3,1,3,1,null,1]'
 *
 * 给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「伪回文」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。
 *
 * 请你返回从根到叶子节点的所有路径中 伪回文 路径的数目。
 *
 *
 *
 * 示例 1：
 * 输入：root = [2,3,1,3,1,null,1]
 * 输出：2
 * 解释：上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
 * ⁠    在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1]
 * 存在回文排列 [1,2,1] 。
 *
 *
 * 示例 2：
 * 输入：root = [2,1,1,1,3,null,null,null,null,null,1]
 * 输出：1
 * 解释：上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
 * ⁠    这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
 *
 *
 * 示例 3：
 * 输入：root = [9]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 给定二叉树的节点数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 9
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
    vector<int> path;

    int pseudoPalindromicPaths (TreeNode* root) {
        path.resize(10);
        dfs(root);
        return sum;
    }

    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        path[root->val]++;

        if (root->left == NULL && (root->right == NULL)) {
            // left
            if (isPathOK()) {
                sum++;
            }
        }

        dfs(root->left);

        dfs(root->right);

        path[root->val]--;
    }

    bool isPathOK() {
        int odd = 0;
        for (int i = 1; i <= 9; i++) {
            if (path[i] & 1) {
                odd++;
            }
        }
        return (odd <= 1);
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


