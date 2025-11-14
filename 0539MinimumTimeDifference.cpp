/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-14
 * @tag    string, math, sort
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
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 *
 * https://leetcode.cn/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (65.43%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    73.7K
 * Total Submissions: 112.6K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
 *
 *
 *
 * 示例 1：
 * 输入：timePoints = ["23:59","00:00"]
 * 输出：1
 *
 *
 * 示例 2：
 * 输入：timePoints = ["00:00","23:59","00:00"]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * 2 <= timePoints.length <= 2 * 10^4
 * timePoints[i] 格式为 "HH:MM"
 *
 *
 */

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int range = 24*60;
        vector<int> minBucket(range, 0);
        for (auto& ts : timePoints) {
            string hour = ts.substr(0,2);
            string minu = ts.substr(3);
            //cout << "hour=" << hour << " min=" << minu << endl;
            int minIdx = stoi(hour) * 60 + stoi(minu);
            minBucket[minIdx]++;
        }

        int minDiff = range;
        int p1 = -1;
        int firstV = -1;
        for (int i = 0; i < range; i++) {
            if (minBucket[i] == 0) {
                continue;
            }
            if (minBucket[i] > 1) {
                return 0;
            }
            if (p1 == -1) {
                p1 = i;
                firstV = i;
                continue;
            }
            minDiff = min(minDiff, i - p1);
            p1 = i;
        }
        // circle
        minDiff = min(minDiff, firstV - p1  + range);
        return minDiff;
    }
};
// @lc code=end

/*
Finished
Your Input
["23:59","00:00"]
Output (0 ms)
1439
Expected Answer
1
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
