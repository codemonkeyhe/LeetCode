/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-03
 * @tag  binaryTree
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
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 *
 * https://leetcode.cn/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (61.39%)
 * Likes:    775
 * Dislikes: 0
 * Total Accepted:    108.3K
 * Total Submissions: 176K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * 给你一棵二叉树的根节点 root ，返回所有 重复的子树 。
 *
 * 对于同一类的重复子树，你只需要返回其中任意 一棵 的根结点即可。
 *
 * 如果两棵树具有 相同的结构 和 相同的结点值 ，则认为二者是 重复 的。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4,null,2,4,null,null,4]
 * 输出：[[2,4],[4]]
 *
 * 示例 2：
 * 输入：root = [2,1,1]
 * 输出：[[1]]
 *
 * 示例 3：
 * 输入：root = [2,2,2,3,null,3,null]
 * 输出：[[2,3],[3]]
 *
 *
 *
 * 提示：
 * 树中的结点数在 [1, 5000] 范围内。
 * -200 <= Node.val <= 200
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*> > str2node;
        dfs(root, str2node);
        vector<TreeNode*> res;
        for (auto it: str2node) {
            if (it.second.size() >= 2) {
                res.push_back(it.second[0]);
            }
        }
        return res;
    }


    string dfs(TreeNode* root, unordered_map<string, vector<TreeNode*> >& str2node ) {
        if (root == NULL) {
            return "X|";
        }
        string leStr = dfs(root->left, str2node);
        string riStr = dfs(root->right, str2node);
        // errorCase [2,1,11,11,null,1]
        // 1, 11,X,X,X 和 11,1,X,X,X混淆了
        // 因此，每个元素后面需要追加分隔符
        // string treeStr = to_string(root->val) + leStr + riStr;
        string treeStr = to_string(root->val) + "|" + leStr + riStr;
        str2node[treeStr].push_back(root);
        return treeStr;
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


