/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-21
 * @tag  linkedList
 * @similar  19, 24, 1721
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
 *
 * https://leetcode.cn/problems/swapping-nodes-in-a-linked-list/description/
 *
 * algorithms
 * Medium (63.46%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 47.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head 和一个整数 k 。
 *
 * 交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。
 *
 *
 *
 * 示例 1：
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[1,4,3,2,5]
 *
 *
 * 示例 2：
 * 输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * 输出：[7,9,6,6,8,7,3,0,9,5]
 *
 *
 * 示例 3：
 * 输入：head = [1], k = 1
 * 输出：[1]
 *
 *
 * 示例 4：
 * 输入：head = [1,2], k = 1
 * 输出：[2,1]
 *
 *
 * 示例 5：
 * 输入：head = [1,2,3], k = 2
 * 输出：[1,2,3]
 *
 *
 *
 *
 * 提示：
 * 链表中节点的数目是 n
 * 1 <= k <= n <= 105
 * 0 <= Node.val <= 100
 *
 *
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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 1; i < k; i++) { // as k <= n, no need to judge p2 is null
            p2 = p2->next;
        }
        ListNode* n1 = p2;
        while (p2->next != NULL) {
            p2 = p2->next;
            p1 = p1->next;
        }
        // p1 points last node
        swap(p1->val, n1->val);
        return head;
    }
};
// @lc code=end

/*

O1 swap Node
O2 only swap value, no need to change Pointer

M1 twoPointers
twoPointers keep k distance
p1 --- k steps --- p2
when p2 walked to the listTail, p1 points to the last kth node
then p2 walk k step from the begin, mark the pos
then swap the value

M2 push listNode into a vector


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
