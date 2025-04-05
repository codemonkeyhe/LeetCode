/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-05
 * @tag binaryTree
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
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
 *
 * https://leetcode.cn/problems/print-binary-tree/description/
 *
 * algorithms
 * Medium (69.72%)
 * Likes:    219
 * Dislikes: 0
 * Total Accepted:    39.1K
 * Total Submissions: 56.1K
 * Testcase Example:  '[1,2]'
 *
 * 给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局
 * 。构造此格式化布局矩阵需要遵循以下规则：
 *
 *
 * 树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
 * 矩阵的列数 n 应该等于 2^height+1 - 1 。
 * 根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
 * 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2^height-r-1] ，右子节点放置在
 * res[r+1][c+2^height-r-1] 。
 * 继续这一过程，直到树中的所有节点都妥善放置。
 * 任意空单元格都应该包含空字符串 "" 。
 *
 *
 * 返回构造得到的矩阵 res 。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2]
 * 输出：
 * [["","1",""],
 * ["2","",""]]
 *
 *
 * 示例 2：
 * 输入：root = [1,2,3,null,4]
 * 输出：
 * [["","","","1","","",""],
 * ["","2","","","","3",""],
 * ["","","4","","","",""]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数在范围 [1, 2^10] 内
 * -99 <= Node.val <= 99
 * 树的深度在范围 [1, 10] 内
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
class SolutionComplicated {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int dep = calcDep(root) -1 ;
        int m = dep+1; //行
        int n = (1 << m) - 1; //列
        vector<vector<string>> pic(m, vector<string>(n, ""));
        int faPos = (n-1)/2;
        pic[0][faPos] = to_string(root->val);
        int hei = 0;
        //cout << "dep=" << dep << endl;
        pt(root, hei, dep, faPos, pic);
        return pic;
    }

    int calcDep(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leDep = calcDep(root->left);
        int riDep = calcDep(root->right);
        int curDep = leDep;
        if (curDep < riDep) {
            curDep = riDep;
        }
        return curDep+1;
    }


    void pt(TreeNode* root, int hei, int dep, int faPos, vector<vector<string>>& pic) {
        if (root == NULL) {
            return;
        }
        if (hei >= dep) {
            return;
        }
        int sonDep = hei+1;
        int delta = 1 << (dep - hei -1);
        if (root->left) {
            pic[sonDep][faPos-delta] = to_string(root->left->val);
            pt(root->left, sonDep, dep, faPos-delta, pic);
        }

        if (root->right) {
            pic[sonDep][faPos+delta] = to_string(root->right->val);
            pt(root->right, sonDep, dep, faPos+delta, pic);
        }
        return;
    }
};


class Solution {
public:

    int calcDep(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leDep = calcDep(root->left);
        int riDep = calcDep(root->right);
        return max(leDep, riDep)+1;
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int dep = calcDep(root) -1 ;
        int m = dep+1; //行
        int n = (1 << m) - 1; //列
        vector<vector<string>> pic(m, vector<string>(n, ""));
        int faPos = (n-1)/2;
        pt(root, dep,  0, faPos, pic);
        return pic;
    }


    // 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2^height-r-1] ，右子节点放置在  res[r+1][c+2^height-r-1]

    void pt(TreeNode* root, const int &hei, int r, int c, vector<vector<string>>& pic) {
        if (root == NULL) {
            return;
        }
        pic[r][c] = to_string(root->val);
        if (hei <= r) {
            return;
        }
        int delta = 1 << (hei - r - 1);
        if (root->left) {
            pt(root->left, hei, r + 1, c - delta, pic);
        }

        if (root->right) {
            pt(root->right, hei, r + 1, c + delta, pic);
        }
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


