/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-05
 * @tag hashmap
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
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 *
 * https://leetcode.cn/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (85.65%)
 * Likes:    824
 * Dislikes: 0
 * Total Accepted:    225.8K
 * Total Submissions: 263.6K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 *  给你一个字符串 jewels 代表石头中宝石的类型，另有一个字符串 stones 代表你拥有的石头。 stones
 * 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
 *
 * 字母区分大小写，因此 "a" 和 "A" 是不同类型的石头。
 *
 *
 *
 * 示例 1：
 * 输入：jewels = "aA", stones = "aAAbbbb"
 * 输出：3
 *
 *
 * 示例 2：
 * 输入：jewels = "z", stones = "ZZ"
 * 输出：0
 *
 *
 *
 *
 * 提示：
 * 1 <= jewels.length, stones.length <= 50
 * jewels 和 stones 仅由英文字母组成
 * jewels 中的所有字符都是 唯一的
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int hmap[255] = {0};
        for (int i = 0; i < jewels.size(); i++) {
            hmap[jewels[i]] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (hmap[stones[i]] == 1) {
                cnt++;
            }
        }
        return cnt;
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


