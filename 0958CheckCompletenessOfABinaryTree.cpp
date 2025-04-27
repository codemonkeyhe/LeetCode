/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-27
 * @tag binaryTree,bfs
 * @similar
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
 *
 * https://leetcode.cn/problems/check-completeness-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (54.95%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    66.3K
 * Total Submissions: 119K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵二叉树的根节点 root ，请你判断这棵树是否是一棵 完全二叉树 。
 *
 * 在一棵 完全二叉树 中，除了最后一层外，所有层都被完全填满，并且最后一层中的所有节点都尽可能靠左。最后一层（第 h 层）中可以包含 1 到 2^h
 * 个节点。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4,5,6]
 * 输出：true
 * 解释：最后一层前的每一层都是满的（即，节点值为 {1} 和 {2,3} 的两层），且最后一层中的所有节点（{4,5,6}）尽可能靠左。
 *
 *
 * 示例 2：
 * 输入：root = [1,2,3,4,5,null,7]
 * 输出：false
 * 解释：值为 7 的节点不满足条件「节点尽可能靠左」。
 *
 *
 *
 *
 * 提示：
 * 树中节点数目在范围 [1, 100] 内
 * 1 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTreeError(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }

        if (root->left == NULL && root->right != NULL) {
            return false;
        }

        if (root->left != NULL && root->right == NULL) {
            return true;
        }

        bool rLeft = isCompleteTree(root->left);
        bool rRight = isCompleteTree(root->right);
        return rLeft && rRight;
    }


    bool isCompleteTreeBFS(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        //int dep = 0;
        int wantCnt = 1;
        bool lastLevel = false;
        while(!que.empty()) {
            int cnt = que.size();
            wantCnt = cnt << 1;
            bool finalLeaf  = false;
            for (int i = 0; i < cnt; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left == NULL && cur->right != NULL) {
                    return false;
                }
                if (finalLeaf && (cur->left || (cur->right))) {
                    return false;
                }
                if (cur->right == NULL) {
                    finalLeaf = true;
                }
                /*
                if (cur->left == NULL && cur->right == NULL) {
                    finalLeaf = true;
                }
                if (cur->left != NULL && cur->right == NULL) {
                    finalLeaf = true;
                }
               */
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
            }
            //dep++;
            int sonCnt = que.size();
            if (lastLevel && sonCnt != 0) {
                return false;
            }
            if (!lastLevel && (sonCnt != wantCnt)) {// must the last level
                lastLevel = true;
            }
        }
        return true;
    }


    bool isCompleteTreeBFSV2(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        //int dep = 0;
        bool finalLeaf = false;
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0; i < cnt; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left == NULL && cur->right != NULL) {
                    return false;
                }
                if (finalLeaf && (cur->left || (cur->right))) {
                    return false;
                }
                if (cur->right == NULL) {
                    finalLeaf = true;
                }
                /*
                if (cur->left == NULL && cur->right == NULL) {
                    finalLeaf = true;
                }
                if (cur->left != NULL && cur->right == NULL) {
                    finalLeaf = true;
                }
               */
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
            }
        }
        return true;
    }

    bool isCompleteTreeDFSError(TreeNode* root) {
        vector<int> vi;
        int dep = 0;
        auto res = dfs(root, dep, vi);
        if (res == false) {
            return false;
        }
        for (int i = 0; i < vi.size() ; i++) {
            cout << "i=" << i << " size=" << vi[i] << endl;
        }
        for (int i = 0; i < vi.size() -2; i++) {
            if ((vi[i] <<1) != vi[i+1]) {
                return false;
            }
        }


        return true;
    }


    bool dfs(TreeNode* root, int dep, vector<int>& vi) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && (root->right != NULL)) {
            return false;
        }
        if (dep >= vi.size()) {
            vi.push_back(1);
        } else {
            // dep < vi.size()
            vi[dep]++;
        }
        dep++;
        bool bl = dfs(root->left, dep, vi);
        bool br = dfs(root->right,dep,vi);
        return bl && br;
    }

    bool isCompleteTree(TreeNode* root) {
        int num = 1;
        int total = 0;
        walk(root, num, total);
        if (lastNodeNum != total ) {
            return false;
        }
        return true;
    }


    int lastNodeNum = -1;

    void walk(TreeNode* root, int num, int& total) {
        if (root == NULL) {
            return;
        }
        if (num > lastNodeNum) {
            lastNodeNum  = num;
        }
        total++;
        num = num<<1;
        walk(root->left, num, total);
        walk(root->right, num + 1, total);
    }

};
// @lc code=end

/*
M1 BFS
M2 编号


Wrong Answer
73/120 cases passed (N/A)
Testcase
[1,2,3,5,null,7,8]
Answer
true
Expected Answer
false

Testcase
[1,2,3,4,5,null,7]
Answer
true
Expected Answer
false

1
2 3
45 X7

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


