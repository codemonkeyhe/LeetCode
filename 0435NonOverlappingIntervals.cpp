/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-13
 * @tag greedy,dynamicProgramming
 * @similar 300,435, 452, 646
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 * https://leetcode.cn/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (51.72%)
 * Likes:    1219
 * Dislikes: 0
 * Total Accepted:    328.3K
 * Total Submissions: 620.7K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回
 * 需要移除区间的最小数量，使剩余区间互不重叠 。
 * 注意 只在一点上接触的区间是 不重叠的。例如 [1, 2] 和 [2, 3] 是不重叠的。
 *
 *
 *
 * 示例 1:
 * 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * 输出: 1
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 *
 *
 * 示例 2:
 * 输入: intervals = [ [1,2], [1,2], [1,2] ]
 * 输出: 2
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 *
 *
 * 示例 3:
 * 输入: intervals = [ [1,2], [2,3] ]
 * 输出: 0
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 *
 *
 *
 *
 * 提示:
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    //  compare left point
    // a[0] == b[0]  must return false
    static bool cmpFn(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    int eraseOverlapIntervalsTLE55(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> dp(n, 0);

        sort(intervals.begin(), intervals.end(), cmpFn);

        for (int i = 0; i < n; i++) {
            int maxV = 0;
            vector<int>& cur = intervals[i];
            for (int k = 0; k < i; k++) { // 0~ i-1
                if (intervals[k][1] <= cur[0])  { // not overlap
                    maxV = max(maxV, dp[k]);
                }
            }
            dp[i] = maxV + 1;
        }
        int maxN = *max_element(dp.begin(), dp.end());
        return  n - maxN;
    }

    static bool cmpFn2(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    // sort by rightPoint
    int eraseOverlapIntervalsM2(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmpFn2);

        int cnt = 1;
        int rightP = intervals[0][1];
        for (int i = 1; i < n; i++) {
            auto& cur = intervals[i];
            if (cur[0] < rightP) { //overlop, skip
                continue;
            }
            // not overlap
            cnt++;
            rightP = intervals[i][1];
        }
        return n - cnt;
    }

    // sort  by leftPoint
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmpFn);

        int cnt = 0;
        int rightP = intervals[0][1];
        int minR = rightP;
        for (int i = 1; i < n; i++) {
            auto& cur = intervals[i];
            if (cur[0] >= minR) { //not overlop, skip
                minR = cur[1];
                continue;
            }
            // overlap
            minR = min(minR, cur[1]); // 右端点最早结束的优先
            cnt++; //删去其中1个重复的，保留另外一个右端点最早的
        }
        return cnt;
    }



};
// @lc code=end


/*
dp[i]表示 intervals[0 .. i] 中 以区间intervals[i]结尾的  区间互不重叠的 最多数量
answer = N -  max{dp[0], dp[1] ... dp[N-1]};

dp[i] =  max(dp[k], dp[k+1] ... dp[i-1]) + 1   &&  dp[k]必须满足 intervals[k] 和 intervals[i]不重叠,  k - [0 ~ i-1]


Time Limit Exceeded
55/59 cases passed (N/A)
Testcase
[[-15372,11264],[-43730,-33388],[-36639,1280],[840,35984],[-38240,17122],[-37497,-1380],[47229,49062],[-45771,43174],[20443,34360],[38798,39394],[-22692,16373],[-22621,-2258],[-81,38395],[15345,23474],[47816,47915],[41254,46599],[3742,19258],[-21774,21717],[-20502,33620],[-3943,45736],[-34683,27103],... 1123916 more character
Expected Answer
79008

https://leetcode.cn/problems/non-overlapping-intervals/solutions/1263171/tan-xin-jie-fa-qi-shi-jiu-shi-yi-ceng-ch-i63h
正确的思路既能够按照区间左端点排序，也能够按照区间右端点排序。
1.对于按照区间左端点排序，当两个比较的区间存在重叠时，再比较区间右端点的大小，保留右端点小的区间（对应结束时间早的区间)，这样能够满足剩余非重叠区间的个数最多。
2.对于按照区间右端点排序，当两个比较的区间存在重叠时，无需比较右端点的大小, 因为按照右端点排序, 后者肯定大于前者，因此只需保留右端点(前者)小的区间(对应结束时间早的区间)。
综上所述：按照左区间排序比按照右区间排序多了一步比较两区间右端点大小，选出右端点小的区间的步骤罢了。整体思路还是贪心。



*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


