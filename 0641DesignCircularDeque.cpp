/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-29
 * @tag  linkedNode
 * @similar  622, 641
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 *
 * https://leetcode.cn/problems/design-circular-deque/description/
 *
 * algorithms
 * Medium (56.74%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    76.2K
 * Total Submissions: 134.8K
 * Testcase Example:  '["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]\n' +
  '[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * 设计实现双端队列。
 * 实现 MyCircularDeque 类:
 * MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
 * boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
 * boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
 * boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
 * boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
 * int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
 * int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
 * boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
 * boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。
 *
 *
 *
 *
 * 示例 1：
 * 输入
 * ["MyCircularDeque", "insertLast", "insertLast", "insertFront",
 * "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
 * [[3], [1], [2], [3], [4], [], [], [], [4], []]
 * 输出
 * [null, true, true, true, false, 2, true, true, true, 4]
 *
 * 解释
 * MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
 * circularDeque.insertLast(1);                    // 返回 true
 * circularDeque.insertLast(2);                    // 返回 true
 * circularDeque.insertFront(3);                    // 返回 true
 * circularDeque.insertFront(4);                    // 已经满了，返回 false
 * circularDeque.getRear();                  // 返回 2
 * circularDeque.isFull();                        // 返回 true
 * circularDeque.deleteLast();                    // 返回 true
 * circularDeque.insertFront(4);                    // 返回 true
 * circularDeque.getFront();                // 返回 4
 *
 *
 *
 *
 * 提示：
 * 1 <= k <= 1000
 * 0 <= value <= 1000
 * insertFront, insertLast, deleteFront, deleteLast, getFront, getRear,
 * isEmpty, isFull  调用次数不大于 2000 次
 */


// @lc code=start

struct DNode {
    int val;
    DNode *prev;
    DNode *next;
    DNode(int v): val(v), prev(nullptr), next(nullptr) { }

};



class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        size = 0;
        capacity = k;
        head = new DNode(-1);
        tail = new DNode(-2);
        head->next = tail;
        tail->prev = head;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        DNode* pn = new DNode(value);
        pn->next = head->next;
        pn->prev = head;
        pn->prev->next = pn;
        pn->next->prev = pn;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        DNode* pn = new DNode(value);
        pn->next = tail;
        pn->prev = tail->prev;
        pn->prev->next = pn;
        pn->next->prev = pn;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        DNode* pn = head->next;
        pn->prev->next = pn->next;
        pn->next->prev = pn->prev;
        // delete pn;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        DNode* pn = tail->prev;
        pn->prev->next = pn->next;
        pn->next->prev = pn->prev;
        // delete pn;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return head->next->val;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return tail->prev->val;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }


    DNode* head;
    DNode* tail;
    int capacity;
    int size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
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
