/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-09-26
 * @tag   backtracing, dfs, dynamicProgramming
 * @similar 638
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 *
 * https://leetcode.cn/problems/shopping-offers/description/
 *
 * algorithms
 * Medium (62.10%)
 * Likes:    455
 * Dislikes: 0
 * Total Accepted:    51.3K
 * Total Submissions: 82.1K
 * Testcase Example:  '[2,5]\n[[3,0,5],[1,2,10]]\n[3,2]'
 *
 * 在 LeetCode 商店中， 有 n 件在售的物品。每件物品都有对应的价格。然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。
 * 给你一个整数数组 price 表示物品价格，其中 price[i] 是第 i 件物品的价格。另有一个整数数组 needs 表示购物清单，其中
 * needs[i] 是需要购买第 i 件物品的数量。
 *
 * 还有一个数组 special 表示大礼包，special[i] 的长度为 n + 1 ，其中 special[i][j] 表示第 i 个大礼包中内含第
 * j 件物品的数量，且 special[i][n] （也就是数组中的最后一个整数）为第 i 个大礼包的价格。
 *
 * 返回 确切
 * 满足购物清单所需花费的最低价格，你可以充分利用大礼包的优惠活动。你不能购买超出购物清单指定数量的物品，即使那样会降低整体价格。任意大礼包可无限次购买。
 *
 *
 *
 * 示例 1：
 * 输入：price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
 * 输出：14
 * 解释：有 A 和 B 两种物品，价格分别为 ¥2 和 ¥5 。
 * 大礼包 1 ，你可以以 ¥5 的价格购买 3A 和 0B 。
 * 大礼包 2 ，你可以以 ¥10 的价格购买 1A 和 2B 。
 * 需要购买 3 个 A 和 2 个 B ， 所以付 ¥10 购买 1A 和 2B（大礼包 2），以及 ¥4 购买 2A 。
 *
 * 示例 2：
 * 输入：price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
 * 输出：11
 * 解释：A ，B ，C 的价格分别为 ¥2 ，¥3 ，¥4 。
 * 可以用 ¥4 购买 1A 和 1B ，也可以用 ¥9 购买 2A ，2B 和 1C 。
 * 需要买 1A ，2B 和 1C ，所以付 ¥4 买 1A 和 1B（大礼包 1），以及 ¥3 购买 1B ， ¥4 购买 1C 。
 * 不可以购买超出待购清单的物品，尽管购买大礼包 2 更加便宜。
 *
 *
 *
 * 提示：
 * n == price.length == needs.length
 * 1 <= n <= 6
 * 0 <= price[i], needs[i] <= 10
 * 1 <= special.length <= 100
 * special[i].length == n + 1
 * 0 <= special[i][j] <= 50
 * 生成的输入对于 0 <= j <= n - 1 至少有一个 special[i][j] 非零。
 *
 *
 */

// @lc code=start
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int len = price.size();
        vector<vector<int>> validSp;
        for (auto vv : special) {
            bool isValid = true;
            int cnt = 0;
            int totalPrice = 0;
            for (int i = 0; i < len; i++) {
                cnt += vv[i];
                totalPrice += vv[i] * price[i];
                if (vv[i] > needs[i]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                //  大礼包不合法 或者  大礼包一点都不优惠
                if (cnt == 0 || (totalPrice <= vv[len])) {
                    isValid = false;
                }
            }
            if (isValid) {
                validSp.push_back(vv);
            }
        }

        int minPrice = bt(price, validSp, needs);
        return minPrice;
    }

    int bt(vector<int> &price, vector<vector<int>> &bags, vector<int> &needs) {
        int len = needs.size();
        int needCnt = 0;
        for (auto ne : needs) {
            needCnt += ne;
        }
        if (needCnt == 0) {
            return 0;
        }

        // no use special cost
        int stdPrice = 0;
        for (int i = 0; i < len; i++) {
            stdPrice += price[i] * needs[i];
        }

        // use special cost
        int minPrice = stdPrice;
        for (int i = 0; i < bags.size(); i++) {
            auto& vv = bags[i];
            bool use = true;
            for (int j = 0; j < len; j++) {
                if (vv[j] > needs[j]) {
                    use = false;
                    break;
                }
            }
            if (!use) {
                continue;
            }
            // use vv
            for (int j = 0; j < len; j++) {
                needs[j] -= vv[j];
            }
            int curPrice = bt(price, bags, needs) + vv[len];
            // revert needs
            minPrice = min(curPrice, minPrice);
            for (int j = 0; j < len; j++) {
                needs[j] += vv[j];
            }
        }
        return minPrice;
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
