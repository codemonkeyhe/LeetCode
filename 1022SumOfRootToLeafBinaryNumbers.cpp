/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-
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
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 *
 * https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/description/
 *
 * algorithms
 * Easy (74.71%)
 * Likes:    258
 * Dislikes: 0
 * Total Accepted:    64.9K
 * Total Submissions: 86.5K
 * Testcase Example:  '[1,0,1,0,1,0,1]'
 *
 * 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。
 * 例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
 * 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
 * 返回这些数字之和。题目数据保证答案是一个 32 位 整数。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,0,1,0,1,0,1]
 * 输出：22
 * 解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 *
 *
 * 示例 2：
 * 输入：root = [0]
 * 输出：0
 *
 *
 * 提示：
 * 树中的节点数在 [1, 1000] 范围内
 * Node.val 仅为 0 或 1 
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
class SolutionBT {
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<int> path;
        int sum = 0;
        bt(root, path, sum);
        return sum;
    }


    void bt(TreeNode* root, vector<int>& path, int& sum) {
        if (root == NULL) {
            return;
        }

        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) { //leaf
            int cur = 0;
            int wei = 1;
            int i = path.size()-1;
            while (i >= 0) {
                cur += path[i]*wei;
                wei*=2;
                i--;
            }
            sum +=cur;
        }

        bt(root->left, path, sum);
        bt(root->right, path, sum);
        path.pop_back();
        return ;
    }

};

//
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<int> path;
        return dfs(root, path);
    }


    int dfs(TreeNode* root, vector<int> path) {
        if (root == NULL) {
            return 0;
        }

        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) { //leaf
            int cur = 0;
            int wei = 1;
            int i = path.size()-1;
            while (i >= 0) {
                cur += path[i]*wei;
                wei*=2;
                i--;
            }
            return cur;
        }

        int sumLeft = dfs(root->left, path);
        int sumRight = dfs(root->right, path);
        int sum = sumLeft+sumRight;
        return sum;
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


