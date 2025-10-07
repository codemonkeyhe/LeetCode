/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-07
 * @tag string,hashmap
 * @similar  12, 273
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 *
 * https://leetcode.cn/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (67.13%)
 * Likes:    1387
 * Dislikes: 0
 * Total Accepted:    557.5K
 * Total Submissions: 811.1K
 * Testcase Example:  '3749'
 *
 * 七个不同的符号代表罗马数字，其值如下：
 *
 *
 *
 *
 * 符号 * 值
 * I  1
 * V  5
 * X  10
 * L  50
 * C  100
 * D  500
 * M  1000
 *
 * 罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：
 * 如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
 * 如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减
 * 1 (I)：IX。仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
 * 只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。你不能多次附加 5 (V)，50 (L) 或 500
 * (D)。如果需要将符号附加4次，请使用 减法形式。
 *
 *
 * 给定一个整数，将其转换为罗马数字。
 *
 *
 *
 * 示例 1：
 * 输入：num = 3749
 * 输出： "MMMDCCXLIX"
 * 解释：
 * 3000 = MMM 由于 1000 (M) + 1000 (M) + 1000 (M)
 * ⁠700 = DCC 由于 500 (D) + 100 (C) + 100 (C)
 * ⁠ 40 = XL 由于 50 (L) 减 10 (X)
 * ⁠  9 = IX 由于 10 (X) 减 1 (I)
 * 注意：49 不是 50 (L) 减 1 (I) 因为转换是基于小数位
 *
 *
 *
 * 示例 2：
 * 输入：num = 58
 * 输出："LVIII"
 *
 * 解释：
 * 50 = L
 * ⁠8 = VIII
 *
 *
 *
 * 示例 3：
 * 输入：num = 1994
 * 输出："MCMXCIV"
 * 解释：
 * 1000 = M
 * ⁠900 = CM
 * ⁠ 90 = XC
 * ⁠  4 = IV
 *
 *
 *
 * 提示：
 * 1 <= num <= 3999
 *
 *
 */

// @lc code=start
class SolutionUgly {
public:
    unordered_map<int, string> roman = {
        {  1    , "I"},
        {  5    , "V"},
        {  10   , "X"},
        {  50   , "L"},
        {  100  , "C"},
        {  500  , "D"},
        {  1000 , "M"},
    };

    unordered_map<int, string> roman49 = {
        {  4    , "IV"},
        {  9   , "IX"},
        {  40   , "XL"},
        {  90  , "XC"},
        {  400  , "CD"},
        {  900 , "CM"},
    };


    string intToRoman(int num) {
        string res = "";
        vector<string> nodes;
        int wei = 1;
        while (num > 0) {
            int dig = num%10;
            num = num /10;
            if (dig != 0 ) {
                // ERROR CASE  miss if (dig != 0)
                auto tmp = getRoman(dig * wei, dig);
                nodes.push_back(tmp);
            }
            wei *= 10;
        }
        for (int i = nodes.size()-1; i >= 0; i--) {
            res += nodes[i];
        }

        return res;
    }

    string getRoman(int num, int dig) {
        if (roman.count(num)) {
            return roman[num];
        }
        if (dig == 4 || dig == 9) {
            return roman49[num];
        }
        if  (num < 5) {
            return build("I", dig);
        } else if (num < 10) {
            return "V" + build("I", dig - 5);
        } else if (num < 50) {
            return build("X", dig);
        } else if (num < 100) {
            return "L" + build("X", dig - 5);
        } else if (num < 500) {
            return build("C", dig);
        } else if (num < 1000) {
            return "D" + build("C", dig - 5);
        } else if (num <= 3999) {
            return build("M", dig);
        } else  {
            return "ERROR";
        }
        return "Unknown";
    }

    string build(string c, int times) {
        if (times == 0) {
            return c;
        }
        string s = "";
        while (times > 0) {
            s += c;
            times--;
        }
        return s;
    }

};



class Solution {
public:
    vector<pair<int, string> > roman = {
        {  1000 , "M"},
        {  900 , "CM"},
        {  500  , "D"},
        {  400  , "CD"},
        {  100  , "C"},
        {  90  , "XC"},
        {  50   , "L"},
        {  40   , "XL"},
        {  10   , "X"},
        {  9   , "IX"},
        {  5    , "V"},
        {  4    , "IV"},
        {  1    , "I"},
    };



    string intToRoman(int num) {
        string res = "";
        for (auto [val, rm] : roman) {
            while(num >= val) {
                num -= val;
                res += rm;
            }
        }
        return res;
    }

};
// @lc code=end


/*
Wrong Answer
3006/3999 cases passed (N/A)
Testcase
10
Answer
"XI"
Expected Answer
"X"

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


