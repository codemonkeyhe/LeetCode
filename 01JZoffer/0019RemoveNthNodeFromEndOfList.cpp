/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-06
 */

/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.6 MB, less than 5.26% of C++ online submissions for Remove Nth Node From End of List.
*/

 ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* p1 = head;
     ListNode* p2 = head;
     for (int i = 1; i <= n; ++i) {
         if (p2 == NULL) {
             break;
         }
         p2 = p2->next;
     }
     ListNode* pre = p1;
     while (p2 != NULL) {
         p2 = p2->next;
         pre = p1;
         p1 = p1->next;
     }
     if (p1 == head) { // head node
         head = head->next;
     } else {
         pre->next = p1->next;
     }
     delete p1;
     return head;
 }


};


//Runtime: 4 ms, faster than 61.91% of C online submissions for Remove Nth Node From End of List.
//Memory Usage: 5.4 MB, less than 100.00% of C online submissions for Remove Nth Node From End of List.
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    ListNode* p1 = head;
    ListNode* p2 = head;
    // n always  valid
    for (int i = 0; i < n; ++i) {
        p2 = p2->next;
    }
    if (p2==NULL) { //delete head
        head = head->next;
        free(p1);
        return head;
    }
    while (p2->next != NULL) {
        p2 = p2->next;
        p1 = p1->next;
    }
    ListNode* del = p1->next;
    p1->next = del->next;
    free(del);
    return head;
}

int main() {
    Solution s;

    return 0;
}

/*
Tips
双指针+滑动窗口

删除时都要区分删除头结点和中间节点，
可以在头结点前面加多一个哨兵，这样就无须区分头结点和中间节点
*/