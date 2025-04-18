/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-18
 * @tag twoPointers,string
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
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 *
 * https://leetcode.cn/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (63.58%)
 * Likes:    573
 * Dislikes: 0
 * Total Accepted:    81.4K
 * Total Submissions: 128.1K
 * Testcase Example:  '"00110011"'
 *
 * 给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是成组连续的。
 *
 * 重复出现（不同位置）的子串也要统计它们出现的次数。
 *
 *
 * 示例 1：
 * 输入：s = "00110011"
 * 输出：6
 * 解释：6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
 * 注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
 * 另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。
 *
 * 示例 2：
 * 输入：s = "10101"
 * 输出：4
 * 解释：有 4 个子串："10"、"01"、"10"、"01" ，具有相同数量的连续 1 和 0 。
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 10^5
 * s[i] 为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution {
public:
// Your runtime beats 58.66 % of cpp submissions
    int countBinarySubstringsUgly(string s) {
        int len = s.size();
        int cnt = 0;
        int i = 0;
        int j = 0;
        int p1 = -1;
        int p2 = -1;
        int c0 = 0;
        int c1 = 0;
        while(i < len && j < len) {
            while(j < len) {
                if (s[j] == '0') {
                    c0++;
                } else { // 1
                    c1++;
                }
                if ((j < len-1) && (s[j] != s[j+1])) {
                    p1 = p2;
                    p2 = j;
                    if (p1>=0) {
                        j++;
                        break;
                    }
                }
                j++;
            }
            //count [i, j-1]
            cnt+= min(c0, c1);
            //cout << "i=" << i << " j=" << j << " c0=" << c0 << " c1=" << c1 << endl;
            if (j==len) {
                break;
            }
            i = p1;
            if (s[i] == '1') {
                c1 = 0;
            } else {
                c0 = 0;
            }
            i++;
        }
        return cnt;

    }


    int countBinarySubstrings(string s) {
        int len = s.size();
        int i = 0;
        int j = 0;
        int c3 = 0;
        int c4 = 0;
        int cnt = 0;
        while(i < len && j < len) {
            char& cur = s[i];
            j = i;
            c3 = 0;
            while(j < len) {
                if (s[j] != cur) {
                    break;
                }
                c3++;
                j++;
            }
            cnt += min(c3, c4);
            i = j;
            c4 = c3;
        }
        return cnt;
    }

};
// @lc code=end

/*
思路对了，但是实现复杂，分段的代码复杂了
把双指针实现成了四指针

0和1的计数也复杂了，不用关心0和1，拆分计数就好了

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


