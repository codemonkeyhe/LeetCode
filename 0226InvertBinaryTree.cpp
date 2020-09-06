/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-06
 * @tag
 * @similar  100 101
 */

/*
Invert a binary tree.
Example:
Input:
     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:
     4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.2 MB, less than 5.00% of C++ online submissions for Invert Binary Tree.
递归不熟练，不会用返回值
*/
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }


/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.6 MB, less than 5.00% of C++ online submissions for Invert Binary Tree.
熟练版，思考了返回值的意义
直接下面这样会有BUG，因为指针root->left被修改了
        root->left = invertTree(root->right);
        root->right = invertTree(root->left);
*/
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.4 MB, less than 5.00% of C++ online submissions for Invert Binary Tree.
*/
    TreeNode* invertTreeM2(TreeNode* root) {
        if (root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while (n-- > 0) {
                TreeNode* cur = q.front();
                q.pop();
                TreeNode* tmp = cur->left;
                cur->left = cur->right;
                cur->right = tmp;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
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

M2 queue BFS

*/


