/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-05
 * @tag
 * @similar  700 701
 */

/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?


Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 104].
-10^5 <= Node.val <= 10^5
Each node has a unique value.
root is a valid binary search tree.
-10^5 <= key <= 10^5
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    //前驱节点
    TreeNode* predecessor(TreeNode* root) {
        if (root == NULL && root->left == NULL)
            return root;
        TreeNode* p = root->left;
        while (p->right) {
            p = p->right;
        }
        return p;
    }

    //后继节点
    TreeNode* successor(TreeNode* root) {
        if (root == NULL && root->right == NULL)
            return root;
        TreeNode* p = root->right;
        while (p->left) {
            p = p->left;
        }
        return p;
    }

/*
执行用时：40 ms , 在所有 C++ 提交中击败了 99.77% 的用户
内存消耗： 15.4 MB , 在所有 C++ 提交中击败了 100.00% 的用户
*/
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        TreeNode* cur = root;
        TreeNode* fa = cur;
        while (cur != NULL) {
            if (cur->val == key) {
                break;
            }
            fa = cur;
            if (cur->val < key) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        if (cur == NULL) {  // Not exist
            return root;
        }
        if (!cur->left && !cur->right) {  // leaf node  or one root
            // free(cur)
            if (fa == cur) {  // Only one root
                return NULL;
            }
            // leaf node
            if (fa->right == cur) {
                fa->right = NULL;
            } else {
                fa->left = NULL;
            }
            return root;
        }
        if (!cur->left || !cur->right) {  //左子树为空 或者 右为空
            if (fa == cur) {              //删除为根节点
                return cur->right ? cur->right : cur->left;
            }
            // free(cur)
            if (fa->right == cur) {
                fa->right = cur->right ? cur->right : cur->left;
            } else {
                fa->left = cur->right ? cur->right : cur->left;
            }
            return root;
        }
        //左右不为空
        if (fa == cur) { //删除根节点
            TreeNode* succ = successor(cur);
            succ->left = cur->left;
            return cur->right;
        }
        // 寻找cur节点在中序遍历中的前驱节点 即比cur小一点的节点
        TreeNode* leftSon = cur->left;
        TreeNode* rightSon = cur->right;
        if (fa->right == cur) {
            fa->right = rightSon;
            TreeNode* succ = successor(cur);
            succ->left = leftSon;
        } else {
            fa->left = leftSon;
            TreeNode* pre = predecessor(cur);
            pre->right = rightSon;
            // free(cur)
        }
        return root;
    }
};

struct TreeNode* deleteNode(struct TreeNode* root, int key) {}

int main() {
    Solution s;
}

/*
Tips
M1 Recursion
非常方便
//浓缩版
https://leetcode.com/problems/delete-node-in-a-bst/discuss/93293/Very-Concise-C%2B%2B-Solution-for-General-Binary-Tree-not-only-BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* right = root->right;
                while (right->left)
                    right = right->left;
                swap(root->val, right->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }

https://leetcode.com/problems/delete-node-in-a-bst/discuss/152449/C%2B%2B-Easiest-solution-with-Recursive-beats-98.88

M2 iterator
非常麻烦

*/
