/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-19
 * @tag math,trick
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
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 *
 * https://leetcode.cn/problems/rectangle-overlap/description/
 *
 * algorithms
 * Easy (49.51%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    55.7K
 * Total Submissions: 111.8K
 * Testcase Example:  '[0,0,2,2]\n[1,1,3,3]'
 *
 * 矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。矩形的上下边平行于
 * x 轴，左右边平行于 y 轴。
 *
 * 如果相交的面积为 正 ，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
 *
 * 给出两个矩形 rec1 和 rec2 。如果它们重叠，返回 true；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 * 输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
 * 输出：true
 *
 *
 * 示例 2：
 * 输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
 * 输出：false
 *
 *
 * 示例 3：
 * 输入：rec1 = [0,0,1,1], rec2 = [2,2,3,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 * rect1.length == 4
 * rect2.length == 4
 * -10^9 <= rec1[i], rec2[i] <= 10^9
 * rec1 和 rec2 表示一个面积不为零的有效矩形
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int& x1 = rec1[0];
        int& y1 = rec1[1];
        int& x2 = rec1[2];
        int& y2 = rec1[3];
        int& m1 = rec2[0];
        int& n1 = rec2[1];
        //int& m2 = rec2[2];
        int& n2 = rec2[3];

        if (x1 > m1) { //swap to make sure x1 <= m1
            return isRectangleOverlap(rec2, rec1);
        }

        if (x1 <= m1 && m1 < x2 ) {
            if (y1  <= n1 && n1 < y2) {
                return true;
            }
            if (n1 <= y1 && n2 > y1) {
                return true;
            }
            return false;
        }

        return false;
    }
};
// @lc code=end


/*
M1 反向思维
先考虑不相交的场景
再取反

M2 拆分成线段的交集
X轴线段有交集且Y轴线段有交集



*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


