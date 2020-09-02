/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-02
 * @tag  Recursion; TwoPointers
 * @similar
 */

/*
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
        //pre是左半链表逆置后的表头，而cur正好等于slow,指向右半链表的起始链表
        //不管链表长度是奇数，还是偶数，cur和slow均指向右半链表。
        // [1,2,3,2,1]  当fast->1时，必有cur->3 slow->3
Runtime: 20 ms, faster than 99.65% of C++ online submissions for Palindrome Linked List.
Memory Usage: 13.9 MB, less than 89.30% of C++ online submissions for Palindrome Linked List.
*/
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* ne = NULL;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (cur != NULL) {
                ne = cur->next;
                cur->next = pre;
                pre = cur;
                cur = ne;
            }
        }
        if (fast != NULL) {  //说明链表长度是奇数,如果链表长度是偶数，必有fast==NULL
            slow = slow->next;
        }
        //pre为左半链表逆置后的头结点
        while (pre != NULL && slow != NULL) {
            if (pre->val != slow->val) {
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }


};

bool isPalindrome(struct ListNode* head){

}


int main() {
    Solution s;
}


/*
Tips
M1  双指针+链表左半逆置 [这个方法会修改链表本身，题目没有说不能修改链表本身]
链表左半逆置再比较是否相等
1->2->2->1->NULL
fast=NULL slow=2-2nd

1->2->3->2->1
fast=1 slow=3
2->1  3->2->1
每逆置一个节点，fast指针走2步
当fast指针为NULL时，正好逆置了一半
于是再一次比较slow指针和head是否相等

Skill
官方解法是先遍历一边定位fast和slow，而M1方法则少了一次遍历，而是把链表逆置和快慢指针揉在一起了
官方解法是逆置右半链表，不用区分奇数和偶数情况


M2  stack

M3 Recursion[TODO]
链接：https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode/
class Solution {
    private ListNode frontPointer;

    private boolean recursivelyCheck(ListNode currentNode) {
        if (currentNode != null) {
            if (!recursivelyCheck(currentNode.next)) return false;
            if (currentNode.val != frontPointer.val) return false;
            frontPointer = frontPointer.next;
        }
        return true;
    }

    public boolean isPalindrome(ListNode head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
}

https://leetcode.com/problems/palindrome-linked-list/discuss/64490/My-easy-understand-C%2B%2B-solution
class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }

    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};

*/


