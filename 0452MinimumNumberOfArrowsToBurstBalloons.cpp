/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-16
 * @tag greedy
 * @similar 300,435, 452
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 *
 * https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (51.50%)
 * Likes:    1100
 * Dislikes: 0
 * Total Accepted:    368.1K
 * Total Submissions: 694.9K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * 有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend]
 * 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。
 *
 * 一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足
 * xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
 *
 * 给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。
 *
 *
 * 示例 1：
 * 输入：points = [[10,16],[2,8],[1,6],[7,12]]
 * 输出：2
 * 解释：气球可以用2支箭来爆破:
 * -在x = 6处射出箭，击破气球[2,8]和[1,6]。
 * -在x = 11处发射箭，击破气球[10,16]和[7,12]。
 *
 * 示例 2：
 * 输入：points = [[1,2],[3,4],[5,6],[7,8]]
 * 输出：4
 * 解释：每个气球需要射出一支箭，总共需要4支箭。
 *
 * 示例 3：
 * 输入：points = [[1,2],[2,3],[3,4],[4,5]]
 * 输出：2
 * 解释：气球可以用2支箭来爆破:
 * - 在x = 2处发射箭，击破气球[1,2]和[2,3]。
 * - 在x = 4处射出箭，击破气球[3,4]和[4,5]。
 *
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= points.length <= 10^5
 * points[i].length == 2
 * -2^31 <= xstart < xend <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    static bool cmpFn(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        sort(points.begin(), points.end(), cmpFn);

        int rightP = points[0][1];
        int cnt = 1;
        for (int i = 1; i < len; i++) {
            auto& cur = points[i];
            if (cur[0] <= rightP) { // overlap
                continue;
            }
            rightP = cur[1];
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end


/*
和435几乎一样
LC435: 只在一点上接触的区间是 不重叠的
这一题，两个区间在一点上接触算是重叠，不用额外浪费一支箭



Case1 不相交
弓箭数  == 线段数

Case2 相交
[1,4]   [2, 7]   [6,8]  需要2只
[1,40]   [2, 7]   [6,8]  全覆盖，只需要1只

对于2个相交的线段，需要记录交集区间，然后如果下一个线段在交集区间内，则少一只剑





*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
