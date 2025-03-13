/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-13
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
 *
 * https://leetcode.cn/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (65.15%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    98.5K
 * Total Submissions: 150.5K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n' +
  '[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * 请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
 *
 * 举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。
 * 如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
 * 如果给定的两个根结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
 * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：root1 = [1,2,3], root2 = [1,3,2]
 * 输出：false
 *
 *
 * 提示：
 * 给定的两棵树结点数在 [1, 200] 范围内
 * 给定的两棵树上的值在 [0, 200] 范围内
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        getLeaf(root1, leaf1);
        vector<int> leaf2;
        getLeaf(root2, leaf2);
        if (leaf1.size() != leaf2.size()) {
            return false;
        }
        return (leaf1 == leaf2);
        /*
        for (int i = 0; i < leaf1.size(); i++) {
            if (leaf1[i] != leaf2[i]) {
                return false;
            }
        }
        return true;
        */
    }

    void getLeaf(TreeNode* root, vector<int>& leaf) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            leaf.push_back(root->val);
            return;
        }
        getLeaf(root->left, leaf);
        getLeaf(root->right, leaf);
        return;
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


