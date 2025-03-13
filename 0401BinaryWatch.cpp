/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-13
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 *
 * https://leetcode.cn/problems/binary-watch/description/
 *
 * algorithms
 * Easy (62.85%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    78.1K
 * Total Submissions: 124.3K
 * Testcase Example:  '1'
 *
 * 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。每个 LED 代表一个 0 或
 * 1，最低位在右侧。
 *
 *
 * 例如，下面的二进制手表读取 "4:51" 。
 *
 * 给你一个整数 turnedOn ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
 *
 * 小时不会以零开头：
 * 例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
 *
 *
 * 分钟必须由两位数组成，可能会以零开头：
 * 例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。
 *
 *
 *
 *
 * 示例 1：
 * 输入：turnedOn = 1
 * 输出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 *
 *
 * 示例 2：
 * 输入：turnedOn = 9
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 * 0 <= turnedOn <= 10
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, vector<string> > hourL;
    unordered_map<int, vector<string> > minL;

    Solution() {
        hourL =  {
            {0, {"0:"}},
            {1, {"1:","2:","4:", "8:" }},
            {2, {"3:","5:","9:", "6:", "10:" }},
            {3, {"7:","11:"} }
        };


        minL = {
            {0, {"00"}},
            {1, {"01", "02", "04", "08", "16", "32"}},
            {2, {"03", "05", "09", "17", "33", "06", "10", "18", "34", "12", "20", "36", "24", "40", "48"}},
            {3, {"07", "11", "19", "35", "13", "21", "37", "25", "41", "49", "14", "22", "38", "26", "42", "50", "28", "44", "52","56"}},
            {4, {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58" }},
            {5, {"31", "47", "55", "59"}}
        };
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        if (turnedOn >= 9) {
            return res;
        }
        bf(turnedOn, res);
        return res;
    }


    void bf(int turnedOn, vector<string>& res) {
        int maxH = 3;
        int maxM = 5;
        for (int i = 0; i <= turnedOn; i++) {
            if (i > maxH) {
                continue;
            }
            int j = turnedOn - i;
            if (j > maxM)  {
                continue;
            }
            vector<string> hList = hourL[i];
            vector<string> mList = minL[j];
            for (int k = 0; k < hList.size(); k++) {
                for (int m = 0; m < mList.size(); m++) {
                    string ss = hList[k] + mList[m];
                    res.push_back(ss);
                }
            }
        }
        return ;
    }

};
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


