/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-21
 * @tag  simulation, recursion
 * @similar  1518, 3100
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换水问题
 *
 * https://leetcode.cn/problems/water-bottles/description/
 *
 * algorithms
 * Easy (69.70%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    83.6K
 * Total Submissions: 117K
 * Testcase Example:  '9\n3'
 *
 * 超市正在促销，你可以用 numExchange 个空水瓶从超市兑换一瓶水。最开始，你一共购入了 numBottles 瓶水。
 * 如果喝掉了水瓶中的水，那么水瓶就会变成空的。
 * 给你两个整数 numBottles 和 numExchange ，返回你 最多 可以喝到多少瓶水。
 *
 *
 *
 * 示例 1：
 * 输入：numBottles = 9, numExchange = 3
 * 输出：13
 * 解释：你可以用 3 个空瓶兑换 1 瓶水。
 * 所以最多能喝到 9 + 3 + 1 = 13 瓶水。
 *
 *
 * 示例 2：
 * 输入：numBottles = 15, numExchange = 4
 * 输出：19
 * 解释：你可以用 4 个空瓶兑换 1 瓶水。
 * 所以最多能喝到 15 + 3 + 1 = 19 瓶水。
 * 15+3(3)+1(2)
 *
 *
 *
 *
 *
 * 提示：
 * 1 <= numBottles <= 100
 * 2 <= numExchange <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0;
        total += numBottles;
        int water = 0;
        int extraBot = 0;
        while (numBottles >= numExchange) {
            water = numBottles/numExchange;
            total += water;
            extraBot = numBottles % numExchange;
            numBottles = water + extraBot;
        }
        return total;
    }



};
// @lc code=end


/*
变体：
https://www.nowcoder.com/questionTerminal/fe298c55694f4ed39e256170ff2c205f

某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
小张手上有 n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。



*/


int bot3Error(int numBot) {
    int total = 0;
    int water = 0;
    int extraBot = 0;
    while (numBot >= 3) {
        water = numBot / 3;
        extraBot = numBot % 3;
        numBot = water + extraBot;
        total += water;
    }
    return total;
}


int bot3(int numBot) {
    int total = 0;
    int water = 0;
    int extraBot = 0;
    while (numBot >= 3) {
        water = numBot / 3;
        extraBot = numBot % 3;
        numBot = water + extraBot;
        total += water;
    }
    if (numBot == 2) { // 借1个瓶子，喝完水，归还
        total += 1;
    }
    return total;
}


// 2个瓶子换1瓶牛奶，有N元

int milk(int n) {
    int total = 0;
    int milk = n;
    total += milk;
    int bot = n;
    int extraBot = 0;
    while (bot >= 2) {
        milk = bot / 2;
        extraBot = bot % 2;
        total += milk;
        bot = milk + extraBot;
    }
    return total;
}

/* 递归版本


 int bottle(int bot) {
     if (bot < 2 ) {
         return 0;
     }
     if (bot == 2) {
         return 1;
     }

     int full = bot/2;
     int extra = bot%2;
     int leftBot = full + extra;
     return full+ bottle(leftBot);
 }

int main()
{
    for (int i = 0; i <= 10; i++) {
         cout << "i=" << i << " bottle=" <<  i+ bottle(i) << endl;
    }


    std::cout << "Hello World";
    return 0;
}
*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
