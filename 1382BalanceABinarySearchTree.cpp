/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-02
 * @tag  greedy,BST
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
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
 *
 * https://leetcode.cn/problems/balance-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (74.14%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 45.9K
 * Testcase Example:  '[1,null,2,null,3,null,4]'
 *
 * 给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。
 * 如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,null,2,null,3,null,4,null,null]
 * 输出：[2,1,3,null,null,null,4]
 * 解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
 *
 *
 * 示例 2：
 * 输入: root = [2,1,3]
 * 输出: [2,1,3]
 *
 *
 *
 *
 * 提示：
 * 树节点的数目在 [1, 10^4] 范围内。
 * 1 <= Node.val <= 10^5
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


    void walkLXR(TreeNode* root,  vector<int>& nodes) {
        if (root == NULL) {
            return;
        }
        walkLXR(root->left, nodes);
        nodes.push_back(root->val);
        walkLXR(root->right, nodes);
    }


    TreeNode* buildB(vector<int>& data, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(data[mid]);
        root->left = buildB(data, start, mid-1);
        root->right = buildB(data, mid+1, end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        walkLXR(root, nodes);
        return buildB(nodes, 0, nodes.size()-1);
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


