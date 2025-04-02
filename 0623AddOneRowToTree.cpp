/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-02
 * @tag
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
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 *
 * https://leetcode.cn/problems/add-one-row-to-tree/description/
 *
 * algorithms
 * Medium (60.12%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    52.7K
 * Total Submissions: 87.4K
 * Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
 *
 * 给定一个二叉树的根 root 和两个整数 val 和 depth ，在给定的深度 depth 处添加一个值为 val 的节点行。
 *
 * 注意，根节点 root 位于深度 1 。
 *
 * 加法规则如下:
 *
 *
 * 给定整数 depth，对于深度为 depth - 1 的每个非空树节点 cur ，创建两个值为 val 的树节点作为 cur
 * 的左子树根和右子树根。
 * cur 原来的左子树应该是新的左子树根的左子树。
 * cur 原来的右子树应该是新的右子树根的右子树。
 * 如果 depth == 1 意味着 depth - 1 根本没有深度，那么创建一个树节点，值 val
 * 作为整个原始树的新根，而原始树就是新根的左子树。
 *
 *
 *
 *
 * 示例 1:
 * 输入: root = [4,2,6,3,1,5], val = 1, depth = 2
 * 输出: [4,1,1,2,null,null,6,3,1,5]
 *
 * 示例 2:
 * 输入: root = [4,2,null,3,1], val = 1, depth = 3
 * 输出:  [4,2,null,1,1,3,null,null,1]
 *
 *
 *
 *
 * 提示:
 * 节点数在 [1, 10^4] 范围内
 * 树的深度在 [1, 10^4]范围内
 * -100 <= Node.val <= 100
 * -10^5 <= val <= 10^5
 * 1 <= depth <= the depth of tree + 1
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
class SolutionBFS {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* nRoot = new TreeNode(val);
            nRoot->left = root;
            return nRoot;
        }

        queue<TreeNode*> qe;
        qe.push(root);
        int dep = 1;
        while(!qe.empty()) {
            int cnt = qe.size();
            bool add = false;
            if (dep+1 == depth) {
                add = true;
            }
            for(int i = 0; i < cnt; i++) {
                TreeNode* cur = qe.front();
                qe.pop();

                if (cur->left) {
                    qe.push(cur->left);
                }

                if (cur->right) {
                    qe.push(cur->right);
                }

                if (add) {
                    TreeNode* node1 = new TreeNode(val);
                    TreeNode* node2 = new TreeNode(val);
                    TreeNode* oldLeft = cur->left;
                    TreeNode* oldRight = cur->right;
                    cur->left = node1;
                    cur->right = node2;
                    node1->left = oldLeft;
                    node2->right = oldRight;
                }
            }
            dep++;

            if (add) {
                break;
            }
        }
        return root;
    }
};


// DFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, NULL);
        }

        int dep = 1;
        dfs(root, val, dep, depth);
        return root;
    }

    void dfs(TreeNode* root, int val, int curD, int depth) {
        if (root == NULL) {
            return ;
        }
        int ndep = curD+1;

        if (ndep == depth) {
            TreeNode* node1 = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            TreeNode* oldLeft = root->left;
            TreeNode* oldRight = root->right;
            root->left = node1;
            root->right = node2;
            node1->left = oldLeft;
            node2->right = oldRight;
            return;
        }

        dfs(root->left, val, ndep, depth);

        dfs(root->right, val, ndep, depth);

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


