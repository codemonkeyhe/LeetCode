/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-11-10
 * @tag  backtracing
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
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 *
 * https://leetcode.cn/problems/24-game/description/
 *
 * algorithms
 * Hard (53.74%)
 * Likes:    515
 * Dislikes: 0
 * Total Accepted:    57.6K
 * Total Submissions: 102.6K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 给定一个长度为4的整数数组 cards 。你有 4 张卡片，每张卡片上都包含一个范围在 [1,9] 的数字。您应该使用运算符 ['+', '-',
 * '*', '/'] 和括号 '(' 和 ')' 将这些卡片上的数字排列成数学表达式，以获得值24。
 *
 * 你须遵守以下规则:
 * 除法运算符 '/' 表示实数除法，而不是整数除法。
 * 例如， 4 /(1 - 2 / 3)= 4 /(1 / 3)= 12 。
 * 每个运算都在两个数字之间。特别是，不能使用 “-” 作为一元运算符。
 * 例如，如果 cards =[1,1,1,1] ，则表达式 “-1 -1 -1 -1” 是 不允许 的。
 * 你不能把数字串在一起
 * 例如，如果 cards =[1,2,1,2] ，则表达式 “12 + 12” 无效。
 *
 *
 * 如果可以得到这样的表达式，其计算结果为 24 ，则返回 true ，否则返回 false 。
 *
 *
 *
 * 示例 1:
 * 输入: cards = [4, 1, 8, 7]
 * 输出: true
 * 解释: (8-4) * (7-1) = 24
 *
 *
 * 示例 2:
 * 输入: cards = [1, 2, 1, 2]
 * 输出: false
 *
 *
 * 提示:
 * cards.length == 4
 * 1 <= cards[i] <= 9
 *
 *
 */

// @lc code=start
class Solution {
public:
    // /ˈepsɪlɒn/
    const double EPSILON = 1e-6;

    bool judgePoint24(vector<int>& cards) {
        vector<double> douCard(cards.begin(), cards.end());
        return  backt(douCard);
    }


    bool backt(vector<double> cards) {
        int lenn = cards.size();
        if (cards.size() == 0) {
            return false;
        }
        if (cards.size() == 1 && fabs(cards[0]-24) <= EPSILON) {
            return true;
        }

        for (int i = 0; i < lenn; i++) {
            for (int j = i+1; j < lenn; j++) {
                // BUG
                //int c1 = cards[i];
                //int c2 = cards[j];
                double c1 = cards[i];
                double c2 = cards[j];
                auto leftCard = getLeftCard(cards, i, j);
                auto opVals = getOptionVal(c1, c2);
                for (auto val : opVals) {
                    leftCard.push_back(val);
                    auto ok  = backt(leftCard);
                    if (ok) {
                        return true;
                    }
                    leftCard.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> getLeftCard(vector<double>& cards, int i, int j) {
        vector<double> res;
        for (int k = 0; k < cards.size(); k++) {
            if (k == i || k == j) {
                continue;
            }
            res.push_back(cards[k]);
        }
        return res;
    }


    vector<double> getOptionVal(double c1, double c2) {
        vector<double> res;
        res.push_back(c1+c2);
        res.push_back(c1-c2);
        res.push_back(c2-c1);
        res.push_back(c1*c2);
        if (fabs(c2) > EPSILON) {// not zero
            res.push_back(c1 / c2);
        }

        if (fabs(c1) > EPSILON) {// not zero
            res.push_back(c2 / c1);
        }
        return res;
    }
};
// @lc code=end


/*
[4, 1, 8, 7]

 * 解释: (8-4) * (7-1) = 24

  [1,9]



DFS空间预估
M1

c1 op c2 op c3 op c4 = 24
op= + - * /

c1-c4  的排列数 4*3*2*1 = 24种
op的组合数 4*4*4 = 64种
计算顺序 op1 op2 op3
顺序排列数 3*2*1=6
总的空间 24*64*6=9216 约等于 10000种

M2
一共有 4 个数和 3 个运算操作，因此可能性非常有限。一共有多少种可能性呢？
首先从 4 个数字中有序地选出 2 个数字，共有 4×3=12 种选法，并选择加、减、乘、除 4 种运算操作之一，用得到的结果取代选出的 2 个数字，剩下 3 个数字。
然后在剩下的 3 个数字中有序地选出 2 个数字，共有 3×2=6 种选法，并选择 4 种运算操作之一，用得到的结果取代选出的 2 个数字，剩下 2 个数字。
最后剩下 2 个数字，有 2 种不同的顺序，并选择 4 种运算操作之一。
因此，一共有 12×4×6×4×2×4=9216 种不同的可能性。


暴力DFS???


作者：灵茶山艾府
链接：https://leetcode.cn/problems/24-game/solutions/3756006/mei-ci-he-bing-liang-zhang-pai-di-gui-xi-0sdu/
设参与运算的两个数为 x 和 y，那么至多有六种运算结果：
x+y,x−y,y−x, x⋅y,
y/ x , x/ y
注意除法需要保证分母不为 0。

Wrong Answer
65/71 cases passed (N/A)
Testcase
[8,1,6,6]
Answer
false
Expected Answer
true

6 / (1 - 6/8)

*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
