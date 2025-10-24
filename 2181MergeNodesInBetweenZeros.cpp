/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-24
 * @tag      LinkedList
 * @similar   817, 2181
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
 *
 * https://leetcode.cn/problems/merge-nodes-in-between-zeros/description/
 *
 * algorithms
 * Medium (83.70%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    47.6K
 * Total Submissions: 54.6K
 * Testcase Example:  '[0,3,1,0,4,5,2,0]'
 *
 * 给你一个链表的头节点 head ，该链表包含由 0 分隔开的一连串整数。链表的 开端 和 末尾 的节点都满足 Node.val == 0 。
 * 对于每两个相邻的 0 ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 0 移除，修改后的链表不应该含有任何 0 * 。
 * 返回修改后链表的头节点 head 。
 *
 *
 *
 * 示例 1：
 * 输入：head = [0,3,1,0,4,5,2,0]
 * 输出：[4,11]
 * 解释：
 * 上图表示输入的链表。修改后的链表包含：
 * - 标记为绿色的节点之和：3 + 1 = 4
 * - 标记为红色的节点之和：4 + 5 + 2 = 11
 *
 *
 * 示例 2：
 * 输入：head = [0,1,0,3,0,2,2,0]
 * 输出：[1,3,4]
 * 解释：
 * 上图表示输入的链表。修改后的链表包含：
 * - 标记为绿色的节点之和：1 = 1
 * - 标记为红色的节点之和：3 = 3
 * - 标记为黄色的节点之和：2 + 2 = 4
 *
 *
 *
 *
 * 提示：
 * 列表中的节点数目在范围 [3, 2 * 10^5] 内
 * 0 <= Node.val <= 1000
 * 不 存在连续两个 Node.val == 0 的节点
 * 链表的 开端 和 末尾 节点都满足 Node.val == 0
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
    // no need to new node
    ListNode* mergeNodesM1(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        int sum = 0;
        while(p2 != NULL) {
            if (p2->val == 0) {
                p1->next->val = sum;
                p1->next->next = p2->next;
                p1 = p2;
                p2 = p1->next;
                sum = 0;
                continue;
            }
            sum += p2->val;
            p2 = p2->next;
        }
        return head->next;
    }

    ListNode* mergeNodesM2(ListNode* head) {
        //ListNode* p1 = head;
        ListNode* p2 = head->next;
        int sum = 0;
        ListNode dummy;
        dummy.next = head;
        ListNode* tail = &dummy;
        while(p2 != NULL) {
            if (p2->val == 0) {
                ListNode* tmp = new ListNode(sum);
                tail->next = tmp;
                tail = tail->next;
                p2 = p2->next;
                sum = 0;
                continue;
            }
            sum += p2->val;
            p2 = p2->next;
        }
        return dummy.next;
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
