/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-
 * @tag BST
 * @similar 783
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (62.76%)
 * Likes:    617
 * Dislikes: 0
 * Total Accepted:    315.8K
 * Total Submissions: 501.4K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 *
 * 差值是一个正数，其数值等于两值之差的绝对值。
 *
 *
 *
 * 示例 1：
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 *
 *
 * 示例 2：
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 树中节点的数目范围是 [2, 10^4]
 * 0 <= Node.val <= 10^5
 *
 *
 *
 *
 * 注意：本题与 783
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int pp = -1;
        LXRmin(root, res, pp);
        return res;
    }

    void LXRmin(TreeNode* root, int& res, int& pre) {
        if (root == NULL) {
            return ;
        }

        LXRmin(root->left, res, pre);
        if (pre == -1)  {
            pre = root->val;
        } else {
            int diff = root->val - pre;
            if (diff < res) {
                res = diff;
            }
            pre = root->val;
        }
        LXRmin(root->right, res, pre);
        return ;
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


