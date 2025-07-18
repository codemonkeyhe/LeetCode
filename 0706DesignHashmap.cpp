/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-13
 * @tag design,hashTable
 * @similar  705,706,1206
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 *
 * https://leetcode.cn/problems/design-hashmap/description/
 *
 * algorithms
 * Easy (65.08%)
 * Likes:    451
 * Dislikes: 0
 * Total Accepted:    127.4K
 * Total Submissions: 195.6K
 * Testcase Example:  '["MyHashMap","put","put","get","get","put","get","remove","get"]\n' +
  '[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
 *
 * 实现 MyHashMap 类：
 * MyHashMap() 用空映射初始化对象
 * void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key
 * 已经存在于映射中，则更新其对应的值 value 。
 * int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
 * void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
 *
 *
 *
 *
 * 示例：
 * 输入：
 * ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
 * [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
 * 输出：
 * [null, null, null, 1, -1, null, 1, null, -1]
 *
 * 解释：
 * MyHashMap myHashMap = new MyHashMap();
 * myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
 * myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
 * myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
 * myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
 * myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
 * myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
 * myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
 * myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
 *
 *
 *
 *
 * 提示：
 * 0 <= key, value <= 10^6
 * 最多调用 10^4 次 put、get 和 remove 方法
 *
 *
 */

// @lc code=start
class MyHashMap {
  public:
    const static int base = 1021;

    const static int hashFun(int key) { return key % base; }

    MyHashMap() { hmap.resize(base); }

    void put(int key, int value) {
        int idx = hashFun(key);
        auto &bucket = hmap[idx];
        for (auto &[k, v] : bucket) {
            if (k == key) {
                v = value;
                return;
            }
        }
        // not exist
        bucket.push_back(make_pair(key, value));
    }

    int get(int key) {
        int idx = hashFun(key);
        auto &bucket = hmap[idx];
        for (auto &[k, v] : bucket) {
            if (k == key) {
                return v;
            }
        }
        return -1;
    }

    void remove(int key) {
        int idx = hashFun(key);
        auto &bucket = hmap[idx];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    vector<list<pair<int, int>>> hmap;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
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


