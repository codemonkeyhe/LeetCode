/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-06
 * @tag
 * @similar
 */

/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].
Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:

    void helper(TreeNode* root, map<int, int> &valTcnt, int &pre, int &cnt, int &maxCnt) {
        if (root ==NULL)
            return;
        helper(root->left, valTcnt, pre, cnt, maxCnt);
        //visit root->val
        if (root->val == pre) {
            cnt++;
            if (cnt > maxCnt) {
                maxCnt = cnt;
            }
        } else {
            cnt = 1;
        }
        valTcnt[root->val] = cnt;
        pre = root->val;
        helper(root->right, valTcnt, pre, cnt, maxCnt);
    }

/*
Runtime: 44 ms, faster than 36.34% of C++ online submissions for Find Mode in Binary Search Tree.
Memory Usage: 25.8 MB, less than 40.62% of C++ online submissions for Find Mode in Binary Search Tree
可以把map砍掉，直接把结果存入res
*/
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        int cnt = 1;
        int maxCnt = 1;
        map<int, int> valTcnt;
        int pre = INT_MIN;
        helper(root, valTcnt, pre, cnt, maxCnt);
        for (auto it = valTcnt.begin(); it != valTcnt.end(); it++) {
            if (it->second == maxCnt) {
                res.push_back(it->first);
            }
        }
        return res;
    }

};

int* findMode(struct TreeNode* root, int* returnSize){

}


int main() {
    Solution s;
}


/*
Tips
InOrder+walk
M1  InOrder Recursion
不需要额外申请vector保存中序遍历的结果，只需要维持一个等值计数器
第一遍遍历找出次数最大的众数的次数,同时把所有的数都放入res
第二次遍历不用再遍历树了，遍历vector以次数作为标杆，找出所有的众数


M2 InOrder Stack
不符合题意，使用了stack空间

M3 1次遍历法
https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/98191/C%2B%2B-O(n)-time-and-O(1)-space-by-inorder-traversal

class Solution {
public:
    int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
    vector<int> res;

    vector<int> findMode(TreeNode *root)
    {
        inorderTraversal(root);
        return res;
    }

    void inorderTraversal(TreeNode *root)
    {
        if (root == NULL) return; // Stop condition
        inorderTraversal(root->left); // Traverse left subtree
        if (precursor == root->val) currFreq++;
        else currFreq = 1;
        if (currFreq > maxFreq)
        {// Current node value has higher frequency than any previous visited
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        }
        else if (currFreq == maxFreq)
        {// Current node value has a frequency equal to the highest of previous visited
            res.push_back(root->val);
        }
        precursor = root->val; // Update the precursor
        inorderTraversal(root->right); // Traverse right subtree
    }
};

*/


