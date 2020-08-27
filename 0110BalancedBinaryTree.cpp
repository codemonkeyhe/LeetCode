/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-
 * @tag
 * @similar  104 111
 */

/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:
    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 24 ms, faster than 48.74% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 21.8 MB, less than 38.16% of C++ online submissions for Balanced Binary Tree.
*/
    int height(TreeNode* root) {
       if (root == NULL) {
           return 0;
        }
        int depLeft = height(root->left);
        int depRight = height(root->right);
        if (depLeft == -1 || depRight == -1 || abs(depRight - depLeft) > 1) {
            return -1;
        }
        return max(depLeft, depRight) + 1;
    }


    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        return height(root) >=0;

     //   int depth = 0;
    //    return helper(root, depth);
    }


/*
Runtime: 24 ms, faster than 48.74% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 21.6 MB, less than 79.18% of C++ online submissions for Balanced Binary Tree.
*/
    bool helperV1(TreeNode* root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        int depLeft = 0;
        int depRight = 0;
        bool left = helper(root->left, depLeft);
        bool right = helper(root->right, depRight);
        depth = max(depRight, depLeft) + 1;
        if (left && right &&  abs(depRight-depLeft) <=1) {
            return true;
        }
        return false;
    }

/*
Runtime: 16 ms, faster than 90.62% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 21.7 MB, less than 75.63% of C++ online submissions for Balanced Binary Tree.
*/
    bool helperV2(TreeNode* root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        int depLeft = 0;
        int depRight = 0;
        bool left = helper(root->left, depLeft);
        if (left == false) {
            return false;
        }
        bool right = helper(root->right, depRight);
        if (right == false) {
            return false;
        }
        if (abs(depRight-depLeft) >1) {
            return false;
        }
        depth = max(depRight, depLeft) + 1;
        return true;
    }

/*
Runtime: 12 ms, faster than 98.64% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 22 MB, less than 18.91% of C++ online submissions for Balanced Binary Tree.
砍掉叶子节点，避免了abs max调用
*/
    bool helper(TreeNode* root, int& depth) {
        if (!root->left && !root->right) {
            depth = 1;
            return true;
        }
        int depLeft = 0;
        int depRight = 0;
        bool left = true;
        if (root->left)
            left = helper(root->left, depLeft);
        if (!left) {
            return false;
        }
        bool right = true;
        if (root->right)
            right = helper(root->right, depRight);
        if (!right) {
            return false;
        }
        //if (abs(depRight-depLeft) >1) {
        if (depRight - depLeft > 1 || depRight - depLeft < -1) {
            return false;
        }
        depth = depRight > depLeft ? depRight + 1 : depLeft + 1;
        return true;
    }
};

bool isBalanced(struct TreeNode* root){

}


int main() {
    Solution s;
}


/*
Tips
M1 DFS
写啰嗦了
可以用-1作为标志 对于平衡的二叉树，返回正常的高度，对于不平衡的二叉树，返回-1

M2

*/


