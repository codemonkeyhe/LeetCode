/**
 * @file
 * @brief   1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-27
 * @tag
 * @similar 83
 */

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Return the linked list sorted as well.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 12 ms, faster than 62.60% of C++ online submissions for Remove Duplicates from Sorted List II.
Memory Usage: 10.9 MB, less than 65.40% of C++ online submissions for Remove Duplicates from Sorted List II.
*/
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode preHead(-1);
        preHead.next = head;
        ListNode* pre = &preHead;
        ListNode* cur = preHead.next;
        ListNode* ne = NULL;
        while(cur!=NULL) {
            ne = cur->next;
            while (ne != NULL && ne->val == cur->val) {
                ne = ne->next;
            }
            if (cur->next != ne)
                pre->next = ne;
            else
                pre = pre->next;
            cur = ne;
        }
        return preHead.next;
    }

};

struct ListNode* deleteDuplicates(struct ListNode* head){

}

int main() {
    Solution s;
}


/*
Tips
新建哨兵节点，这样避免删除头节点
M1

M2
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/san-chong-jie-fa-duo-tu-zhan-shi-82-shan-chu-pai-x/

*/


