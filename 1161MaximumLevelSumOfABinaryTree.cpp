/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-30
 * @tag binaryTree,bfs,dfs
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
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 *
 * https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (65.55%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    55.1K
 * Total Submissions: 83.5K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * 给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。
 * 请返回层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,7,0,7,-8,null,null]
 * 输出：2
 * 解释：
 * 第 1 层各元素之和为 1，
 * 第 2 层各元素之和为 7 + 0 = 7，
 * 第 3 层各元素之和为 7 + -8 = -1，
 * 所以我们返回第 2 层的层号，它的层内元素之和最大。
 *
 *
 * 示例 2：
 * 输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在 [1, 10^4]范围内
 * -10^5 <= Node.val <= 10^5
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
    int maxLevelSum(TreeNode* root) {
        int dep = 0;
        vector<int> sum;
        dfsSum(root, dep, sum);
        int maxSum = INT_MIN;
        int maxDep = -1;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] > maxSum) {
                maxSum = sum[i];
                maxDep = i;
            }
        }
        return maxDep + 1;
    }

    void dfsSum(TreeNode* root, int dep, vector<int>& sum) {
        if (root == NULL) {
            return;
        }

        if (dep >= sum.size()) {  // first node of the same level
            sum.push_back(root->val);
        } else {
            sum[dep] += root->val;
        }

        dep++;
        dfsSum(root->left, dep, sum);
        dfsSum(root->right, dep, sum);
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


