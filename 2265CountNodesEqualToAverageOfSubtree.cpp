/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-02
 * @tag binaryTree,dfs
 * @similar 1080
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2265 lang=cpp
 *
 * [2265] 统计值等于子树平均值的节点数
 *
 * https://leetcode.cn/problems/count-nodes-equal-to-average-of-subtree/description/
 *
 * algorithms
 * Medium (82.50%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 17.4K
 * Testcase Example:  '[4,8,5,0,1,null,6]'
 *
 * 给你一棵二叉树的根节点 root ，找出并返回满足要求的节点数，要求节点的值等于其 子树 中值的 平均值 。
 *
 * 注意：
 *
 *
 * n 个元素的平均值可以由 n 个元素 求和 然后再除以 n ，并 向下舍入 到最近的整数。
 * root 的 子树 由 root 和它的所有后代组成。
 *
 *
 *
 *
 * 示例 1：
 * 输入：root = [4,8,5,0,1,null,6]
 * 输出：5
 * 解释：
 * 对值为 4 的节点：子树的平均值 (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 。
 * 对值为 5 的节点：子树的平均值 (5 + 6) / 2 = 11 / 2 = 5 。
 * 对值为 0 的节点：子树的平均值 0 / 1 = 0 。
 * 对值为 1 的节点：子树的平均值 1 / 1 = 1 。
 * 对值为 6 的节点：子树的平均值 6 / 1 = 6 。
 *
 *
 * 示例 2：
 * 输入：root = [1]
 * 输出：1
 * 解释：对值为 1 的节点：子树的平均值 1 / 1 = 1。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 1000] 内
 * 0 <= Node.val <= 1000
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
    int res = 0;

    int averageOfSubtree(TreeNode* root) {
        sumNode(root);
        return res;
    }



    pair<int, int> sumNode(TreeNode* root) {
        if (root == NULL) {
            return make_pair(0, 0);
        }
        auto [sumLe, cntLe] = sumNode(root->left);
        auto [sumRi, cntRi] = sumNode(root->right);
        int sum = sumLe + sumRi + root->val;
        int cnt = cntLe + cntRi + 1;
        if (sum/cnt == root->val) {
            res++;
        }
        return make_pair(sum, cnt);
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


