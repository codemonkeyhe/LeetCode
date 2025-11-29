/**
 * @file
 * @brief   P17
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-19
 */

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "common.h"

using namespace std;


class Solution {
public:

/*
Runtime: 16 ms, faster than 8.41% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 14.4 MB, less than 5.74% of C++ online submissions for Merge Two Sorted Lists.
fool code
silly1  find head code is ugly, use sentinel node, contruct a new head is better.
silly2  when  l1 walk done firstly, no need to walk l2 one by one
*/
 ListNode* mergeTwoListsFool(ListNode* l1, ListNode* l2) {
     if (l1 == NULL) {
         return l2;
     }
     if (l2 == NULL) {
         return l1;
     }
     ListNode* head = NULL;
     ListNode* tail = NULL;
     if (l1 != NULL && l2 != NULL) {
         if (l1->val <= l2->val) {
             head = l1;
             l1 = l1->next;
         } else {
             head = l2;
             l2 = l2->next;
         }
         tail = head;
     }
     while (l1 != NULL && l2 != NULL) {
         if (l1->val <= l2->val) {
             tail->next = l1;
             tail = tail->next;
             l1 = l1->next;
         } else {
             tail->next = l2;
             tail = tail->next;
             l2 = l2->next;
         }
     }
     while (l1 != NULL) {
         tail->next = l1;
         tail = tail->next;
         l1 = l1->next;
     }
     while (l2 != NULL) {
         tail->next = l2;
         tail = tail->next;
         l2 = l2->next;
     }
     return head;
 }

 // 递归版  代码冗余
 /*
Runtime: 8 ms, faster than 84.85% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 14.5 MB, less than 5.74% of C++ online submissions for Merge Two Sorted Lists.
 */
 ListNode* mergeTwoListsSilly(ListNode* l1, ListNode* l2) {
     if (l1 == NULL) {
         return l2;
     } else if(l2 == NULL){
         return l1;
     }
     ListNode* head = NULL;
     if (l1 != NULL && l2 != NULL) {
         if (l1->val <= l2->val) {
             head = l1;
             l1 = l1->next;
         } else {
             head = l2;
             l2 = l2->next;
         }
     }
     head->next = mergeTwoLists(l1, l2);
     return head;
 }


 // 递归精简版
    // https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/

    /*
    Runtime: 12 ms, faster than 36.36% of C++ online submissions for Merge Two Sorted Lists.
    Memory Usage: 14.4 MB, less than 5.74% of C++ online submissions for Merge Two Sorted Lists.
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }


};

/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Merge Two Sorted
Lists. Memory Usage: 5.8 MB, less than 100.00% of C online submissions for Merge
Two Sorted Lists.
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    //struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    //struct ListNode* tail = head;
    struct ListNode head; //避免后续的free
    struct ListNode* tail = &head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }
    return head.next;

    // struct ListNode* sentinel = head;
    //head = head->next;
    //free(sentinel);
    //return head;
}

int main() {
    Solution s;

    return 0;
}
