/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-20
 * @tag  recursion, linkedList
 * @similar   83, 206, 237
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 *
 * https://leetcode.cn/problems/remove-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (76.02%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    45.5K
 * Total Submissions: 59.9K
 * Testcase Example:  '[5,2,13,3,8]'
 *
 * 给你一个链表的头节点 head 。
 * 移除每个右侧有一个更大数值的节点。
 * 返回修改后链表的头节点 head 。
 *
 *
 *
 * 示例 1：
 * 输入：head = [5,2,13,3,8]
 * 输出：[13,8]
 * 解释：需要移除的节点是 5 ，2 和 3 。
 * - 节点 13 在节点 5 右侧。
 * - 节点 13 在节点 2 右侧。
 * - 节点 8 在节点 3 右侧。
 *
 *
 * 示例 2：
 * 输入：head = [1,1,1,1]
 * 输出：[1,1,1,1]
 * 解释：每个节点的值都是 1 ，所以没有需要移除的节点。
 *
 *
 *
 *
 * 提示：
 * 给定列表中的节点数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 10^5
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
    // M1 recursion
    ListNode* removeNodesM1(ListNode* head) {
        //ListNode dummy(0);
        //dummy->next = head;
        auto res = rem(head);
        return res;
    }


    ListNode* rem(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode *tail = rem(head->next);
        if (head->val < tail->val) { // remove head
            return tail;
        }
        head->next = tail;
        return head;
    }

    // M2
    ListNode* removeNodes(ListNode* head) {
        // use vector as stack
        vector<ListNode*> st;
        ListNode* cur = head;
        while (cur != NULL) {
            while(!st.empty() && st.back()->val < cur->val) {
                st.pop_back();
            }
            st.push_back(cur);
            cur = cur->next;
        }
        for (int i = 0; i < st.size() -1; i++) {
            st[i]->next = st[i+1];
        }
        return st[0];
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
