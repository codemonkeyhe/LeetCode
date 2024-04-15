/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-12
 * @tag
 * @similar
 * 但凡链表相关的，三个套路思考一下
 * 1 vector存地址来处理
 * 2 递归
 * 3 双指针 
 */

/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 

示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]
 

提示：
列表中的节点数目在范围 [0, 104] 内
1 <= Node.val <= 50
0 <= val <= 50
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

    //写复杂了  
    ListNode* removeElementsM1(ListNode* head, int val) {
        ListNode* preH = new ListNode();
        preH->next = head;
        ListNode* cur = head;
        ListNode* p1 = preH;
        ListNode* p2 = NULL;
        while(cur) { 
            if (cur->val != val) {
                p1 = cur;
                cur = cur->next;
                continue;
            }
            p2 = cur->next;
            p1->next = cur->next;
            //cur->next = NULL;
            cur = p2;
        }
        return preH->next;
    }

    // 简洁版 tricks 走一步看两步  
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* preH = new ListNode();
        preH->next = head;
        ListNode* cur = preH;
        while(cur->next) { 
            if (cur->next->val != val) {
                cur = cur->next;
            } else {
                cur->next = cur->next->next;
            }
        }
        return preH->next;
    }


    ListNode* removeElementsM2(ListNode* head, int val) {
        auto res = remElements(head, val);
        return res;
    }


    ListNode* remElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        auto newH = remElements(head->next, val);
        if (head->val == val) {
            return newH;
        }
        head->next = newH;
        return head;
    }

};


int main() {
    Solution s;
}


/*
Tips
https://leetcode.cn/problems/remove-linked-list-elements/description/ 

M1 就地删除法 

M2 递归 

M3 用栈 

递归 当作 函数栈
第一版 入栈前操作，写完代码，大脑单步发现不行
于是 只能是出栈后的操作 

*/


