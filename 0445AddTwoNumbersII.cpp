/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-27
 * @tag
 * @similar 2
 */

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
/*
Runtime: 44 ms, faster than 52.67% of C++ online submissions for Add Two Numbers II.
Memory Usage: 72.7 MB, less than 29.27% of C++ online submissions for Add Two Numbers II.
写复杂了
1 stack不应该存指针，存值就好了
2 不需要哨兵节点，直接逆序链成链表就好
*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        while (l1 != NULL) {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            s2.push(l2);
            l2 = l2->next;
        }
        int cur = 0;
        int carry = 0;
        ListNode* res = new ListNode(-1);
        ListNode* ne = NULL;
        while(!s1.empty() || !s2.empty()) {
            int v1 = 0;
            int v2 = 0;
            if (!s1.empty()) {
                v1 = s1.top()->val;
                s1.pop();
            }
            if (!s2.empty()) {
                v2 = s2.top()->val;
                s2.pop();
            }
            cur = carry + v1 + v2;
            carry = cur / 10;
            ne = res->next;
            res->next = new ListNode(cur % 10);
            res->next->next = ne;
        }
        if (carry) {
            ne = res->next;
            res->next = new ListNode(1);
            res->next->next = ne;
        }
        return res->next;
    }

};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

}

int main() {
    Solution s;
}


/*
Tips
M1 stack

M2 DFS

*/


