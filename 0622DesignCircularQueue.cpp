/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-11
 * @tag  design,queue
 * @similar  622, 641, 1670
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 *
 * https://leetcode.cn/problems/design-circular-queue/description/
 *
 * algorithms
 * Medium (46.50%)
 * Likes:    565
 * Dislikes: 0
 * Total Accepted:    164.3K
 * Total Submissions: 349.9K
 * Testcase Example:  '["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]\n' +
  '[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于
 * FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
 *
 *
 * 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
 * 你的实现应该支持如下操作：
 * MyCircularQueue(k): 构造器，设置队列长度为 k 。
 * Front: 从队首获取元素。如果队列为空，返回 -1 。
 * Rear: 获取队尾元素。如果队列为空，返回 -1 。
 * enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 * deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 * isEmpty(): 检查循环队列是否为空。
 * isFull(): 检查循环队列是否已满。
 *
 *
 *
 *
 * 示例：
 * MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
 * circularQueue.enQueue(1);  // 返回 true
 * circularQueue.enQueue(2);  // 返回 true
 * circularQueue.enQueue(3);  // 返回 true
 * circularQueue.enQueue(4);  // 返回 false，队列已满
 * circularQueue.Rear();  // 返回 3
 * circularQueue.isFull();  // 返回 true
 * circularQueue.deQueue();  // 返回 true
 * circularQueue.enQueue(4);  // 返回 true
 * circularQueue.Rear();  // 返回 4
 *
 *
 *
 * 提示：
 * 所有的值都在 0 至 1000 的范围内；
 * 操作数将在 1 至 1000 的范围内；
 * 请不要使用内置的队列库。
 *
 *
 */

// @lc code=start
class MyCircularQueueM1 {
public:
    MyCircularQueueM1(int k) {
        cap = k;
        vc.resize(cap);
        head = 0;
        tail = 0;
        cnt = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        vc[tail] = value;
        tail = (tail + 1) % cap;
        cnt++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % cap;
        cnt--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return vc[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        if (tail == 0) {
            return vc[cap-1];
        }
        return vc[tail-1];
    }

    bool isEmpty() {
        if (tail == head && (cnt==0)) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (tail == head && (cnt==cap)) {
            return true;
        }
        return false;
    }

    vector<int> vc;
    int cnt;
    int cap;
    int head;
    int tail;

};



class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        cap = k+1;
        vc.resize(cap);
        head = 0;
        tail = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        vc[tail] = value;
        tail = (tail + 1) % cap;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) % cap;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return vc[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        if (tail == 0) {
            return vc[cap-1];
        }
        return vc[tail-1];
    }

    bool isEmpty() {
        return (tail == head);
    }

    bool isFull() {
        return ((tail+1)%cap == head);
    }

    vector<int> vc;
    int cap;
    int head;
    int tail;
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

/*
tail指向下一个插入位置

M1 使用计数器来区分 isFull和isEmpty
M2 保留一个位置来区分空和满
k=3时， VC的size=4，其中vc[3]不使用
isEmpty  head=tail
isFull  head=0 tail=3, (tail+1) %4 = head
0 1 2 3
A B C X
deque后 ,head=1, tail=3，再enQue(D)，如下
t = 0, h=1   (tail+1)%4==head，此时 vc[0]不使用
t h
0 1 2 3
X B C D


size=4
h
0 1 2 3
A B C D
t t t t
Case0 h=0 t=0  h==t  isEmpty=true
vc[0] = A  t=1
vc[1] = B  t=2
vc[2] = C  t=3
vc[3] = D  t=4%4=0=h   t指向下一个插入的位置
Case1 h=0 t=4    (tail)%4=0   isFull = true
无法区分 isEmpty和isFull

引入cap和cnt两个概念
cap=size=4
cnt表示当前数目
当h==t时，cnt=0表示empty cnt=cap时，表示full


deQueue  h++  h=1  t=0

Case2



Wrong Answer
46/59 cases passed (N/A)
Testcase
["MyCircularQueue","enQueue","Rear","Rear","deQueue","enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
' +
  '[[6],[6],[],[],[],[5],[],[],[],[],[],[]]
Answer
[null,true,6,6,true,true,5,true,0,false,false,false]
Expected Answer
[null,true,6,6,true,true,5,true,-1,false,false,false]
Stdout
Enque OK, cnt=1
REAR tail=1
REAR tail=1
deQUE OK, cnt=0
Enque OK, cnt=1
REAR tail=2
deQUE OK, cnt=0
FRONT head=2


*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


