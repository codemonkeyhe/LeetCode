/**
 * @file
 * @brief   102-simialr
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-27
 */

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

class Solution {
public:
/*
Runtime: 4 ms, faster than 82.27% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12.1 MB, less than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
*/
    vector<vector<int>> zigzagLevelOrderM1(TreeNode* root) {
        vector<vector<int>>  res;
        if (root == NULL) {
            return res;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        int depth = 1;
        TreeNode* cur;
        while (!q.empty()) {
            int n = q.size();
            vector<int> v;
            if (depth & 0x01) {
                while (n--) {
                    cur = q.back();
                    q.pop_back();
                    v.push_back(cur->val);
                    if (cur->left)
                        q.push_front(cur->left);
                    if (cur->right)
                        q.push_front(cur->right);
                }
            } else {
                while (n--) {
                    cur = q.front();
                    q.pop_front();
                    v.push_back(cur->val);
                    if (cur->right)
                        q.push_back(cur->right);
                    if (cur->left)
                        q.push_back(cur->left);
                }
            }
            res.push_back(v);
            depth++;
        }
        return res;
    }

/*
Runtime: 4 ms, faster than 82.27% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12 MB, less than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
*/
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>  res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int odd = 0;
        TreeNode* cur;
        while (!q.empty()) {
            int n = q.size();
            vector<int> v(n,0);
            for(int i = 0; i < n; ++i) {
                cur = q.front();
                if (odd)
                    v[n-i-1] = cur->val;
                else
                    v[i] = cur->val;
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(v);
            odd=!odd;
        }
        return res;
    }

};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

}

int main() {

    Solution s;

    return 0;
}


/*
Tips
M1 BFS+deque [也可以把deque换成list，其他API不变]
相当于把deque砍成2个stack去使用，左边是一个stack,右边是一个stack。
奇数层节点入右stack，偶数层节点入左stack。
左pop右push (pop_front+push_back) 或者 右pop左push (pop_back+push_front)

M2 BFS+queue
依然是正常层序遍历，用queue即可，只是遇到奇数层时，逆序放入到vector

M3 DFS
不推荐
因为要反转偶数层的遍历顺序，会有额外的代价
这种一目了然的BFS就不要强行改成DFS了


*/
