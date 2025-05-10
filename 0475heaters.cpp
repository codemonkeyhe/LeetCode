/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-10
 * @tag binarySearch,twoPointers
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
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 *
 * https://leetcode.cn/problems/heaters/description/
 *
 * algorithms
 * Medium (41.38%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    75.8K
 * Total Submissions: 183.2K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
 *
 * 在加热器的加热半径范围内的每个房屋都可以获得供暖。
 *
 * 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。
 *
 * 注意：所有供暖器 heaters 都遵循你的半径标准，加热的半径也一样。
 *
 *
 *
 * 示例 1:
 * 输入: houses = [1,2,3], heaters = [2]
 * 输出: 1
 * 解释: 仅在位置 2 上有一个供暖器。如果我们将加热半径设为 1，那么所有房屋就都能得到供暖。
 *
 *
 * 示例 2:
 * 输入: houses = [1,2,3,4], heaters = [1,4]
 * 输出: 1
 * 解释: 在位置 1, 4 上有两个供暖器。我们需要将加热半径设为 1，这样所有房屋就都能得到供暖。
 *
 *
 * 示例 3：
 * 输入：houses = [1,5], heaters = [2]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 * 1 <= houses.length, heaters.length <= 3 * 10^4
 * 1 <= houses[i], heaters[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:

    int findRadiusUgly(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int maxD = INT_MIN;
        for (auto& hou : houses) {
            // find first >= hou
            auto rightH = lower_bound(heaters.begin(), heaters.end(), hou);
            int dis = 0;
            if (rightH ==  heaters.end()) { // means hou is bigger than all heaters
                int disL =  hou - heaters.back();
                dis = disL;
            } else {
                int disR = *rightH - hou;
                dis = disR;
                if (rightH != heaters.begin()) {
                    auto leftH = rightH - 1;
                    int disL = hou - *leftH;
                    dis = min(dis, disL);
                }
            }

            maxD = max(maxD, dis);
        }
        return maxD;
    }


    int findRadiusM1(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int maxD = INT_MIN;
        for (auto& hou : houses) {
            // find first >= hou
            auto rightH = lower_bound(heaters.begin(), heaters.end(), hou);
            int disL = INT_MAX;
            int disR = INT_MAX;
            if (rightH ==  heaters.end()) { // means hou is bigger than all heaters
                disL =  hou - heaters.back();
            } else {
                disR = *rightH - hou;
                if (rightH != heaters.begin()) {
                    auto leftH = rightH - 1;
                    disL = hou - *leftH;
                }
            }
            auto dis = min(disL, disR);
            maxD = max(maxD, dis);
        }
        return maxD;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0;
        int j = 0;
        int maxD = INT_MIN;
        while(i < houses.size()) {
            while (j < heaters.size() && (houses[i] > heaters[j])) {
                j++;
            }
            // house[i] <= heaters[j]
            int disL = (j >= 1) ? (houses[i] - heaters[j - 1]) : INT_MAX;
            int disR = (j < heaters.size()) ? (heaters[j] - houses[i]) : INT_MAX;
            auto dis = min(disL, disR);
            maxD = max(maxD, dis);
            i++;
        }
        return maxD;
    }
};
// @lc code=end

/*
Your Input
[1,2,3]
[2]
Output (0 ms)
0
Expected Answer
1


Wrong Answer
23/30 cases passed (N/A)
Testcase
[1,5]
[2]
Answer
1
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


