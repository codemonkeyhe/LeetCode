/**
 * @file
 * @brief P16
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-19
 */

/*
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
/*
Runtime: 8 ms, faster than 78.29% of C++ online submissions for Reverse Linked List.
Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Reverse Linked List.
*/
    ListNode* reverseList(ListNode* head) {
        ListNode* p1 = NULL;
        ListNode* p2 = head;
        while (head!=NULL) {
            head = head->next;
            p2->next = p1;
            p1=p2;
            p2=head;
        }
        return p1;
    }

};

//Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Linked List.
//Memory Usage: 6 MB, less than 100.00% of C online submissions for Reverse Linked List.
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* n = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return n;
}


int main() {

    Solution s;

    return 0;
}


/*
递归的解法Skill
1. 把递归调用链当做stack去理解，快速进入到最后一个节点。
然后函数末尾处写翻转逻辑。
遇到最后一个节点时，他的地址一直往回带，作为新表头结点。
2. head->next = NULL;
只是为了让新表的尾节点指向NULL而已，对于其他节点算是冗余操作
3. 递归终止条件 head->next == NULL是为了锁定到最后一个节点，而非最末位的NULL。

4. 修改指向时，是通过head节点去操作。每一层递归栈都指向当前的节点。
    head->next->next = head;

*/
