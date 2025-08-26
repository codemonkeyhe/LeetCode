/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-26
 * @tag  linkedList
 * @similar  707, 1206
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 *
 * https://leetcode.cn/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (34.42%)
 * Likes:    1159
 * Dislikes: 0
 * Total Accepted:    410.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 你可以选择使用单链表或者双链表，设计并实现自己的链表。
 * 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
 * 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
 *
 * 实现 MyLinkedList 类：
 * MyLinkedList() 初始化 MyLinkedList 对象。
 * int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
 * void addAtHead(int val) 将一个值为 val
 * 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
 * void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
 * void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果
 * index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
 * void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 *
 *
 * 示例：
 * 输入
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
 * "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * 输出
 * [null, null, null, null, 2, null, 3]
 *
 * 解释
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
 * myLinkedList.get(1);              // 返回 2
 * myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
 * myLinkedList.get(1);              // 返回 3
 *
 *
 *
 *
 * 提示：
 * 0 <= index, val <= 1000
 * 请不要使用内置的 LinkedList 库。
 * 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。
 *
 *
 */

// @lc code=start

struct Node {
    int val;

    Node* next;
    Node* prev;

    Node(): val(0), next(NULL), prev(NULL) {}

    Node(int v): val(v), next(NULL), prev(NULL) {}
};


class MyLinkedList {
public:
    MyLinkedList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        head->prev = tail;
        tail->prev = head;
        maxIdx = -1; // XXX start from -1
    }

    int get(int index) {
        if (index < 0 || index > maxIdx) {
            return -1;
        }
        Node* p = head->next;
        while (index-- > 0) {
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val) {
        Node* pn = new Node(val);
        pn->next = head->next;
        pn->prev = head;
        head->next->prev = pn;
        head->next = pn;
        maxIdx++;
    }

    void addAtTail(int val) {
        Node* pn = new Node(val);
        pn->next = tail;
        pn->prev = tail->prev;
        tail->prev->next = pn;
        tail->prev = pn;
        maxIdx++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > maxIdx + 1) {
            return;
        }
        /* still work, no need to specialize
        if (index == maxIdx+1) { // can delete
            addAtTail(val);
            return;
        }
        */
        Node* pn = new Node(val);
        Node* p = head->next;
        while (index-- > 0) {
            p = p->next;
        }
        // insert before p
        pn->next = p;
        pn->prev = p->prev;
        p->prev->next = pn;
        p->prev = pn;
        maxIdx++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > maxIdx) {
            return;
        }
        Node* p = head->next;
        while (index-- > 0) {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        maxIdx--;
        delete p;
    }

    Node* head;
    Node* tail;
    int maxIdx;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
