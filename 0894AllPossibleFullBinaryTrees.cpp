/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-02
 * @tag binaryTree,dp
 * @similar  95,96
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的真二叉树
 *
 * https://leetcode.cn/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (80.60%)
 * Likes:    421
 * Dislikes: 0
 * Total Accepted:    40.1K
 * Total Submissions: 49.8K
 * Testcase Example:  '7'
 *
 * 给你一个整数 n ，请你找出所有可能含 n 个节点的 真二叉树 ，并以列表形式返回。答案中每棵树的每个节点都必须符合 Node.val == 0 。
 * 答案的每个元素都是一棵真二叉树的根节点。你可以按 任意顺序 返回最终的真二叉树列表。
 * 真二叉树 是一类二叉树，树中每个节点恰好有 0 或 2 个子节点。
 *
 *
 *
 * 示例 1：
 * 输入：n = 7
 * 输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 *
 *
 * 示例 2：
 * 输入：n = 3
 * 输出：[[0,0,0]]
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 20
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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n%2 == 0) {
            return vector<TreeNode*>();
        }
        if (n == 1) {
            TreeNode* tmp = new TreeNode(0);
            return vector<TreeNode*>{tmp};
        }

        vector<TreeNode*> res;
        // n , rootNode is 1, leftSon is i , rightSon is n -1 -i;
        for (int i = 1; i < n - 1; i+=2) {
            // root is i+1;
            int j = n - 1 - i;
            auto leftSon = allPossibleFBT(i);
            auto rightSon = allPossibleFBT(j);
            for (auto& le : leftSon) {
                for (auto& ri : rightSon) {
                    TreeNode* root = new TreeNode(0);
                    root->left = le;
                    root->right = ri;
                    res.push_back(root);
                }
            }
        }
        return res;
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


