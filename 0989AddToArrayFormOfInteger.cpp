/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-21
 * @tag array,math
 * @similar 2,415
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 *
 * https://leetcode.cn/problems/add-to-array-form-of-integer/description/
 *
 * algorithms
 * Easy (45.21%)
 * Likes:    265
 * Dislikes: 0
 * Total Accepted:    80.9K
 * Total Submissions: 179.7K
 * Testcase Example:  '[1,2,0,0]\n34'
 *
 * 整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。
 * 例如，对于 num = 1321 ，数组形式是 [1,3,2,1] 。
 * 给定 num ，整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：num = [1,2,0,0], k = 34
 * 输出：[1,2,3,4]
 * 解释：1200 + 34 = 1234
 *
 *
 * 示例 2：
 * 输入：num = [2,7,4], k = 181
 * 输出：[4,5,5]
 * 解释：274 + 181 = 455
 *
 *
 * 示例 3：
 * 输入：num = [2,1,5], k = 806
 * 输出：[1,0,2,1]
 * 解释：215 + 806 = 1021
 *
 *
 *
 *
 * 提示：
 * 1 <= num.length <= 10^4
 * 0 <= num[i] <= 9
 * num 不包含任何前导零，除了零本身
 * 1 <= k <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> addToArrayFormV1(vector<int>& num, int k) {
        int len = num.size();
        reverse(num.begin(), num.end());
        vector<int> res;
        while (k > 0) {
            res.push_back(k%10);
            k = k/10;
        }
        int rlen = res.size();
        if (rlen <= len) {
            res.resize(len+1);
        } else {
            res.resize(rlen+1);
        }

        int flen = res.size();
        int i = 0, j = 0;
        int ac = 0;
        while (i < len || j < flen) {
            int cur = ac;
            if (i < len) {
                cur += num[i];
            }
            if (j < flen) {
                cur += res[j];
            }
            ac = cur/10;
            res[j] = cur%10;
            i++;
            j++;
        }
        if (res[flen-1] == 0) {
            res.resize(flen-1);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
        int len = num.size();
        vector<int> res;
        while (k > 0) {
            res.push_back(k%10);
            k = k/10;
        }
        int rlen = res.size();
        if (rlen <= len) {
            res.resize(len+1);
        } else {
            res.resize(rlen+1);
        }

        int flen = res.size();
        int i = len-1, j = 0;
        int ac = 0;
        while (j < flen) {
            int cur = ac;
            if (i >= 0) {
                cur += num[i];
            }
            cur += res[j];
            ac = cur/10;
            res[j] = cur%10;
            i--;
            j++;
        }
        if (res[flen-1] == 0) {
            res.resize(flen-1);
        }
        reverse(res.begin(), res.end());
        return res;
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


