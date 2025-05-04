/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-05
 * @tag  sort,string,greedy
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
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode.cn/problems/largest-number/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    1337
 * Dislikes: 0
 * Total Accepted:    258.3K
 * Total Submissions: 621.9K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 *
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 *
 *
 *
 * 示例 1：
 * 输入：nums = [10,2]
 * 输出："210"
 *
 * 示例 2：
 * 输入：nums = [3,30,34,5,9]
 * 输出："9534330"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
// 3 30   330 303


/*

ErrorCase:   Cause RuntimeError why??
        if ((a+b) <= (b+a)) {

CorrectCase:
 if ((a+b) < (b+a))
 means if (op1 == op2) cmp function should return false


Runtime Error
61/235 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::length_error'
terminate called after throwing an instance of 'std::length_error'
  what():  basic_string::_M_create
Testcase
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Expected Answer
"0"

*/


    static bool dicCmp(string& a, string& b) {
        if ((a+b) < (b+a)) {
            return true;
        }
        return false;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> sn;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            sn.push_back(to_string(nums[i]));
        }
        /*
        auto cmp = [](string& left, string& right) {
            return (left + right) < (right + left);
        };
        */
        //sort(sn.begin(), sn.end(), cmp);
        sort(sn.begin(), sn.end(), dicCmp);
        if (sn[(len-1)] == "0") {
            return "0";
        }
        string res = "";
        for (int i = len -1; i >= 0; i--) {
            res += sn[i];
        }
        return res;
    }
};
// @lc code=end

/*

Wrong Answer
58/235 cases passed (N/A)
Testcase
[0,0]
Answer
"00"
Expected Answer
"0"

Wrong Answer
186/235 cases passed (N/A)
Testcase
[3,30,34,5,9]
Answer
"9534303"
Expected Answer
"9534330"

Runtime Error
61/235 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::length_error'
terminate called after throwing an instance of 'std::length_error'
  what():  basic_string::_M_create
Testcase
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
Expected Answer
"0"
Stdout
snsize=100 nums.size=100


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


