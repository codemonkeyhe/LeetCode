/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-31
 * @tag   dfs, dp?
 * @similar  2397, 698
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 *
 * https://leetcode.cn/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (46.74%)
 * Likes:    559
 * Dislikes: 0
 * Total Accepted:    85.4K
 * Total Submissions: 181.9K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * 你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你
 * 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。
 *
 * 如果你能使这个正方形，则返回 true ，否则返回 false 。
 *
 *
 *
 * 示例 1:
 * 输入: matchsticks = [1,1,2,2,2]
 * 输出: true
 * 解释: 能拼成一个边长为2的正方形，每边两根火柴。
 *
 *
 * 示例 2:
 * 输入: matchsticks = [3,3,3,3,4]
 * 输出: false
 * 解释: 不能用所有火柴拼成一个正方形。
 *
 *
 *
 *
 * 提示:
 * 1 <= matchsticks.length <= 15
 * 1 <= matchsticks[i] <= 10^8
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (auto& v: matchsticks) {
            sum += v;
        }
        if (sum % 4 != 0) {
            return false;
        }
        int edge = sum/4;
        for (auto& v: matchsticks) {
            if (v > edge) {
                return false;
            }
        }
        //去掉sort则TLE189/195
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> square(4, 0);
        auto res = dfs(matchsticks, 0, square, edge);
        return res;
    }


    bool dfs(vector<int>& sticks, int idx, vector<int>& square, int edge) {
        if (idx == sticks.size()) {
            return true;
            /* still ok but duplicate
            if (square[0] == square[1] && square[1] == square[2] && square[2] == square[3]) {
                return true;
            }
            return false;
            */
        }

        int curLen = sticks[idx];
        for (int i = 0; i < 4; i++) {
            if (square[i]+curLen > edge) {
                continue;
            }
            square[i] += curLen;
            auto res = dfs(sticks, idx+1, square, edge);
            if (res) {
                return true;
            }
            square[i] -= curLen;
        }
        return false;
    }
};
// @lc code=end

/*
Time Limit Exceeded
177/195 cases passed (N/A)
Testcase
[1,1,1,1,1,1,1,1,1,1,1,1,1,1,102]
Expected Answer
false


Time Limit Exceeded
189/195 cases passed (N/A)
Testcase
[14,10,10,10,10,10,10,10,10,10,10,10,8,9,19]
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


