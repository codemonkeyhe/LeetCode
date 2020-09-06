/**
 * @file
 * @brief  3rd-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-0
 * @tag
 * @similar 543
 */

/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:
Input: [1,2,3]

       1
      / \
     2   3
Output: 6

Example 2:
Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7
Output: 42
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

/*
Runtime: 36 ms, faster than 90.56% of C++ online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 28.3 MB, less than 94.05% of C++ online submissions for Binary Tree Maximum Path Sum.
*/
    int helper(TreeNode* root, int &maxS) {
        if (root == NULL) {
            return 0;
        }
        int leftSum = helper(root->left, maxS);
        int rightSum = helper(root->right, maxS);
        int curSum = (leftSum > 0 ? leftSum : 0) +
                     (rightSum > 0 ? rightSum : 0) + root->val;
        if (curSum > maxS) {
            maxS = curSum;
        }
        int m = max(leftSum, rightSum);
        return (m > 0 ? m : 0) + root->val;
    }


    int maxPathSum(TreeNode* root) {
        //BUG int maxS =  0;
        int maxS =  INT_MIN;
        helper(root, maxS);
        return  maxS;
    }

};


int maxPathSum(struct TreeNode* root){

}


int main() {
    Solution s;
}


/*
Tips
直觉告诉我
和543的直径类似，和深度有关
只是这里不再用深度算直径，而是把深度往上累加
每一个节点求 以该节点为根的 树的最大路径和

所有节点的最大路径和的最大值，就是题解


M1 DFS

M2

*/


