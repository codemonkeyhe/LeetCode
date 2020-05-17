/**
 * @file
 * @brief   P5
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-05-17
 */

/*
You are given an immutable linked list, print out all values of each node in reverse with the help of the following interface:

ImmutableListNode: An interface of immutable linked list, you are given the head of the list.

You need to use the following functions to access the linked list (you can't access the ImmutableListNode directly):
ImmutableListNode.printValue(): Print value of the current node.
ImmutableListNode.getNext(): Return the next node.

The input is only given to initialize the linked list internally. You must solve this problem without modifying the linked list. In other words, you must operate the linked list using only the mentioned APIs.

Follow up:
Could you solve this problem in:
Constant space complexity?
Linear time complexity and less than linear space complexity?


Example 1:
Input: head = [1,2,3,4]
Output: [4,3,2,1]

Example 2:
Input: head = [0,-4,-1,3,-5]
Output: [-5,3,-1,-4,0]

Example 3:
Input: head = [-2,0,6,4,4,-6]
Output: [-6,4,4,6,0,-2]


Constraints:
The length of the linked list is between [1, 1000].
The value of each node in the linked list is between [-1000, 1000].
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>

using namespace std;

class  ImmutableListNode {
    public:
ImmutableListNode(int x): val(x), next(NULL){}
~ImmutableListNode(){}

//Print value of the current node.
void printValue(){ cout << val << " "; }

//Return the next node.
ImmutableListNode* getNext() { return next; }

int val;
ImmutableListNode* next;
};


typedef  ImmutableListNode ListNode;

ListNode* buildList(vector<int>& data, int len) {
    if (data.size() == 0) {
        return NULL;
    }
    ListNode* head = new ListNode(data[0]);
    ListNode* tail = head;
    for (size_t i = 1; i < data.size() && i < len; ++i) {
        ListNode* p = new ListNode(data[i]);
        tail->next = p;
        tail = tail->next;
    }
    return head;
}


class Solution {
public:

    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head == NULL) {
            return;
        }
        printLinkedListInReverse(head->getNext());
        head->printValue();
        return ;
    }


};



int main() {
    vector<int> listA = {1,2,3,4};
    int len=4;
    auto head = buildList(listA, len);

    Solution s;
    s.printLinkedListInReverse(head);

    return 0;
}


/*
Tips
too easy

advanced: skip-list

https://leetcode.com/discuss/interview-question/algorithms/198827/print-immutable-linked-list-in-reverse-order-in-a-machine-with-small-ram
https://leetcode.com/discuss/interview-question/124617/Print-out-an-immutable-singly-linked-list-in-reverse/
https://blog.csdn.net/qq_32424059/article/details/103471737



*/