/**
 * @file
 * @brief  1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-0
 * @tag
 * @similar
 */

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 4 ms, faster than 92.35% of C++ online submissions for Partition List.
Memory Usage: 10.1 MB, less than 30.14% of C++ online submissions for Partition List.
*/
    ListNode* partition(ListNode* head, int x) {
        ListNode left(-1);
        ListNode right(-1);
        ListNode* p1 = &left;
        ListNode* p2 = &right;
        while(head!=NULL) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        //拼接left和right
        p1->next = right.next;
        return left.next;
    }

};

struct ListNode* partition(struct ListNode* head, int x){

}


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


