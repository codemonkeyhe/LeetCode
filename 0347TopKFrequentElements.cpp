/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-21
 * @tag  sort,quickSelect,heapSort
 * @similar 215, 347, 692
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.64%)
 * Likes:    1822
 * Dislikes: 0
 * Total Accepted:    541.8K
 * Total Submissions: 851.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 * 1 <= nums.length <= 105
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 *
 */


// @lc code=start
class CmpFun2 {
    public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
};


class Solution {
public:
    //greater
    static bool cmpFn(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }

    vector<int> topKFrequentM1(vector<int>& nums, int k) {
        unordered_map<int, int> num2cnt;
        for (auto& num: nums) {
            num2cnt[num]++;
        }

        vector<int> res;

        // M1
        //priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&cmpFn)> minHeap(cmpFn);

        // M2
        //priority_queue<pair<int, int>, vector<pair<int, int> >, CmpFun2> minHeap;

        auto cmpFn3 = [](pair<int, int>& a, pair<int, int>& b) -> bool {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmpFn3)> minHeap;

        for (auto& [num, cnt]: num2cnt) {
            if (minHeap.size() < k) {
                minHeap.push(make_pair(cnt, num));
                continue;
            }
            // size >=k
            int topV = minHeap.top().first;
            if (cnt <= topV) {
                continue;
            }
            minHeap.pop();
            minHeap.push(make_pair(cnt, num));
        }
        while(!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }

   int partitions(vector<pair<int, int> >& a, int low, int high) {
        int pivot = a[low].first;
        int i = low;
        int j = high;
        while (i < j) {
            // 从右往左找到第一个小于pivot的值的下标
            while (i < j && a[j].first >= pivot)
                --j;
            // 从左往右找到第一个大于pivot的值的下标
            while (i < j && a[i].first <= pivot)
                ++i;
            if (i < j) {
                swap(a[i], a[j]);
            }
        }
        swap(a[low], a[i]);
        return i;
    }

    // 核心点， 第K大的元素归到leftPart来覆盖
    // 每次必须 pivot+-1，保证边界缩小，不会死循环
    void topK(vector<pair<int, int> >& nums, int low, int high, int k, vector<int>& res) {
        int pivot = partitions(nums, low, high);
        int order = high - pivot;
        if (order >= k) { // to right
            topK(nums, pivot + 1, high, k, res);
        } else { // to left,
            // cover right part
            for (int i = pivot; i <= high; i++) {
                res.push_back(nums[i].second);
            }
            if (k > order + 1) { // key step
                topK(nums, low, pivot - 1, k - order - 1, res);
            }
        }
    }


    vector<int> topKFrequentM2(vector<int>& nums, int k) {
        unordered_map<int, int> num2cnt;
        for (auto& num: nums) {
            num2cnt[num]++;
        }

        vector<pair<int, int> > nodes;
        for (auto& [num, cnt]: num2cnt) {
            nodes.push_back(make_pair(cnt, num));
        }

        vector<int> res;
        topK(nodes, 0, nodes.size()-1, k, res);
        return res;
    }


    // minHeap优化版，不用和小根队堆顶比较，直接pop n-k次，把前面小的清理掉，后面剩余的就是k大,和 LC 215类似
    /*
    核心点：
    假设n=100,k=3
    数组排序后，第1大 k=1的元素就是n[99]
    数组排序后，第2大 k=2的元素就是n[98]
    数组排序后，第3大 k=3的元素就是n[97]
    minHeap小根堆大小为3， 先放入3个元素，这3个元素要么比 n[97-99]小，要么就是n[97-99]
    接下来放入第4个元素，然后 minHeap.size=4> k，需要pop一个，pop是4个元素的最小值，
    这个最小值必然不是n[97-99],因为他们是nums数组里前3大的， 必然不是第4小，否则就矛盾了。
    因此，每次都是pop第4小的元素，总共执行了 100-4+1 = 97次，剩余的3个元素，就是前k大的

    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2cnt;
        for (auto& num: nums) {
            num2cnt[num]++;
        }

        vector<int> res;

        auto cmpFn3 = [](pair<int, int>& a, pair<int, int>& b) -> bool {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmpFn3)> minHeap;

        for (auto& [num, cnt]: num2cnt) {
            minHeap.push(make_pair(cnt, num));
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        while(!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }

};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


