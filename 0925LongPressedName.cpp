/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-21
 * @tag twoPointers
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
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 *
 * https://leetcode.cn/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (37.31%)
 * Likes:    323
 * Dislikes: 0
 * Total Accepted:    80K
 * Total Submissions: 214.5K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
 *
 * 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
 *
 *
 *
 * 示例 1：
 * 输入：name = "alex", typed = "aaleex"
 * 输出：true
 * 解释：'alex' 中的 'a' 和 'e' 被长按。
 *
 *
 * 示例 2：
 * 输入：name = "saeed", typed = "ssaaedd"
 * 输出：false
 * 解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
 *
 *
 *
 *
 * 提示：
 * 1 <= name.length, typed.length <= 1000
 * name 和 typed 的字符都是小写字母
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nlen = name.size();
        int tlen = typed.size();
        if (nlen > tlen) {
            return false;
        }
        if (nlen == tlen) {
            return (name == typed);
        }
        int i = 0;
        int j = 0;
        while (i < nlen && j < tlen) {
            if (typed[j] != name[i]) {
                return false;
            }
            while (i < nlen && (j < tlen) && (typed[j] == name[i])) {
                j++;
                i++;
            }
            i--;
            while ((j < tlen) && (typed[j] == name[i])) {
                j++;
            }
            i++;
        }
        if (i == nlen && j == tlen) {
            return true;
        }
        return false;
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


