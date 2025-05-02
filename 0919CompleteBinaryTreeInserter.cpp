/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-02
 * @tag queue,binaryTree
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
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 *
 * https://leetcode.cn/problems/complete-binary-tree-inserter/description/
 *
 * algorithms
 * Medium (67.15%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    35.6K
 * Total Submissions: 52.9K
 * Testcase Example:  '["CBTInserter","insert","insert","get_root"]\n[[[1,2]],[3],[4],[]]'
 *
 * 完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。
 *
 * 设计一种算法，将一个新节点插入到一棵完全二叉树中，并在插入后保持其完整。
 *
 * 实现 CBTInserter 类:
 * CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
 * CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点
 * TreeNode。使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
 * CBTInserter.get_root() 将返回树的头节点。
 *
 *
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入
 * ["CBTInserter", "insert", "insert", "get_root"]
 * [[[1, 2]], [3], [4], []]
 * 输出
 * [null, 1, 2, [1, 2, 3, 4]]
 *
 * 解释
 * CBTInserter cBTInserter = new CBTInserter([1, 2]);
 * cBTInserter.insert(3);  // 返回 1
 * cBTInserter.insert(4);  // 返回 2
 * cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数量范围为 [1, 1000] 
 * 0 <= Node.val <= 5000
 * root 是完全二叉树
 * 0 <= val <= 5000 
 * 每个测试用例最多调用 insert 和 get_root 操作 10^4 次
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
class CBTInserterM1 {
public:
    CBTInserterM1(TreeNode* root) {
        _root = root;
    }

    int insert(int val) {
        queue<TreeNode*> que;
        que.push(_root);
        TreeNode* tmp = new TreeNode(val);
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0 ; i < cnt; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) {
                    que.push(cur->left);
                } else {
                    cur->left = tmp;
                    return cur->val;
                }
                if (cur->right) {
                    que.push(cur->right);
                } else {
                    cur->right = tmp;
                    return cur->val;
                }
            }
        }
        return 0;
    }

    TreeNode* get_root() {
        return _root;
    }


    TreeNode* _root;
};


class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        _root = root;
        queue<TreeNode*> que;
        que.push(_root);
        while(!que.empty()) {
            int cnt = que.size();
            for (int i = 0 ; i < cnt; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
                if (cur->left == NULL || (cur->right == NULL)) {
                    todo.push(cur);
                }
            }
        }
    }

    int insert(int val) {
        TreeNode* tmp = new TreeNode(val);
        if (todo.empty()) {
            return 0;
        }

        TreeNode* cur = todo.front();
        if (cur->left == NULL) {
            cur->left = tmp;
        } else if (cur->right == NULL) {
            cur->right = tmp;
            todo.pop();
        }
        todo.push(tmp);
        return cur->val;
    }

    TreeNode* get_root() {
        return _root;
    }


    queue<TreeNode*> todo;
    TreeNode* _root;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

/*
Wrong Answer
69/84 cases passed (N/A)
Testcase
["CBTInserter","insert","insert","insert","get_root"]
[[[1]],[2],[3],[4],[]]
Answer
[null,1,1,0,[1,2,3]]
Expected Answer
[null,1,1,2,[1,2,3,4]]
*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


