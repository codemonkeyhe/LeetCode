/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-30
 * @tag binaryTree
 * @similar 1325
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
 *
 * https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/description/
 *
 * algorithms
 * Medium (62.09%)
 * Likes:    189
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 45K
 * Testcase Example:  '[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]\n1'
 *
 * 给你二叉树的根节点 root 和一个整数 limit ，请你同时删除树中所有 不足节点 ，并返回最终二叉树的根节点。
 * 假如通过节点 node 的每种可能的 “根-叶” 路径上值的总和全都小于给定的 limit，则该节点被称之为 不足节点 ，需要被删除。
 * 叶子节点，就是没有子节点的节点。
 * 【题目容易产生误解，意思是 ：  如果当前子树中的所有叶子节点均为「不足节点」则当前节点需要删除，结合示例3来理解。】
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
 * 输出：[1,2,3,4,null,null,7,8,9,null,14]
 *
 *
 * 示例 2：
 * 输入：root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
 * 输出：[5,4,8,11,null,17,4,7,null,null,null,5]
 *
 *
 * 示例 3：
 * 输入：root = [1,2,-3,-5,null,4,null], limit = -1
 * 输出：[1,null,-3,4]
 *
 *
 *
 *
 * 提示：
 * 树中节点数目在范围 [1, 5000] 内
 * -10^5 <= Node.val <= 10^5
 * -10^9 <= limit <= 10^9
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
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum = 0;
        bool res = isLimit(root, limit, sum);
        if (res) {
            return NULL;
        }
        return root;
    }


    // Error version
    TreeNode* delLimit(TreeNode* root, int limit, int& sum) {
        if (root == NULL) {
            return NULL;
        }

        sum += root->val;

        auto left = delLimit(root->left, limit, sum);
        root->left = left;

        auto right = delLimit(root->right, limit, sum);
        root->right = right;

        // cur  leaf node should be del
        if ((root->left == NULL) && (root->right == NULL) && (sum < limit)) {
            sum -= root->val;
            return NULL;
        }
        sum -= root->val;

        return  root;
    }


    // true means insufficient node
    // false means ok
    bool isLimit(TreeNode* root, int limit, int& sum) {
        if (root == NULL) {
            // key point, NULL taken as insufficient
            return true;
        }

        // any leaf node shoud give a clear result, whether insufficient or not
        // ErrorCase
        //          if ((root->left == NULL) && (root->right == NULL) && (sum < limit)) { return true; }
        if ((root->left == NULL) && (root->right == NULL) ) {
            if ((root->val + sum < limit)) {
                return true;
            } else {
                return false;
            }
        }

        sum += root->val;

        auto left = isLimit(root->left, limit, sum);
        auto right = isLimit(root->right, limit, sum);

        // cur  leaf node should be del
        if (left){
            root->left = NULL;
        }
        if (right) {
            root->right = NULL;
        }
        sum -= root->val;
        // only both left and right son are  insufficient ,
        // then current node is insufficient
        return  left && right;
    }



};

// @lc code=end


/*

Wrong Answer
73/117 cases passed (N/A)
Testcase
[1,2,-3,-5,null,4,null]
-1
Answer
[1,2,-3,null,null,4]
Expected Answer
[1,null,-3,4]


Wrong Answer
78/117 cases passed (N/A)
Testcase
[10,5,10]
21
Answer
[10]
Expected Answer
[]

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


