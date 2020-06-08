/**
 * @file
 * @brief  P25-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-07
 */

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
/*
Runtime: 12 ms, faster than 82.37% of C++ online submissions for Path Sum.
Memory Usage: 21.6 MB, less than 5.29% of C++ online submissions for Path Sum.
*/
    bool hasPathSumM2(TreeNode* root, int sum) {
        bool res = false;
        if (root == NULL) {
            return false;
        }
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* pre;
        int total = 0;
        while(!s.empty() || cur != NULL) { // LXR
            while (cur != NULL) {
                s.push(cur);
                total += cur->val;
                cur = cur->left;
            }
            cur = s.top();
            if (cur->right!= NULL && cur->right != pre) {
                cur = cur->right;
            } else {
                if (!cur->left && !cur->right && sum == total) {  // means leaf node
                    return true;
                }
                s.pop();
                total -= cur->val;
                pre = cur; // mark pre pop
                cur = NULL;
            }
        }
        return res;
    }

//Runtime: 8 ms, faster than 97.17% of C++ online submissions for Path Sum.
//Memory Usage: 21.5 MB, less than 6.23% of C++ online submissions for Path Sum.
    bool ps11(TreeNode* root, int sum, int total) {
        if (root == NULL) {
            return false;
        }
        total += root->val;
        if (!root->left && !root->right && total == sum) { // leaf node
            return true;
        }
        return ps11(root->left, sum, total) || ps11(root->right, sum, total);
    }

//Runtime: 12 ms, faster than 82.37% of C++ online submissions for Path Sum.
//Memory Usage: 21.2 MB, less than 56.96% of C++ online submissions for Path Sum.
    bool ps12(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        sum -= root->val;
        if (!root->left && !root->right && sum==0) { // leaf node
            return true;
        }
        return ps12(root->left, sum) || ps12(root->right, sum);
    }



    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        //return ps11(root, sum, 0);
        return ps12(root, sum);
    }

};

/*
Runtime: 16 ms, faster than 50.97% of C++ online submissions for Path Sum.
Memory Usage: 21.7 MB, less than 5.29% of C++ online submissions for Path Sum.
*/
bool hasPathSum(struct TreeNode* root, int sum){
    queue<pair<TreeNode*, int> > q;
    if (root == NULL) {
        return false;
    }
    q.push(make_pair(root, sum));
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            TreeNode* cur = q.front().first;
            int total = q.front().second - cur->val;
            q.pop();
            if (!cur->left && !cur->right && total == 0) {
                return true;
            }
            if (cur->left) {
                q.push(make_pair(cur->left, total));
            }
            if (cur->right) {
                q.push(make_pair(cur->right, total));
            }
        }
    }
    return false;
}

int main() {

    Solution s;

    return 0;
}


/*
Tips

M1 recursive
M1.1 pass the pathsum to subtree
M1.2 like M1.1,  no need to pass pathsum,  pass sum - cur.val , if leaf node' sum ==0, means true

M2 DFS use stack, and count pathsum  when walkers reach leaf node
M2.1
like 094 ， need pre pointer  to tell us the father who has been visited
M2.2
stack<TreeNode*, int> s;  pass pathsum to subtree

M3 BFS use queue, pass current pathsum to left and right tree
queue<TreeNode*, int> q
*/
