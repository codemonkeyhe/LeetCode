/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-21
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
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 *
 * https://leetcode.cn/problems/fair-candy-swap/description/
 *
 * algorithms
 * Easy (63.55%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    77.9K
 * Total Submissions: 122K
 * Testcase Example:  '[1,1]\n[2,2]'
 *
 * 爱丽丝和鲍勃拥有不同总数量的糖果。给你两个数组 aliceSizes 和 bobSizes ，aliceSizes[i] 是爱丽丝拥有的第 i
 * 盒糖果中的糖果数量，bobSizes[j] 是鲍勃拥有的第 j 盒糖果中的糖果数量。
 *
 * 两人想要互相交换一盒糖果，这样在交换之后，他们就可以拥有相同总数量的糖果。一个人拥有的糖果总数量是他们每盒糖果数量的总和。
 *
 * 返回一个整数数组 answer，其中 answer[0] 是爱丽丝必须交换的糖果盒中的糖果的数目，answer[1]
 * 是鲍勃必须交换的糖果盒中的糖果的数目。如果存在多个答案，你可以返回其中 任何一个 。题目测试用例保证存在与输入对应的答案。
 *
 *
 *
 * 示例 1：
 * 输入：aliceSizes = [1,1], bobSizes = [2,2]
 * 输出：[1,2]
 *
 *
 * 示例 2：
 * 输入：aliceSizes = [1,2], bobSizes = [2,3]
 * 输出：[1,2]
 *
 *
 * 示例 3：
 * 输入：aliceSizes = [2], bobSizes = [1,3]
 * 输出：[2,3]
 *
 *
 * 示例 4：
 * 输入：aliceSizes = [1,2,5], bobSizes = [2,4]
 * 输出：[5,4]
 *
 *
 *
 *
 * 提示：
 * 1 <= aliceSizes.length, bobSizes.length <= 10^4
 * 1 <= aliceSizes[i], bobSizes[j] <= 10^5
 * 爱丽丝和鲍勃的糖果总数量不同。
 * 题目数据保证对于给定的输入至少存在一个有效答案。
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwapV1(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        int sumB = 0;
        for(auto& candy: aliceSizes) {
            sumA += candy;
        }

        for(auto& candy: bobSizes) {
            sumB += candy;
        }
        int avg = (sumA + sumB) / 2;
        int diff = avg - sumA; //
        for (int i = 0; i < aliceSizes.size(); i++) {
            for (int j = 0; j < bobSizes.size(); j++) {
                if (bobSizes[j] - aliceSizes[i] == diff) {
                    return vector<int>{aliceSizes[i], bobSizes[j]};
                }
            }
        }
        return vector<int>{0,0};
    }

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0;
        int sumB = 0;
        for(auto& candy: aliceSizes) {
            sumA += candy;
        }

        for(auto& candy: bobSizes) {
            sumB += candy;
        }
        int diff = (sumB - sumA) / 2;

        unordered_set<int> bob(bobSizes.begin(), bobSizes.end());

        for (int i = 0; i < aliceSizes.size(); i++) {
            int want = aliceSizes[i] + diff;
            if (bob.count(want)) {
                return vector<int>{aliceSizes[i], want};
            }
        }
        return vector<int>{0, 0};
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


