/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-25
 * @tag   hashTable,doublyLinkedList
 * @similar  146, 460
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 *
 * https://leetcode.cn/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (47.32%)
 * Likes:    885
 * Dislikes: 0
 * Total Accepted:    100.9K
 * Total Submissions: 207.8K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * 请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。
 *
 * 实现 LFUCache 类：
 *
 *
 * LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
 * int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
 * void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量
 * capacity 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最久未使用
 * 的键。
 *
 *
 * 为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。
 * 当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 *
 *
 *
 * 示例：
 * 输入：
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * 输出：
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 *
 * 解释：
 * // cnt(x) = 键 x 的使用计数
 * // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
 * LFUCache lfu = new LFUCache(2);
 * lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
 * lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 * lfu.get(1);      // 返回 1
 * ⁠                // cache=[1,2], cnt(2)=1, cnt(1)=2
 * lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
 * ⁠                // cache=[3,1], cnt(3)=1, cnt(1)=2
 * lfu.get(2);      // 返回 -1（未找到）
 * lfu.get(3);      // 返回 3
 * ⁠                // cache=[3,1], cnt(3)=2, cnt(1)=2
 * lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
 * ⁠                // cache=[4,3], cnt(4)=1, cnt(3)=2
 * lfu.get(1);      // 返回 -1（未找到）
 * lfu.get(3);      // 返回 3
 * ⁠                // cache=[3,4], cnt(4)=1, cnt(3)=3
 * lfu.get(4);      // 返回 4
 * ⁠                // cache=[3,4], cnt(4)=2, cnt(3)=3
 *
 *
 *
 * 提示：
 * 1 <= capacity <= 10^4
 * 0 <= key <= 10^5
 * 0 <= value <= 10^9
 * 最多调用 2 * 10^5 次 get 和 put 方法
 *
 *
 */

// @lc code=start

struct DNode {
    int key;
    int val;
    int freq;

    DNode* prev;
    DNode* next;

    DNode() : key(0), val(0), freq(0), prev(NULL), next(NULL) {}

    DNode(int k, int v) : key(k), val(v), freq(1), prev(NULL), next(NULL) {}
};


class LFUCache1 {
public:
    LFUCache1(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (key2val.count(key)) {
            auto* pn = key2val[key];
            int oldFreq = pn->freq;
            pn->freq++;
            // del from oldFreq
            pn->prev->next = pn->next;
            pn->next->prev = pn->prev;
            pn->prev = NULL;
            pn->next = NULL;
            DNode* oldHead = freq2list[oldFreq];
            if (oldHead->next == oldHead->prev) { // means oldFreq empty
                if (oldFreq == minFreq) {
                    minFreq++;
                }
            }

            // add to newFreq
            if (freq2list.count(pn->freq) == 0) {
                DNode *dummyHead = new DNode();
                DNode* dummyTail = new DNode();
                dummyHead->next = dummyTail;
                dummyHead->prev = dummyTail;
                dummyTail->prev = dummyHead;
                freq2list[pn->freq] = dummyHead;
            }
            DNode* head = freq2list[pn->freq];
            pn->next = head->next;
            head->next->prev = pn;
            head->next = pn;
            pn->prev = head;
            return pn->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (key2val.count(key)) { // update
            auto* pn = key2val[key];
            pn->val = value;
            int oldFreq = pn->freq;
            pn->freq++;
            // del from oldFreq
            pn->prev->next = pn->next;
            pn->next->prev = pn->prev;
            DNode* oldHead = freq2list[oldFreq];
            if (oldHead->next == oldHead->prev) { // means oldFreq empty
                if (oldFreq == minFreq) {
                    minFreq++;
                }
            }

            // add to newFreq
            if (freq2list.count(pn->freq) == 0) {
                DNode* dummyHead = new DNode();
                DNode* dummyTail = new DNode();
                dummyHead->next = dummyTail;
                dummyHead->prev = dummyTail;
                dummyTail->prev = dummyHead;
                freq2list[pn->freq] = dummyHead;
            }
            DNode* head = freq2list[pn->freq];
            pn->next = head->next;
            head->next->prev = pn;
            head->next = pn;
            pn->prev = head;
            return;
        }

        // insert
        if (key2val.size() >= cap) {
            // delete one
            DNode* dh = freq2list[minFreq];
            DNode* tail  = dh->prev;
            DNode* node = tail->prev;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            if (tail->prev == dh) { // means empty
                // no need to do with minFreq as it will set to 1
            }
            key2val.erase(node->key);

        }

        minFreq = 1;
        DNode* pn = new DNode(key, value);
        key2val[key] = pn;
        if (freq2list.count(1) == 0) {
            DNode *dummyHead = new DNode();
            DNode *dummyTail = new DNode();
            dummyHead->next = dummyTail;
            dummyHead->prev = dummyTail;
            dummyTail->prev = dummyHead;
            freq2list[1] = dummyHead;
        }
        DNode *head = freq2list[1];
        pn->next = head->next;
        head->next->prev = pn;
        head->next = pn;
        pn->prev = head;
    }

    int cap;
    // int cnt;
    unordered_map<int, DNode*> key2val;
    unordered_map<int, DNode*> freq2list;
    int minFreq;
};



class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (key2val.count(key)) {
            auto* pn = key2val[key];
            // del from oldFreq
            delFromFreq(pn);

            // add to newFreq
            pn->freq++;
            addToFreq(pn);
            return pn->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (key2val.count(key)) { // update
            auto* pn = key2val[key];
            // del from oldFreq
            delFromFreq(pn);
            pn->val = value;
            pn->freq++;
            // add to newFreq
            addToFreq(pn);
            return;
        }

        // insert
        if (key2val.size() >= cap) {
            delOneLFU();
        }
        minFreq = 1;
        DNode* pn = new DNode(key, value);
        key2val[key] = pn;
        addToFreq(pn);
    }

    void delFromFreq(DNode *pn) {
        int oldFreq = pn->freq;
        pn->prev->next = pn->next;
        pn->next->prev = pn->prev;
        pn->prev = NULL;
        pn->next = NULL;
        DNode *oldHead = freq2list[oldFreq];
        if (oldHead->next == oldHead->prev) { // means oldFreq empty
            if (oldFreq == minFreq) {
                minFreq++;
            }
        }
    }

    void addToFreq(DNode *pn) {
        if (freq2list.count(pn->freq) == 0) {
            DNode *dummyHead = new DNode();
            DNode *dummyTail = new DNode();
            dummyHead->next = dummyTail;
            dummyHead->prev = dummyTail;
            dummyTail->prev = dummyHead;
            freq2list[pn->freq] = dummyHead;
        }
        DNode *head = freq2list[pn->freq];
        pn->next = head->next;
        head->next->prev = pn;
        head->next = pn;
        pn->prev = head;
    }

    // remove all delete , still works
    void delOneLFU() {
        // delete one
        DNode *dh = freq2list[minFreq];
        DNode *tail = dh->prev;
        DNode *node = tail->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        key2val.erase(node->key);
        delete node;
        if (tail->prev == dh) { // means empty
            // no need to do with minFreq as it will set to 1
            // can delete  list from freq2list
            freq2list.erase(minFreq);
            delete tail;
            delete dh;
        }
    }

    int cap;
    unordered_map<int, DNode*> key2val;
    unordered_map<int, DNode*> freq2list;
    int minFreq;
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


/*

原因： minFreq维护错误，当freq对应的列表为空时，还需要判定OldFreq==minFreq，才需要加1
        if (oldHead->next == oldHead->prev) { // means oldFreq empty
            if (oldFreq == minFreq) {
                minFreq++;
            }
        }


Wrong Answer
18/25 cases passed (N/A)
Testcase
["LFUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
' +
  '[[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]
Answer
[null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,14,null,null,18,null,null,11,null,null,null,null,null,18,null,null,24,null,4,29,30,null,12,11,null,null,null,null,29,null,null,null,null,17,22,18,null,null,null,24,null,null,null,20,null,null,null,-1,18,18,null,null,null,null,20,null,null,null,null,null,null,null]
Expected Answer
[null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,14,null,null,18,null,null,11,null,null,null,null,null,18,null,null,-1,null,4,29,30,null,12,11,null,null,null,null,29,null,null,null,null,17,-1,18,null,null,null,-1,null,null,null,20,null,null,null,29,18,18,null,null,null,null,20,null,null,null,null,null,null,null]
Stdout



*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
