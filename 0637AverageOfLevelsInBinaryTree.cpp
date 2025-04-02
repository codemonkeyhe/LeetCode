/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-02
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
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (70.58%)
 * Likes:    527
 * Dislikes: 0
 * Total Accepted:    251.5K
 * Total Submissions: 350.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10^-5 以内的答案可以被接受。
 *
 *
 *
 * 示例 1：
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 * 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
 * 因此返回 [3, 14.5, 11] 。
 *
 *
 * 示例 2:
 * 输入：root = [3,9,20,15,7]
 * 输出：[3.00000,14.50000,11.00000]
 *
 *
 *
 *
 * 提示：
 * 树中节点数量在 [1, 10^4] 范围内
 * -2^31 <= Node.val <= 2^31 - 1
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> qe;
        qe.push(root);
        vector<double> res;
        while(!qe.empty()) {
            int cnt = qe.size();
            long long sum = 0;
            for (int i = 0; i < cnt; i++) {
                TreeNode* cur = qe.front();
                qe.pop();
                sum+= cur->val;

                if (cur->left) {
                    qe.push(cur->left);
                }

                if (cur->right) {
                    qe.push(cur->right);
                }

            }
            double avg = double(sum)/cnt;
            res.push_back(avg);
        }
        return res;
    }
};

// dfs
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<long long> sum;
        vector<int> cnt;
        int dep = 0;
        dfs(root, dep, sum, cnt);
        vector<double> res;
        for (int i = 0; i < sum.size(); i++) {
            res.push_back( double(sum[i]) / cnt[i]);
        }
        return res;
    }

    void dfs(TreeNode* root, int dep, vector<long long>& sum, vector<int>& cnt) {
        if (root == NULL) {
            return;
        }

        if (sum.size() == dep) {
            sum.push_back(root->val);
            cnt.push_back(1);
        } else {
            sum[dep] += root->val;
            cnt[dep]++;
        }

        dfs(root->left, dep + 1, sum, cnt);
        dfs(root->right, dep + 1, sum, cnt);
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


