/**
 * @file
 * @brief  CCI-2.1
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-27
 * @tag
 * @similar 82
 */

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 12 ms, faster than 80.85% of C++ online submissions for Remove Duplicates from Sorted List.
Memory Usage: 11.1 MB, less than 26.38% of C++ online submissions for Remove Duplicates from Sorted List.
*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* ne = head;
        while (cur != NULL) {
            ne = cur->next;
            while (ne != NULL && ne->val == cur->val) {
                ne = ne->next;
            }
            cur->next = ne;
            cur = ne;
        }
        return head;
    }

/*
Runtime: 12 ms, faster than 80.85% of C++ online submissions for Remove Duplicates from Sorted List.
Memory Usage: 11 MB, less than 58.13% of C++ online submissions for Remove Duplicates from Sorted List.
*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == cur->val) {
                cur->next = cur->next->next;
            }else {
                cur = cur->next;
            }
        }
        return head;
    }
};

struct ListNode* deleteDuplicates(struct ListNode* head){

}


int main() {
    Solution s;
}


/*
Tips
M1 双指针
T-O(N)
不需要主动free
It is unnecessary to free, because using it only if you are sure that the nodes have been allocated with malloc function. please refer to https://leetcode.com/discuss/7188/concise-solution-and-memory-freeing

M2  单指针

*/


