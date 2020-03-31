/**
 * @file
 * @brief BOP 3.6 判断两链表是否相交
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-06
 * @date 2020-03-30
 */

/*
Write a program to find the node at which the intersection of two singly linked
lists begins. For example, the following two linked lists: begin to intersect at
node c1.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2,
skipB = 3 Output: Reference of the node with value = 8 Input Explanation: The
intersected node's value is 8 (note that this must not be 0 if the two lists
intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it
reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A;
There are 3 nodes before the intersected node in B.

Example 2:
Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB
= 1 Output: Reference of the node with value = 2 Input Explanation: The
intersected node's value is 2 (note that this must not be 0 if the two lists
intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it
reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are
1 node before the intersected node in B.

Example 3:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B,
it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0,
while skipA and skipB can be arbitrary values. Explanation: The two lists do not
intersect, so return null.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function
returns. You may assume there are no cycles anywhere in the entire linked
structure. Your code should preferably run in O(n) time and use only O(1)
memory.
*/

#include <iostream>
#include <vector>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *buildList(vector<int> &data, int len) {
    if (data.size() == 0) {
        return NULL;
    }
    struct ListNode *head = new ListNode(data[0]);
    struct ListNode *tail = head;
    for (size_t i = 1; i < data.size() && i < len; ++i) {
        ListNode *p = new ListNode(data[i]);
        tail->next = p;
        tail = tail->next;
    }
    return head;
}

void setTail(ListNode * head, ListNode *p) {
    ListNode *t = head;
    ListNode *pre = head;
    while (t != NULL) {
        pre = t;
        t = t->next;
    }
    pre->next = p;
}

void printList(ListNode *head) {
    ListNode *p = head;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode *getTail(ListNode *headA) {}

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {}
};

int main() {
    vector<int> listA = {4, 1, 8, 4, 5};
    int skipA = 2;
    vector<int> listB = {5, 0, 1, 8, 4, 5};
    int skipB = 3;

    ListNode *la;
    ListNode *lb;
    if (listA.size() == skipA || listB.size() == skipB) {  // no interact
        la = buildList(listA, skipA);
        lb = buildList(listB, skipB);
    } else {
        if (listA.size() > listB.size()) {
            la = buildList(listA, listA.size());
            lb = buildList(listB, skipB);
            ListNode* p = la;
            for(int i = 0; i < skipA; ++i) {
                p = p->next;
            }
            setTail(lb, p);
        } else {
            la = buildList(listA, skipA);
            lb = buildList(listB, listB.size());
            ListNode* p = lb;
            for(int i = 0; i < skipB; ++i) {
                p = p->next;
            }
            setTail(la, p);
        }
    }

    printList(la);
    printList(lb);

    Solution s;
    auto r2 = s.getIntersectionNode(la, lb);
    if (r2 != NULL) {
        cout << "CPP:" << r2->val << endl;
    }
    return 0;
}

/*
Tips
XXX
M0 hash表存储每个节点的地址，如果两个链表相交，则节点的地址相同。
这个与题目的S=O(1)相违背

M1 把la.tail指向lb.head。
如果la和lb相交，则必有环。环的入口就是相交点。
如果la和lb不相交，则必将遍历到末尾的NULL结束。

*/
