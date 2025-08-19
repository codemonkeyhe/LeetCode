/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-19
 * @tag   matrix,simulation
 * @similar  54,59,885,2326
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=885 lang=cpp
 *
 * [885] 螺旋矩阵 III
 *
 * https://leetcode.cn/problems/spiral-matrix-iii/description/
 *
 * algorithms
 * Medium (72.18%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    11.9K
 * Total Submissions: 16.2K
 * Testcase Example:  '1\n4\n0\n0'
 *
 * 在 rows x cols 的网格上，你从单元格 (rStart, cStart)
 * 面朝东面开始。网格的西北角位于第一行第一列，网格的东南角位于最后一行最后一列。
 *
 * 你需要以顺时针按螺旋状行走，访问此网格中的每个位置。每当移动到网格的边界之外时，需要继续在网格之外行走（但稍后可能会返回到网格边界）。
 * 最终，我们到过网格的所有 rows x cols 个空间。
 * 按照访问顺序返回表示网格位置的坐标列表。
 *
 *
 *
 * 示例 1：
 * 输入：rows = 1, cols = 4, rStart = 0, cStart = 0
 * 输出：[[0,0],[0,1],[0,2],[0,3]]
 *
 *
 * 示例 2：
 * 输入：rows = 5, cols = 6, rStart = 1, cStart = 4
 * 输出：[[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 *
 *
 *
 *
 * 提示：
 * 1 <= rows, cols <= 100
 * 0 <= rStart < rows
 * 0 <= cStart < cols
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> spiralMatrixIIIV1(int rows, int cols, int rStart, int cStart) {
        int total = rows * cols;
        vector<vector<int> > res;
        int cnt = 1;
        int i = rStart;
        int j = cStart;
        res.push_back(vector<int>{i, j});
        int width = 1;
        int height = 1;
        while(cnt++ <= total) {
            // to right
            for(int k = 0; k < width; k++) {
                j++;
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    res.push_back(vector<int>{i, j});
                }
            }
            width++;

            // to down
            for(int k = 0; k < height; k++) {
                i++;
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    res.push_back(vector<int>{i, j});
                }
            }
            height++;

            // to left
            for(int k = 0; k < width; k++) {
                j--;
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    res.push_back(vector<int>{i, j});
                }
            }
            width++;

            // to up
            for(int k = 0; k < height; k++) {
                i--;
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    res.push_back(vector<int>{i, j});
                }
            }
            height++;
        }
        return res;
    }

    const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows * cols;
        vector<vector<int> > res;
        int cnt = 1;
        int i = rStart;
        int j = cStart;
        res.push_back(vector<int>{i, j});
        int width = 1;
        int height = 1;
        while(cnt++ <= total) {
            for (int d = 0; d <= 3; d++) {
                auto& dir = dirs[d];
                // 0right 1down 2left 3up
                int step = 0;
                if (d == 1 || d == 3) {
                    step = height;
                    height++;
                } else {
                    step = width;
                    width++;
                }
                for (int k = 0; k < step; k++) {
                    i = i + dir[0];
                    j = j + dir[1];
                    if (i >= 0 && i < rows && j >= 0 && j < cols) {
                        res.push_back(vector<int>{i, j});
                    }
                }
            }
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
