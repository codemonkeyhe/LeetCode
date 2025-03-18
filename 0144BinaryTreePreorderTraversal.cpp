/**
 * @file
 * @brief  94-144-145-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-20;2025-03-18
 */

/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class SolutionOld {
public:

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
*/
    void XLR(TreeNode* root, vector<int> &res) {
        if (root == NULL)
            return;
        res.push_back(root->val);
        XLR(root->left, res);
        XLR(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // M1
        // M2 stack
        int m = 5;
        switch (m) {
            case 0:
                XLR(root, res);
                break;
            case 1:
                preOrderLR(root, res);
                break;
            case 2:
                preOrderXLR(root, res);
                break;
            case 3:
                preOrderR(root, res);
                break;
            case 4:
                Morris(root, res);
                break;
            case 5:
                MorrisChangeTree(root, res);
                break;
        }
        return res;
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
*/
    void preOrderLR(TreeNode* root, vector<int> &res) {
        stack<TreeNode*> s;
        if (root==NULL) {
            return;
        }
        s.push(root);
        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right!=NULL)
                s.push(cur->right);
            if (cur->left!=NULL)
                s.push(cur->left);
        }
    }

    // same as 0094-inOrder ,just one line different
    void preOrderXLR(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur != NULL) {
            while (cur != NULL) {
                res.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            cur = cur->right;
        }
    }

/*
Runtime: 4 ms, faster than 30.24% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
*/
    void preOrderR(TreeNode* root, vector<int> &res) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                res.push_back(cur->val);
                if (cur->right != NULL) {
                    s.push(cur->right);
                }
                cur = cur->left;
            }
            if (!s.empty()) {
                cur = s.top();
                s.pop();
            }
        }
    }

/*
Runtime: 4 ms, faster than 32.38% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.

just one line diff with 094
*/
  void Morris(TreeNode* root, vector<int> &res) {
        TreeNode* cur = root;
        TreeNode* pre;
        while (cur != NULL) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right!=NULL && pre->right != cur){
                    pre = pre->right;
                }
                if (pre->right == NULL) { // first time to visit left tree the rightmost leaf node
                    res.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                } else {// second time to visit left tree the rightmost leaf node
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
    }

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
Memory Usage: 8 MB, less than 80.05% of C++ online submissions for Binary Tree Preorder Traversal.
*/
    void MorrisChangeTree(TreeNode* root, vector<int>& res) {
        TreeNode* cur = root;
        TreeNode* pre;
        while (cur!=NULL) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right != NULL) {
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
        }
    }
};

const int EMPTY_V = 0x80000000;
TreeNode* buildBinaryTree(vector<int> nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    vector<TreeNode*> data;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == EMPTY_V) {
            data.push_back(NULL);
        } else {
            TreeNode* p = new TreeNode(nums[i]);
            data.push_back(p);
        }
    }
    int len = data.size();
    for (int i = 0; i < len; ++i) {
        TreeNode* node = data[i];
        if (node == NULL) {
            continue;
        }
        int leftPos = 2 * i + 1;
        int rightPos = leftPos + 1;
        if (leftPos < len) {
            node->left = data[leftPos];
        }
        if (rightPos < len) {
            node->right = data[rightPos];
        }
    }
    return data[0];
}

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (71.89%)
 * Likes:    1319
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 * 解释：
 *
 *
 * 示例 2：
 * 输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
 * 输出：[1,2,4,5,6,7,3,8,9]
 * 解释：
 *
 *
 * 示例 3：
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 4：
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();
            res.push_back(tmp->val);
            if (tmp->right) {
                st.push(tmp->right);
            }
            if (tmp->left) {
                st.push(tmp->left);
            }
        }
        return res;
    }
};
// @lc code=end



int main() {

    const int len = 7;
    int nums[len] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nu(nums, nums + len);
    TreeNode* root = buildBinaryTree(nu);

    SolutionOld s;
    auto v = s.preorderTraversal(root);
    for (auto e: v) {
        cout << e << " ";
    }

    return 0;
}

/*
M1 recursive

M2 stack
M2.1
R L to stack
相当于 BFS

M2.2 stack
only R to stack

M2.3  stack
X L R to stack
还是DFS

M2.5 nullptr as mark

M3 morris
M3.1 Morris (Not Change tree)
M3.2 Morris (Change Tree to Threaded Tree)


https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/45266/Accepted-iterative-solution-in-Java-using-stack.
*/