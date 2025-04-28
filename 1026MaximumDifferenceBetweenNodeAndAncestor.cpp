/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-28
 * @tag  dfs,binaryTree
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
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
 *
 * https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/description/
 *
 * algorithms
 * Medium (77.81%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    60.3K
 * Total Submissions: 77K
 * Testcase Example:  '[8,3,10,1,6,null,14,null,null,4,7,13]'
 *
 * 给定二叉树的根节点 root，找出存在于 不同 节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B
 * 的祖先。
 *
 * （如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）
 *
 *
 *
 * 示例 1：
 * 输入：root = [8,3,10,1,6,null,14,null,null,4,7,13]
 * 输出：7
 * 解释：
 * 我们有大量的节点与其祖先的差值，其中一些如下：
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * 在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
 *
 *
 * 示例 2：
 * 输入：root = [1,null,2,null,0,3]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 * 树中的节点数在 2 到 5000 之间。
 * 0 <= Node.val <= 105
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

    int maxAncestorDiffON2(TreeNode* root) {
        int maxDiff = INT_MIN;
        walk(root, maxDiff);
        return maxDiff;
    }

    void walk(TreeNode* root, int& maxDiff) {
        if (root == NULL) {
            return ;
        }
        dfs(root, root->val, maxDiff);

        walk(root->left, maxDiff);

        walk(root->right,  maxDiff);
    }


    void dfs(TreeNode* root, int& anc, int& maxDiff) {
        if (root == NULL) {
            return;
        }
        int diff = abs(anc - root->val);
        if (diff > maxDiff) {
            maxDiff = diff;
        }
        dfs(root->left, anc, maxDiff);
        dfs(root->right, anc, maxDiff);
    }


    int maxAncestorDiffV1(TreeNode* root) {
        int maxDiff = INT_MIN;
        findMinMax(root, maxDiff);
        return maxDiff;
    }


    // min, max
    pair<int, int> findMinMax(TreeNode* root, int& maxDiff) {
        if (root == NULL) {
            return make_pair(100001 ,0);
        }

        auto left = findMinMax(root->left, maxDiff);
        auto right = findMinMax(root->right, maxDiff);

        int minV = min(left.first, right.first);
        int maxV = max(left.second, right.second);

        if (minV != 100001) {
            int d1 = abs(root->val - minV);
            maxDiff = ((maxDiff>d1) ? maxDiff : d1);
        }

        if (maxV != 0) {
            int d2 = abs(root->val - maxV);
            maxDiff = max(maxDiff, d2);
        }

        minV = min(minV, root->val);
        maxV = max(maxV, root->val);

        return make_pair(minV, maxV);
    }

    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = findDiff(root, root->val, root->val);
        return maxDiff;
    }

    int findDiff(TreeNode* root, int minV, int maxV) {
        if (root == NULL) {
            return 0;
        }

        int diff = max(abs(root->val - minV), abs(root->val - maxV));

        minV = min(minV, root->val);
        maxV = max(maxV, root->val);

        auto left = findDiff(root->left, minV, maxV);
        auto right = findDiff(root->right, minV, maxV);

        diff = max(left, diff);
        diff = max(right, diff);

        return  diff;
    }
};
// @lc code=end

/*
Wrong Answer
18/30 cases passed (N/A)
Testcase
[2,null,0,1]
Answer
1
Expected Answer
2

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


