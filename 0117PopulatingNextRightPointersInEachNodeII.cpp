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
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 *
 * https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (69.29%)
 * Likes:    911
 * Dislikes: 0
 * Total Accepted:    310.9K
 * Total Submissions: 435.8K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * 给定一个二叉树：
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
 *
 * 初始状态下，所有 next 指针都被设置为 NULL 。
 *
 *
 *
 * 示例 1：
 * 输入：root = [1,2,3,4,5,null,7]
 * 输出：[1,#,2,3,#,4,5,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next
 * 指针连接），'#' 表示每层的末尾。
 *
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 * 树中的节点数在范围 [0, 6000] 内
 * -100 <= Node.val <= 100
 *
 *
 * 进阶：
 *
 *
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序的隐式栈空间不计入额外空间复杂度。
 *
 *
 *
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



class SolutionERR {
public:
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
                p->next = findNextNode(p, cur);
                    cur = cur->next;

                p = p->next;
                i++;
            }
            cur = head;
            if (head) {
               // head = findNextHead(cur);
            }
        }
        return root;
    }

     Node*  findNextNode(Node* h, Node* cur) {
        if (cur->left && (cur->left != h)) {
            return cur->left;
        }

        if (cur->right && (cur->right != h)) {
            return cur->right;
        }

        Node* p = cur;
        while(p->next) {
            p = p->next;
            if (p->left) {
                return p->left;
            }
            if (p->right) {
                return p->right;
            }
        }
        return NULL;
     }







/* Wrong
    void dfs(Node* root) {
        if (root == NULL) {
            return ;
        }

        if (root->left) {
            root->left->next = root->right;
        }

        if (root->next != NULL) {
            if (root->right != NULL) {
                if (root->next->left) {
                    root->right->next = root->next->left;
                } else {
                    root->right->next = root->next->right;
                }
            } else if (root->left != NULL) {
                if (root->next->left) {
                    root->left->next = root->next->left;
                } else {
                    root->left->next = root->next->right;
                }
            }
        }

        dfs(root->left);
        dfs(root->right);
    }
*/

/* Wrong
    void dfs(Node* le, Node* ri) {
        if (le == NULL || ri == NULL) {
            return;
        }

        le->next = ri;

        dfs(le->left, le->right);

        dfs(ri->left, ri->right);

        if (le->right == NULL) {
            if (ri->left) {
                dfs(le->left, ri->left);
            } else {
                dfs(le->left, ri->right);
            }

        } else {
            if (ri->left) {
                dfs(le->right, ri->left);
            } else {
                dfs(le->right, ri->right);
            }
        }
    }
    */
};

// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/solutions/429828/tian-chong-mei-ge-jie-dian-de-xia-yi-ge-you-ce-15/comments/2289827/

class Solution {
public:
    // 核心思路，遍历当前层，构建下一层
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        Node* cur = root;
        while(cur) {
            Node dam(0);
            Node* p = &dam;
            while(cur){
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


