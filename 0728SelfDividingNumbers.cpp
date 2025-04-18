/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-18
 * @tag math
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
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 *
 * https://leetcode.cn/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (76.31%)
 * Likes:    274
 * Dislikes: 0
 * Total Accepted:    90.5K
 * Total Submissions: 118.5K
 * Testcase Example:  '1\n22'
 *
 * 自除数 是指可以被它包含的每一位数整除的数。
 *
 *
 * 例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
 *
 *
 * 自除数 不允许包含 0 。
 *
 * 给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right]（包括两个端点）内所有的 自除数 。
 *
 *
 *
 * 示例 1：
 * 输入：left = 1, right = 22
 * 输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 *
 *
 * 示例 2:
 * 输入：left = 47, right = 85
 * 输出：[48,55,66,77]
 *
 *
 *
 *
 * 提示：
 * 1 <= left <= right <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>  res;
        for (int i = left; i <= right; i++) {
            if (isSelfDiv(i)) {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isSelfDiv(int num) {
        int n = num;
        while (n > 0) {
            int c = n % 10;
            if (c == 0) {
                return false;
            }
            if (num % c != 0) {
                return false;
            }
            n = n / 10;
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


