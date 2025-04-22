/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-22
 * @tag hashTable, math
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
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 *
 * https://leetcode.cn/problems/x-of-a-kind-in-a-deck-of-cards/description/
 *
 * algorithms
 * Easy (37.17%)
 * Likes:    309
 * Dislikes: 0
 * Total Accepted:    68.1K
 * Total Submissions: 183.5K
 * Testcase Example:  '[1,2,3,4,4,3,2,1]'
 *
 * 给定一副牌，每张牌上都写着一个整数。
 *
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 *
 *
 * 每组都有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 *
 *
 * 仅当你可选的 X >= 2 时返回 true。
 *
 *
 *
 * 示例 1：
 * 输入：deck = [1,2,3,4,4,3,2,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
 *
 *
 * 示例 2：
 * 输入：deck = [1,1,1,2,2,2,3,3]
 * 输出：false
 * 解释：没有满足要求的分组。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= deck.length <= 10^4
 * 0 <= deck[i] < 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> n2cnt;
        for (auto& n : deck) {
            n2cnt[n]++;
        }
        int g = n2cnt[deck[0]];
        for (auto& [k, v]: n2cnt) {
            g = gcd(v, g);
        }
        return g >=2;
    }

    int gcd(int x, int y) {
        int tmp = 0;
        while (y > 0) {
            tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }

    int gcd2(int x, int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y, x % y);
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


