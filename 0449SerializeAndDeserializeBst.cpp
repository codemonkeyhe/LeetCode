/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-22
 * @tag  BST
 * @similar 297
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 *
 * https://leetcode.cn/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (62.25%)
 * Likes:    566
 * Dislikes: 0
 * Total Accepted:    69K
 * Total Submissions: 110.7K
 * Testcase Example:  '[2,1,3]'
 *
 * 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
 *
 * 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。
 * 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
 *
 * 编码的字符串应尽可能紧凑。
 *
 *
 *
 * 示例 1：
 * 输入：root = [2,1,3]
 * 输出：[2,1,3]
 *
 *
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 * 树中节点数范围是 [0, 10^4]
 * 0 <= Node.val <= 10^4
 * 题目数据 保证 输入的树是一棵二叉搜索树。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    char sepStr = ',';

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (root == NULL) {
            return res;
        }
        XLRString(root, res);
        return res;
    }

    void XLRString(TreeNode* root, string& res) {
        if (root == NULL) {
            return;
        }
        res += to_string(root->val) + sepStr;
        XLRString(root->left, res);
        XLRString(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vals = getData(data);
        auto root = buildBST(vals, 0, vals.size()-1);
        return root;
    }

    TreeNode* buildBST(const vector<int>& vals, int le, int ri) {
        if (le > ri) {
            return NULL;
        }
        TreeNode* root = new TreeNode(vals[le]);
        int i = le+1;
        for (;i <= ri; i++) {
            if (vals[i] >= vals[le])  {
                break;
            }
        }
        root->left = buildBST(vals, le+1, i-1);
        root->right = buildBST(vals, i, ri);
        return root;
    }

    vector<int> getData(string& data) {
        vector<int> res;
        int i = 0;
        int j = 0;
        while (j < data.size()) {
            if (data[j] == sepStr) {
                string ss = data.substr(i, j - i);
                res.push_back(stoi(ss));
                i = j+1;
            }
            j++;
        }
        return res;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


