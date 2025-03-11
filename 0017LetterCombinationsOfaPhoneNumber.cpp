/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-03-10
 * @tag
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (59.68%)
 * Likes:    3013
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 * 输入：digits = ""
 * 输出：[]
 *
 *
 * 示例 3：
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 *
 *
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, string > ss;

    Solution(){

        ss = {
            { '2', "abc"},
            { '3', "def"},
            { '4', "ghi"},
            { '5', "jkl"},
            { '6', "mno"},
            { '7', "pqrs"},
            { '8', "tuv"},
            { '9', "wxyz"},
        };

    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<char> path;
        if (digits.size() == 0 ) {
            return res;
        }
        bt(digits, path, res);
        return res;
    }


    void bt(string digits, vector<char>& path, vector<string>& res) {
        int total = digits.size();
        if (total == 0) {
            string tmp(path.begin(), path.end());
            res.push_back(tmp);
            return;
        }
        char cur = digits[0];
        string cList = ss[cur];
        for (int i = 0; i < cList.size(); i++) {
            path.push_back(cList[i]);
            bt(digits.substr(1), path, res);
            path.pop_back();
        }
        return;
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


