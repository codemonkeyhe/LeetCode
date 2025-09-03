/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-03
 * @tag  dfs,linkedList
 * @similar 114, 430
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 *
 * https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list/description/
 *
 * algorithms
 * Medium (59.59%)
 * Likes:    448
 * Dislikes: 0
 * Total Accepted:    72.2K
 * Total Submissions: 120.7K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]'
 *
 * 你会得到一个双链表，其中包含的节点有一个下一个指针、一个前一个指针和一个额外的 子指针
 * 。这个子指针可能指向一个单独的双向链表，也包含这些特殊的节点。这些子列表可以有一个或多个自己的子列表，以此类推，以生成如下面的示例所示的 多层数据结构
 * 。
 * 给定链表的头节点 head ，将链表 扁平化 ，以便所有节点都出现在单层双链表中。让 curr
 * 是一个带有子列表的节点。子列表中的节点应该出现在扁平化列表中的 curr 之后 和 curr.next 之前 。
 * 返回 扁平列表的 head 。列表中的节点必须将其 所有 子指针设置为 null 。
 *
 *
 *
 * 示例 1：
 * 输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 * 输出：[1,2,3,7,8,11,12,9,10,4,5,6]
 * 解释：输入的多级列表如上图所示。
 * 扁平化后的链表如下图：
 *
 *
 *
 * 示例 2：
 * 输入：head = [1,2,null,3]
 * 输出：[1,3,2]
 * 解释：输入的多级列表如上图所示。
 * 扁平化后的链表如下图：
 *
 *
 *
 * 示例 3：
 * 输入：head = []
 * 输出：[]
 * 说明：输入中可能存在空列表。
 *
 *
 *
 *
 * 提示：
 * 节点数目不超过 1000
 * 1 <= Node.val <= 10^5
 *
 *
 *
 *
 * 如何表示测试用例中的多级链表？
 *
 * 以 示例 1 为例：
 * ⁠1---2---3---4---5---6--NULL
 * ⁠        |
 * ⁠        7---8---9---10--NULL
 * ⁠            |
 * ⁠            11--12--NULL
 *
 * 序列化其中的每一级之后：
 * [1,2,3,4,5,6,null]
 * [7,8,9,10,null]
 * [11,12,null]
 *
 *
 * 为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。
 * [1,2,3,4,5,6,null]
 * [null,null,7,8,9,10,null]
 * [null,11,12,null]
 *
 *
 * 合并所有序列化结果，并去除末尾的 null 。
 * [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 *
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
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* getTail(Node* head) {
        Node* p = head;
        while (p != NULL && p->next != NULL ) {
            p = p->next;
        }
        return p;
    }

    Node* flattenM1(Node* head) {
        Node* p = head;
        while (p != NULL) {
            if (p->child == NULL) {
                p = p->next;
                continue;
            }
            // p->child != NULL
            Node* ne = p->next;
            Node* pn = flatten(p->child);
            //insert pn between p, ne
            pn->prev = p;
            // STOP XXX  after flatten, how to find tail
            //pn....tail = ne;
            Node* sonTail = getTail(pn);
            sonTail->next = ne;
            p->next = pn;
            if (ne != NULL) {
                ne->prev = sonTail;
            }
            p->child = NULL;
            p = ne;
        }
        return head;
    }



    Node* flattenM2(Node* head) {
        pair<Node*, Node*> pa = ft(head);
        return pa.first;
    }


    pair<Node*, Node*> ft(Node* head) {
        Node* p = head;
        //while (p != NULL && p->next != NULL) {
        while (p != NULL) {
            if (p->child == NULL) {
                if (p->next == NULL) {
                    return make_pair(head, p);
                }
                p = p->next;
                continue;
            }
            // p->child != NULL
            Node* ne = p->next;
            // insert [sonHead, sonTail]  between p and ne
            pair<Node*, Node*> pa = ft(p->child);
            Node* sonHead = pa.first;
            Node* sonTail = pa.second;
            sonHead->prev = p;
            sonTail->next = ne;
            p->next = sonHead;
            p->child = NULL;
            if (ne != NULL) {
                ne->prev = sonTail;
                p = ne;
            } else {
                return make_pair(head, sonTail);
            }
        }
        return make_pair(head, p);
    }

    // M3
    Node* flattenM3(Node* head) {
        dfs(head);
        return head;
    }


    Node* dfs(Node* head) {
        Node* p = head;
        Node* lastNode = p;
        while (p != NULL) {
            if (p->child == NULL) {
                lastNode = p;
                p = p->next;
                continue;
            }
            // child != NULL
            Node* ne = p->next;
            Node* sonTail = dfs(p->child);
            // insert [p->child ... sonTail] between p and ne
            Node* sonHead = p->child;
            sonHead->prev = p;
            sonTail->next = ne;
            p->next = sonHead;
            if (ne != NULL) {
                ne->prev = sonTail;
            }
            lastNode = sonTail;
            p->child = NULL;
            p = ne;
        }
        return lastNode;
    }

    // M4
    Node* flatten(Node* head) {
        Node* p = head;
        while (p != NULL) {
            if (p->child == NULL) {
                p = p->next;
                continue;
            }
            Node* sonHead = p->child;
            Node* sonTail = getTail(p->child);
            Node* ne = p->next;
            sonHead->prev = p;
            sonTail->next = ne;
            p->next = sonHead;
            if (ne != NULL) {
                ne->prev = sonTail;
            }
            p->child = NULL;
            //ERROR p = ne;
            p = p->next;
        }
        return head;
    }


};
// @lc code=end

/*
Wrong Answer
20/26 cases passed (N/A)
Testcase
[1,null,2,null,3,null]
Answer
The linked list [1] is not a valid doubly linked list.
Expected Answer
[1,2,3]

*/


/*
skill
关键在于DFS时尾节点怎么处理
M1 DFS返回的是head节点，要拿到尾节点，再次通过getTail函数遍历，性能地下

M2   DFS返回的是pair<head,tail>， pair.second就是尾节点，省去了getTail函数

M3 借鉴官方解法： DFS返回的就是tail节点， head节点不用返回，因为 p->child就是递归入口，在当前上下文下，p就是head节点


M4
非DFS，遇到child直接展开，接上去


*/


/*
M3
Runtime Error
7/26 cases passed (N/A)
Error
Line 112: Char 17: runtime error: member access within null pointer of type 'Node' (solution.cpp)
Line 112: Char 17: runtime error: member access within null pointer of type 'Node' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:168:17
Testcase
[1,null,2,null,3,null]
Expected Answer
[1,2,3]


Wrong Answer
20/26 cases passed (N/A)
Testcase
[1,null,2,null,3,null]
Answer
[1,2]
Expected Answer
[1,2,3]

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
