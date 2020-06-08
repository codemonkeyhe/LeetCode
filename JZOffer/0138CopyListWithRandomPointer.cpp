/**
 * @file
 * @brief  P26  133-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-06-08
 */

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Example 4:
Input: head = []
Output: []

Explanation: Given linked list is empty (null pointer), so return null.

Constraints:
-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.
*/

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    // Runtime: 28 ms, faster than 6.75% of C++ online submissions for Copy List
    // with Random Pointer. Memory Usage: 11.3 MB, less than 37.50% of C++ online
    // submissions for Copy List with Random Pointer.
    void copyOldList(Node* head) {
        Node* p = head;
        Node* tmp = NULL;
        while (p != NULL) {
            Node* n = new Node(p->val);
            n->next = p->next;
            p->next = n;
            p = n->next;
        }
    }

    void fixRandom(Node* head) {
        Node* p = head;
        while (p != NULL) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
    }

    Node* splitList(Node* head) {
        Node* p1 = head;
        Node* h2 = p1->next;
        Node* p2 = h2;
        while (p1 != NULL) {
            p1->next = p2->next;
            p1 = p1->next;
            if (p1)
                p2->next = p1->next;
            p2 = p2->next;
        }
        return h2;
    }

    Node* copyRandomListM1(Node* head) {
        if (head==NULL) return NULL;
        copyOldList(head);
        fixRandom(head);
        return splitList(head);
    }

//Runtime: 28 ms, faster than 6.75% of C++ online submissions for Copy List with Random Pointer.
//Memory Usage: 11.5 MB, less than 8.16% of C++ online submissions for Copy List with Random Pointer.
    Node* m2(Node* head, unordered_map<Node*, Node*>& m) {
        if (head == NULL)
            return NULL;
        unordered_map<Node*, Node*>::iterator it;
        if ( (it = m.find(head)) != m.end()) {
            return it->second;
        }
        Node* n = new Node(head->val);
        m.insert(make_pair(head, n));
        n->next = m2(head->next, m);
        n->random = m2(head->random, m);
        return n;
    }

    Node* copyRandomListM2(Node* head) {
        unordered_map<Node*, Node*>  m;
        return m2(head, m);
    }

//Runtime: 12 ms, faster than 90.69% of C++ online submissions for Copy List with Random Pointer.
//Memory Usage: 11.1 MB, less than 78.41% of C++ online submissions for Copy List with Random Pointer.
    Node* copyRandomListM3(Node* head) {
        if (head==NULL) return NULL;
        //copyOldList(head);
        Node* p = head;
        Node* tmp = NULL;
        while (p != NULL) {
            Node* n = new Node(p->val);
            n->next = p->next;
            p->next = n;
            p = n->next;
        }
        //fixRandom(head);
        p = head;
        while (p != NULL) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        //splitList(head)优化版;
        Node* p1 = head;
        Node* h2 = p1->next;
        Node* p2 = h2;
        p1->next = p2->next;
        p1 = p1->next;
        while (p1 != NULL) {
            p2->next = p1->next;
            p2 = p2->next;
            p1->next = p2->next;
            p1 = p1->next;
        }
        return h2;
    }
};

struct Node* copyRandomList(struct Node* head) {

}

int main() {

    Solution s;

    return 0;
}


/*
Tips
M1  hashmap<Node*, Node*>记录L1和L2的对应关系
a来自原表L1, b来自拷贝的表L2。
第一步 拷贝L1到L2。 L1={a1,a2,...an}，L2={b1,b2,...bn}，其中 ai->val = bi->val
第二步 再次遍历L1，修改random指针。例如L1中的ai->random=aj, 对应hashmap里面的bi->random=bj

M2  当做图的复制去考虑
依然用hashmap记录对应关系，相当于M1的改进版，只是hashmap多了一个访问去重的功能，相当于visited的功能。


M3 染色体的有丝分裂
在L1的每个节点后面插入拷贝的新节点
然后修改random指针， oldNode->next->random = oldNode->random->next;
最后拉链解开旧表和新表

*/
