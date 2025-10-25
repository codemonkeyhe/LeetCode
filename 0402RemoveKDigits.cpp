/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-10-25
 * @tag         stack, greedy
 * @similar   402, 738
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 *
 * https://leetcode.cn/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (31.91%)
 * Likes:    1145
 * Dislikes: 0
 * Total Accepted:    190.4K
 * Total Submissions: 581.3K
 * Testcase Example:  '"1432219"\n3'
 *
 * 给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。
 *
 *
 * 示例 1 ：
 * 输入：num = "1432219", k = 3
 * 输出："1219"
 * 解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
 *
 *
 * 示例 2 ：
 * 输入：num = "10200", k = 1
 * 输出："200"
 * 解释：移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
 *
 *
 * 示例 3 ：
 * 输入：num = "10", k = 2
 * 输出："0"
 * 解释：从原数字移除所有的数字，剩余为空就是 0 。
 *
 *
 * 提示：
 * 1 <= k <= num.length <= 105
 * num 仅由若干位数字（0 - 9）组成
 * 除了 0 本身之外，num 不含任何前导零
 *
 *
 */

// @lc code=start
class Solution {
public:
    string removeKdigitsM1Ugly(string num, int k) {
        vector<char> st;
        int lens = num.size();
        int i = 0;
        while(i < lens) {
            char& cur = num[i];
            while ((k > 0) && !st.empty() && st.back() > cur) {
                st.pop_back();
                k--;
            }
            if (k == 0) {
                break;
            }
            st.push_back(cur);
            i++;
        }

        string res = "";
        int j = 0;
        while(j < st.size() && (st[j] == '0')) {
            j++;
        }
        for (; j < st.size(); j++) {
            res += st[j];
        }
        if (st.size() == 0) {
            while (i < lens && (num[i] == '0')) {
                i++;
            }
        }
        while (i < lens) {
            res += num[i];
            i++;
        }
        if (res == "" || res.size() <= k) {
            return "0";
        }
        if (k > 0) {
            return res.substr(0, res.size() - k);
        }
        return res;
    }

    string removeKdigits(string num, int k) {
        vector<char> st;
        int lens = num.size();
        int i = 0;
        while(i < lens) {
            char& cur = num[i];
            while ((k > 0) && !st.empty() && st.back() > cur) {
                st.pop_back();
                k--;
            }
            st.push_back(cur);
            i++;
        }
        while (k > 0) {
            st.pop_back();
            k--;
        }

        string res = "";
        int j = 0;
        while(j < st.size() && (st[j] == '0')) {
            j++;
        }
        for (; j < st.size(); j++) {
            res += st[j];
        }
        if (res == "") {
            return "0";
        }
        return res;
    }
};
// @lc code=end

/*
Wrong Answer
17/44 cases passed (N/A)
Testcase
"10200"
1
Answer
"0200"
Expected Answer
"200"


num =
"33526221184202197273"
k = 19

添加到测试用例
输出 ""
预期结果 "0"


输入
num = "10001"
k = 4

添加到测试用例
输出 "1"
预期结果 "0"
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
