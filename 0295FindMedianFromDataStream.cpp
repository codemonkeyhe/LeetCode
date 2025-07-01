/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-01
 * @tag  priorityQueue,design,twoPointers
 * @similar 295,480
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode.cn/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (54.47%)
 * Likes:    1132
 * Dislikes: 0
 * Total Accepted:    223.7K
 * Total Submissions: 391.5K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
 * 例如 arr = [2,3,4] 的中位数是 3 。
 * 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
 *
 *
 * 实现 MedianFinder 类:
 * MedianFinder() 初始化 MedianFinder 对象。
 * void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
 * double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10^-5 以内的答案将被接受。
 *
 *
 *
 * 示例 1：
 * 输入
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * 输出
 * [null, null, null, 1.5, null, 2.0]
 *
 * 解释
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 * 提示:
 * -10^5 <= num <= 10^5
 * 在调用 findMedian 之前，数据结构中至少有一个元素
 * 最多 5 * 10^4 次调用 addNum 和 findMedian
 *
 *
 */


// @lc code=start
class MaxHeap {
public:
    MaxHeap() { }

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
        int p = i; // parent
        int j = 2 * p + 1; //leftSon
        while (j < len) {
            if (j + 1 < len && (vc[j] < vc[j + 1])) {
                j++; // j points to bigger one
            }
            if (cur >= vc[j]) {  // no need to swap
                break;
            }
            vc[p] = vc[j]; // son go up
            p = j;
            j = 2 * j + 1;
        }
        vc[p] = cur;
    }

    // i为新节点，从i开始往上调整堆
    void heapAdjustUp(int i) {
        int cur = vc[i];
        int j = i; //son
        int p = (i - 1) / 2; //parent
        while (p >= 0 && j != 0) {
            if (cur <= vc[p]) {  // no need to swap
                break;
            }
            vc[j] = vc[p]; // parent go down
            j = p;
            p = (p - 1) / 2;
        }
        vc[j] = cur;
    }

    vector<int> vc;
};


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
        int p = i; // parent
        int j = 2 * p + 1; // leftSon
        while (j < len) {
            if (j + 1 < len && (vc[j] > vc[j + 1])) {
                j++; // j points smaller one
            }
            if (cur <= vc[j]) {  // no need to swap
                break;
            }
            vc[p] = vc[j]; //son go up
            p = j;
            j = 2 * j + 1;
        }
        vc[p] = cur;
    }

    // i为新节点，从i开始往上调整堆
    void heapAdjustUp(int i) {
        int cur = vc[i];
        int j = i; //son
        int p = (i - 1) / 2; //parent
        while (p >= 0 && j != 0) {
            if (cur >= vc[p]) {  // no need to swap
                break;
            }
            vc[j] = vc[p]; //parent go down
            j = p;
            p = (p - 1) / 2;
        }
        vc[j] = cur;
    }

    vector<int> vc;
};

class MedianFinder {
public:
    MedianFinder() {
    }

    void addNumV1(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }
        if (num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        // balance
        int cntLow = maxHeap.size();
        int cntBig = minHeap.size();
        if (cntLow == cntBig || (cntLow == cntBig+1)) {
            return;
        }
            // not equal
        if (cntLow>cntBig) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    //代码简化，但是逻辑较为复杂
    void addNum(int num) {
        // balance
        int cntLow = maxHeap.size();
        int cntBig = minHeap.size();
        if (cntLow == cntBig) {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top())/2.0f;
        }
        // must cntLow  == cntBig+1
        return maxHeap.top();
    }

    MinHeap minHeap;
    MaxHeap maxHeap;

    //priority_queue<int, vector<int>, greater<int> > minHeap; // store bigger
   // priority_queue<int, vector<int>, less<int> > maxHeap; // store smaller
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
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


