/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-18
 * @tag sort
 * @similar  56, 763
 */

/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
/*
 修改intervals 就地合并
Runtime: 44 ms, faster than 75.13% of C++ online submissions for Merge Intervals.
Memory Usage: 14.3 MB, less than 89.83% of C++ online submissions for Merge Intervals.
Ugly
//区间就地合并，int1=megre(int1, int2);
*/
    vector<vector<int>> mergeUgly(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 1) {
            res.push_back(intervals[0]);
            return res;
        }
        int pre = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[pre][1] < intervals[i][0]) { //pre区间和i区间不重合
                res.push_back(intervals[pre]);
                pre = i;
                if (i == n - 1) {  //收尾
                    res.push_back(intervals[i]);
                }
                continue;
            } else if (intervals[pre][1] < intervals[i][1]) { //两区间重合
                intervals[pre][1] = intervals[i][1];
                if (i == n - 1) {  //收尾
                    res.push_back(intervals[pre]);
                }
            } else { //pre区间 包含 i区间
                if (i == n - 1) {  //收尾
                    res.push_back(intervals[pre]);
                }
            }
        }
        return res;
    }

    /*
    代码优化版
Runtime: 52 ms, faster than 52.70% of C++ online submissions for Merge Intervals.
Memory Usage: 14.2 MB, less than 98.82% of C++ online submissions for Merge Intervals.
//区间就地合并，int1=megre(int1, int2);
            //else { //pre区间 包含 i区间 }
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        int n = intervals.size();
        if (n == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        int pre = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[pre][1] < intervals[i][0]) { //pre区间和i区间不重合
                res.push_back(intervals[pre]);
                pre = i;
            } else if (intervals[pre][1] < intervals[i][1]) { //两区间重合
                intervals[pre][1] = intervals[i][1];
            }
        }
        //最后一个区间的收尾工作
        res.push_back(intervals[pre]);
        return res;
    }




/*
不修改intervals
每次把cur区间与res[last]去比较，重合的话修改res[last]，相当于包含了cur区间
不重合 res.push_back(cur);
Runtime: 48 ms, faster than 66.18% of C++ online submissions for Merge Intervals.
Memory Usage: 14.3 MB, less than 93.52% of C++ online submissions for Merge Intervals.

*/
    vector<vector<int>> mergeM2(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        int n = intervals.size();
        if (n==0) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            int& preR = res.back()[1];
            if (preR < intervals[i][0]) {  // pre区间和 cur区间不重合
                res.push_back(intervals[i]);
            } else if(preR < intervals[i][1]){  //两区间重合
                preR  = intervals[i][1];
            }
           // else { //区间覆盖 }
        }
        return res;
    }



};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){

}


int main() {
    Solution s;
}


/*
Tips
M1 修改intervals
就地合并

M2 不修改intervals
在res里面合并

*/


