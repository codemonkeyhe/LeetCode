/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-14
 * @tag   rejectionSampling,randomized
 * @similar  470, 478
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 *
 * https://leetcode.cn/problems/generate-random-point-in-a-circle/description/
 *
 * algorithms
 * Medium (48.33%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    33.2K
 * Total Submissions: 68.4K
 * Testcase Example:  '["Solution","randPoint","randPoint","randPoint"]\n[[1.0,0.0,0.0],[],[],[]]'
 *
 * 给定圆的半径和圆心的位置，实现函数 randPoint ，在圆中产生均匀随机点。
 *
 * 实现 Solution 类:
 * 提示：
 * 0 < radius <= 10^8
 * -10^7 <= x_center, y_center <= 10^7
 * randPoint 最多被调用 3 * 10^4 次
 *
 *
 */

// @lc code=start
class Solution {
public:
    double x;
    double y;
    double r;
    mt19937 gen{random_device{}()};

    //std::random_device rd;  // 将用于获得随机数引擎的种子
    //std::mt19937 gen; // 以 rd() 播种的标准 mersenne_twister_engine
    uniform_real_distribution<double> dis;

    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
        dis = uniform_real_distribution<double>(-r, r);
    }

    vector<double> randPoint() {
        // [-R, +R)
        double ranX = 0.0f;
        double ranY = 0.0f;
        while (true) {
            // // 用 dis 变换 gen 生成的随机  中的 double
            ranX  = dis(gen);
            ranY  = dis(gen);
            if ((ranX * ranX) + (ranY * ranY) <= (r * r)) {
                break;
            }
        }
        return vector<double>{ranX + x, ranY + y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

/*
https://www.apiref.com/cpp-zh/cpp/numeric/random/uniform_real_distribution.html
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
