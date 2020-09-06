/**
 * @file
 * @brief  1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-06
 * @tag
 * @similar
 */

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
Runtime: 4 ms, faster than 80.65% of C++ online submissions for Binary Tree Right Side View.
Memory Usage: 11.7 MB, less than 68.54% of C++ online submissions for Binary Tree Right Side View.
DFS思路可以进一步优化
先左再右，以最后覆盖为准
改成 先右再左，一旦写入res就无法覆盖
*/
    void helperM21(TreeNode* root, int depth, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        if (depth >= res.size()) {
            res.push_back(root->val);
        } else if (depth < res.size()) {
            res[depth] = root->val;
        }
        helperM21(root->left, depth+1, res);
        helperM21(root->right, depth+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        //helperM21(root, 0, res);
        helperM22(root, 0, res);
        return res;
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Right Side View.
Memory Usage: 11.7 MB, less than 91.61% of C++ online submissions for Binary Tree Right Side View.
*/
    void helperM22(TreeNode* root, int depth, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        if (depth >= res.size()) {
            res.push_back(root->val);
        }
        helperM22(root->right, depth+1, res);
        helperM22(root->left, depth+1, res);
    }



//Runtime: 4 ms, faster than 80.65% of C++ online submissions for Binary Tree Right Side View.
//Memory Usage: 11.7 MB, less than 78.84% of C++ online submissions for Binary Tree Right Side View.
    vector<int> rightSideViewM2(TreeNode* root) {
        vector<int> res;
        if (root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while (n-- > 0) {
                TreeNode* cur = q.front();
                q.pop();
                if (n==0) {
                    res.push_back(cur->val);
                }
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return res;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize){

}


int main() {
    Solution s;
}


/*
Tips
M1  BFS
输出每一层的最后1个节点

M2  DFS
每一层只能输出一个节点，
传递层号,层号对应res的下标
同一层的元素 覆盖同一下标的res

*/


