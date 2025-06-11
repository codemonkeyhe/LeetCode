/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-06,2025-06-11
 * @tag  recursion,binaryTree
 * @similar 104
 */


/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode.cn/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (60.35%)
 * Likes:    1689
 * Dislikes: 0
 * Total Accepted:    556.1K
 * Total Submissions: 893.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你一棵二叉树的根节点，返回该树的 直径 。
 * 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
 * 两节点之间路径的 长度 由它们之间边数表示。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4,5]
 * 输出：3
 * 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
 *
 *
 * 示例 2：
 * 输入：root = [1,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 树中节点数目在范围 [1, 10^4] 内
 * -100 <= Node.val <= 100
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
    int maxD = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return maxD;
    }


    int getHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        int curHeight = max(leftH, rightH) + 1;
        int curD = leftH + rightH;
        maxD = max(maxD, curD);
        return curHeight;
    }
};
// @lc code=end



/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class SolutionOld {
public:

/*
Runtime: 12 ms, faster than 90.87% of C++ online submissions for Diameter of Binary Tree.
Memory Usage: 20.7 MB, less than 82.53% of C++ online submissions for Diameter of Binary Tree.
BUG原因 粗心大意 没看清题意， 直径不是经过节点数，而是路径path
*/
    // 返回树的深度
    int helper(TreeNode* root, int &maxDia) {
        if (root == NULL) {
            return 0;
        }
        int leftDep = helper(root->left, maxDia);
        int rightDep = helper(root->right, maxDia);
       //BUG int curDia = leftDep + rightDep + 1;
        int curDia = leftDep + rightDep;
        if (curDia > maxDia) {
            maxDia = curDia;
        }
        return max(leftDep, rightDep) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }

};


int diameterOfBinaryTree(struct TreeNode* root){

}


int main() {
    Solution s;
}


/*
Tips
本质上是考 二叉树的最大深度

每个节点的直径定义为  左子树最大深度+右子树最大深度+1
树的直径： 遍历每个节点的直径，找出最大的直径

M1 DFS

M2

*/


