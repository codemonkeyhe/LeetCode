/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-25
 * @tag  OneShot
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 *
 * https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (77.30%)
 * Likes:    855
 * Dislikes: 0
 * Total Accepted:    368.9K
 * Total Submissions: 477K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
 *
 *
 *
 * 示例 1：
 * 输入：root = [3,1,4,null,2], k = 1
 * 输出：1
 *
 *
 * 示例 2：
 * 输入：root = [5,3,6,2,4,null,null,1], k = 3
 * 输出：3
 *
 *
 * 提示：
* 树中的节点数为 n 。
* 1 <= k <= n <= 104
* 0 <= Node.val <= 104
 *
 *
 * 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？
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

    int kthSmallestM1(TreeNode* root, int k) {
        vector<int> res;
        LXR(root, res);
        return res[k-1];
    }

    void LXR(TreeNode* root, vector<int> &res) {
        if (root == NULL) {
            return;
        }
        LXR(root->left, res);
        res.push_back(root->val);
        LXR(root->right, res);
    }

    int kthSmallestM2(TreeNode* root, int k) {
        auto leftCnt = cntTree(root->left);
        if (leftCnt == k - 1) {
            return root->val;
        }
        if (leftCnt > k - 1) {
            return kthSmallest(root->left, k);
        } else {
            return kthSmallest(root->right, k - leftCnt - 1);
        }
    }

    int cntTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftCnt = cntTree(root->left);
        int rightCnt = cntTree(root->right);
        return leftCnt + rightCnt + 1;
    }



    // M3
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> nodeCnt;
        recordCnt(root, nodeCnt);
        return kthSmallestM3(root, k, nodeCnt);
    }


    int kthSmallestM3(TreeNode* root, int k,  unordered_map<TreeNode*, int>& nodeCnt) {
        auto leftCnt = nodeCnt[root->left];
        if (leftCnt == k - 1) {
            return root->val;
        }
        if (leftCnt > k - 1) {
            return kthSmallestM3(root->left, k, nodeCnt);
        } else {
            return kthSmallestM3(root->right, k - leftCnt - 1, nodeCnt);
        }
    }

    int recordCnt(TreeNode* root, unordered_map<TreeNode*, int>& nc) {
        if (root == NULL) {
            return 0;
        }
        int leftCnt = recordCnt(root->left, nc);
        int rightCnt = recordCnt(root->right, nc);
        int total = leftCnt + rightCnt + 1;
        nc[root] = total;
        return total;
    }
};
// @lc code=end

/*
M1  LXR 中序遍历，再取第k个数

M2 递归加计数，
计数可以用map缓存，减少重复计算

M3
或者先全局计数，存储每个Node对应的计数，然后再寻找解法

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


