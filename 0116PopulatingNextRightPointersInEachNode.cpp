/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-21
 * @tag  binaryTree
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 *
 * https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (73.39%)
 * Likes:    1177
 * Dislikes: 0
 * Total Accepted:    452K
 * Total Submissions: 608.6K
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 *
 * 初始状态下，所有 next 指针都被设置为 NULL。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4,5,6,7]
 * 输出：[1,#,2,3,#,4,5,6,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B
 * 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
 *
 *
 *
 *
 * 示例 2:
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 * 树中节点的数量在 [0, 2^12 - 1] 范围内
 * -1000 <= node.val <= 1000
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 *
 *
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class SolutionM1 {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        queue<Node*> qe;
        qe.push(root);
        while(!qe.empty()) {
            int cnt = qe.size();
            Node* pre = NULL;
            for (int i = 0; i < cnt; i++) {
                Node* cur = qe.front();
                qe.pop();
                if (i>0) {
                    pre->next = cur;
                }

                if (cur->left) {
                    qe.push(cur->left);
                }

                if (cur->right) {
                    qe.push(cur->right);
                }
                pre = cur;
            }
        }
        return root;
    }
};

class SolutionM2 {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        dfs(root->left, root->right);
        return root;
    }


    void dfs(Node* le, Node* ri) {
        if (le == NULL || ri == NULL) {
            return;
        }

        le->next = ri;

        dfs(le->left, le->right);

        dfs(ri->left, ri->right);

        dfs(le->right, ri->left);
    }
};


class SolutionM3 {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        dfs(root);
        return root;
    }

    void dfs(Node* root) {
        if (root == NULL) {
            return ;
        }

        if (root->left) {
            root->left->next = root->right;
        }

        if (root->right && root->next) {
            root->right->next = root->next->left;
        }


        dfs(root->left);
        dfs(root->right);
    }

};


class SolutionM4 {
public:
    // 效率低
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        Node* cur = root;
        Node* head = cur->left;
        while (cur) {
            Node* p = head;
            int i = 0;
            while (p && cur) {
                if (i % 2 == 1) {
                    p->next = cur->left;
                } else {
                    p->next = cur->right;
                    cur = cur->next;
                }
                p = p->next;
                i++;
            }
            cur = head;
            if (head) {
                head = head->left;
            }
        }
        return root;
    }
};



class Solution {
public:
    // 核心思路，遍历当前层，构建下一层
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        Node* cur = root;
        while(cur) {
           // cout << " 111cur=" << cur->val << endl;
            Node dam(0);
            Node* p = &dam;
            while(cur){
            //    cout << "222 cur=" << cur->val << endl;
                if (cur->left) {
                    p->next = cur->left;
                    p = p->next;
                }
                if (cur->right) {
                    p->next = cur->right;
                    p = p->next;
                }
                cur = cur->next;
            }
            cur = dam.next;
        }
        return root;
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


