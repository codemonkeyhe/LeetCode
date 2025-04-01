/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-24
 * @tag  binaryTree
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
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (73.17%)
 * Likes:    626
 * Dislikes: 0
 * Total Accepted:    299.3K
 * Total Submissions: 406.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 *
 * 假设二叉树中至少有一个节点。
 *
 *
 *
 * 示例 1:
 * 输入: root = [2,1,3]
 * 输出: 1
 *
 *
 * 示例 2:
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 *
 *
 *
 *
 * 提示:
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qe;
        qe.push(root);
        int leftSon = 0;
        while(!qe.empty()) {
            int cnt = qe.size();
            for (int i = 0; i < cnt; i++) {
                TreeNode* tmp = qe.front();
                qe.pop();
                if (i == 0) {
                    leftSon = tmp->val;
                }
                if (tmp->left) {
                    qe.push(tmp->left);
                }

                if (tmp->right) {
                    qe.push(tmp->right);
                }
            }
        }
        return leftSon;
    }
};


class Solution {
public:
    int maxDep = -1;

    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        int dep = 0;
        maxDep = -1;
        dfs(root, dep, res);
        return res;
    }

   //  同一层的只会覆盖第一次，第二次的话相当于== maxDep，则不会覆盖
    void dfs(TreeNode* root, int dep, int& res) {
        if (root == NULL)  {
            return;
        }

        if (dep > maxDep) {
            maxDep = dep;
            res = root->val;
        }

        dfs(root->left, dep+1, res);
        dfs(root->right, dep+1, res);
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


