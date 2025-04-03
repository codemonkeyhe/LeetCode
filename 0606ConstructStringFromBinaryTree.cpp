/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-03
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
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 *
 * https://leetcode.cn/problems/construct-string-from-binary-tree/description/
 *
 * algorithms
 * Medium (61.85%)
 * Likes:    410
 * Dislikes: 0
 * Total Accepted:    85.2K
 * Total Submissions: 137.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。
 *
 * 空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4]
 * 输出："1(2(4))(3)"
 * 解释：初步转化后得到 "1(2(4)())(3()())" ，但省略所有不必要的空括号对后，字符串应该是"1(2(4))(3)" 。
 *
 *
 * 示例 2：
 * 输入：root = [1,2,3,null,4]
 * 输出："1(2()(4))(3)"
 * 解释：和第一个示例类似，但是无法省略第一个空括号对，否则会破坏输入与输出一一映射的关系。
 *
 *
 *
 * 提示：
 * *
 * 树中节点的数目范围是 [1, 10^4]
 * -1000 <= Node.val <= 1000
 *
 *
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
    string tree2str(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        string curStr = to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            return curStr;
        }
        string leStr = tree2str(root->left);
        string riStr = tree2str(root->right);
        curStr +=  "(" + leStr  + ")";
        if (root->right) {
            curStr +=  "(" + riStr + ")";
        }
        return curStr;
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


