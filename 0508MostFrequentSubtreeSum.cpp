/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-22
 * @tag BinaryTree
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
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 *
 * https://leetcode.cn/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (75.64%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    51.9K
 * Total Submissions: 68.4K
 * Testcase Example:  '[5,2,-3]'
 *
 * 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 *
 * 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 *
 *
 *
 * 示例 1：
 * 输入: root = [5,2,-3]
 * 输出: [2,-3,4]
 *
 *
 * 示例 2：
 * 输入: root = [5,2,-5]
 * 输出: [2]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 10^4] 范围内
 * -10^5 <= Node.val <= 10^5
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (root == NULL) {
            return  vector<int>();
        }

        unordered_map<int, int > sumToCnt;
        dfs(root, sumToCnt);

        unordered_map<int, vector<int> > cntToSum;
        int maxCnt = 0;
        for (auto pp : sumToCnt)  {
            int sum = pp.first;
            int cnt = pp.second;
            if (cnt > maxCnt) {
                maxCnt = cnt;
            }
            cntToSum[cnt].push_back(sum);
        }
        return cntToSum[maxCnt];
    }

    //  return sumOfAllNodes
    int dfs(TreeNode* root, unordered_map<int, int >& sumToCnt) {
        if (root == NULL) {
            return 0;
        }
        int leftSum = dfs(root->left, sumToCnt);
        int rightSum = dfs(root->right, sumToCnt);
        int curSum = leftSum + (root->val) + rightSum;
        sumToCnt[curSum]++;
        return  curSum;
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


