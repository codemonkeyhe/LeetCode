/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-03
 * @tag binaryTree
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
 * @lc app=leetcode.cn id=1367 lang=cpp
 *
 * [1367] 二叉树中的链表
 *
 * https://leetcode.cn/problems/linked-list-in-binary-tree/description/
 *
 * algorithms
 * Medium (44.44%)
 * Likes:    225
 * Dislikes: 0
 * Total Accepted:    43.1K
 * Total Submissions: 91.1K
 * Testcase Example:  '[4,2,8]\n[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]'
 *
 * 给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
 *
 * 如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False
 * 。
 *
 * 一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
 *
 *
 *
 * 示例 1：
 * 输入：head = [4,2,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：true
 * 解释：树中蓝色的节点构成了与链表对应的子路径。
 *
 *
 * 示例 2：
 * 输入：head = [1,4,2,6], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：true
 *
 *
 * 示例 3：
 * 输入：head = [1,4,2,6,8], root =
 * [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 * 输出：false
 * 解释：二叉树中不存在一一对应链表的路径。
 *
 *
 *
 *
 * 提示：
 * 二叉树和链表中的每个节点的值都满足 1 <= node.val <= 100 。
 * 链表包含的节点数目在 1 到 100 之间。
 * 二叉树包含的节点数目在 1 到 2500 之间。
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

/*
    Error
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (root->val != head->val) {
            return isSubPath(head, root->left) || isSubPath(head, root->right);
        }
        auto okLeft = isSubPath(head->next, root->left);
        if (okLeft) {
            return true;
        }
        auto okRight = isSubPath(head->next, root->right);
        return okRight;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (root->val != head->val) {
            return (isSubPath(head, root->left) || isSubPath(head, root->right));
        }
        // root->val == head->val
        错误原因： 当前相等，如果左右不相等，不应该直接return，而是应该继续游走，
        因此，isMatch应该刚到 游走的前面
        cout << "root=" << root->val << " matchHead" << endl;
        return (isMatch(head->next, root->left) || isMatch(head->next, root->right));
    }

    */

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (root->val == head->val) {
            bool isOK = (isMatch(head->next, root->left) || isMatch(head->next, root->right));
            if (isOK) {
                return true;
            }
        }
        return (isSubPath(head, root->left) || isSubPath(head, root->right));
    }


    bool isMatch(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (head->val != root->val) {
            return false;
        }
        return (isMatch(head->next, root->left) || isMatch(head->next, root->right));
    }


    ListNode* _head;

    bool isSubPathM2(ListNode* head, TreeNode* root) {
        _head = head;
        return walk(head, root);
    }

    bool walk(ListNode* head, TreeNode* root) {
        if (head == NULL) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (root->val == head->val) {
            if (walk(head->next, root->left) || walk(head->next, root->right)) {
                return true;
            }
        }
        if (head == _head) {
            return walk(_head, root->left) || walk(_head, root->right);
        }
        return false;
    }

};
// @lc code=end

/*
思路
区分walk和match
当 head->val != root->val，walk函数需要继续walk， match函数直接返回false，这是区别
先match，不行再walk



Wrong Answer
64/68 cases passed (N/A)
Testcase
[1,4,2,6]
[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Answer
false
Expected Answer
true

Wrong Answer
61/68 cases passed (N/A)
Testcase
[4,2]
[4,4,4,1,null,null,null,2]
Answer
true
Expected Answer
false

Wrong Answer
61/68 cases passed (N/A)
Testcase
[1,10]
[1,null,1,10,1,9]
Answer
false
Expected Answer
true

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


