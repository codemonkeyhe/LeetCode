/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-08
 * @tag binaryTree
 * @similar 742, 863, 2385
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 *
 * https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (61.44%)
 * Likes:    730
 * Dislikes: 0
 * Total Accepted:    62K
 * Total Submissions: 100.7K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * 给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 k ，返回到目标结点 target 距离为 k
 * 的所有结点的值的数组。
 *
 * 答案可以以 任何顺序 返回。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 * 输出：[7,4,1]
 * 解释：所求结点为与目标结点（值为 5）距离为 2 的结点，值分别为 7，4，以及 1
 *
 *
 * 示例 2:
 * 输入: root = [1], target = 1, k = 3
 * 输出: []
 *
 *
 *
 *
 * 提示:
 * 节点数在 [1, 500] 范围内
 * 0 <= Node.val <= 500
 * Node.val 中所有值 不同
 * 目标结点 target 是树上的结点。
 * 0 <= k <= 1000
 *
 *
 *
 *
 */
unordered_map
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> son2Fa;
        vector<int> res;
        getSon(target, k, res);
        dfs(root,  son2Fa);
        son2Fa[root] = NULL;
        TreeNode* cur = target;

        int i = k;
        while (i>=0) {
            TreeNode* fa = son2Fa[cur];
            if (fa == NULL) {
                break;
            }
            int newD = i-2;
            if (fa->left == cur) {
                getSon(fa->right, newD, res); // go to RightSon
            } else { //
                getSon(fa->left, newD, res); // go to LeftSon
            }
            cur = fa;
            i--;
            if (i == 0) {
                res.push_back(fa->val);
            }
        }
        return res;
    }


    void getSon(TreeNode* target, int k, vector<int>& res) {
        if (target == NULL) {
            return;
        }
        if (k == 0) {
            res.push_back(target->val);
            return;
        }
        int newK = k-1;
        getSon(target->left, newK, res);
        getSon(target->right, newK, res);
        return ;
    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&  son2Fa) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            son2Fa[root->left] = root;
            dfs(root->left, son2Fa);
        }
        if (root->right) {
            son2Fa[root->right] = root;
            dfs(root->right, son2Fa);
        }
        return;
    }


};
// @lc code=end




int main() {
    Solution s;
}


/*

BinaryTree FindFather
M1 Dfs and build son2fa map
M2 DFS parse tree to graph


Tips
M1

M2

*/


