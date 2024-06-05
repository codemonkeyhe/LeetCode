/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-06-05
 * @tag OneShot; array
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=252 lang=cpp
 *
 * [252] 会议室
 *
 * https://leetcode.cn/problems/meeting-rooms/description/
 *
 * algorithms
 * Easy (58.43%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    28K
 * Total Submissions: 47.8K
 * Testcase Example:  '[[0,30],[5,10],[15,20]]'
 *
 * 给定一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi]
 * ，请你判断一个人是否能够参加这里面的全部会议。
 *
 *
 *
 * 示例 1：
 * 输入：intervals = [[0,30],[5,10],[15,20]]
 * 输出：false
 *
 *
 * 示例 2：
 * 输入：intervals = [[7,10],[2,4]]
 * 输出：true
 *
 *
 * 提示：
 *
 * 0 <= intervals.length <= 104
 * intervals[i].length == 2
 * 0 <= starti < endi <= 106
 *
 */

// @lc code=start
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return true;
        }
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size()-1; i++) {
            vector<int>& vc = intervals[i];
            vector<int>& next = intervals[i+1];
            if ((next[0] >= vc[0]) && (next[0] < vc[1])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

/*
Testcase
[[13,15],[1,13]]
Answer
false
Expected Answer
true

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


