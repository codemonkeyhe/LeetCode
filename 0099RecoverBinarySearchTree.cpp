/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-21
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
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode.cn/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Medium (60.64%)
 * Likes:    993
 * Dislikes: 0
 * Total Accepted:    164.9K
 * Total Submissions: 269.4K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。请在不改变其结构的情况下，恢复这棵树 。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,3,null,null,2]
 * 输出：[3,1,null,null,2]
 * 解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
 *
 *
 * 示例 2：
 * 输入：root = [3,1,4,null,null,2]
 * 输出：[2,1,4,null,null,3]
 * 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 *
 *
 *
 * 提示：
 * 树上节点的数目在范围 [2, 1000] 内
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 * 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用 O(1) 空间的解决方案吗？
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
class SolutionM1 {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        TreeNode* p1 = NULL;
        TreeNode* p2 = NULL;
        for (int i = 0; i < nodes.size()-1; i++) {
            if (nodes[i]->val > nodes[i+1]->val) {
                p2 = nodes[i+1];
                if (p1 == NULL) {
                    p1 = nodes[i];
                } else {
                    break;
                }
            }
        }

        // swap
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }

    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

};


class Solution {
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
    }

    void inorder(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        TreeNode* p1 = NULL;
        TreeNode* p2 = NULL;
        while(!st.empty() || (cur != NULL)) {
            while (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            // visit cur->val
           // cout << " cur=" << cur->val << endl;

            // Error Position
            //pre = cur;
            //cur = cur->right;

            if (pre && cur && (pre->val > cur->val)) {
                p2 = cur;
                if (p1 == NULL) {
                    p1 = pre;
                } else {
                    break;
                }
            }


            pre = cur;
            cur = cur->right;
        }

        if (p1 && p2) {
  //          cout << " p1=" << p1->val << endl;
   //         cout << " p2=" << p2->val << endl;
            int tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
        }
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


