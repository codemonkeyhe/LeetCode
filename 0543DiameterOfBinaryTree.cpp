/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-06
 * @tag  recursion
 * @similar 104
 */

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

class Solution {
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


