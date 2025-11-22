/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-22
 * @tag    math
 * @similar
 */

/*
直角三角形
勾股定理
a*a + b*b = c*c
*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 *
 * https://leetcode.cn/problems/valid-square/description/
 *
 * algorithms
 * Medium (47.01%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    40.4K
 * Total Submissions: 85.5K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * 给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。
 *
 * 点的坐标 pi 表示为 [xi, yi] 。 输入没有任何顺序 。
 *
 * 一个 有效的正方形 有四条等边和四个等角(90度角)。
 *
 *
 *
 * 示例 1:
 * 输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * 输出: true
 *
 *
 * 示例 2:
 * 输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
 * 输出：false
 *
 *
 * 示例 3:
 * 输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
 * 输出：true
 *
 *
 *
 *
 * 提示:
 * p1.length == p2.length == p3.length == p4.length == 2
 * -10^4 <= xi, yi <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool validSquareStupid(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, vector<int>> x2p;
        unordered_map<int, vector<int>> y2p;
        vector<vector<int>> points = {p1, p2, p3, p4};
        for (int i = 0; i < 4; i++) {
            auto& p = points[i];
            auto& x = p[0];
            auto& y = p[1];
            x2p[x].push_back(i);
            y2p[y].push_back(i);
        }
        if (x2p.size() != 2 || y2p.size() != 2) {
            return false;
        }
        int slen = 0;
        for (auto& [x, ps] : x2p) {
            if (ps.size() != 2) {
                return false;
            }
            auto& p1 = points[ps[0]];
            auto& p2 = points[ps[1]];
            auto curLen = abs(p1[1] - p2[1]);
            if (slen == 0) {
                slen = curLen;
            } else if (curLen != slen) {
                return false;
            }
        }
        for (auto &[y, ps] : y2p) {
            if (ps.size() != 2) {
                return false;
            }
            auto& p1 = points[ps[0]];
            auto& p2 = points[ps[1]];
            auto curLen = abs(p1[0] - p2[0]);
            if (curLen != slen) {
                return false;
            }
        }
        return true;
    }


    bool validSquareWA254_256(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        auto dis12 = distance2(p1, p2);
        auto dis13 = distance2(p1, p3);
        auto dis14 = distance2(p1, p4);
        if (dis12 == 0 || dis13 == 0 || dis14 == 0) {
            return false;
        }
        if (dis12 == dis13) { // means dis14 is long
            auto dis23 = distance2(p2, p3);
            if (dis12 + dis13 != dis23) {
                return false;
            }
            auto dis24 = distance2(p2, p4);
            if (dis12 + dis24 != dis14) {
                return false;
            }
        } else {
            if (dis12 == dis14) { // means dis13 is long
                auto dis24 = distance2(p2, p4);
                if (dis12 + dis14 != dis24) {
                    return false;
                }
                auto dis23 = distance2(p2, p3);
                if (dis12 + dis23 != dis13) {
                    return false;
                }
            } else { // dis12 is long
                if (dis13 != dis14) {
                    return false;
                }
                auto dis34 = distance2(p3, p4);
                if (dis13 + dis14 != dis34) {
                    return false;
                }
                auto dis23 = distance2(p2, p3);
                if (dis13 + dis23 != dis12) {
                    return false;
                }
            }
        }
        return true;
    }

    int distance2(vector<int>& p1, vector<int>& p2) {
        int x = abs(p1[0] - p2[0]);
        int y = abs(p1[1] - p2[1]);
        return x * x + y * y;
    }

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        auto dis12 = distance2(p1, p2);
        auto dis13 = distance2(p1, p3);
        auto dis14 = distance2(p1, p4);
        auto dis23 = distance2(p2, p3);
        auto dis24 = distance2(p2, p4);
        auto dis34 = distance2(p3, p4);
        unordered_map<int, int> lenCnt;
        lenCnt[dis12]++;
        lenCnt[dis13]++;
        lenCnt[dis14]++;
        lenCnt[dis23]++;
        lenCnt[dis24]++;
        lenCnt[dis34]++;
        if (lenCnt.size() != 2)  {
            return false;
        }
        int l1 = 0;
        int l2 = 0;
        for (auto &[len, cnt] : lenCnt) {
            if (cnt == 2) {
                l1 = len;
            } else if (cnt == 4) {
                l2 = len;
            } else  {
                return false;
            }
        }
        if (l2 + l2 != l1) {
            return false;
        }
        return true;
    }
};
// @lc code=end


/*

Wrong Answer
103/256 cases passed (N/A)
Testcase
[1,0]
[-1,0]
[0,1]
[0,-1]
Answer
false
Expected Answer
true



Wrong Answer
252/256 cases passed (N/A)
Testcase
[0,0]
[1,1]
[0,0]
[0,0]
Answer
true
Expected Answer
false

Wrong Answer
254/256 cases passed (N/A)
Testcase
[1,1]
[0,1]
[1,2]
[0,0]
Answer
true
Expected Answer
false

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
