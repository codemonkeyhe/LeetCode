/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-11
 * @tag   binarySearch,twoPointers
 * @similar  34,744,875
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 *
 * https://leetcode.cn/problems/find-right-interval/description/
 *
 * algorithms
 * Medium (57.06%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    50.1K
 * Total Submissions: 87.8K
 * Testcase Example:  '[[1,2]]'
 *
 * 给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。
 * 区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。注意 i 可能等于 j 。
 * 返回一个由每个区间 i 的 右侧区间 在 intervals 中对应下标组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为
 * -1 。
 *
 *
 * 示例 1：
 * 输入：intervals = [[1,2]]
 * 输出：[-1]
 * 解释：集合中只有一个区间，所以输出-1。
 *
 *
 * 示例 2：
 * 输入：intervals = [[3,4],[2,3],[1,2]]
 * 输出：[-1,0,1]
 * 解释：对于 [3,4] ，没有满足条件的“右侧”区间。
 * 对于 [2,3] ，区间[3,4]具有最小的“右”起点;
 * 对于 [1,2] ，区间[2,3]具有最小的“右”起点。
 *
 *
 * 示例 3：
 * 输入：intervals = [[1,4],[2,3],[3,4]]
 * 输出：[-1,2,-1]
 * 解释：对于区间 [1,4] 和 [3,4] ，没有满足条件的“右侧”区间。
 * 对于 [2,3] ，区间 [3,4] 有最小的“右”起点。
 *
 *
 *
 *
 * 提示：
 * 1 <= intervals.length <= 2 * 10^4
 * intervals[i].length == 2
 * -10^6 <= starti <= endi <= 10^6
 * 每个间隔的起点都 不相同
 *
 *
 */

// @lc code=start
class Solution {
public:
    // 弱序 严格   a=b must return false
    // a < b return true
    static bool cmpFn(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return true;
        }
        return false;
    }

    // find first >= target
    // BlueArea [0, left) < target //means left>=target
    // RedArea (right, END) >= target  //means right+1 >= target
    // answer = right+1  or left
    /*
   INT_MAX
   left = right+1 = LEN, right=LEN-1;
   INT_MIN  left=0; right=left-1=-1;

    */
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) { // 闭区间[left, right]非空
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> findRightIntervalM1(vector<vector<int>>& intervals) {
        unordered_map<int, int> start2i;
        vector<int> starts;
        for (int i = 0; i < intervals.size(); i++) {
            start2i[intervals[i][0]] = i;
            starts.push_back(intervals[i][0]);
        }
        //sort(intervals.begin(), intervals.end(), cmpFn);
        vector<int> res;
        sort(starts.begin(), starts.end());
        for (auto& val: intervals) {
            // find first >= end
            //int j = lower_bound(starts.begin(), starts.end(), val[1]) - starts.begin();
            int j = lowerBound(starts, val[1]);
            if (j == starts.size()) { // means not found
                res.push_back(-1);
                continue;
            }
            int nearS = starts[j];
            res.push_back(start2i[nearS]);
        }
        return res;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> lefts;
        vector<pair<int, int>> rights;
        for (int i = 0; i < intervals.size(); i++) {
            lefts.push_back(make_pair(intervals[i][0], i));
            rights.push_back(make_pair(intervals[i][1],i ));
        }
        sort(lefts.begin(), lefts.end());
        sort(rights.begin(), rights.end());
        int i = 0;
        int j = 0;
        vector<int> res(lefts.size(), 0);
        while (i < rights.size()) {
            int idx = rights[i].second;
            while((j < lefts.size()) && ( rights[i].first > lefts[j].first)) {
                j++;
            }
            // means lefts[j].first >= rights[i].first  or j == lefts.size()
            if (j == lefts.size()) {
                res[idx] = -1;
            } else {
                res[idx] = lefts[j].second;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

/*
Wrong Answer
7/20 cases passed (N/A)
Testcase
[[3,4],[2,3],[1,2]]
Answer
[1,0,-1]
Expected Answer
[-1,0,1]

Wrong Answer
11/20 cases passed (N/A)
Testcase
[[1,4],[2,3],[3,4]]
Answer
[-1,2,0]
Expected Answer
[-1,2,-1]


*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


