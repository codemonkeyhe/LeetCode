/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-05
 * @tag greedy
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
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 *
 * https://leetcode.cn/problems/lemonade-change/description/
 *
 * algorithms
 * Easy (59.03%)
 * Likes:    648
 * Dislikes: 0
 * Total Accepted:    278K
 * Total Submissions: 469.1K
 * Testcase Example:  '[5,5,5,10,20]'
 *
 * 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
 * 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
 * 注意，一开始你手头没有任何零钱。
 * 给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false
 * 。
 *
 *
 *
 * 示例 1：
 * 输入：bills = [5,5,5,10,20]
 * 输出：true
 * 解释：
 * 前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
 * 第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
 * 第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
 * 由于所有客户都得到了正确的找零，所以我们输出 true。
 *
 *
 * 示例 2：
 * 输入：bills = [5,5,10,10,20]
 * 输出：false
 * 解释：
 * 前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
 * 对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
 * 对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
 * 由于不是每位顾客都得到了正确的找零，所以答案是 false。
 *
 *
 *
 *
 * 提示：
 * 1 <= bills.length <= 10^5
 * bills[i] 不是 5 就是 10 或是 20 
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int len = bills.size();
        int coin5 = 0;
        int coin10 = 0;
        //int coin20 = 0;   useless
        for (int i = 0; i < len; i++) {
            int& cur = bills[i];
            if (cur == 5) {
                coin5++;
            } else if (cur == 10) {
                if (coin5 <= 0) {
                    return false;
                }
                coin10++;
                coin5--; // give back 5
            } else if (cur == 20) {
                // two way: 5*3  10*5 , greedy use 10 first
                if (coin10 > 0 && coin5 > 0) {
                    coin10--;
                    coin5--;
                    continue;
                }
                if (coin5 >= 3) {
                    coin5 -= 3;
                    continue;
                }
                return false;
            }
        }
        return true;
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


