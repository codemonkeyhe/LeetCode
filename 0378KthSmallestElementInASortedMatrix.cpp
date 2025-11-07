/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-07
 * @tag   priorityQueue
 * @similar  373, 378
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 *
 * https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (63.78%)
 * Likes:    1054
 * Dislikes: 0
 * Total Accepted:    135.2K
 * Total Submissions: 212K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * 给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
 * 请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。
 * 你必须找到一个内存复杂度优于 O(n^2) 的解决方案。
 *
 *
 *
 * 示例 1：
 * 输入：matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * 输出：13
 * 解释：矩阵中的元素为 [1,5,9,10,11,12,13,13,15]，第 8 小元素是 13
 *
 *
 * 示例 2：
 * 输入：matrix = [[-5]], k = 1
 * 输出：-5
 *
 *
 *
 *
 * 提示：
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * 题目数据 保证 matrix 中的所有行和列都按 非递减顺序 排列
 * 1 <= k <= n^2
 *
 *
 *
 *
 * 进阶：
 * 你能否用一个恒定的内存(即 O(1) 内存复杂度)来解决这个问题?
 * 你能在 O(n) 的时间复杂度下解决这个问题吗?这个方法对于面试来说可能太超前了，但是你会发现阅读这篇文章（ this paper ）很有趣。
 *
 *
 */

// @lc code=start

struct Node{
    int val;
    int x;
    int y;

    Node(int v, int i, int j) {
        val = v;
        x = i;
        y = j;
    }

};

struct cmpST {
    bool operator()(Node &a, Node &b) {
        return a.val > b.val;
     }
};

class Solution {
  public:

    bool greaterFn(Node &a, Node &b) {
        if (a.val > b.val) {
            return true;
        }
        return false;
    }

    // M1 struct Node
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // ERROR
        // priority_queue<Node, vector<Node>, greaterFn> minHeap;
        priority_queue<Node, vector<Node>, cmpST> minHeap;

        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++) {
            Node no(matrix[i][0], i, 0);
            minHeap.push(no);
        }

        int cnt = 0;
        while (cnt <= k) {
            if (minHeap.empty()) {
                break;
            }
            auto cur = minHeap.top();
            minHeap.pop();
            cnt++;
            if (cnt == k) {
                return cur.val;
            }
            int r = cur.x;
            int c = cur.y + 1;
            if (c < col) {
                Node no(matrix[r][c], r, c);
                minHeap.push(no);
            }
        }
        return 0;
    }


    // M2 tuple
    int kthSmallestM2(vector<vector<int>> &matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++) {
            tuple tu(matrix[i][0], i, 0);
           // auto tu = make_tuple(matrix[i][0], i, 0);
            minHeap.push(tu);
        }

        int cnt = 0;
        while (cnt <= k) {
            if (minHeap.empty()) {
                break;
            }
            auto cur = minHeap.top();
            minHeap.pop();
            cnt++;
            if (cnt == k) {
                return get<0>(cur);
            }
            int r = get<1>(cur);
            int c = get<2>(cur) + 1;
            if (c < col) {
            //    tuple tu(matrix[r][c], r, c);
                auto tu = make_tuple(matrix[r][c], r, c);
                minHeap.push(tu);
            }
        }
        return 0;
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
