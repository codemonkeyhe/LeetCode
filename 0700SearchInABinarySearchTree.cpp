/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-05
 * @tag
 * @similar  CRUD 701 450
 */

/*
Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example,
Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2
     / \
    1   3
In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 84 ms, faster than 32.90% of C++ online submissions for Search in a Binary Search Tree.
Memory Usage: 35 MB, less than 5.10% of C++ online submissions for Search in a Binary Search Tree.
*/
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }
        if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }

/*
Runtime: 140 ms, faster than 5.14% of C++ online submissions for Search in a Binary Search Tree.
Memory Usage: 35.1 MB, less than 5.10% of C++ online submissions for Search in a Binary Search Tree.
*/
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur->val == val) {
                return cur;
            }
            if (cur->val < val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return cur;
    }


};

struct TreeNode* searchBST(struct TreeNode* root, int val){

}


int main() {
    Solution s;
}


/*
Tips
M1 Recursion

M2 Iteration

*/


