/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-01
 * @tag  binaryTree,dfs
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

    bool evaluateTree(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        if (!root->left && !root->right) { //leaf
            return  root->val;
        }

        auto leRes = evaluateTree(root->left);
        auto riRes = evaluateTree(root->right);
        if (root->val ==  2) {
            return leRes || riRes;
        }
        // 3 means and
        return leRes && riRes;
    }

};


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


