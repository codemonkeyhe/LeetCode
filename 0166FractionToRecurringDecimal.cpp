/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-07
 * @tag hashtable,math
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
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode.cn/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (33.47%)
 * Likes:    491
 * Dislikes: 0
 * Total Accepted:    69.7K
 * Total Submissions: 208.2K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 如果存在多个答案，只需返回 任意一个 。
 * 对于所有给定的输入，保证 答案字符串的长度小于 10^4 。
 *
 *
 *
 * 示例 1：
 * 输入：numerator = 1, denominator = 2
 * 输出："0.5"
 *
 *
 * 示例 2：
 * 输入：numerator = 2, denominator = 1
 * 输出："2"
 *
 *
 * 示例 3：
 * 输入：numerator = 4, denominator = 333
 * 输出："0.(012)"
 *
 *
 *
 *
 * 提示：
 * -2^31 <= numerator, denominator <= 2^31 - 1
 * denominator != 0
 *
 *
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        return divide(numerator, denominator);
    }

    /* useless, covered by up%down
    if (up == 0) {
        return "0";
    }
    */
    string divide(long up, long down) {
        if (up % down == 0) {
            return to_string(up / down);
        }

        int belowZero = 0;
        if (up < 0) {
            up = -up;
            belowZero++;
        }
        if (down < 0) {
            down = -down;
            belowZero++;
        }
        bool isPositive = (belowZero == 1) ? false : true;
        string res = "";
        if (!isPositive) {
            res+="-";
        }
        int left = up / down;
        res += to_string(left) + ".";
        long next = up % down; //保证next<down

        unordered_map<int, int> num2idx;

        int idx = 0;
        int loopBegin = -1;
        string dotPart = "";
        while (next > 0) {// cal dotPart
            if (num2idx.count(next)) {
                loopBegin = num2idx[next];
                break;
            }
            num2idx[next] = idx;
            next = next * 10;
            int part = next/down;
            int todo = next % down;
            dotPart += to_string(part);
            //cout << "idx=" << idx << " todo=" << todo << " next=" << next << endl;
            next = todo;
            idx++;
        }

        if (loopBegin >= 0) {
            string p1 = dotPart.substr(0, loopBegin);
            string p2 = dotPart.substr(loopBegin);
            return res + p1 + "(" + p2 + ")";
        }
        return res + dotPart;
    }
};
// @lc code=end


/*
执行出错
30 / 41 个通过的测试用例
Line 16: Char 20: runtime error: negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:25:20
最后执行的输入
添加到测试用例
numerator =
-1
denominator =
-2147483648


坑1 next为int不行，要用 long long
坑2 循环分割点的处理

坑3 竖式除法补0的逻辑细节没想清楚，比如 4/333
为何一次性补齐2个零，而不是每次补一个0

坑4 hashmap的更新环节

4/333=0.012不是好例子，因为小数点后面的值012和idx的增长0,1,2容易混淆


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


