/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-02
 * @tag  Recursion
 * @similar  236
 */

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).
Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Constraints:
All of the nodes' values will be unique.
p and q are different and both values will exist in the BST
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 44 ms, faster than 59.56% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.4 MB, less than 46.81% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/
    TreeNode* lowestCommonAncestorM1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }

/*
Runtime: 40 ms, faster than 81.84% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.3 MB, less than 80.06% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (cur != NULL) {
            if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else  if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else  {
                return cur;
            }
        }
        return NULL;
    }

};


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

}

int main() {
    Solution s;
}


/*
Tips
M1 ??

M2 ??

*/


