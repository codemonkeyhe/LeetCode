/**
 * @file
 * @brief  102-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-27
 */

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
Runtime: 4 ms, faster than 94.96% of C++ online submissions for Binary Tree Level Order Traversal II.
Memory Usage: 12.9 MB, less than 100.00% of C++ online submissions for Binary Tree Level Order Traversal II.
*/
    int getDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(getDepth(root->left), getDepth(root->right)) +1;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        int depth = getDepth(root);
        vector<vector<int> > res(depth, vector<int>());
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            while(size--) {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res[depth-level-1] = v;
            level++;
        }
        return res;
    }

};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

}

int main() {

    Solution s;

    return 0;
}


/*
Tips
M1 BFS+queue
M1.1 同102 把结果逆序一下 reverse
M1.2 先求树的深度，这样BFS时,把行放到对应的二维数组中。

M2 DFS
M2.1 先求树的深度，这样DFS时,把元素放到对应的行中

https://leetcode.com/problems/binary-tree-level-order-traversal-ii/discuss/35108/C%2B%2B-4ms-solution!

*/
