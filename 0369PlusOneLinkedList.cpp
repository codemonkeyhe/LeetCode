/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-31
 * @tag    linkedList
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
 * @lc app=leetcode.cn id=369 lang=cpp
 *
 * [369] 给单链表加一
 *
 * https://leetcode.cn/problems/plus-one-linked-list/description/
 *
 * algorithms
 * Medium (61.91%)
 * Likes:    133
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 21.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个用链表表示的非负整数， 然后将这个整数 再加上 1 。
 * 这些数字的存储是这样的：最高位有效的数字位于链表的首位 head 。
 *
 *
 *
 * 示例 1:
 * 输入: head = [1,2,3]
 * 输出: [1,2,4]
 *
 *
 *
 *
 * 示例 2:
 * 输入: head = [0]
 * 输出: [1]
 *
 *
 *
 *
 * 提示：
 * 链表中的节点数在 [1, 100] 的范围内。
 * 0 <= Node.val <= 9
 * 由链表表示的数字不包含前导零，除了零本身。
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
    ListNode* plusOne(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* lastNot9 = head;
        ListNode* p = dummy;
        while(p != NULL) {
            if (p->val != 9) {
                lastNot9 = p;
            }
            p = p->next;
        }

        lastNot9->val = lastNot9->val + 1;
        ListNode* p2 = lastNot9->next;
        while (p2 != NULL) {
            p2->val = 0;
            p2 = p2->next;
        }
        if (lastNot9 == dummy) {
            return dummy;
        }
        return head;
    }
};
// @lc code=end

/*
1 2 9 9 3 9 9 9
1 2 9 9 4 0 0 0

0 9 9
1 0 0

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
