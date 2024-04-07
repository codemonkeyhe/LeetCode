/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-0
 * @tag
 * @similar
 */

/*

给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
 

提示：
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <queue>

using namespace std;


class Solution {
public:
    ListNode* mergeKListsM1(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        for (int i = 0; i < lists.size(); i++) {
            res = merge2Lists(res, lists[i]);
        }
        return  res;
    }

    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 == NULL) {
            tail->next = l2;
        }
        if (l2 == NULL) {
            tail->next = l1;
        }
        return head->next;
    }


    ListNode* mergeKListsM2(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        auto res = mergeK(lists, 0, lists.size()-1);
        return res;
    }

    ListNode* mergeK(vector<ListNode*>& lists, int left, int right) {
      if (left == right) {
        return lists[left];
      }
      auto mid = (left + right) / 2;
      auto l1 = mergeK(lists, left, mid);
      auto l2 = mergeK(lists, mid + 1, right);
      auto res = merge2Lists(l1, l2);
      return res;
    }

    // 小根堆
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*, vector<ListNode*>, comp> pq;
      for (auto v : lists) {
        if (v != NULL) {
          pq.push(v);
        }
      }
      ListNode head;
      ListNode* tail = &head;
      while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        tail->next = cur;
        tail = tail->next;
        if (cur->next) {
          pq.push(cur->next);
        }
      }
      return head.next;
    }
};

// 相当于 greater<ListNode*>
struct comp {
  bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

int main() { Solution s; }

/*
Tips
M1

M2

M3 priority queue  Ugly
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

作者：力扣官方题解
链接：https://leetcode.cn/problems/merge-k-sorted-lists/solutions/219756/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
