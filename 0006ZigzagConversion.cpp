/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-22
 * @tag  string
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
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode.cn/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (52.85%)
 * Likes:    2497
 * Dislikes: 0
 * Total Accepted:    788.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 *
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 * 请你实现这个将字符串进行指定行数变换的函数：
 * string convert(string s, int numRows);
 *
 *
 *
 * 示例 1：
 * 输入：s = "PAYPALISHIRING", numRows = 3
 * 输出："PAHNAPLSIIGYIR"
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * 示例 2：
 * 输入：s = "PAYPALISHIRING", numRows = 4
 * 输出："PINALSIGYAHRPI"
 * 解释：
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 *
 * 示例 3：
 * 输入：s = "A", numRows = 1
 * 输出："A"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 由英文字母（小写和大写）、',' 和 '.' 组成
 * 1 <= numRows <= 1000
 *
 *
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        //if (n == 1 || (numRows == 1)) {
        if (numRows == 1 || (numRows >= n)) {
            return s;
        }
        int blockSize = numRows + numRows - 2;
        int cols = (n / blockSize + 1) * (numRows - 1);
       // cout << " cols=" << cols << endl;
        vector<vector<char>> vv(numRows, vector<char>(cols, ' '));
        int i = 0;
        int j = 0;
        //bool down = true;
        for (int k = 0; k < n; k++) {
        //    cout << "k=" << k <<  " i=" << i << " j=" << j << endl;
            vv[i][j] = s[k];
            /*
            if (i == numRows -1) {
                down = false;
            } else if ((down == false) && (i == 0)) {
                down = true;
            }
            */
          //  if (down) {
            if (k % blockSize < numRows - 1) {
                i++;
            } else {
                i--;
                j++;
            }
        }

        string res = "";
        for (int a = 0; a < numRows; a++) {
            for (int b = 0; b < cols; b++) {
                if (vv[a][b] != ' ') {
                    res += vv[a][b];
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
Runtime Error
2/1157 cases passed (N/A)
Error
Line 6: Char 23: runtime error: division by zero (solution.cpp)
Line 6: Char 23: runtime error: division by zero (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:15:23
Testcase
"A"
1
Expected Answer
"A"



k % blockSize < numRows - 1


 * 输入：s = "PAYPALISHIRING", numRows = 3
 * 输出："PAHNAPLSIIGYIR"
 0 P   A   H   N
 1 A P L S I I G
 2 Y   I   R

blockSize=3*3-2=4
k%4 < 3-1
K%4 < 2



*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


