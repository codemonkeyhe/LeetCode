/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-15 
 * @tag
 */

/*
* @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 *
 * https://leetcode.cn/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (64.58%)
 * Likes:    778
 * Dislikes: 0
 * Total Accepted:    236.7K
 * Total Submissions: 366.5K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。
 * 
 * 第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。
 * 请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。
 * 
 * 你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。
 * 
 * 
 * 
 * 示例 1:
 * 输入: head = [1,2,3,4,5]
 * 输出: [1,3,5,2,4]
 * 
 * 示例 2:
 * 输入: head = [2,1,3,5,6,4,7]
 * 输出: [2,3,6,7,1,5,4]
 * 
 * 
 * 提示:
 * n ==  链表中的节点数
 * 0 <= n <= 10^4
 * -10^6 <= Node.val <= 10^6
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

  ListNode* oddEvenListM1(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p1i = p1;
        ListNode* p2 = head->next; 
        ListNode* p2i = p2;
        ListNode* cur = p2->next;
        int i = 0;
        while(cur) {
            if (i%2 == 0) {
               p1i->next = cur; 
               p1i = cur;
            } else {
                p2i->next = cur;
                p2i = cur;
            }
            cur = cur->next;
            i++;
        }
        p1i->next = p2;
        p2i->next = NULL;
        return p1;
    }


    // M2
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head->next; 
        ListNode* p3 = p1;
        ListNode* p4 = p2;

        while(p3 && p4) {
            if (!p4->next) break;
            p3->next = p4->next;
            p3 = p3->next;
            p4->next = p3->next;
            p4 = p4->next;
        }
        p3->next = p2;
        return head;;
    }

};


int main() {
    Solution s;
}


/*
Tips
M1  头部 插入法 

M2  就地分离再合并  双指针 

*/


