/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-24
 * @tag  simulation
 * @similar  537, 592, 640
 */

/*

*/



#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 *
 * https://leetcode.cn/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (74.27%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    49.6K
 * Total Submissions: 66.8K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：
 *
 *
 * 实部 是一个整数，取值范围是 [-100, 100]
 * 虚部 也是一个整数，取值范围是 [-100, 100]
 * i^2 == -1
 *
 *
 * 给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。
 *
 * 示例 1：
 * 输入：num1 = "1+1i", num2 = "1+1i"
 * 输出："0+2i"
 * 解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
 *
 *
 * 示例 2：
 * 输入：num1 = "1+-1i", num2 = "1+-1i"
 * 输出："0+-2i"
 * 解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
 *
 *
 * 提示：
 * num1 和 num2 都是有效的复数表示。
 *
 *
 */

// @lc code=start
class Solution {
public:

    string complexNumberMultiply(string num1, string num2) {
        auto [a, b] = parseNumV2(num1);
        auto [c, d] = parseNumV2(num2);
        int p1 = a * c - b * d;
        int p2 = b * c + a * d;
        return to_string(p1) + "+" + to_string(p2) + "i";
    }

    pair<int, int> parseNum(string& s) {
        int idx = s.find('+');
        int n1 =  stoi(s.substr(0, idx));
        int n2 =  stoi(s.substr(idx+1, s.size()-idx-2));
        return make_pair(n1, n2);
    }


    // s format A+ (-B)i
    pair<int, int> parseNumV2(string &s) {
        stringstream ss(s);
        int n1, n2;
        char plus;
        //char i ;
        //ss >> n1 >> plus >> n2 >> i;
        // still ok
        ss >> n1 >> plus >> n2;
        return make_pair(n1, n2);
    }

    // Others's code
    // 利用了C++的 complex
    // 且  stringstream用的很好
    string complexNumberMultiplyV2(string num1, string num2) {
        auto get = [](string& s){
            stringstream ss(s);
            int i, r; char c;
            ss >> r >> c >> i;
            return complex<int>(r, i);
        };
        auto a = get(num1) * get(num2);
        return to_string(a.real()) + '+' + to_string(a.imag()) + 'i';
    }

/*
sscanf sprintf
作者：知心猛男
链接：https://leetcode.cn/problems/complex-number-multiplication/solutions/1291939/zhi-xin-meng-nan-sscanf-he-sprintf-he-ch-hf0q/
*/
    string complexNumberMultiplyV3(string num1, string num2) {
        int a1, b1, a2, b2;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        char ans[20];
        sprintf(ans, "%d+%di", a1*a2-b1*b2, a1*b2+a2*b1);
        return ans;
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
