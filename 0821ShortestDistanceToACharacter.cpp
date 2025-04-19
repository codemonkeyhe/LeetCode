/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-19
 * @tag twoPointers, array
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
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 *
 * https://leetcode.cn/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (72.75%)
 * Likes:    367
 * Dislikes: 0
 * Total Accepted:    83.1K
 * Total Submissions: 114.2K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * 给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。
 *
 * 返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近
 * 的字符 c 的 距离 。
 *
 * 两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。
 *
 *
 *
 * 示例 1：
 * 输入：s = "loveleetcode", c = "e"
 * 输出：[3,2,1,0,1,0,0,1,2,2,1,0]
 * 解释：字符 'e' 出现在下标 3、5、6 和 11 处（下标从 0 开始计数）。
 * 距下标 0 最近的 'e' 出现在下标 3 ，所以距离为 abs(0 - 3) = 3 。
 * 距下标 1 最近的 'e' 出现在下标 3 ，所以距离为 abs(1 - 3) = 2 。
 * 对于下标 4 ，出现在下标 3 和下标 5 处的 'e' 都离它最近，但距离是一样的 abs(4 - 3) == abs(4 - 5) = 1 。
 * 距下标 8 最近的 'e' 出现在下标 6 ，所以距离为 abs(8 - 6) = 2 。
 *
 *
 * 示例 2：
 * 输入：s = "aaab", c = "b"
 * 输出：[3,2,1,0]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s[i] 和 c 均为小写英文字母
 * 题目数据保证 c 在 s 中至少出现一次
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.size();
        int i = 0;
        int j = 0;
        vector<int>  res(len, 0);
        while(i<len && j < len) {
            j = i;
            while(j < len) {
                if (s[j] == c) {
                    break;
                }
                j++;
            }
            int m = i;
            int n = j-1;
            int dis = 1;
            while(m<=n) {
                if (m != 0) {
                    res[m] = dis;
                    m++;
                }
                if (n != len-1) {
                    res[n] = dis;
                    n--;
                }
                dis++;
            }
            i = j+1;
        }
        return res;
    }
};
// @lc code=end

/*
M1 TwoPointers


M2 2次扫描

1st: left to right ， 求char c右侧的距离
2nd: right to left,  求char c左侧的距离，同时和1st的距离做比较，取Min
c  - d1 - s - d2 -  c
1st为了求d1
2nd为了求d2， s的距离= min(d1, d2)


*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


