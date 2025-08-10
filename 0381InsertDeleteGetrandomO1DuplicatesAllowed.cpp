/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-10
 * @tag  randomized
 * @similar  380, 381, 470
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 *
 * https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (41.77%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    31.5K
 * Total Submissions: 75.8K
 * Testcase Example:  '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n' +
  '[[],[1],[1],[2],[],[1],[]]'
 *
 * RandomizedCollection 是一种包含数字集合(可能是重复的)的数据结构。它应该支持插入和删除特定元素，以及删除随机元素。
 *
 * 实现 RandomizedCollection 类:
 * RandomizedCollection()初始化空的 RandomizedCollection 对象。
 * bool insert(int val) 将一个 val 项插入到集合中，即使该项已经存在。如果该项不存在，则返回 true ，否则返回 false 。
 * bool remove(int val) 如果存在，从集合中移除一个 val 项。如果该项存在，则返回 true ，否则返回 false 。注意，如果
 * val 在集合中出现多次，我们只删除其中一个。
 * int getRandom() 从当前的多个元素集合中返回一个随机元素。每个元素被返回的概率与集合中包含的相同值的数量 线性相关 。
 *
 *
 * 您必须实现类的函数，使每个函数的 平均 时间复杂度为 O(1) 。
 * 注意：生成测试用例时，只有在 RandomizedCollection 中 至少有一项 时，才会调用 getRandom 。
 *
 *
 *
 * 示例 1:
 * 输入
 * ["RandomizedCollection", "insert", "insert", "insert", "getRandom",
 * "remove", "getRandom"]
 * [[], [1], [1], [2], [], [1], []]
 * 输出
 * [null, true, false, true, 2, true, 1]
 *
 * 解释
 * RandomizedCollection collection = new RandomizedCollection();// 初始化一个空的集合。
 * collection.insert(1);   // 返回 true，因为集合不包含 1。
 * ⁠                       // 将 1 插入到集合中。
 * collection.insert(1);   // 返回 false，因为集合包含 1。
 * // 将另一个 1 插入到集合中。集合现在包含 [1,1]。
 * collection.insert(2);   // 返回 true，因为集合不包含 2。
 * // 将 2 插入到集合中。集合现在包含 [1,1,2]。
 * collection.getRandom(); // getRandom 应当:
 * // 有 2/3 的概率返回 1,
 * // 1/3 的概率返回 2。
 * collection.remove(1);   // 返回 true，因为集合包含 1。
 * // 从集合中移除 1。集合现在包含 [1,2]。
 * collection.getRandom(); // getRandom 应该返回 1 或 2，两者的可能性相同。
 *
 *
 *
 * 提示:
 * -2^31 <= val <= 2^31 - 1
 * insert, remove 和 getRandom 最多 总共 被调用 2 * 10^5 次
 * 当调用 getRandom 时，数据结构中 至少有一个 元素
 *
 *
 */

// @lc code=start

class RandomizedCollection2Bugs {
public:

    bool insert(int val) {
        bool res = false;
        if (v2idx.count(val) == 0) {
            res = true;
        }
        v2idx[val].insert(nums.size());
        nums.push_back(val);
        return res;
    }

    bool remove(int val) {
        if (v2idx.count(val) == 0) {
            return false;
        }
        auto& idxs = v2idx[val];
        if (idxs.size()==0) {
            return false;
        }
        int idx = *idxs.begin();
        int last = nums.back();
        int lastIdx = nums.size() - 1;

        //XXX BUG2 when lastIdx == idx
        nums[idx] = last;
        nums.pop_back();
        // last change from  lastIdx to idx
        v2idx[last].erase(lastIdx);
        v2idx[last].insert(idx);

        //XXX BUG1
        idxs.erase(idx);
        if (idxs.size() == 0) {
            v2idx.erase(val);
        }
        return true;
    }

    int getRandom() {
        int len = nums.size();
        int idx = rand() % len;
        return nums[idx];
    }

    vector<int> nums;
    unordered_map<int, unordered_set<int>> v2idx;

};


class RandomizedCollection {
public:
    RandomizedCollection() {
        srand(time(NULL));
    }

    bool insert(int val) {
        bool res = false;
        if (v2idx.count(val) == 0) {
            res = true;
        }
        v2idx[val].insert(nums.size());
        nums.push_back(val);
        return res;
    }

    bool remove(int val) {
        if (v2idx.count(val) == 0) {
            return false;
        }
        auto& idxs = v2idx[val];
        if (idxs.size()==0) {
            return false;
        }
        int idx = *idxs.begin();
        int last = nums.back();
        int lastIdx = nums.size() - 1;
        if (lastIdx == idx) {
            nums.pop_back();
            idxs.erase(idx);
        } else {
            nums.pop_back();
            idxs.erase(idx);
            nums[idx] = last;
            // last change from  lastIdx to idx
            v2idx[last].erase(lastIdx);
            v2idx[last].insert(idx);
        }

        if (idxs.size() == 0) {
            v2idx.erase(val);
        }
        return true;
    }

    int getRandom() {
        int idx = rand() % (nums.size());
        return nums[idx];
    }

    vector<int> nums;
    unordered_map<int, unordered_set<int>> v2idx;

};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

/*

Wrong Answer
30/32 cases passed (N/A)
Testcase
["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
' +
  '[[],[1],[1],[2],[1],[2],[2],[1],[2],[2],[2],[],[],[],[],[],[],[],[],[],[]]
Answer
[null,true,false,true,false,false,false,true,true,true,false,2,1,1,1,1,1,1,2,1,1]
Expected Answer
[null,true,false,true,false,false,false,true,true,true,true,1,1,1,1,1,1,1,1,1,1]



Wrong Answer
["RandomizedCollection","insert","remove","insert"]
[[],[1],[1],[1]]
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
