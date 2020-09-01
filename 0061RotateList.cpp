/**
 * @file
 * @brief  1st-AC
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-01
 * @tag
 * @similar
 */

/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
M1
[len=3 k%len=1  p=len-k=3-1=2 ]
Runtime: 24 ms, faster than 6.53% of C++ online submissions for Rotate List.
Memory Usage: 11.4 MB, less than 24.93% of C++ online submissions for Rotate List.
*/

    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0)
            return head;
        if (head == NULL)
            return NULL;
        int len = 0;
        ListNode* p = head;
        ListNode* tail = head;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        len++;
        k = k % len;
        if (k == 0)
            return head;
        int begin = len - k;
        ListNode* newTail = head;
        while(begin > 1) {
            newTail = newTail->next;
            begin--;
        }
        //定位新的头
        ListNode* newHead = newTail->next;
        //断开新的尾
        newTail->next = NULL;
        //首尾相接
        tail->next = head;
        return newHead;
    }

};

struct ListNode* rotateRight(struct ListNode* head, int k){

}


int main() {
    Solution s;
}


/*
Tips
M1 模拟法
首尾相接，断新尾


M2

*/


