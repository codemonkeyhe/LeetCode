/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-04
 * @tag   design, linkedList, hashMap
 * @similar   432, 460
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 *
 * https://leetcode.cn/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (46.43%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 71.3K
 * Testcase Example:  '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n' +
  '[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
 *
 * 实现 AllOne 类：
 * AllOne() 初始化数据结构的对象。
 * inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
 * dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key
 * 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
 * getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
 *
 *
 * 注意：每个函数都应当满足 O(1) 平均时间复杂度。
 *
 *
 *
 * 示例：
 * 输入
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * 输出
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 *
 * 解释
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "leet"
 *
 *
 *
 *
 * 提示：
 * 1 <= key.length <= 10
 * key 由小写英文字母组成
 * 测试用例保证：在每次调用 dec 时，数据结构中总存在 key
 * 最多调用 inc、dec、getMaxKey 和 getMinKey 方法 5 * 10^4 次
 *
 *
 */

// @lc code=start

struct SNode {
    int cnt;
    unordered_set<string> keys;
    SNode* prev;
    SNode* next;

    SNode(int c) {
        cnt = c;
        prev = NULL;
        next = NULL;
    }

};


class AllOne {
public:
    AllOne() {
        head = new SNode(-1);
        tail = new SNode(-1);
        head->next = tail;
        tail->prev = head;
    }

    void checkEmpty(SNode* cur) {
        if (cur->keys.size() == 0) { // need to del cur
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
    }

    void insertAfterCur(SNode *ne, SNode *cur) {
        ne->prev = cur;
        ne->next = cur->next;
        ne->prev->next = ne;
        ne->next->prev = ne;
    }

    void inc(string key) {
        if (keymap.count(key)) {
            SNode* cur = keymap[key];
            cur->keys.erase(key);
            int cnt = cur->cnt;
            if (cur->next->cnt != (cnt + 1)) {
                // new a sNode
                SNode* ne = new SNode(cnt+1);
                insertAfterCur(ne, cur);
                ne->keys.insert(key);
                keymap[key] = ne;
            }  else {
                SNode* ne = cur->next;
                ne->keys.insert(key);
                keymap[key] = ne;
            }
            checkEmpty(cur);

        } else { // not exist
            SNode *ne = NULL;
            if (head->next->cnt == 1) {
                ne = head->next;
            } else {
                ne = new SNode(1);
                insertAfterCur(ne, head);
            }
            ne->keys.insert(key);
            keymap[key] = ne;
        }
    }

    void dec(string key) {
        SNode* cur = keymap[key];
        cur->keys.erase(key);
        int cnt = cur->cnt;
        if (cnt > 1) {
            if (cur->prev->cnt != (cnt - 1)) {
                SNode *pr = new SNode(cnt - 1);
                pr->keys.insert(key);
                pr->prev = cur->prev;
                pr->next = cur;
                pr->prev->next = pr;
                pr->next->prev = pr;
                keymap[key] = pr;
            } else {
                SNode *pr = cur->prev;
                pr->keys.insert(key);
                keymap[key] = pr;
            }
        } else { //cnt == 1
            keymap.erase(key);
        }

        checkEmpty(cur);
    }

    string getMaxKey() {
        if (tail->prev == head) {
            return "";
        }
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) {
            return "";
        }
        return *(head->next->keys.begin());
    }

    unordered_map<string, SNode*> keymap;
    SNode* head;
    SNode* tail;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end


/*

RootCause:  desc对于cnt==1的元素 没处理好

Wrong Answer
22/24 cases passed (N/A)
Testcase
["AllOne","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","inc","dec","dec","dec","dec","dec","dec","inc","inc","inc","inc","getMaxKey","getMinKey","inc","inc","getMaxKey","getMinKey","inc","dec","getMaxKey","getMinKey"]
' +
  '[[],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],[],[],["k"],["l"],[],[],["a"],["j"],[],[]]
Answer
[null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,"i","l",null,null,"i","i",null,null,"a","j"]
Expected Answer
[null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,"i","k",null,null,"g","g",null,null,"g","a"]

*/


int main() {
    Solution s;
}


/*
Tips
和LFU460有区别，不能借鉴LFU460的解法，做不到O(1)时间维护minFreq
因为这一题有desc操作，当干掉最小的元素后，难以更新minFreq

多个不同的key，共用同一个Node, 从head到Tail的cnt从小到大，非连续增大

Head -> Node{cnt=1, keys{...}}
-> Node{cnt=4, keys{...}}
-> Node{cnt=100, keys{...}}
-> Tail

hashmap<string, Node*>  keymap;



M1

M2

*/
