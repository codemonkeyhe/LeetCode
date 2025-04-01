/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-01
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
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (66.43%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    178.5K
 * Total Submissions: 267.7K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 *
 *
 *
 * 示例1：
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 *
 *
 * 示例2：
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 *
 *
 *
 *
 * 提示：
 * 二叉树的节点个数的范围是 [0,10^4]
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
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
    vector<int> largestValues(TreeNode* root) {
        // 100 is too small
        // vector<int> res(100);
        if (root == NULL) {
            return vector<int>();
        }
        vector<int> res(1000);
        queue<TreeNode*> que;
        que.push(root);
        int dep = 0;
        while(!que.empty()) {
            int cnt = que.size();
            for(int i = 0; i < cnt; i++) {
                TreeNode* tmp = que.front();
                que.pop();
                if (i == 0) {
                    res[dep] = tmp->val;
                } else if (tmp->val > res[dep]) {
                    res[dep] = tmp->val;
                }

                if (tmp->left) {
                    que.push(tmp->left);
                }

                if (tmp->right) {
                    que.push(tmp->right);
                }
            }
            dep++;
        }
        res.resize(dep);
        return res;
    }
};


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        }
        vector<int>  res;
        res.resize(1000, INT_MIN);
        int dep = 0;
        int maxDep = 0;
        dfs(root, dep, maxDep, res);
        res.resize(maxDep+1);
        return res;
    }


    void dfs(TreeNode* root, int dep, int& maxDep, vector<int>& res) {
        if (root == NULL) {
            return;
        }

        if (root->val > res[dep]) {
            res[dep] = root->val;
        }
        if (dep > maxDep) {
            maxDep = dep;
        }
        int ndep = dep+1;
        dfs(root->left, ndep, maxDep, res);
        dfs(root->right, ndep, maxDep, res);
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


