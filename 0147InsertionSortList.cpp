/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-04
 * @tag
 * @similar
 */

/*
Sort a linked list using insertion sort.

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list


Algorithm of Insertion Sort:
Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 56 ms, faster than 26.33% of C++ online submissions for Insertion Sort List.
Memory Usage: 10.1 MB, less than 5.04% of C++ online submissions for Insertion Sort List.
cur位置如下所示
[ ... pre {cur} pos ...]　(cur ne ..)
*/
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode preHeader(INT_MIN);
        preHeader.next = head;
        ListNode* cur = head->next;
        head->next = NULL; // 相当于第一个元素就是有序链表
        ListNode* ne = NULL;
        while (cur != NULL) {
            ListNode* pos = preHeader.next;
            ListNode* pre = &preHeader;
            while (pos && cur->val > pos->val) {
                pre = pos;
                pos = pos->next;
            }
            pre->next = cur;
            ne = cur->next;
            cur->next = pos;
            cur = ne;
        }
        return preHeader.next;
    }
};

struct ListNode* insertionSortList(struct ListNode* head){

}


int main() {
    Solution s;
}


/*
Tips
M1 插入排序
T=O(n^2)

M2

*/


