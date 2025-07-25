/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-25
 * @tag  math, hashTable
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
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode.cn/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (40.30%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    91.8K
 * Total Submissions: 227.6K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。
 *
 *
 *
 * 示例 1：
 * 输入：points = [[1,1],[2,2],[3,3]]
 * 输出：3
 *
 *
 * 示例 2：
 * 输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出：4
 *
 *
 *
 *
 * 提示：
 * 1 <= points.length <= 300
 * points[i].length == 2
 * -104 <= xi, yi <= 104
 * points 中的所有点 互不相同
 *
 *
 */

// @lc code=start
class Solution {
public:
    // M1 暴力法
    /*
   41/41 cases passed (11 ms)
    Your runtime beats 99.59 % of cpp submissions
    */
    int maxPointsM1(vector<vector<int>>& points) {
        int len = points.size();
        if (len <= 2) {
            return len;
        }
        int maxCnt = 0;
        for (int i = 0; i < len; i++) { // p1
            for (int j = i+1; j < len; j++) { //p2
                int cnt = 2;
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                for (int k = j+1; k < len; k++)  { // p3
                    if (dy * (points[k][0] - points[i][0]) == dx*(points[k][1] - points[i][1])) {
                        cnt++;
                    }
                }
                // cnt points is at line(p1, p2)
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }

/*
41/41 cases passed (19 ms)
Your runtime beats 83.37 % of cpp submissions
*/
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if (len <= 2) {
            return len;
        }
        int maxCnt = 0;
        for (int i = 0; i < len; i++) { // p1
            // 由P1点出发的斜率情况数
            unordered_map<int, int> hm;
            int cnt = 0;
            for (int j = i+1; j < len; j++) { //p2
                // ERROR LOGIC
                //int dy = abs(points[j][1] - points[i][1]);
                //int dx = abs(points[j][0] - points[i][0]);
                //斜率可以是负数 //但是 -1/2 和 1/-2的斜率是相同的，因此，需要归一化，约定dy不能为负数
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                if (dy < 0) {
                    dy = -dy;
                    dx = -dx;
                }
                // 用自定义的 gcdd能通过，用std::gcd则不过，原因在于公约数是负数时的处理
                // FailCase: [[2,3],[3,3],[-5,3]]
                // 解决办法： 当dx==0或者dy==0时，分开统计
                int g = gcdd(dx, dy);
                int key = (dx / g) * 100000 + dy / g;
                //cout << "i=" << i << " j=" << j << " gcd=" << g << " key=" << key << endl;
                hm[key]++;
            }
            for (auto &[k, v] : hm) {
                cnt = max(cnt, v + 1); // v+1需要算上p1本身
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }

    int gcdd(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcdd(y, x%y);
    }

};
// @lc code=end


/*
原理
p1(x1,y1)
p2(x2,y2)
p3(x3,y3)
假设P1，p2, p3的斜率相等，则必然在一条直线上，因此有
(y2-y1)/(x2-x1)  == (y3-y1)/(x3-x1)


Wrong Answer
39/41 cases passed (N/A)
Testcase
[[0,0]]
Answer
0
Expected Answer
1


Wrong Answer
26/41 cases passed (N/A)
Testcase
[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Answer
3
Expected Answer
4


points =
[[0,0],[1,-1],[1,1]]


Wrong Answer
40/41 cases passed (N/A)
Testcase
[[2,3],[3,3],[-5,3]]
Answer
2
Expected Answer
3

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


