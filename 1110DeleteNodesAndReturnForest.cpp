/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-30
 * @tag binaryTree,dfs
 * @similar  1325
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 *
 * https://leetcode.cn/problems/delete-nodes-and-return-forest/description/
 *
 * algorithms
 * Medium (69.47%)
 * Likes:    359
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 63.9K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n[3,5]'
 *
 * 给出二叉树的根节点 root，树上每个节点都有一个不同的值。
 *
 * 如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
 *
 * 返回森林中的每棵树。你可以按任意顺序组织答案。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
 * 输出：[[1,2,null,4],[6],[7]]
 *
 *
 * 示例 2：
 * 输入：root = [1,2,4,null,3], to_delete = [3]
 * 输出：[[1,2,4]]
 *
 *
 *
 *
 * 提示：
 * 树中的节点数最大为 1000。
 * 每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
 * to_delete.length <= 1000
 * to_delete 包含一些从 1 到 1000、各不相同的值。
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
    vector<TreeNode*> delNodesUgly(TreeNode* root, vector<int>& to_delete) {
        set<TreeNode*> woods;
        woods.insert(root);
        for (auto val: to_delete ) {
            delWoods(woods, val);
        }
        vector<TreeNode*> res(woods.begin(), woods.end());
        return res;
    }

    void delWoods(set<TreeNode*>& woods, int val) {
        for (auto root : woods) {
            if (delN(woods, root, val)) {
                return;
            }
            if (root->val == val) {
                woods.erase(root);
                if (root->left) {
                    woods.insert(root->left);
                }
                if (root->right) {
                    woods.insert(root->right);
                }
            }
        }
    }

    void addSonToWoods(set<TreeNode*>& woods, TreeNode* root) {
        // delCurNode
        // left son and right son into woods
        if (root->left) {
            woods.insert(root->left);
        }
        if (root->right) {
            woods.insert(root->right);
        }
    }

    bool delN(set<TreeNode*>& woods, TreeNode* root, int val) {
        if (root == NULL) {
            return false;
        }

        if (root->left && (root->left->val == val)) {
            addSonToWoods(woods, root->left);
            root->left = NULL;
            return true;
        }

        if (root->right && (root->right->val == val)) {
            addSonToWoods(woods, root->right);
            root->right = NULL;
            return true;
        }


        bool dleft = delN(woods, root->left, val);
        //cout << "val=" << root->val << "delV=" << val << " delLeft=" << dleft << endl;
        if (dleft) {
            return true;
        }

        bool dright = delN(woods, root->right, val);
        //cout << "val=" << root->val << "delV=" << val  << " delright=" << dright << endl;
        if (dright) {
            return true;
        }
        return false;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> dels(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        root = buildWoods(res, root, dels);
        if (root != NULL) {
            res.push_back(root);
        }
        return res;
    }

    TreeNode* buildWoods(vector<TreeNode*>& res, TreeNode* root, unordered_set<int>& dels) {
        if (root == NULL) {
            return NULL;
        }
        root->left = buildWoods(res, root->left, dels);
        root->right = buildWoods(res, root->right, dels);

        if (dels.count(root->val)) {
            if (root->left) {
                res.push_back(root->left);
            }
            if (root->right) {
                res.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }

};
// @lc code=end

/*

Wrong Answer
53/112 cases passed (N/A)
Testcase
[1,2,null,4,3]
[2,3]
Answer
[[1],[4],[3]]
Expected Answer
[[1],[4]]


Wrong Answer
60/112 cases passed (N/A)
Testcase
[1,2,3,null,null,null,4]
[2,1]
Answer
[]
Expected Answer
[[3,null,4]]


Wrong Answer
78/112 cases passed (N/A)
Testcase
[1,2,3,null,null,null,4]
[2,1]
Answer
[[3,null,4],[1,null,3,null,4]]
Expected Answer
[[3,null,4]]
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


