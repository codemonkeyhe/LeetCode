/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-05
 * @tag  BinaryTree
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
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 *
 * https://leetcode.cn/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (48.04%)
 * Likes:    826
 * Dislikes: 0
 * Total Accepted:    93.3K
 * Total Submissions: 192.4K
 * Testcase Example:  '[5,4,5,1,1,null,5]'
 *
 * 给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。
 *
 * 两个节点之间的路径长度 由它们之间的边数表示。
 *
 *
 *
 * 示例 1:
 * 输入：root = [5,4,5,1,1,5]
 * 输出：2
 *
 *
 * 示例 2:
 * 输入：root = [1,4,5,4,4,5]
 * 输出：2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 树的节点数的范围是 [0, 10^4] 
 * -1000 <= Node.val <= 1000
 * 树的深度将不超过 1000 
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
class SolutionUgly {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lpath = 0;
        bt(root, lpath);
        return lpath;
    }

    int bt(TreeNode* root, int& lpath) {
        if (root == NULL) {
            return 0;
        }
        int leP = bt(root->left, lpath);
        int riP = bt(root->right, lpath);
        bool eqLeft = false;
        if (root->left && (root->val == (root->left->val))) {
            eqLeft = true;
        }

        bool eqRight = false;
        if (root->right && (root->val == (root->right->val))) {
            eqRight = true;
        }

       // cout << " root=" << root->val << " lePath=" << leP << " riPath=" << riP <<  " eqLeft=" << eqLeft << " eqRight=" << eqRight << endl;

        if (!eqLeft && !eqRight) {
            return 0;
        }

        if (eqLeft && eqRight) {
            // 不过根节点
            int curP = leP+riP+2;
            if (curP > lpath) {
                lpath = curP;
                //cout << "lpath=" << lpath << endl;
            }
        }

        if (eqLeft) {
            leP+=1;
        }
        if (eqRight) {
            riP+=1;
        }
        int maxP = max(leP, riP);
        if (maxP > lpath) {
            lpath = maxP;
        }

        if (eqLeft && eqRight) {
            return maxP;
        }
        if (eqLeft) {
            return leP;
        }
        if (eqRight) {
            return riP;
        }
        return 0;
    }
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lpath = 0;
        btGrace(root, lpath);
        return lpath;
    }


    int btGrace(TreeNode* root, int& lpath) {
        if (root == NULL) {
            return 0;
        }
        int leP = btGrace(root->left, lpath);
        int riP = btGrace(root->right, lpath);
        int eqLeft = 0;
        if (root->left && (root->val == (root->left->val))) {
            eqLeft = leP+1;
        }

        int eqRight = 0;
        if (root->right && (root->val == (root->right->val))) {
            eqRight = riP+1;
        }

        if (!eqLeft && !eqRight) {
            return 0;
        }
        if (eqLeft+eqRight > lpath) {
            lpath = eqLeft+eqRight;
        }
        return max(eqLeft, eqRight);
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


