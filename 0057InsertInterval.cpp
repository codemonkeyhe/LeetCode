/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-24
 * @tag  array
 * @similar  56
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode.cn/problems/insert-interval/description/
 *
 * algorithms
 * Medium (42.61%)
 * Likes:    889
 * Dislikes: 0
 * Total Accepted:    212.5K
 * Total Submissions: 498.6K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i
 * 个区间的开始和结束，并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end]
 * 表示另一个区间的开始和结束。
 *
 * 在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti
 * 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
 * 返回插入之后的 intervals。
 *
 * 注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。
 *
 *
 *
 * 示例 1：
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 *
 *
 * 示例 2：
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 *
 *
 *
 *
 * 提示：
 * 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^5
 * intervals 根据 starti 按 升序 排列
 * newInterval.length == 2
 * 0 <= start <= end <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insertM1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > res;
        int left = newInterval[0];
        int right = newInterval[1];
        int len = intervals.size();

        vector<int> starts;
        for (int i = 0; i < len; i++) {
            starts.push_back(intervals[i][0]);
        }
        // find first >= left , intervals[idx].left >= left
        int idx = lower_bound(starts.begin(), starts.end(), left) - starts.begin();
        int i = 0;
        for (; i < idx - 1; i++) { // must not overlap
            res.push_back(vector<int>{intervals[i][0], intervals[i][1]});
        }

        int newLeft = left;
        int newRight = right;
        if (i == idx-1) { // maybe overlap
            int curLeft = intervals[idx - 1][0];
            int curRight = intervals[idx - 1][1];
            if (curRight < left) {
                res.push_back(vector<int>{curLeft, curRight});
            } else {
                // means overlap
                newLeft = curLeft;
                newRight = max(curRight, newRight);
            }
            i++;
        }
        // i == idx
        for (; i < len; i++) { //test if  overlaps
            int curLeft = intervals[i][0];
            int curRight = intervals[i][1];
            if (curLeft <= newRight) {  // means overlap
                newRight = max(curRight, newRight);
                continue;
            }
            // curLeft > right // means no overlap
            break;
        }
        res.push_back(vector<int>{newLeft, newRight});

        for (; i < len; i++) {
            res.push_back(vector<int>{intervals[i][0], intervals[i][1]});
        }
        return res;
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        vector<vector<int> > res;
        int left = newInterval[0];
        int right = newInterval[1];
        if (len == 0) {
            res.push_back(vector<int>{left, right});
            return res;
        }
        int newLeft = left;
        int newRight = right;
        bool noset = true;
        for (int i = 0; i < len; i++) {
            int curLeft = intervals[i][0];
            int curRight = intervals[i][1];
            if (curRight < left) { // on left ,and not overlap
                res.push_back(vector<int>{curLeft, curRight});
                continue;
            }
            // curRight >= left
            if (curLeft > right) { // on right, and not overlap
                if (noset) {
                    res.push_back(vector<int>{newLeft, newRight});
                    noset = false;
                }
                res.push_back(vector<int>{curLeft, curRight});
                continue;
            }
            // curLeft <= right
            newLeft = min(curLeft, newLeft);
            newRight = max(curRight, newRight);
        }
        if (noset) {
            res.push_back(vector<int>{newLeft, newRight});
        }
        return res;
    }


};
// @lc code=end


/**
Wrong Answer
54/158 cases passed (N/A)
Testcase
[]
[5,7]
Answer
[]
Expected Answer
[[5,7]]


Wrong Answer
55/158 cases passed (N/A)
Testcase
[[1,5]]
[2,3]
Answer
[]
Expected Answer
[[1,5]]
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


