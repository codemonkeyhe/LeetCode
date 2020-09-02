/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-08-23
 * @tag
 * @similar 92
 */

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* ne = head;
        while (cur != NULL) {
            ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        return pre;
    }

    // in: head-> ... ->tail
    // out:  head<- ... <-tail
    void reverseList(ListNode* head, ListNode* tail) {
        ListNode* pre = tail->next;
        ListNode* cur = head;
        ListNode* ne = head;
        while (pre != tail) {
            ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
    }



/*
Time Limit Exceeded
[1,2,3,4,5]
1

XXX K=1不用反转
Input
[1,2,3,4,5]
1
Output [5,4,3,2,1]
Expected [1,2,3,4,5]

关于K=1的处理有分歧，否则一次AC
Runtime: 24 ms, faster than 26.15% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 10.3 MB, less than 34.08% of C++ online submissions for Reverse Nodes in k-Group.
[ preSubTail]->[curSubHead(newTail) ... curSubTail(newHead)]->[nextSubHead..]

实现太啰嗦了，4点优化
1. 对末尾小于数目K的子链表，无需特殊处理
2. 每一个轮次的子链表反转时，不需要断开末尾的链，把结束标志传给reverseList，这样就避免了对最后一个子链表数目小于K的特殊处理
3. 不利用形参head，只需要5个指针，preSubTail, curSubHead, curSubTail, nextSubHead. newTail和newHead是多余的,因为reverseList后，curSubHead==newTail
4. 循环结构没控制好，1个while循环显得比较乱，while+for合适点
5. 加多1个哨兵，避免对前节点特殊处理,哨兵不需要new，因为new需要delete释放，直接用栈上的对象即可

*/
    ListNode* reverseKGroupFool(ListNode* head, int k) {
        if (k == 0 || k == 1) {
            return head;
        }
        ListNode* res = NULL;
        ListNode* preSubTail = NULL;
        ListNode* nextSubHead = head;
        ListNode* curSubHead = head;
        ListNode* curSubTail = head;
        int i = 0;
        while (nextSubHead != NULL) {
            nextSubHead = nextSubHead->next;
            i++;
            if (i == k - 1) {
                curSubTail = nextSubHead;
            }
            if (i == k) {
                i = 0;
                curSubTail->next = NULL;
                ListNode* newTail = curSubHead;
                ListNode* newHead = reverseList(curSubHead);
                if (preSubTail != NULL) {
                    preSubTail->next = newHead;
                } else { //说明是第一个子链表的反转
                    res = newHead;
                }
                preSubTail = newTail;
                curSubHead = nextSubHead;
                continue;;
            }
        }
        if (i < k) { //补齐末尾
            preSubTail->next = curSubHead;
        }
        return res;
    }

    /*
Runtime: 16 ms, faster than 82.09% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 10.2 MB, less than 55.35% of C++ online submissions for Reverse Nodes in k-Group.
    */
   ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1) {
            return head;
        }
        ListNode preHeader(-1);
        preHeader.next = head;
        ListNode* preSubTail = &preHeader;
        ListNode* curSubHead = head;
        ListNode* curSubTail = head;
        ListNode* nextSubHead = head;
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        while (curSubHead) {
            curSubTail = preSubTail;
            for (int i = 0; i < k; ++i) {
                curSubTail = curSubTail->next;
                if (!curSubTail) {  //最后一组链表不足K个，直接结束
                    return preHeader.next;
                }
            }
            nextSubHead = curSubTail->next;
            reverseList(curSubHead, curSubTail);
            newTail = curSubHead;
            newHead = curSubTail;
            preSubTail->next = newHead;
            newTail->next = nextSubHead;
            preSubTail = newTail;
            curSubHead = newTail->next;
        }
        return preHeader.next;
   }
};


struct ListNode* reverseKGroup(struct ListNode* head, int k){

}

/*
Tips
M1 常规模拟法
每遍历K个元素作为一组子链表，断开子链表的尾指针，子链表反转，就像leetcode-206一样反转链表
再把当前的子链表[newHead, newTail]与之前的子链表尾巴[...preSubTail]串联起来
preSubTail->next = newHead;
preSubTail = newTail;
https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11457/20-line-iterative-C%2B%2B-solution
ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next)
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
    }


M2 递归法  TODO
https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11435/C%2B%2B-Elegant-and-Small
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;

        while ( first != last )
        {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        auto node=head;
        for (int i=0; i < k; ++i)
        {
            if ( ! node  )
                return head; // nothing to do list too sort
            node = node->next;
        }

        auto new_head = reverse( head, node);
        head->next = reverseKGroup( node, k);
        return new_head;
    }

*/

int main() {
    const int len = 5;
    int nums[len] = {1, 2, 3, 4, 5};
    int k = 2;
    vector<int> nu(nums, nums + len);
    ListNode* li = buildList(nu, len);
    Solution s;
    auto res = s.reverseKGroup(li, k);
    printList(res);
}

