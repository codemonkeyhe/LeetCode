/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-14
 * @tag matrix,math
 * @similar  836
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 *
 * https://leetcode.cn/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (54.14%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    68.6K
 * Total Submissions: 126K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * 给你 二维 平面上两个 由直线构成且边与坐标轴平行/垂直 的矩形，请你计算并返回两个矩形覆盖的总面积。
 *
 * 每个矩形由其 左下 顶点和 右上 顶点坐标表示：
 * 第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
 * 第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
 * 输出：45
 *
 *
 * 示例 2：
 * 输入：ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 =  2
 * 输出：16
 *
 *
 *
 *
 * 提示：
 * -10^4 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int leftX = max(ax1, bx1);
        int rightX = min(ax2, bx2);
        int upY = min(ay2, by2);
        int downY = max(ay1, by1);
        int shareArea = 0;
        if (rightX > leftX && (upY > downY)) {
            // 不相交时，坐标不合法
            shareArea = (rightX - leftX) * (upY - downY);
        }
        return squArea(ax1, ay1, ax2, ay2) + squArea(bx1, by1, bx2, by2)-shareArea;
    }

    // leftDown (x1,y1 )  rightUp(x2,y2)
    int squArea(int x1, int y1, int x2, int y2) {
        return (x2-x1) * (y2-y1);
    }

};
// @lc code=end

/*
Wrong Answer
两个矩形不想交

2351/3080 cases passed (N/A)
Testcase
-2
-2
2
2
3
3
4
4
Answer
16
Expected Answer
17

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


