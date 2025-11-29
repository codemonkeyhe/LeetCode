/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-14
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
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MINV = 0x7FFFFFFF;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

    //可否不用 tree作为中转，直接把结果存到res里面
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

  void RootFirstTraverse(TreeNode* root, vector<vector<int>> &res, int i) {
        if (root == NULL) {
            return ;
        }
        if (res.size() <= i) {
            vector<int> v;
            res.push_back(v);
        }
        res[i].push_back(root->val);
        RootFirstTraverse(root->left, res, i+1);
        RootFirstTraverse(root->right, res, i+1);
        return;
    }


    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        RootFirstTraverse(root, res, 0);
        return res;
    }

    vector<vector<int>> levelOrder4(TreeNode* root) {
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

// nums必须是按照二叉树层序遍历的方式去描述二叉树，空缺的元素用MINV占位
TreeNode* buildBinaryTree(vector<int> nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    vector<TreeNode*> data;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == MINV) {
            data.push_back(NULL);
            continue;
        }
        TreeNode* p = new TreeNode(nums[i]);
        data.push_back(p);
    }
    int len = data.size();
    for (int i = 0; i < len; ++i) {
        TreeNode* node = data[i];
        if (node == NULL) {
            continue;
        }
        int leftPos = 2 * i + 1;
        int rightPos = leftPos + 1;
        if (leftPos >= len) {
            continue;
        }
        node->left = data[leftPos];
        if (rightPos < len) {
            node->right = data[rightPos];
        }
    }
    return data[0];
}

void RootFirstPrint(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    RootFirstPrint(root->left);
    RootFirstPrint(root->right);
    return;
}

template <typename T>
void print2DVector(vector<vector<T>>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int len = 7;
    int nums[len] = {3, 9, 20, MINV, MINV, 15, 7};
    /*
    for (int i = 0; i < len; ++i) {
        printf("%d ", nums[i]);
    }
    */
    vector<int> nu(nums, nums + len);
    TreeNode* root = buildBinaryTree(nu);
    // RootFirstPrint(root);

    Solution s;
    auto r2 = s.levelOrder2(root);
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

M4 BFS + NULL作为新层的标记
https://www.cnblogs.com/miloyip/archive/2010/05/12/binary_tree_traversal.html
*/
