/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-04
 * @tag binaryTree
 * @similar  863
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 *
 * [2385] 感染二叉树需要的总时间
 *
 * https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/description/
 *
 * algorithms
 * Medium (51.63%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 52.5K
 * Testcase Example:  '[1,5,3,null,4,10,6,9,2]\n3'
 *
 * 给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start
 * 的节点开始爆发。
 *
 * 每分钟，如果节点满足以下全部条件，就会被感染：
 * 节点此前还没有感染。
 * 节点与一个已感染节点相邻。
 * 返回感染整棵树需要的分钟数。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,5,3,null,4,10,6,9,2], start = 3
 * 输出：4
 * 解释：节点按以下过程被感染：
 * - 第 0 分钟：节点 3
 * - 第 1 分钟：节点 1、10、6
 * - 第 2 分钟：节点5
 * - 第 3 分钟：节点 4
 * - 第 4 分钟：节点 9 和 2
 * 感染整棵树需要 4 分钟，所以返回 4 。
 *
 *
 * 示例 2：
 * 输入：root = [1], start = 1
 * 输出：0
 * 解释：第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 10^5
 * 每个节点的值 互不相同
 * 树中必定存在值为 start 的节点
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
    unordered_map<int, TreeNode*> son2fa;
    int maxPath = 0;

    int amountOfTime(TreeNode* root, int start) {
        makeFa(root);
        son2fa[root->val] = NULL;
        TreeNode* fa = son2fa[start];
        if (fa == NULL) { // means start is root
            dfs(root, NULL, son2fa, 0);
            return maxPath;
        }
        TreeNode* ss = fa->left;
        if ((fa->left == NULL) || (ss->val != start)) {
            ss = fa->right;
        }

        dfs(ss, NULL, son2fa, 0);
        return maxPath;
    }


    void makeFa(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            son2fa[root->left->val] = root;
            makeFa(root->left);
        }
        if (root->right) {
            son2fa[root->right->val] = root;
            makeFa(root->right);
        }
    }

    void dfs(TreeNode* ss, TreeNode* from, unordered_map<int, TreeNode*>& son2fa, int dep) {
        if (ss == NULL) {
            return;
        }
        if (dep > maxPath) {
            maxPath = dep;
        }
        dep++;
        auto fa = son2fa[ss->val];
        if (fa != from) {
            dfs(fa, ss, son2fa, dep);
        }
        if (ss->left != from) {
            dfs(ss->left, ss, son2fa, dep);
        }
        if (ss->right != from) {
            dfs(ss->right, ss, son2fa, dep);
        }
    }


};
// @lc code=end

/*

Wrong Answer
4/80 cases passed (N/A)
Testcase
[1,2,null,3,null,4,null,5]
2
Answer
5
Expected Answer
3

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


