/**
 * @file
 * @brief  P26  133-similar
 * @author MonkeyHe
 * @version  1.0
 * @date 20200608; 20251113
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

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 *
 * https://leetcode.cn/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (66.73%)
 * Likes:    1360
 * Dislikes: 0
 * Total Accepted:    277.2K
 * Total Submissions: 415.1K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
 *
 * 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random
 * 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
 *
 * 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random
 * --> y 。
 *
 * 返回复制链表的头节点。
 *
 * 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 * val：一个表示 Node.val 的整数。
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 * 你的代码 只 接受原链表的头节点 head 作为传入参数。
 *
 *
 *
 * 示例 1：
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 *
 * 示例 2：
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 *
 *
 * 示例 3：
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 *
 *
 *
 *
 * 提示：
 * 0 <= n <= 1000
 * -10^4 <= Node.val <= 10^4
 * Node.random 为 null 或指向链表中的节点。
 *
 *
 *
 *
 */

// @lc code=start
/*
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        // copyList
        Node* p = head;
        while(p != NULL) {
            Node* nextStep = p->next;
            Node* tmp = new Node(p->val);
            tmp->next = p->next;
            p->next = tmp;
            p = nextStep;
        }

        // fix random
        p = head;
        while (p != NULL) {
            if (p->random == NULL) {
                p = p->next->next;
                continue;
            }
            auto mirror = p->random->next;
            p->next->random = mirror;
            p = p->next->next;
        }

        // splitList
        Node* newHead = head->next;
        /*  M1
        Node* h1 = new Node(0);
        Node* h2 = new Node(0);
        Node* p1 = head;
        Node* p2 = head->next;
        while (p1 != NULL && p2 != NULL ) {
            h1->next = p1;
            h2->next = p2;
            h1 = h1->next;
            h2 = h2->next;
            p1 = p1->next->next;
            if (p2->next == NULL) {
                break;
            }
            p2 = p2->next->next;
        }
        h1->next = NULL;
        h2->next = NULL;
        */

        Node* p1 = head;
        Node* p2 = head->next;
        while (p1 != NULL && p2 != NULL) {
            p1->next = p1->next->next;
            if (p2->next == NULL) {
                break;
            }
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        return newHead;
    }
};
// @lc code=end

/*
a b c
a a1 b b1 c c1


Your Input
[[7,null],[13,0],[11,4],[10,2],[1,0]]
Output (0 ms)
Next pointer of node with label 1 from the original list was modified.
Expected Answer


*/

class SolutionOld {
   public:

    /*
    //M1
    Runtime: 8 ms, faster than 99.58% of C++ online submissions for Copy List with Random Pointer.
Memory Usage: 11.3 MB, less than 36.48% of C++ online submissions for Copy List with Random Pointer.
    */
    Node* copyRandomListM1(Node* head) {
        if (head == NULL)
            return NULL;
        // copy next
        unordered_map<Node*, Node*> hm;
        Node* p = head;
        Node cp(-1);
        Node* tail = &cp;
        while (p != NULL) {
            Node* n = new Node(p->val);
            hm[p] = n;
            tail->next = n;
            tail = tail->next;
            p = p->next;
        }
        tail->next = NULL;
        // copy random
        Node* p1 = head;
        Node* p2 = cp.next;
        while (p1 != NULL) {
            p2->random = hm[p1->random];
            p1 = p1->next;
            p2 = p2->next;
        }
        return cp.next;
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

    //M3
    Node* copyRandomList(Node* head) {
        if (head==NULL) return NULL;
        copyOldList(head);
        fixRandom(head);
        return splitList(head);
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
依然用hashmap记录对应关系，相当于M1的改进版，改成递归的写法


M3 染色体的有丝分裂
在L1的每个节点后面插入拷贝的新节点
然后修改random指针， oldNode->next->random = oldNode->random->next;
最后拉链解开旧表和新表

*/
