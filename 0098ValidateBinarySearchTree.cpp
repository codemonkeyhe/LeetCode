/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-03
 * @tag
 * @similar
 */

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

    2
   / \
  1   3
Input: [2,1,3]
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6
Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:


    void inOrder(TreeNode* root, vector<int> &path) {
        if (root == NULL)
            return;
        inOrder(root->left, path);
        path.push_back(root->val);
        inOrder(root->right, path);
    }

/*
M1
Runtime: 16 ms, faster than 90.85% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 22 MB, less than 6.98% of C++ online submissions for Validate Binary Search Tree.
*/
    bool isValidBSTM1(TreeNode* root) {
        vector<int> path;
        inOrder(root, path);
        for (int i = 1; i < path.size(); ++i) {
            if (path[i-1] >= path[i]) {
                return false;
            }
        }
        return true;
    }

//M2
//Runtime: 20 ms, faster than 69.98% of C++ online submissions for Validate Binary Search Tree.
//Memory Usage: 21.9 MB, less than 15.62% of C++ online submissions for Validate Binary Search Tree.
    bool isValidBSTM2(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            //LXR visit cur->val
            // 把visit的方式变成比较大小
            if (pre != NULL && pre->val >= cur->val) {
                return false;
            }
            pre = cur;
            cur = cur->right;
        }
        return true;
    }

//M3
//Runtime: 20 ms, faster than 69.98% of C++ online submissions for Validate Binary Search Tree.
//Memory Usage: 21.5 MB, less than 80.34% of C++ online submissions for Validate Binary Search Tree.
    bool helper(TreeNode* root, TreeNode* lower, TreeNode* upper) {
        if (root == NULL) { //empty tree is a BST
            return true;
        }
        if (lower && root->val <= lower->val) {
            return false;
        }
        if (upper && root->val >= upper->val) {
            return false;
        }
        return helper(root->left, lower, root) && helper(root->right, root, upper);
    }

    bool isValidBST(TreeNode* root) {
        //因为不清楚val的范围，正负无穷用INT_MIN表示不妥当，只能用指针，NULL表示无穷
        //return helper(root, INT_MIN, INT_MAX);
        return helper(root, NULL, NULL);
    }



};

bool isValidBST(struct TreeNode* root){

}


int main() {
    Solution s;
}


/*
Tips
边界条件
空树[]  返回true
不用考虑多个节点val相等的情况

M1  InOrder+vector
LXR 的结果是有序数组

M2  InOrder+stack
like 094
使用stack, 移动的是cur

M3 DFS
思维误区
以为  root->left->val < root->val < root->right->val 就是BST
其实是  AllValInLeft < root->val < AllValInRight
画一个上下界传递的BST，可以发现，要把 lower和upper传递下去即可
当前val作为leftSon的upper，作为rightSon的lower
     5
   /   \
  4     8
 / \   / \
1   7 3   9
        [-,+]
     /         \
  [-,5]        [5,+]
 /    \        /   \
[-,4] [4,5]  [5,8] [8,+]



*/


