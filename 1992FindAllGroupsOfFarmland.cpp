/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-25
 * @tag matrix, trick
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
 * @lc app=leetcode.cn id=1992 lang=cpp
 *
 * [1992] 找到所有的农场组
 *
 * https://leetcode.cn/problems/find-all-groups-of-farmland/description/
 *
 * algorithms
 * Medium (61.83%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 11.9K
 * Testcase Example:  '[[1,0,0],[0,1,1],[0,1,1]]'
 *
 * 给你一个下标从 0 开始，大小为 m x n 的二进制矩阵 land ，其中 0 表示一单位的森林土地，1 表示一单位的农场土地。
 *
 * 为了让农场保持有序，农场土地之间以矩形的 农场组 的形式存在。每一个农场组都 仅
 * 包含农场土地。且题目保证不会有两个农场组相邻，也就是说一个农场组中的任何一块土地都 不会 与另一个农场组的任何一块土地在四个方向上相邻。
 *
 * land 可以用坐标系统表示，其中 land 左上角坐标为 (0, 0) ，右下角坐标为 (m-1, n-1) 。请你找到所有 农场组
 * 最左上角和最右下角的坐标。一个左上角坐标为 (r1, c1) 且右下角坐标为 (r2, c2) 的 农场组 用长度为 4 的数组 [r1, c1,
 * r2, c2] 表示。
 *
 * 请你返回一个二维数组，它包含若干个长度为 4 的子数组，每个子数组表示 land 中的一个 农场组 。如果没有任何农场组，请你返回一个空数组。可以以
 * 任意顺序 返回所有农场组。
 *
 * 示例 1：
 * 输入：land = [[1,0,0],[0,1,1],[0,1,1]]
 * 输出：[[0,0,0,0],[1,1,2,2]]
 * 解释：
 * 第一个农场组的左上角为 land[0][0] ，右下角为 land[0][0] 。
 * 第二个农场组的左上角为 land[1][1] ，右下角为 land[2][2] 。
 *
 *
 * 示例 2：
 * 输入：land = [[1,1],[1,1]]
 * 输出：[[0,0,1,1]]
 * 解释：
 * 第一个农场组左上角为 land[0][0] ，右下角为 land[1][1] 。
 *
 *
 * 示例 3：
 * 输入：land = [[0]]
 * 输出：[]
 * 解释：
 * 没有任何农场组。
 *
 *
 *
 *
 * 提示：
 * m == land.length
 * n == land[i].length
 * 1 <= m, n <= 300
 * land 只包含 0 和 1 。
 * 农场组都是 矩形 的形状。
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findFarmlandStupid(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int r = land.size();
        int c = land[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (land[i][j] == 1) {
                    auto fl = findland(land, i, j);
                    res.push_back(fl);
                }
            }
        }
        return res;
    }

    vector<int> findland(vector<vector<int>>& land, int p1, int p2) {
        vector<int> res;

        int height = 0;
        for (int i = p1; i < land.size(); i++) {
            if (land[i][p2] == 1) {
                height++;
            } else {
                break;
            }
        }

        int width = 0;
        for (int j = p2; j < land[0].size(); j++) {
            if (land[p1][j] == 1) {
                width++;
            } else {
                break;
            }
        }

        // mark visited
        for (int i = p1; i < p1 + height; i++) {
            for (int j = p2; j < p2 + width; j++) {
                land[i][j] = 0;
            }
        }

        res.push_back(p1);
        res.push_back(p2);
        res.push_back(p1 + height - 1);
        res.push_back(p2 + width - 1);
        return res;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int r = land.size();
        int c = land[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (land[i][j] == 0) {
                    continue;
                }
                if ((i > 0 && land[i-1][j] == 1) || (j>0 && (land[i][j-1] == 1))) {
                    // not left up startpoint
                    continue;
                }
                int k = i;
                while (k < r && (land[k][j] == 1)) {
                    k++;
                }
                int n = j;
                while (n < c && (land[i][n] == 1)) {
                    n++;
                }
                res.push_back(vector<int>{i, j, k - 1, n - 1});
                j = n;
            }
        }
        return res;
    }


};
// @lc code=end

/*
Wrong Answer
199/220 cases passed (N/A)
Testcase
[[1,1,0,0,0,1],[1,1,0,0,0,0]]
Answer
[[0,0,1,2],[0,5,0,5]]
Expected Answer
[[0,0,1,1],[0,5,0,5]]

*/




int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


