/**
 * @file
 * @brief  P18-Similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-19
 */

/*
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true

Example 2:
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false

Example 3:
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
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

/*
Runtime: 4 ms, faster than 36.09% of C++ online submissions for Same Tree.
Memory Usage: 10.1 MB, less than 5.55% of C++ online submissions for Same Tree.
*/
 bool isSameTreeFool(TreeNode* p, TreeNode* q) {
     if (p != NULL && q == NULL) {
         return false;
     }
     if (p == NULL && q != NULL) {
         return false;
     }
     if (p == NULL && q == NULL) {
         return true;
     }
     if (p->val != q->val) {
         return false;
     }
     bool left = isSameTree(p->left, q->left);
     bool right = isSameTree(p->right, q->right);
     return left && right;
 }

/*
Runtime: 4 ms, faster than 36.09% of C++ online submissions for Same Tree.
Memory Usage: 9.9 MB, less than 72.22% of C++ online submissions for Same Tree.
*/
 bool isSameTreeSilly(TreeNode* p, TreeNode* q) {
     if (p == NULL && q == NULL) {
         return true;
     }
     if (p == NULL || q == NULL) {
         return false;
     }
     if (p->val != q->val) {
         return false;
     }
     if (isSameTree(p->left, q->left)){
        return isSameTree(p->right, q->right);
     }
     return false;
 }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Same Tree.
Memory Usage: 9.9 MB, less than 55.56% of C++ online submissions for Same Tree.
*/
 bool isSameTree(TreeNode* p, TreeNode* q) {
     if (!p && !q ) {
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


};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {}
}

int main() {

    Solution s;

    return 0;
}


