/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-17
 * @tag  math,string
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
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.cn/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (69.49%)
 * Likes:    333
 * Dislikes: 0
 * Total Accepted:    218.3K
 * Total Submissions: 314.1K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1
 * 开始）返回结果，其中：
 *
 *
 * answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
 * answer[i] == "Fizz" 如果 i 是 3 的倍数。
 * answer[i] == "Buzz" 如果 i 是 5 的倍数。
 * answer[i] == i （以字符串形式）如果上述条件全不满足。
 *
 *
 *
 *
 * 示例 1：
 * 输入：n = 3
 * 输出：["1","2","Fizz"]
 *
 *
 * 示例 2：
 * 输入：n = 5
 * 输出：["1","2","Fizz","4","Buzz"]
 *
 *
 * 示例 3：
 * 输入：n = 15
 *
 * 输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n, "");
        for (int i = 1; i <= n; i++ ) {
            if (i%15 == 0) {
                res[i-1] = "FizzBuzz" ;
            } else if (i%3==0) {
                res[i-1] = "Fizz" ;
            } else if (i%5==0) {
                res[i-1] = "Buzz" ;
            } else {
                res[i-1] = to_string(i);
            }
        }
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


