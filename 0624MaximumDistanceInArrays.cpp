/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-21
 * @tag  greedy
 * @similar
 */

/*
* @lc app=leetcode.cn id=624 lang=cpp
* [624]
* 给定 m 个数组，每个数组都已经按照升序排好序了。
*
* 现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数 a 和 b 之间的距离定义为它们差的绝对值 |a-b| 。
*
* 返回最大距离。
*
* 示例 1：
* 输入：[[1,2,3],[4,5],[1,2,3]]
* 输出：4
* 解释：
* 一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。

* 示例 2：
* 输入：arrays = [[1],[1]]
* 输出：0
*
*
* 提示：
* m == arrays.length
* 2 <= m <= 105
* 1 <= arrays[i].length <= 500
* -104 <= arrays[i][j] <= 104
* arrays[i] 以 升序 排序。
* 所有数组中最多有 105 个整数。

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int nlen = arrays.size();
        int minV = INT_MAX;
        int minIdx = -1;
        // BUG 可能是负数 int maxV = 0;
        int maxV = INT_MIN;
        int maxIdx = -1;
        for (int i = 0; i < nlen; i++) {
            auto& cur = arrays[i];
            if (cur[0] < minV) {
                minV = cur[0];
                minIdx = i;
            }
            if (cur.back() > maxV) {
                maxV = cur.back();
                maxIdx = i;
            }
        }
        if (maxIdx != minIdx) {
            return maxV - minV;
        }
        int minV2 = INT_MAX;
        int maxV2 = INT_MIN;
       for (int i = 0; i < nlen; i++) {
            if (i == minIdx ) {
                continue;
            }
            auto& cur = arrays[i];
            if (cur[0] < minV2) {
                minV2 = cur[0];
            }
            if (cur.back() > maxV2) {
                maxV2 = cur.back();
            }
        }
        int ans1 = maxV2 - minV;
        int ans2 = maxV - minV2;
        return max(ans1, ans2);
    }


    int maxDistanceM2(vector<vector<int>>& arrays) {
        int nlen = arrays.size();
        int minV = 100000;
        int maxV = -100000;
        int res = 0;
        for (int i = 0; i < nlen; i++) {
            auto& cur = arrays[i];
            int res1 = maxV - cur.front();
            int res2 = cur.back() - minV;
            res = max({res, res1, res2});
            minV = min(minV, cur.front());
            maxV = max(maxV, cur.back());
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


/*
* @golang

func maxDistance(arrays [][]int) int {
    nLen := len(arrays)
    maxV := -100000
    minV := 100000
    res := 0
    for i := 0; i < nLen; i++ {
        cur := arrays[i]
        cLen := len(cur)
        res1 := maxV - cur[0]
        res2 := cur[cLen-1] - minV
        res = max(res, max(res1, res2))
        minV = min(minV, cur[0])
        maxV = max(maxV, cur[cLen-1])
    }
    return res
}

*/