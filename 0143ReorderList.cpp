/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-11
 * @tag
 * @similar
 */

/*
重排链表
Category	Difficulty	Likes	Dislikes
algorithms	Medium (66.14%)	1463	-

Tags
linked-list


给定一个单链表 L 的头节点 head ，单链表 L 表示为：
L0 → L1 → … → Ln - 1 → Ln

请将其重新排列后变为：
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例 1：
输入：head = [1,2,3,4]
输出：[1,4,2,3]

示例 2：
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
 

提示：
链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:



    void reorderListM1(ListNode* head) {
        vector<ListNode*> arr; 
        ListNode* cur = head;
        while(cur) {
            arr.push_back(cur);
            cur = cur->next;
        }

        int len = arr.size();
        int mid = len/2;
        for (int i = 0; i < mid; i++) {
            arr[i]->next = arr[len-i-1];
        }
        arr[mid]->next = NULL;
        for (int i = len-1; i > mid; i--) {
            arr[i]->next = arr[len-i];
        }
        return ;
    }


    void reorderList(ListNode* head) {
        ListNode* mid = findMidle(head);
        ListNode* l2 = reverseList(mid->next);
        mid->next = NULL;
        mergeList(head, l2);
        return;
    }


/*
    p1  p2
H 1 2 3 4 X  mid=2
      p1    p2 
H 1 2 3 4 5 X  mid = 3

*/
    ListNode* findMidle(ListNode* head) {
        if (head == NULL  || head->next == NULL)  {
            return head;
        }
        ListNode* tmpHead = new ListNode();
        tmpHead->next = head;
        ListNode* p1 = tmpHead;
        ListNode* p2 = tmpHead;
        while(p2) {
            p1 = p1->next;
            if (p2->next) {
                p2 = p2->next->next;
            }
            if (p2 == NULL || p2->next == NULL) {
                break;
            }
        }
        return p1; 
    }

      ListNode* middleNodeV2(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }


    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            ListNode* ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        return pre;
    }

/**
 p1
 1 , 2 
 p2
 4 , 3 


*/
    void mergeList(ListNode* l1, ListNode* l2)  {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p1 && p2)  {
            ListNode* p1ne = p1->next;
            ListNode* p2ne = p2->next;
            p1->next = p2;
            p2->next = p1ne;
           p1 = p1ne; 
           p2 = p2ne;
        }
        return;
    }

};


int main() {
    Solution s;
}


/*
Tips
https://leetcode.cn/problems/reorder-list/solutions/452867/zhong-pai-lian-biao-by-leetcode-solution/  

M1 线性表

M2 寻找链表中点 + 链表逆序 + 合并链表

*/


