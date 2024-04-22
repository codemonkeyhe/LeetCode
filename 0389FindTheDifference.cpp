/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-22
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
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode.cn/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (64.55%)
 * Likes:    463
 * Dislikes: 0
 * Total Accepted:    204K
 * Total Submissions: 316.2K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t ，它们只包含小写字母。
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 请找出在 t 中被添加的字母。
 *
 *
 *
 * 示例 1：
 * 输入：s = "abcd", t = "abcde"
 * 输出："e"
 * 解释：'e' 是那个被添加的字母。
 *
 *
 * 示例 2：
 * 输入：s = "", t = "y"
 * 输出："y"
 *
 *
 * 提示：
 * 0 <= s.length <= 1000
 * t.length == s.length + 1
 * s 和 t 只包含小写字母
 *
 *
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[27] = {0};
        for (int i = 0; i < t.size(); i++) {
            int c = t[i]-'a';
            arr[c] += 1;
        }

        for (int i = 0; i < s.size(); i++) {
            int c = s[i]-'a';
            arr[c] -= 1;
        }

        for (int i = 0; i < 27; i++) {
            if (arr[i] == 1) {
                return char(int('a')+i);
            }
        }
        return ' ';
    }
};
// @lc code=end


/*
方法一：计数

方法二：求和
将字符串 sss 中每个字符的 ASCII 码的值求和，得到S ​ ；对字符串 ttt 同样的方法得到 T
 。两者的差值 T-S 即代表了被添加的字符。


方法三：位运算
如果将两个字符串拼接成一个字符串，则问题转换成求字符串中出现奇数次的字符。类似于「136. 只出现一次的数字」，我们使用位运算的技巧解决本题


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


