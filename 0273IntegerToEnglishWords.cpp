/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-07
 * @tag   simulation
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
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 *
 * https://leetcode.cn/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (36.55%)
 * Likes:    349
 * Dislikes: 0
 * Total Accepted:    43.6K
 * Total Submissions: 118.1K
 * Testcase Example:  '123'
 *
 * 将非负整数 num 转换为其对应的英文表示。
 *
 *
 *
 * 示例 1：
 * 输入：num = 123
 * 输出："One Hundred Twenty Three"
 *
 *
 * 示例 2：
 * 输入：num = 12345
 * 输出："Twelve Thousand Three Hundred Forty Five"
 *
 *
 * 示例 3：
 * 输入：num = 1234567
 * 输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, string> d2str = {
      //  {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "Hundred"}
    };

    vector<string> base = {
        "",
        " Thousand",
        " Million",
        " Billion"
    };

    string numLT1000V2(int num) {
        string curr;
        int hundred = num / 100;
        num %= 100;
        if (hundred != 0) {
            curr = curr + d2str[hundred] + " Hundred ";
        }
        int ten = num / 10;
        if (ten >= 2) {
            curr = curr + d2str[ten*10] + " ";
            num %= 10;
        }
        if (num > 0) {
            curr = curr + d2str[num] + " ";
        }
        while (curr.back() == ' ') {
            curr.pop_back();
        }
        return curr;
    }

    // num == 0-999;
    string numLT1000(int num) {
        if (num == 0) {
            return "";
        }
        string res;
        int h = num/100;
        num = num%100;
        if (h > 0) {
            res += d2str[h] + " Hundred";
        }
        if (num == 0) {
            return res;
        }
        if (h > 0) {
            res += " ";
        }
        if (d2str.count(num)) {
            res += d2str[num];
            return res;
        }
        int ten = num / 10;
        num = num % 10;
        res += d2str[ten * 10] + " " + d2str[num];
        return res;
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        int cur = num;
        vector<string> res;
        int bi = 0;
        while (cur > 0) {
            auto tail = cur % 1000;
            if (tail != 0) {
                string numStr = numLT1000V2(tail);
                string baseStr = base[bi];
                res.push_back(numStr + baseStr);
            }
            bi++;
            cur = cur /1000;
        }
        string str = "";
        for (auto it = res.rbegin(); it != res.rend(); it++) {
            str += *it + " ";
        }
        str.pop_back(); // remove last space
        return str;
    }
};
// @lc code=end

/*

 * 输入：num = 1,234,567
 * 输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty

Billion   1,000,000,000
Million   1,000,000
Thousand   1000
Hundred   100

0 zero

1,000,010
"One Million Ten"

1,000,000,010
"One Billion Ten"


1,000,000,000,010


int占32位，取值范围为-2147483648～2147483647
2147483647
2,147,483,647
Two Billion
One Hundred Forty Seven Million
Four Hundred Eighty Three Thousand
Six Hundred Forty Seven


1214517
"One Million Two Hundred Fourteen Thousand Five Hundred Seventeen"


Wrong Answer
576/601 cases passed (N/A)
Testcase
18
Answer
"Eightteen"
Expected Answer
"Eighteen"


Wrong Answer
584/601 cases passed (N/A)
Testcase
100
Answer
"One Hundred Zero"
Expected Answer
"One Hundred"
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
