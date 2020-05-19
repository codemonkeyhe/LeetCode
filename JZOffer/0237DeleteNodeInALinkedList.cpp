/**
 * @file
 * @brief   P13
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-18
 */

/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
Given linked list -- head = [4,5,1,9], which looks like following:

Example 1:
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

Example 2:
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.

Note:
The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
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
Runtime: 16 ms, faster than 83.42% of C++ online submissions for Delete Node in a Linked List.
Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Delete Node in a Linked List.
*/
    void deleteNode(ListNode* node) {
        ListNode* n = node->next;
        node->val = n->val;
        node->next= n->next;
        delete n;
        n = NULL;
    }


};


void deleteNode(struct ListNode* node) {
    struct ListNode* n =  node->next;
    *node = *n;
    // 直接拷贝节点 相当于val和next同时赋值
    free(n);
}



int main() {

    Solution s;

    return 0;
}


