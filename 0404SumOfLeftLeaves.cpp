/**
 * @file
 * @brief  1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-06
 * @tag  Recusion
 * @similar
 */

/*
Find the sum of all left leaves in a given binary tree.
Example:
    3
   / \
  9  20
    /  \
   15   7
There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // return  helper(root, NULL);
        return  helper1(root, false);
    }

//愚蠢了，其实可以用标志位判断左右分支
//Runtime: 8 ms, faster than 41.81% of C++ online submissions for Sum of Left Leaves.
//Memory Usage: 13.4 MB, less than 93.27% of C++ online submissions for Sum of Left Leaves.
    int helper(TreeNode* root, TreeNode* parent) {
        if (root == NULL) {
            return 0;
        }
        if (!root->left && !root->right && parent && parent->left == root)  {
            return root->val;
        }
        int res = 0;
        res+=helper(root->left, root);
        res+=helper(root->right, root);
        return res;
    }

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
//Memory Usage: 13.5 MB, less than 66.95% of C++ online submissions for Sum of Left Leaves.
    int helper1(TreeNode* root, bool left) {
        if (root == NULL) {
            return 0;
        }
        if (!root->left && !root->right && left)  {
            return root->val;
        }
        int res = 0;
        res+=helper1(root->left, true);
        res+=helper1(root->right, false);
        return res;
    }


};

int sumOfLeftLeaves(struct TreeNode* root){

}


int main() {
    Solution s;
}


/*
Tips
M1 Recusion

M2 BFS-queue 传递父节点的左右分支标志位

M3 DFS-stack  <TreeNode*, bool>


*/


