/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-
 * @tag
 * @similar 445
 */

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 28 ms, faster than 89.11% of C++ online submissions for Add Two Numbers.
Memory Usage: 70.1 MB, less than 85.63% of C++ online submissions for Add Two Numbers.
*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l3(-1);
        ListNode* p = &l3;
        int cur = 0;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            cur = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = cur / 10;
            p->next = new ListNode(cur%10);
            p = p->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry) {
            p->next = new ListNode(1);
        }
        return l3.next;
    }

};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

}

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


