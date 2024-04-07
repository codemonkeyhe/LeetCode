/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-0
 * @tag
 * @similar
 */

/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]
 

提示：
链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
 ListNode* swapPairs(ListNode* head) {
   if (!head || head->next == NULL) {
     return head;
   }
   ListNode* preH = new ListNode();
   preH->next = head;

   ListNode* lastTail = preH;
   ListNode* nextH = NULL;

   ListNode* p1 = head;
   ListNode* p2 = head->next;
   while (p1 != NULL && p2 != NULL) {
     nextH = p2->next;
     p1->next = nextH;
     p2->next = p1;
     lastTail->next = p2;
     lastTail = p1;
     if (p1->next == NULL) {
       break;
     }
     p1 = p1->next;
     if (p1->next == NULL) {
       break;
     }
     p2 = p1->next;
   }
   lastTail->next = NULL;
   return preH->next;
 }
};

int main() { Solution s; }

/*
Tips
M1
head -> 1 -> 2 -> 3 -> 4
head -> 2 -> 1 -> 4 -> 3

p1 p2
1, 2, 3, 4

p2 p1 p1  p2
2, 1, 3, 4

      p2 p1
2, 1, 4, 3

M2

*/
