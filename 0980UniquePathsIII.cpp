/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-11
 * @tag   dfs, backtracking
 * @similar  62, 63, 980
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 *
 * https://leetcode.cn/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (77.75%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    45.1K
 * Total Submissions: 58.4K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * 在二维网格 grid 上，有 4 种类型的方格：
 * 1 表示起始方格。且只有一个起始方格。
 * 2 表示结束方格，且只有一个结束方格。
 * 0 表示我们可以走过的空方格。
 * -1 表示我们无法跨越的障碍。
 *
 *
 * 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。
 * 每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。
 *
 *
 *
 * 示例 1：
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * 输出：2
 * 解释：我们有以下两条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 *
 * 示例 2：
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * 输出：4
 * 解释：我们有以下四条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 *
 * 示例 3：
 * 输入：[[0,1],[2,0]]
 * 输出：0
 * 解释：
 * 没有一条路能完全穿过每一个空的方格一次。
 * 请注意，起始和结束方格可以位于网格中的任意位置。
 *
 *
 *
 *
 * 提示：
 * 1 <= grid.length * grid[0].length <= 20
 *
 *
 */

// @lc code=start
class Solution {
public:

    const vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int total = row * col;
        int cntZero = 0;
       // int cntOb = 0;
        pair<int, int> stp;
        pair<int, int> endp;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    cntZero++;
                } else if (grid[i][j] == 1) {
                    stp = make_pair(i, j);
                } else if (grid[i][j] == 2) {
                    endp = make_pair(i, j);
                } else {
                   // cntOb++;
                }
            }
        }
//        cout << "zero=" << cntZero << " ob=" << cntOb << endl;

        /* M1
        // walked 2个作用： 轨迹去重，记录轨迹长度
       // unordered_set<pair<int, int> > walked;
        set<pair<int, int> > walked;
        walked.insert(stp);
        //auto pathCnt = dfs(grid, cntZero, stp, endp, walked);
        */

       // 用二维的vector记录walked, 单纯用于轨迹去重， 长度用cntZero代劳
        vector<vector<int>> walked(row, vector<int>(col, 0));
        walked[stp.first][stp.second] = 1;
        auto pathCnt = dfs2(grid, cntZero, stp, endp, walked);
        return pathCnt;
    }


    int dfs(vector<vector<int>>& grid, int cntZero, pair<int, int>& startp, pair<int, int>& endp, set<pair<int, int>>& walked) {
        int row = grid.size();
        int col = grid[0].size();

        if (startp == endp) { // reach
            if (walked.size() == cntZero + 2) {
                return 1;
            }
            return 0;
        }

        int curX = startp.first;
        int curY = startp.second;
        int totalCnt = 0;
        for (auto dir : dirs) {
            int ni = curX + dir.first;
            int nj = curY + dir.second;
            if (ni < 0 || ni >= row || nj < 0 || nj >= col) {
                continue;
            }
            if (grid[ni][nj] == -1) { // obstacle
                continue;
            }
            auto nextStep = make_pair(ni, nj);
            if (walked.count(nextStep) != 0) { // walked
                continue;
            }
            walked.insert(nextStep);
            int cnt = dfs(grid, cntZero, nextStep, endp, walked);
            totalCnt += cnt;
            walked.erase(nextStep);
        }

        return totalCnt;
    }



    int dfs2(vector<vector<int>>& grid, int& cntZero, pair<int, int>& startp, pair<int, int>& endp, vector<vector<int>>& walked) {
        int row = grid.size();
        int col = grid[0].size();

        if (startp == endp) { // reach
            if (cntZero == -1) { //包含终点 所以是-1
                return 1;
            }
            return 0;
        }

        int curX = startp.first;
        int curY = startp.second;
        int totalCnt = 0;
        for (auto dir : dirs) {
            int ni = curX + dir.first;
            int nj = curY + dir.second;
            if (ni < 0 || ni >= row || nj < 0 || nj >= col) {
                continue;
            }
            if (grid[ni][nj] == -1) { // obstacle
                continue;
            }
            auto nextStep = make_pair(ni, nj);
            if (walked[ni][nj] == 1) { // walked
                continue;
            }
            walked[ni][nj] = 1;
            cntZero--;
            int cnt = dfs2(grid, cntZero, nextStep, endp, walked);
            cntZero++;
            totalCnt += cnt;
            walked[ni][nj] = 0;
        }

        return totalCnt;
    }


};
// @lc code=end

/*
totalCnt = zero+ob+startP+endP
pathNodeLen = toalCnt - obCnt - startP - endP = zeroCnt
pathNodeLen = toalCnt - obCnt -2

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
