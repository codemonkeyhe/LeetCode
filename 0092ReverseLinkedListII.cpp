/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-02
 * @tag Recursion
 * @similar  25  206
 */

/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
    // reverse  [start, end] (stop)  => [end, start] (stop)
    // return newHead == end == pre
    ListNode* reverseList(ListNode* start, ListNode* stop) {
        ListNode* cur = start;
        ListNode* ne = NULL;
        ListNode* pre = stop;
        while (cur != stop) {
            ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        return pre;
    }


/*
Runtime: 8 ms, faster than 8.91% of C++ online submissions for Reverse Linked List II.
Memory Usage: 7.5 MB, less than 30.39% of C++ online submissions for Reverse Linked List II.
*/
    ListNode* reverseBetweenM1(ListNode* head, int m, int n) {
        ListNode preHeader(-1);
        preHeader.next = head;
        ListNode* preStart = &preHeader;
        //ListNode* start = head;
        ListNode* end = head;
        int width = n - m;
        while (width-- > 0) {
            end = end->next;
        }
        int k = m - 1;
        while (k-- > 0) {
            preStart = preStart->next;
            //start = start->next;
            end = end->next;
        }
        ListNode* newHead = reverseList(preStart->next, end->next); // [start, stop)
        preStart->next = newHead;
        return preHeader.next;
    }

/*
M2
Runtime: 4 ms, faster than 59.57% of C++ online submissions for Reverse Linked List II.
Memory Usage: 7.4 MB, less than 55.53% of C++ online submissions for Reverse Linked List II.
*/
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode preHeader(-1);
        preHeader.next = head;
        ListNode* preStart = &preHeader;
        int k = m - 1;
        while (k-- > 0) {
            preStart = preStart->next;
        }
        //begin reverse cnt nodes
        ListNode* newTail = preStart->next;
        ListNode* cur = preStart->next;
        ListNode* pre = NULL;
        ListNode* ne = NULL;
        int cnt = n - m + 1;
        while (cnt-- > 0) {
            ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        //cur -->stop;  [start, end](stop)
        preStart->next = pre;
        newTail->next = cur;
        return preHeader.next;
    }

};

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){

}


int main() {
    Solution s;
}


/*
Tips
M1  双指针滑动窗口
1.其实就是单链表逆置的加强版,传统的逆置以NULL为标记，这里的逆置以某个节点stop为标记
2.m,n从1开始计数，1代表第一个节点，为了避免区分头结点，需要引入preHead节点
3.  end节点先走n-m+1步，
preStart节点走m-1步，指向要开始逆置的第一个节点的前一个节点，同时end节点也走m+1步
逆置[start(即preStart->next), end]链表,再重新修改表头
T=O(N)+O(N)

M2   OP大法
一次遍历
Do it in one-pass.
M1的改进版

M3  Recursion[TODO]
https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/bu-bu-chai-jie-ru-he-di-gui-di-fan-zhuan-lian-biao/

*/


