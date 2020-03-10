/**
 * @file
 * @brief  快慢指针找环
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-03-10
 */

/*
Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to.
If pos is -1, then there is no cycle in the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Follow up:
Can you solve it using O(1) (i.e. constant) memory?

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

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow->next != NULL) {
            if (fast->next == NULL) break;
            if (fast->next->next == NULL) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        };
        return false;
    }
};

bool hasCycle(struct ListNode *head) {
    bool res = false;
    if (head == NULL) {
        return res;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (true) {
        if (slow->next == NULL) break;
        if (fast->next == NULL) break;
        if (fast->next->next == NULL) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            res = true;
            break;
        }
    };
    return res;
}

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

int main() {
    vector<int> data{3, 2, 0, -4};
    int pos = 1;
    ListNode *head = buildList(data, pos);
    printList(head);
    printf("%d\n", hasCycle(head));
    Solution s;
    cout << s.hasCycle(head) << endl;
    return 0;
}

/*
TIPS
快慢指针
同类型题目 142 268 287

*/
