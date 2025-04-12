/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-12
 * @tag
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
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
 *
 * https://leetcode.cn/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (52.36%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 41.6K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * 给定一颗根结点为 root 的二叉树，树中的每一个结点都有一个 [0, 25] 范围内的值，分别代表字母 'a' 到 'z'。
 * 返回 按字典序最小 的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。
 * 注：字符串中任何较短的前缀在 字典序上 都是 较小 的：
 *
 *
 * 例如，在字典序上 "ab" 比 "aba" 要小。叶结点是指没有子结点的结点。 
 * 节点的叶节点是没有子节点的节点。
 *
 *
 *
 * 示例 1：
 * 输入：root = [0,1,2,3,4,3,4]
 * 输出："dba"
 *
 *
 * 示例 2：
 * 输入：root = [25,1,3,1,3,0,2]
 * 输出："adz"
 *
 *
 * 示例 3：
 * 输入：root = [2,2,1,null,1,0,null,0]
 * 输出："abc"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给定树的结点数在 [1, 8500] 范围内
 * 0 <= Node.val <= 25
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
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        //string minS = "zzzzzzzzzzzzzzzzzzzzzzzzzzz";
        // ~的ASCII码是 126
        string minS = "~";
        bt(root, path, minS);
        return minS;
    }

    void bt(TreeNode* root, string& path, string& minS) {
        if (root == NULL) {
            return;
        }
        char cur = char(root->val+'a');
        path+=cur;

        if (root->left == NULL && root->right ==  NULL)  {
            string ss = path;
            reverse(ss.begin(), ss.end());
            if (ss < minS) {
                minS = ss;
            }
        }

        bt(root->left, path, minS);
        bt(root->right, path, minS);
        path.pop_back();

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


