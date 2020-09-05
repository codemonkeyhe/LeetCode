/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-05
 * @tag
 * @similar
 */

/*
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example,
Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:
         4
       /   \
      2     7
     / \   /
    1   3 5

This tree is also valid:
         5
       /   \
      2     7
     / \
    1   3
         \
          4

Constraints:
The number of nodes in the given tree will be between 0 and 10^4.
Each node will have a unique integer value from 0 to -10^8, inclusive.
-10^8 <= val <= 10^8
It's guaranteed that val does not exist in the original BST.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 188 ms, faster than 5.36% of C++ online submissions for Insert into a Binary Search Tree.
Memory Usage: 57.4 MB, less than 5.55% of C++ online submissions for Insert into a Binary Search Tree.
DFS 没写好
*/
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            if (root->left) {
                insertIntoBST(root->left, val);
            } else {
                root->left  = new TreeNode(val);
            }
        } else {
            if (root->right) {
                insertIntoBST(root->right, val);
            } else {
                root->right  = new TreeNode(val);
            }
        }
        return root;
    }

/*
Runtime: 148 ms, faster than 12.33% of C++ online submissions for Insert into a Binary Search Tree.
Memory Usage: 57.3 MB, less than 5.55% of C++ online submissions for Insert into a Binary Search Tree.
*/
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }


/*
Runtime: 172 ms, faster than 5.36% of C++ online submissions for Insert into a Binary Search Tree.
Memory Usage: 57.2 MB, less than 5.55% of C++ online submissions for Insert into a Binary Search Tree.
*/
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* t = new TreeNode(val);
        if (root == NULL) {
            return t;
        }
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur->val < val) {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = t;
                    break;
                }
            } else {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = t;
                    break;
                }
            }
        }
        return root;
    }
};




int main() {
    Solution s;
}


/*
Tips
M1 Recursion

M2 Iteration

*/


