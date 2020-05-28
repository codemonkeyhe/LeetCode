/**
 * @file
 * @brief   P23
 * @author MonkeyHe
 * @version  2.0
 * @date 2020-03-14
 * @date 2020-05-29
 */

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
   public:
    void RootFirstTraverse(TreeNode* root, multimap<int, int> &tree, int i) {
        if (root == NULL) {
            return ;
        }
        tree.insert(make_pair(i,root->val));
        RootFirstTraverse(root->left, tree, i+1);
        RootFirstTraverse(root->right, tree, i+1);
        return;
    }

    //可以不用 multimap作为中转，直接把结果存到res里面
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        multimap<int, int> tree;
        RootFirstTraverse(root, tree, 0);
        int preLevel = -1;
        for (auto it = tree.begin(); it != tree.end(); ++it){
           // cout << it->first << ":" << it->second << " ";
            if (it->first != preLevel) { // newLevel
                preLevel = it->first;
                vector<int> r;
                r.push_back(it->second);
                res.push_back(r);
            } else { // oldLevel
                res[it->first].push_back(it->second);
            };
        }
        return res;
    }

  //i是depth
  void RootFirstTraverse(TreeNode* root, vector<vector<int>> &res, int i) {
        if (root == NULL) {
            return ;
        }
        if (res.size() <= (size_t)i) {
            vector<int> v;
            res.push_back(v);
        }
        res[i].push_back(root->val);
        RootFirstTraverse(root->left, res, i+1);
        RootFirstTraverse(root->right, res, i+1);
        return;
    }


    vector<vector<int>> levelOrderM2(TreeNode* root) {
        vector<vector<int>> res;
        RootFirstTraverse(root, res, 0);
        return res;
    }

    vector<vector<int>> levelOrderM4(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        res.push_back(vector<int>{});
        while (!que.empty()) {
            TreeNode* p = que.front();
            que.pop();
            if (p != NULL) {
                res.back().push_back(p->val);
                if (p->left != NULL) {
                    que.push(p->left);
                }
                if (p->right != NULL) {
                    que.push(p->right);
                }
            } else {  //当前层已经处理完了，插入新的分层标记
                if (!que.empty()) {
                    que.push(NULL);
                    res.push_back(vector<int>{});
                    continue;
                }
            }
        }
        return res;
    }

/*
Runtime: 4 ms, faster than 93.48% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.8 MB, less than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
*/
    vector<vector<int>> levelOrderM41(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> v;
            while(size--) {
                TreeNode* p = que.front();
                que.pop();
                v.push_back(p->val);
                if (p->left) {
                    que.push(p->left);
                }
                if (p->right) {
                    que.push(p->right);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};

/**
 * @brief
 *
 *
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {}



int main() {
    const int len = 7;
    int nums[len] = {3, 9, 20, EMPTY_V, EMPTY_V, 15, 7};
    /*
    for (int i = 0; i < len; ++i) {
        printf("%d ", nums[i]);
    }
    */
    vector<int> nu(nums, nums + len);
    TreeNode* root = buildBinaryTree(nu);

    Solution s;
    auto r2 = s.levelOrderM41(root);
    print2DVector(r2);

    return 0;
}


/*
Tips
M1 中序遍历，把层号 和 元素一并保存到multimap里面。

M2 中序遍历，把层号 元素 直接保存到vector
下面url的方法和我想的方法是一致的
https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33588/C%2B%2B-4ms-simple-recursive-solution

M3 递归法，性能太低

M4 BFS + NULL作为新层的标记  这种解法比较多余，压根不需要NULL作为新层标记
https://www.cnblogs.com/miloyip/archive/2010/05/12/binary_tree_traversal.html

M4.1 BFS不需要null作为换行标记


*/
