/**
 * @file
 * @brief  P25
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-07
 */

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 28 ms, faster than 23.70% of C++ online submissions for Path Sum II.
Memory Usage: 39.4 MB, less than 6.16% of C++ online submissions for Path Sum II.
*/
    void M1(TreeNode* root, int sum, vector<int> path, vector<vector<int>> &res) {
        if (root == NULL) {
            return;
        }
        sum -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == 0) {
            res.push_back(path);
        }
        M1(root->left, sum, path, res);
        M1(root->right, sum, path, res);
    }

    vector<vector<int>> pathSumM1(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root==NULL) return  res;
        //M1(root, sum, vector<int>(), res);
        //M13
        vector<int> path;
        M13(root, sum, path, res);
        return res;
    }


/*
Runtime: 8 ms, faster than 94.74% of C++ online submissions for Path Sum II.
Memory Usage: 19.9 MB, less than 62.51% of C++ online submissions for Path Sum II.
*/
    void M13(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res) {
        if (root == NULL) {
            return;
        }
        sum -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == 0) {
            res.push_back(path);
        }
        M13(root->left, sum, path, res);
        M13(root->right, sum, path, res);
        path.pop_back();
    }


//Runtime: 16 ms, faster than 64.23% of C++ online submissions for Path Sum II.
//Memory Usage: 19.7 MB, less than 77.76% of C++ online submissions for Path Sum II.
    vector<vector<int>> pathSumM2(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root==NULL) return  res;
        //stack<TreeNode*> s;
        vector<TreeNode*> s; //use vector as stack
        TreeNode* cur = root;
        TreeNode* pre;
        int total = 0;
        while(!s.empty() || cur != NULL) { // LXR
            while (cur != NULL) {
                s.push_back(cur);
                total += cur->val;
                cur = cur->left;
            }
            cur = s.back();
            if (cur->right!= NULL && cur->right != pre) {
                cur = cur->right;
            } else {
                if (!cur->left && !cur->right && sum == total) {  // means leaf node
                    vector<int> tmp;
                    for (int i = 0; i < s.size(); ++i) {
                        tmp.push_back(s[i]->val);
                    }
                    res.push_back(tmp);
                }
                s.pop_back();
                total -= cur->val;
                pre = cur; // mark pre pop
                cur = NULL;
            }
        }
        return res;
    }

};


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){

}

int main() {

    Solution s;

    return 0;
}


/*
Tips
M1 recursive DFS
M1.1 pass the pathsum to subtree
M1.2 like M1.1,  no need to pass pathsum,  pass sum - cur.val , if leaf node' sum ==0, means find a path
在112基础上，如何传递路径?
法1 用vector<int>存储路径，但是性能太低,很多冗余的路径副本
法2 路径用LR或者01(L或R)去记录，把路径传递下去，当找到符合要求的叶节点时，从根节点根据01路径去重构路径. 性能依然很低
合理方法3： 回溯，vector<int>存储路径+ DFS时 状态重置

M2 DFS use stack, and count pathsum  when walkers reach leaf node
M2.1
like 094 ， need pre pointer  to tell us the father who has been visited
use vector as stack, easy to collect result
下面的方法和我的想法一样
https://leetcode.com/problems/path-sum-ii/discuss/36843/C%2B%2B-DFS-17ms-non-recursive-solution

M2.2
stack<TreeNode*, int> s;  pass pathsum to subtree


M3 BFS use queue, pass current pathsum to left and right tree
queue<TreeNode*, int> q


*/
