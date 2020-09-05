/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-05
 * @tag
 * @similar
 */

/*
Given an n-ary tree, return the postorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Follow up:
Recursive solution is trivial, could you do it iteratively?

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    void postorder(Node* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        for (int i = 0; i < root->children.size(); ++i) {
            postorder(root->children[i], res);
        }
        res.push_back(root->val);
    }

/*
Runtime: 56 ms, faster than 44.51% of C++ online submissions for N-ary Tree Postorder Traversal.
Memory Usage: 11.2 MB, less than 68.39% of C++ online submissions for N-ary Tree Postorder Traversal.
*/
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }

};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize) {

}


int main() {
    Solution s;
}


/*
Tips
M1 recursion DFS

M2 stack
M2.1 stack+reverse
(childs) ROOT  == reverse[ ROOT(childs)]
先按照PreOrder遍历，再reverse即可



*/


