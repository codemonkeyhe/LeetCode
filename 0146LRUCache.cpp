/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-03-25
 * @tag   hashTable,doublyLinkedList
 * @similar  146, 460
 */

/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4


提示：

1 <= capacity <= 3000
0 <= key <= 10000
0 <= value <= 105
最多调用 2 * 105 次 get 和 put

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
 public:
  int limit;
  unordered_map<int, DLinkedNode*> data;
  DLinkedNode* head;
  DLinkedNode* tail;

  LRUCache(int capacity) {
    limit = capacity;
    head = new DLinkedNode();
    tail = head;
  }

  int get(int key) {
    auto it = data.find(key);
    if (it != data.end()) {
      DLinkedNode* res = it->second;
      refreshNode(res);
      return res->value;
    }
    return -1;
  }

  void put(int key, int value) {
    auto it = data.find(key);
    if (it != data.end()) {
      DLinkedNode* res = it->second;
      res->value = value;
      refreshNode(res);
      return;
    }

    int curSize = data.size();
    if (curSize >= limit) {
      // removeHead();
      DLinkedNode* delN = head->next;
      if (delN->next != NULL) { // not tail
        head->next = delN->next;
        delN->next->prev = head;
      } else {
        head->next = NULL;
        tail = head;
      }
      data.erase(delN->key);
      delete delN;
    }

    DLinkedNode* newD = new DLinkedNode(key, value);
    addTail(newD);
    data.insert(make_pair(key, newD));
  }

  void refreshNode(DLinkedNode* in) {
    if (in == tail) {
      return;
    }
    // remove first
    in->prev->next = in->next;
    in->next->prev = in->prev;

    //  add second
    addTail(in);
  }

  void addTail(DLinkedNode* in) {
    tail->next = in;
    in->prev = tail;
    in->next = NULL;
    tail = in;
  }

  void PrintList() {
    auto cur = head->next;
    while(cur!=NULL) {
       cout << " [key="  << cur->key << " val=" << cur->value << "]";
       cur = cur->next;
    }
    cout << endl;
  }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  int capacity = 2;
  cout << "HELLO" << endl;
  LRUCache* obj = new LRUCache(2);
  LRUCache objv = *obj;
  objv.put(1, 1);  // 缓存是 {1=1}
  objv.put(2, 2);  // 缓存是 {1=1, 2=2}
  objv.get(1);     // 返回 1
  objv.put(3, 3);  // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  objv.get(2);     // 返回 -1 (未找到)
  objv.put(4, 4);  // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  objv.get(1);     // 返回 -1 (未找到)
  objv.get(3);     // 返回 3
  objv.get(4);     // 返回 4
  objv.PrintList();
}

/*
Tips
坑点
1  put存在时，依然要更新优先级
2  DlinkedNode的key是大部分时是多余的，当数量超过限制，淘汰时才用得着

M1

M2

Fail Case
["LRUCache","get","get","put","get","put","put","put","put","get","put"]
[[1],[6],[8],[12,1],[2],[15,11],[5,2],[1,15],[4,2],[5],[15,15]]


[12,1],
[15,11],
[5,2],


*/
