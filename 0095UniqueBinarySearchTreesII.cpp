/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-20
 * @tag DFS
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode.cn/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (73.95%)
 * Likes:    1604
 * Dislikes: 0
 * Total Accepted:    204.1K
 * Total Submissions: 274.1K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
 *
 *
 * 示例 1：
 * 输入：n = 3
 * 输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 *
 * 示例 2：
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 * 提示：
 * 1
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
class SolutionError {
public:
    vector<TreeNode*> generateTrees(int n) {
        set<int> used;
        vector<TreeNode*> res;
        btTree(n, 1, n, used, NULL, res);
        return res;
    }

    TreeNode* btTree(int total, int le, int ri, set<int>& used, TreeNode* ans, vector<TreeNode*>& res) {
        cout << "le="  << le << " ri=" << ri << endl;
        if (le > ri || (le < 0)) {
            return NULL;
        }

        TreeNode* root = NULL;
        for (int i = le; i <= ri ; i++) {
            root = new TreeNode(i);
            cout << " BUILD root=" << root->val << endl;
            used.insert(i);
            cout << " USE=" << i << endl;
            // left 0- i-1
            TreeNode* god = ans;
            if (used.size() == 1) {
                god = root;
            }
            root->left =  btTree(total, le, i-1,  used, god, res); //核心错误点，返回值没考虑好，左子树的构造有多种可能，这里只选择了1种，导致其他的结果被丢弃
            // right i+1 - n-1
            root->right = btTree(total, i+1, ri, used, god, res);
            cout << " root=" << root->val;
            if (root->left) {
             cout << " r.left=" << root->left->val;
            } else {
                cout << " r.left=NULL" ;
            }
            if (root->right) {
             cout << " r.right=" << root->right->val;
            } else {
                cout << " r.right=NULL" << endl;

            }
            cout << endl;
            if (used.size() == total) {  // find one solution
                if (ans != NULL) {
                    cout << " =========== " << endl;
                    cout << " ans =" << ans->val << endl;
                    cout << " =========== " << endl;

                   TreeNode* tmp = new TreeNode(0);
                   tmp->val = ans->val;
                   tmp->left = ans->left;
                   tmp->right = ans->right;
                   res.push_back(tmp);
                }
            }

            used.erase(i);
           // root->left == NULL;
           // root->right == NULL;
            cout << " DELETE=" << i << endl;
        }
        return root;
    }
};


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        set<int> used;
        vector<TreeNode*> res;
        res = btTree(1, n);
        return res;
    }

    vector<TreeNode*> btTree(int le, int ri) {
        if (le > ri) {
            vector<TreeNode*> tmp{NULL};
            return tmp;
        }

        vector<TreeNode*> res;
        for (int i = le; i <= ri; i++) {
            // i is root
            auto leftTrees = btTree(le, i - 1);
            auto rightTrees = btTree(i + 1, ri);

            for (auto lt : leftTrees) {
                for (auto rt : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

// @lc code=end


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


