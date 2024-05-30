/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-29
 * @tag math
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 *
 * https://leetcode.cn/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (71.52%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    183.7K
 * Total Submissions: 256.8K
 * Testcase Example:  '"A"'
 *
 * 给你一个字符串 columnTitle ，表示 Excel 表格中的列名称。返回 该列名称对应的列序号 。
 *
 * 例如：
 *
 *
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * ...
 *
 *
 *
 * 示例 1:
 * 输入: columnTitle = "A"
 * 输出: 1
 *
 *
 * 示例 2:
 * 输入: columnTitle = "AB"
 * 输出: 28
 *
 *
 * 示例 3:
 * 输入: columnTitle = "ZY"
 * 输出: 701
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= columnTitle.length <= 7
 * columnTitle 仅由大写英文组成
 * columnTitle 在范围 ["A", "FXSHRXW"] 内
 *
 *
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        //string i2a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        unsigned long  res = 0;
        int len = columnTitle.size();
        int i = len-1;
        unsigned long weight = 1;
        while (i>=0) {
            int num = columnTitle[i] - 'A' + 1;
            res += weight * num;
            weight  = weight * 26;
            i--;
        }
        return res;
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


