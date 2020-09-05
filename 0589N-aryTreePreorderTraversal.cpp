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
Given an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Follow up:
Recursive solution is trivial, could you do it iteratively?

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:

    void preorder(Node* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            preorder(root->children[i], res);
        }
    }


//Runtime: 60 ms, faster than 34.89% of C++ online submissions for N-ary Tree Preorder Traversal.
//Memory Usage: 10.9 MB, less than 99.67% of C++ online submissions for N-ary Tree Preorder Traversal.
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }


//Runtime: 68 ms, faster than 24.60% of C++ online submissions for N-ary Tree Preorder Traversal.
//Memory Usage: 11.1 MB, less than 79.71% of C++ online submissions for N-ary Tree Preorder Traversal.
    vector<int> preorderM2(Node* root) {
        if (root==NULL) return vector<int>();
        vector<int> res;
        stack<Node*> s;
        s.push(root);
        Node* cur = NULL;
        while(!s.empty()) {
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            for (int i = cur->children.size() - 1; i >= 0; i--) {
                s.push(cur->children[i]);
            }
        }
        return res;
    }


};




int main() {
    Solution s;
}


/*
Tips
M1 Recursion

M2 Stack

*/


