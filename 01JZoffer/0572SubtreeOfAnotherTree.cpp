/**
 * @file
 * @brief  P18
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-19
 */

/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:
     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
 bool isSameTree(TreeNode* p, TreeNode* q) {
     if (!p && !q) {
         return true;
     }
     if (!p || !q) {
         return false;
     }
     if (p->val != q->val) {
         return false;
     }
     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
 }

 /*
Runtime: 40 ms, faster than 32.67% of C++ online submissions for Subtree of Another Tree.
Memory Usage: 29.3 MB, less than 6.25% of C++ online submissions for Subtree of Another Tree.
 */
 bool isSubtree(TreeNode* s, TreeNode* t) {
     if (s == NULL) {
         return false;
     }
     if (s->val == t->val) {
         if (isSameTree(s, t)) {
             return true;
         }
     }
     return isSubtree(s->left, t) || isSubtree(s->right, t);
 }

};

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {}

int main() {
    Solution s;

    return 0;
}
