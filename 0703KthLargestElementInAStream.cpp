/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-12
 * @tag design, priorityQueue
 * @similar 295, 480, 703
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (52.64%)
 * Likes:    504
 * Dislikes: 0
 * Total Accepted:    110.4K
 * Total Submissions: 207.8K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n' +
  '[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * 设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
 *
 * 请实现 KthLargest 类：
 * KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
 * int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
 *
 *
 *
 *
 * 示例 1：
 * 输入：
 * ["KthLargest", "add", "add", "add", "add", "add"]
 * [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
 * 输出：[null, 4, 5, 5, 8, 8]
 *
 * 解释：
 *
 * KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
 * kthLargest.add(3); // 返回 4
 * kthLargest.add(5); // 返回 5
 * kthLargest.add(10); // 返回 5
 * kthLargest.add(9); // 返回 8
 * kthLargest.add(4); // 返回 8
 *
 *
 *
 *
 * 示例 2：
 * 输入：
 * ["KthLargest", "add", "add", "add", "add"]
 * [[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
 * 输出：[null, 7, 7, 7, 8]
 *
 * 解释：
 * KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
 * kthLargest.add(2); // 返回 7
 * kthLargest.add(10); // 返回 7
 * kthLargest.add(9); // 返回 7
 * kthLargest.add(9); // 返回 8
 *
 *
 * 提示：
 * 0 <= nums.length <= 10^4
 * 1 <= k <= nums.length + 1
 * -10^4 <= nums[i] <= 10^4
 * -10^4 <= val <= 10^4
 * 最多调用 add 方法 10^4 次
 *
 *
 */

// @lc code=start

class MinHeap {
public:
    MinHeap() { }

    bool empty() { return vc.empty(); }

    int top() { return vc[0]; }

    int size() { return vc.size(); }

    void pop() {
        vc[0] = vc.back();
        vc.pop_back();
        heapAdjustDown(0, vc.size());
    }

    void push(int val) {
        vc.push_back(val);
        heapAdjustUp(vc.size() - 1);
    }

    // i为新节点，从i开始往下调整堆 i = [0, len-1]
    void heapAdjustDown(int i, int len) {
        int cur = vc[i];
        int pa = i;
        int son = 2 * pa + 1;
        while (son < len) {
            if (son + 1 < len && (vc[son] > vc[son + 1])) {
                son++; //
            }
            if (cur <= vc[son]) {  // no need to swap
                break;
            }
            vc[pa] = vc[son]; //son go up
            pa = son;
            son = 2 * son + 1;
        }
        vc[pa] = cur;
    }

    // i为新节点，从i开始往上调整堆
    void heapAdjustUp(int i) {
        int cur = vc[i];
        int son = i;
        int pa = (i - 1) / 2;
        while (pa >= 0 && son != 0) {
            if (cur >= vc[pa]) {  // no need to swap
                break;
            }
            vc[son] = vc[pa]; //parent go down
            son = pa;
            pa = (pa - 1) / 2;
        }
        vc[son] = cur;
    }

    vector<int> vc;
};



class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto& num: nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > _k) {
            minHeap.pop();
        }
        // size == k
        return minHeap.top();
    }

//    priority_queue<int, vector<int>, greater<int> > minHeap;
    MinHeap minHeap;

    int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
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


