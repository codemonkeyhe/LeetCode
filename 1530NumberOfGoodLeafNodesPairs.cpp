/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-02
 * @tag binaryTree,dfs
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
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
 *
 * https://leetcode.cn/problems/number-of-good-leaf-nodes-pairs/description/
 *
 * algorithms
 * Medium (59.20%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 23.5K
 * Testcase Example:  '[1,2,3,null,4]\n3'
 *
 * 给你二叉树的根节点 root 和一个整数 distance 。
 *
 * 如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。
 *
 * 返回树中 好叶子节点对的数量 。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,null,4], distance = 3
 * 输出：1
 * 解释：树的叶节点是 3 和 4 ，它们之间的最短路径的长度是 3 。这是唯一的好叶子节点对。
 *
 *
 * 示例 2：
 * 输入：root = [1,2,3,4,5,6,7], distance = 3
 * 输出：2
 * 解释：好叶子节点对为 [4,5] 和 [6,7] ，最短路径长度都是 2 。但是叶子节点对 [4,6] 不满足要求，因为它们之间的最短路径长度为 4
 * 。
 *
 *
 * 示例 3：
 * 输入：root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
 * 输出：1
 * 解释：唯一的好叶子节点对是 [2,5] 。
 *
 *
 * 示例 4：
 * 输入：root = [100], distance = 1
 * 输出：0
 *
 *
 * 示例 5：
 * 输入：root = [1,1,1], distance = 2
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * tree 的节点数在 [1, 2^10] 范围内。
 * 每个节点的值都在 [1, 100] 之间。
 * 1 <= distance <= 10
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
    int res = 0;
    int countPairs(TreeNode* root, int distance) {
        leafDis(root, distance);
        return res;
    }

    vector<int> leafDis(TreeNode* root, int distance) {
        if (root == NULL) {
            return vector<int>();
        }
        if (root->left == NULL && root->right == NULL) {
            //ErrorCase: one  0 return vector<int>(1);
            // WantCase: one 1
            return vector<int>{1};
        }

        auto disLeft = leafDis(root->left, distance);
        auto disRight = leafDis(root->right, distance);

        for (auto& dl : disLeft) {
            for (auto& dr : disRight) {
                if (dl + dr <= distance) {
                    res++;
                }
            }
        }

        vector<int> newDis;
        for (auto dl : disLeft) {
            if (dl < distance) {
                newDis.push_back(dl + 1);
            }
        }
        for (auto dr : disRight) {
            if (dr < distance) {
                newDis.push_back(dr + 1);
            }
        }
        return newDis;
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


