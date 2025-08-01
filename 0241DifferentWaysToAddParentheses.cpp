/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-
 * @tag 卡特兰数,
 * @similar  22, 96, 241, 894
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 *
 * https://leetcode.cn/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (75.48%)
 * Likes:    917
 * Dislikes: 0
 * Total Accepted:    89.7K
 * Total Submissions: 118.8K
 * Testcase Example:  '"2-1-1"'
 *
 * 给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
 * 生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 10^4 。
 *
 *
 *
 * 示例 1：
 * 输入：expression = "2-1-1"
 * 输出：[0,2]
 * 解释：
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 *
 * 示例 2：
 * 输入：expression = "2*3-4*5"
 * 输出：[-34,-14,-10,-10,10]
 * 解释：
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 *
 *
 * 提示：
 * 1 <= expression.length <= 20
 * expression 由数字和算符 '+'、'-' 和 '*' 组成。
 * 输入表达式中的所有整数值在范围 [0, 99] 
 * 输入表达式中的所有整数都没有前导 '-' 或 '+' 表示符号。
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<vector<int>>> cache;

    vector<int> diffWaysToCompute(string expression) {
        int len = expression.size();
        cache = vector<vector<vector<int>>>(len, vector<vector<int> >(len, vector<int>()));
        auto res = dfs(expression, 0, expression.size() - 1);
        return res;
    }

    vector<int> dfs(string& exp, int left, int right) {
        if (cache[left][right].size() > 0) {
            return cache[left][right];
        }

        vector<int>  ans;
        int k = left;
        int num = 0;
        while (k <= right && isdigit(exp[k])) {
            num = num * 10 + (exp[k] - '0');
            k++;
        }
        if (k == right+1) { // means exp[left:right] is all digits
            return vector<int>{num};
        }

        for (int i = left; i <= right; i++) {
            if (isdigit(exp[i])) {
                continue;
            }
            char& op = exp[i];
            auto lvs = dfs(exp, left, i-1);
            auto rvs = dfs(exp, i+1, right);
            for (auto& lv: lvs) {
                for (auto& rv: rvs) {
                    int res = 0;
                    if (op == '+') {
                        res = lv+rv;
                    } else if (op == '-') {
                        res = lv-rv;
                    } else { // *
                        res = lv * rv;
                    }
                    ans.push_back(res);
                }
            }
        }
        cache[left][right] = ans;
        return ans;
    }

};
// @lc code=end

/*
输入：expression = "2*3-4*5"
输出：[-34,-14,-10,-10,10]
解释：
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10


6-4*5
    2*5 = 10
    6-20 = -14
2*(-1)*5
    -2*5 = - 10
    2*-5 = -10
2*3-20
    6-20  = -14
    2*-17 = -34

    -14只有1个，-10有2个



*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
