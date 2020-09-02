/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-02
 * @tag Recursion; Inorder
 * @similar
 */

/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [0]
Output: [0]

Example 4:
Input: head = [1,3]
Output: [3,1]

Constraints:
The numner of nodes in head is in the range [0, 2 * 10^4].
-10^5 <= Node.val <= 10^5
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

    // [head, stop)
    ListNode* getMiddle(ListNode* head, ListNode* stop) {
        ListNode* p = head;
        while (head != stop && head->next != stop) {
            head = head->next->next;
            p = p->next;
        }
        return p;
    }

    // [head, mid)
    /*
Runtime: 24 ms, faster than 88.50% of C++ online submissions for Convert Sorted List to Binary Search Tree.
Memory Usage: 24.6 MB, less than 33.82% of C++ online submissions for Convert Sorted List to Binary Search Tree.
    */
    TreeNode* helper(ListNode* head, ListNode* stop) {
        if (head == stop) {
            return NULL;
        }
        ListNode* mid = getMiddle(head, stop);
        TreeNode* root = new TreeNode(mid->val);
        root->left = helper(head, mid);
        root->right = helper(mid->next, stop);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        return helper(head, NULL);
    }

};


struct TreeNode* sortedListToBST(struct ListNode* head){

}

int main() {
    Solution s;
}


/*
Tips
M1 Recursion
T=O(nlogn)

M2 List 转为 vector
变成0108

M3 Inorder Simulation [TODO]
https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/you-xu-lian-biao-zhuan-huan-er-cha-sou-suo-shu-1-3/
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/solution/
➔ function formBst(start, end)
➔      mid = (start + end) / 2
➔      formBst(start, mid - 1)
➔
➔      TreeNode(head.val)
➔      head = head.next
➔
➔      formBst(mid + 1, end)
➔

*/


