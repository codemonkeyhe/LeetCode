/**
 * @file
 * @brief  快慢指针找环，推导原理见0287
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-10
 */

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Follow-up:
Can you solve it without using extra space?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *buildList(vector<int> &data, int pos) {
    if (data.size() == 0) {
        return NULL;
    }
    struct ListNode *head = new ListNode(data[0]);
    struct ListNode *tail = head;
    for (size_t i = 1; i < data.size(); ++i) {
        ListNode *p = new ListNode(data[i]);
        tail->next = p;
        tail = tail->next;
    }
    ListNode *cycle = head;
    for (int i = 0; i < pos; ++i) {
        cycle = cycle->next;
    }
    tail->next = cycle;
    return head;
}

void printList(ListNode *head) {
    ListNode *p = head;
    int i = 0;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
        ++i;
        if (i > 10) {
            break;
        }
    }
    cout << endl;
}

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        bool existCycle = false;
        while (slow->next != NULL) {
            if (fast->next == NULL) break;
            if (fast->next->next == NULL) break;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                existCycle = true;
                break;
            }
        };
        if (!existCycle) {
            return NULL;
        }
        if (fast == head) {
            return head;
        } else {
            fast = head;
        }
        while (slow->next != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast) {
                return slow;
            }
        }
        return NULL;
    }
};


int main() {
    // vector<int> data{3, 2, 0, -4};
     vector<int> data{1,2};
    int pos = 0;
    ListNode *head = buildList(data, pos);
    printList(head);

    Solution s;
    auto r2 = s.detectCycle(head);
    if (r2 != NULL) {
        cout << "CPP: " << r2->val << endl;
    }
    return 0;
}

/*
Tips
https://leetcode.com/problems/linked-list-cycle-ii/discuss/44820/C%2B%2B-implementation-with-much-more-clear-and-strict-explanation-!-any-one-can-give-more-clear
*/