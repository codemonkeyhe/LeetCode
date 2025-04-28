/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-28
 * @tag bfs,dfs,binaryTree
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
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
 *
 * https://leetcode.cn/problems/even-odd-tree/description/
 *
 * algorithms
 * Medium (58.25%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    38.6K
 * Total Submissions: 65.5K
 * Testcase Example:  '[1,10,4,3,null,7,9,12,8,6,null,null,2]'
 *
 * 如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：
 *
 *
 * 二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
 * 偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
 * 奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
 *
 *
 * 给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
 * 输出：true
 * 解释：每一层的节点值分别是：
 * 0 层：[1]
 * 1 层：[10,4]
 * 2 层：[3,7,9]
 * 3 层：[12,8,6,2]
 * 由于 0 层和 2 层上的节点值都是奇数且严格递增，而 1 层和 3 层上的节点值都是偶数且严格递减，因此这是一棵奇偶树。
 *
 *
 * 示例 2：
 * 输入：root = [5,4,2,3,3,7]
 * 输出：false
 * 解释：每一层的节点值分别是：
 * 0 层：[5]
 * 1 层：[4,2]
 * 2 层：[3,3,7]
 * 2 层上的节点值不满足严格递增的条件，所以这不是一棵奇偶树。
 *
 *
 * 示例 3：
 * 输入：root = [5,9,1,3,5,7]
 * 输出：false
 * 解释：1 层上的节点值应为偶数。
 *
 *
 * 示例 4：
 * 输入：root = [1]
 * 输出：true
 *
 *
 * 示例 5：
 * 输入：root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
 * 输出：true
 *
 *
 *
 *
 * 提示：
 * 树中节点数在范围 [1, 10^5] 内
 * 1 <= Node.val <= 106
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
    bool isEvenOddTreeBFS(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int dep = 0;
        int prev = 0;
        while(!que.empty()) {
            int cnt = que.size();
            int want = (dep+1)%2;
            // want=1 asc  want=0 desc
            prev = INT_MAX;
            if (want) {
                prev = 0;
            }

            for (int i = 0; i < cnt; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if ((cur->val & 1) != want) {
                    return false;
                }
                if (want) {
                    if (cur->val <= prev) {
                        return false;
                    }
                } else {
                    if (cur->val >= prev) {
                        return false;
                    }
                }
                prev = cur->val;

                if (cur->left) {
                    que.push(cur->left);
                }

                if (cur->right) {
                    que.push(cur->right);
                }
            }
            dep++;
        }

        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        int dep = 0;
        vector<int> pre;
        auto res = dfs(root, dep, pre);
        return res;
    }


    bool dfs(TreeNode* root, int dep, vector<int>& pre) {
        if (root == NULL) {
            return true;
        }
        int noWant = dep%2;
        if ((root->val & 1) == (noWant)) {
            return false;
        }

        if (dep >= pre.size()) {
            pre.push_back(root->val);
        } else { //  same level
            if (noWant) {
                if ((root->val >= pre[dep])) {
                    return false;
                }
            } else {
                if (root->val <= pre[dep]) {
                    return false;
                }
            }
            pre[dep] = root->val;
        }
        dep++;
        bool left = dfs(root->left, dep, pre);
        if (left == false) {
            return false;
        }
        bool right = dfs(root->right, dep, pre);
        return right;
    }


};
// @lc code=end

/*
Wrong Answer
94/107 cases passed (N/A)
Testcase
[5,4,2,3,3,7]
Answer
true
Expected Answer
false

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


