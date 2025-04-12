/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-12
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
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
 *
 * https://leetcode.cn/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (71.70%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    40.2K
 * Total Submissions: 55.8K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * 给定一个整数数组，它表示BST(即 二叉搜索树 )的 先序遍历 ，构造树并返回其根。
 *
 * 保证 对于给定的测试用例，总是有可能找到具有给定需求的二叉搜索树。
 *
 * 二叉搜索树 是一棵二叉树，其中每个节点， Node.left 的任何后代的值 严格小于 Node.val , Node.right 的任何后代的值
 * 严格大于 Node.val。
 *
 * 二叉树的 前序遍历 首先显示节点的值，然后遍历Node.left，最后遍历Node.right。
 *
 *
 *
 * 示例 1：
 * 输入：preorder = [8,5,1,7,10,12]
 * 输出：[8,5,10,1,7,null,12]
 *
 *
 * 示例 2:
 * 输入: preorder = [1,3]
 * 输出: [1,null,3]
 *
 *
 *
 *
 * 提示：
 * 1 <= preorder.length <= 100
 * 1 <= preorder[i] <= 10^8
 * preorder 中的值 互不相同
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, 0, preorder.size()-1);
    }


    TreeNode* buildBST(vector<int>& nums, int le, int ri) {
        if (le > ri) {
            return NULL;
        }
        TreeNode* root = new TreeNode(nums[le]);
        int i = le+1;
        for (; i <= ri; i++) {
            if (nums[i] > nums[le]) {
                break;
            }
        }
        root->left = buildBST(nums, le+1, i-1);
        root->right = buildBST(nums, i, ri);
        return root;
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


