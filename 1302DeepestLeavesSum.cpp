/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-18
 * @tag queue, DFS, binaryTree
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
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 *
 * https://leetcode.cn/problems/deepest-leaves-sum/description/
 *
 * algorithms
 * Medium (85.45%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    71.5K
 * Total Submissions: 83.5K
 * Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
 *
 * 给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * 输出：15
 *
 *
 * 示例 2：
 * 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * 输出：19
 *
 *
 *
 *
 * 提示：
 *
 * 树中节点数目在范围 [1, 104] 之间。
 * 1 <= Node.val <= 100
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
    int deepestLeavesSumBFS(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int dep = 0;
        int sum = 0;
        while(!que.empty()) {
            int cnt = que.size();
            int ss = 0;
            for(int i = 0; i < cnt; i++){
                TreeNode* cur = que.front();
                que.pop();

                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
                ss += cur->val;
            }
            dep++;
            sum = ss;
        }
        return sum;
    }


    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int maxDep = -1;
        dfs(root, 0, maxDep, sum);
        return sum;
    }


    void dfs(TreeNode* root, int dep, int& maxDep, int &sum) {
        if (root == NULL) {
            return;
        }
        if (dep > maxDep) {
            maxDep = dep;
            sum = root->val;
        } else if (dep == maxDep){
            sum += root->val;
        }

        dfs(root->left, dep+1, maxDep, sum);

        dfs(root->right, dep+1, maxDep, sum);
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


