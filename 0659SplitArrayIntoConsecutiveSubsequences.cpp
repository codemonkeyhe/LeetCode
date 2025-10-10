/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-10
 * @tag hashmap, greedy, heap
 * @similar
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 *
 * https://leetcode.cn/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (55.18%)
 * Likes:    489
 * Dislikes: 0
 * Total Accepted:    41.7K
 * Total Submissions: 74.9K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * 给你一个按 非递减顺序 排列的整数数组 nums 。
 * 请你判断是否能在将 nums 分割成 一个或多个子序列 的同时满足下述 两个 条件：
 *
 *
 * 每个子序列都是一个 连续递增序列（即，每个整数 恰好 比前一个整数大 1 ）。
 * 所有子序列的长度 至少 为 3 。
 *
 *
 * 如果可以分割 nums 并满足上述条件，则返回 true ；否则，返回 false 。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：nums = [1,2,3,3,4,5]
 * 输出：true
 * 解释：nums 可以分割成以下子序列：
 * [1,2,3,3,4,5] --> 1, 2, 3
 * [1,2,3,3,4,5] --> 3, 4, 5
 *
 *
 * 示例 2：
 * 输入：nums = [1,2,3,3,4,4,5,5]
 * 输出：true
 * 解释：nums 可以分割成以下子序列：
 * [1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
 * [1,2,3,3,4,4,5,5] --> 3, 4, 5
 *
 *
 * 示例 3：
 * 输入：nums = [1,2,3,4,4,5]
 * 输出：false
 * 解释：无法将 nums 分割成长度至少为 3 的连续递增子序列。
 *
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 * nums 按非递减顺序排列
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isPossibleM1(vector<int>& nums) {
        //int lastBox = 0;
        vector<vector<int>> box;
        unordered_map<int, set<int>> val2idx;
        for (auto num: nums) {
            if (val2idx.count(num) == 0) { // not pos
                box.push_back(vector<int>{num});
                int boxIdx = box.size()-1;
                val2idx[num+1].insert(boxIdx);
                continue;
            }

            auto& idxs = val2idx[num];
            int minLen  = 10001;
            int minBox = -1;
            for (auto idx : idxs) {
                if (box[idx].size() < minLen) {
                    minLen = box[idx].size();
                    minBox = idx;
                }
            }
            box[minBox].push_back(num);
            idxs.erase(minBox);
            if (idxs.size() == 0) {
                val2idx.erase(num);
            }
            val2idx[num+1].insert(minBox);
        }
        for (auto b : box) {
            if (b.size() < 3) {
                return false;
            }
        }
        return true;
    }

    // M2 only store box len, not need to put into box
    bool isPossibleM2(vector<int>& nums) {
        vector<int> box; // onle store box len
        unordered_map<int, set<int>> val2idx;
        for (auto num: nums) {
            if (val2idx.count(num) == 0) { // not pos
                // put num into boxIdx
                //box.push_back(vector<int>{num});
                box.push_back(1);
                int boxIdx = box.size()-1;
                val2idx[num+1].insert(boxIdx);
                continue;
            }
            auto& idxs = val2idx[num];
            int minLen  = 10001;
            int minBox = -1;
            for (auto idx : idxs) {
                if (box[idx] < minLen) {
                    minLen = box[idx];
                    minBox = idx;
                }
            }
            //box[minBox].push_back(num);
            box[minBox]++;
            idxs.erase(minBox);
            if (idxs.size() == 0) {
                val2idx.erase(num);
            }
            val2idx[num+1].insert(minBox);
        }
        for (auto b : box) {
            if (b < 3) {
                return false;
            }
        }
        return true;
    }

    // M3 no need to use box , put boxLen into hashmap
    bool isPossibleM3(vector<int> &nums) {
       // unordered_map<int, set<int>> val2len;
        unordered_map<int, multiset<int>> val2len;
        for (auto num: nums) {
            int prev = num - 1;
            if (val2len.count(prev) == 0) { // open a new seq
                // new seq: len =1
                val2len[num].insert(1);
             //   cout << "num=" << num << " size=1" << endl;
                continue;
            }
            // find the small len
            auto& allLen = val2len[prev];
            auto it = allLen.begin();
            int minLen = *it;
            val2len[prev].erase(it); //改为multiset后，只删除第一个
            //cout << "num=" << num << " oldLen=" << minLen << endl;
            if (val2len[prev].size() == 0) {
                val2len.erase(prev);
            }
            val2len[num].insert(minLen + 1);
        }

        for (auto &[v, lens] : val2len) {
            if (*lens.begin() < 3) {
                return false;
            }
        }
        return true;
    }

    // use minHeap to replace multiset
    bool isPossible(vector<int> &nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int> > > val2len;
        for (auto num: nums) {
            int prev = num - 1;
            if (val2len.count(prev) == 0) { // open a new seq
                // new seq: len =1
                val2len[num].push(1);
             //   cout << "num=" << num << " size=1" << endl;
                continue;
            }
            // find the small len
            auto& allLen = val2len[prev];
            int minLen = allLen.top();
            allLen.pop();
            if (allLen.size() == 0) {
                val2len.erase(prev);
            }
            val2len[num].push(minLen + 1);
        }

        for (auto &[v, lens] : val2len) {
            if (lens.top() < 3) {
                return false;
            }
        }
        return true;
    }


};
// @lc code=end

/*

用set<int>存储长度不对，因为可能存在多个长度相同的值，被set去重了
比如
1,2,3,3,3,3,
val=3, set<int>的长度为 3，1，1，1，用multiset可以解决

Wrong Answer
181/187 cases passed (N/A)
Testcase
[1,2,3,5,5,6,7]
Answer
true
Expected Answer
false

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
