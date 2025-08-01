/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-19
 * @tag design
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
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 *
 * https://leetcode.cn/problems/design-hashset/description/
 *
 * algorithms
 * Easy (64.90%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    137K
 * Total Submissions: 210.9K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
 *
 * 实现 MyHashSet 类：
 *
 *
 * void add(key) 向哈希集合中插入值 key 。
 * bool contains(key) 返回哈希集合中是否存在这个值 key 。
 * void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 *
 *
 *
 * 示例：
 *
 *
 * 输入：
 * ["MyHashSet", "add", "add", "contains", "contains", "add", "contains",
 * "remove", "contains"]
 * [[], [1], [2], [1], [3], [2], [2], [2], [2]]
 * 输出：
 * [null, null, null, true, false, null, true, null, false]
 *
 * 解释：
 * MyHashSet myHashSet = new MyHashSet();
 * myHashSet.add(1);      // set = [1]
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(1); // 返回 True
 * myHashSet.contains(3); // 返回 False ，（未找到）
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(2); // 返回 True
 * myHashSet.remove(2);   // set = [1]
 * myHashSet.contains(2); // 返回 False ，（已移除）
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= key <= 10^6
 * 最多调用 10^4 次 add、remove 和 contains
 *
 *
 */

// @lc code=start

 class MyHashSet {
  public:
    const static int base = 1021;

    const static int hashFun(int key) {
        return key%base;
    }

    MyHashSet() {
        hs.resize(base);
    }

    void add(int key) {
        int idx = hashFun(key);
        auto& bucket = hs[idx];
        for (auto& k: bucket) {
            if (k == key) {
                return ;
            }
        }
        // not exist
        bucket.push_back(key);
    }

    bool contains(int key) {
        int idx = hashFun(key);
        auto& bucket = hs[idx];
        for (auto& k: bucket) {
            if (k == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int idx = hashFun(key);
        auto &bucket = hs[idx];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    vector<list<int> > hs;
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
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


