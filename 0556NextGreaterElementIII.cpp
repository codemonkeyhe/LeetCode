/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-09
 * @tag twoPointers
 * @similar  496,503,556,739, 31
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 *
 * https://leetcode.cn/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (36.85%)
 * Likes:    374
 * Dislikes: 0
 * Total Accepted:    54.3K
 * Total Submissions: 147.4K
 * Testcase Example:  '12'
 *
 * 给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。
 *
 * 注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。
 *
 *
 *
 * 示例 1：
 * 输入：n = 12
 * 输出：21
 *
 *
 * 示例 2：
 * 输入：n = 21
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 * 1 <= n <= 231 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:

    int nextGreaterElementM1(int n) {
        int cur = 0;
        int m = n;
        int pre = 0;
        vector<int> digits;
        // step1 find the swap pos
        bool isBig = true;
        while (m > 0) {
            cur = m % 10;
            m = m / 10;
            if (cur < pre) {
                isBig = false;
                break;
            }
            digits.push_back(cur);
            pre = cur;
        }
        if (isBig) { // means no need to swap
            return -1;
        }
        long leftPart = m;

        //step2 find swap element
        int i = 0;
        for (; i < digits.size(); i++) {
            if (digits[i] > cur) {
                break;
            }
        }
        //step3 swap
        leftPart = leftPart * 10 + digits[i];
        digits[i] = cur;
        //step4 reverse order, and make result
        for (int i = 0; i < digits.size(); i++) {
            leftPart = leftPart * 10 + digits[i];
        }
        return leftPart > INT_MAX ? -1 : leftPart;
    }


    int nextGreaterElement(int n) {
        string sn = to_string(n);
        bool isNext = next_permutation(sn.begin(), sn.end());
        long res = stol(sn);
        if (res > INT_MAX || !isNext) {
            return -1;
        }
        return res;
    }
};
// @lc code=end

/*

next_permutation

    // EXP: 12543 -> 13245
    // leftPart = 1 , swapPos = 2 ,  so 12543 = 1 2 543
    // in 543, find the first bigger than 2,  3 >=2
    // change   1 2 543 -> 1 3 542
    // reverse:  1 3 542 -> 1 3 245


13542->14235
12543->13245->13254->13425->13452->13524->13542->14235

Runtime Error
1/39 cases passed (N/A)
Testcase
21
Expected Answer
-1

Runtime Error
19/39 cases passed (N/A)
Testcase
2147483486
Expected Answer
-1

Runtime Error
19/39 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::out_of_range'
terminate called after throwing an instance of 'std::out_of_range'
  what():  stoi
Testcase
2147483486
Expected Answer
-1

Wrong Answer
27/39 cases passed (N/A)
Testcase
21
Answer
12
Expected Answer
-1

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


