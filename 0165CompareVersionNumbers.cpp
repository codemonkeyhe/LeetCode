/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-04
 * @tag  string
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
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 *
 * https://leetcode.cn/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (52.24%)
 * Likes:    449
 * Dislikes: 0
 * Total Accepted:    203.8K
 * Total Submissions: 380.2K
 * Testcase Example:  '"1.2"\n"1.10"'
 *
 * 给你两个 版本号字符串 version1 和 version2 ，请你比较它们。版本号由被点 '.' 分开的修订号组成。修订号的值 是它 转换为整数
 * 并忽略前导零。
 *
 * 比较版本号时，请按 从左到右的顺序 依次比较它们的修订号。如果其中一个版本字符串的修订号较少，则将缺失的修订号视为 0。
 *
 * 返回规则如下：
 *
 *
 * 如果 version1 < version2 返回 -1，
 * 如果 version1 > version2 返回 1，
 * 除此之外返回 0。
 *
 *
 *
 *
 * 示例 1：
 * 输入：version1 = "1.2", version2 = "1.10"
 * 输出：-1
 *
 * 解释：
 * version2。
 *
 *
 * 示例 2：
 * 输入：version1 = "1.01", version2 = "1.001"
 * 输出：0
 *
 * 解释：
 * 忽略前导零，"01" 和 "001" 都代表相同的整数 "1"。
 *
 *
 * 示例 3：
 * 输入：version1 = "1.0", version2 = "1.0.0.0"
 *
 * 输出：0
 * 解释：
 * version1 有更少的修订号，每个缺失的修订号按 "0" 处理。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= version1.length, version2.length <= 500
 * version1 和 version2 仅包含数字和 '.'
 * version1 和 version2 都是 有效版本号
 * version1 和 version2 的所有修订号都可以存储在 32 位整数 中
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> sepStr(string& v, char sep) {
        vector<int>  res;
        stringstream ss;
        ss << v;
        string tmp;
        while(getline(ss, tmp, sep)) {
            res.push_back(stoi(tmp));
        }
        return res;
    }


    int compareVersionUgly(string version1, string version2) {
        auto v1 = sepStr(version1, '.');
        auto v2 = sepStr(version2, '.');
        int i = 0;
        int j = 0;
        while(i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                return -1;
            } else if (v1[i] > v2[j]) {
                return 1;
            } else {
                i++;
                j++;
            }
        }
        if (i == v1.size() && (j == v2.size())) {
            return 0;
        }
        while (i < v1.size()) { //means v1 stil has data
            if (v1[i] > 0) {
                return 1;
            }
            i++;
        }
        while (j < v2.size()) {  // means v2 stil has data
            if (v2[j] > 0) {
                return -1;
            }
            j++;
        }
        return 0;
    }


    int compareVersion(string version1, string version2) {
        auto v1 = sepStr(version1, '.');
        auto v2 = sepStr(version2, '.');
        int i = 0;
        int j = 0;
        while(i < v1.size() || j < v2.size()) {
            int x = (i < v1.size()) ? v1[i] : 0;
            int y = (j < v2.size()) ? v2[j] : 0;
            if (x < y) {
                return -1;
            } else if (x > y) {
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};
// @lc code=end


/*
stoi 支持把"0001" 转成1
getline 需要好好运用



*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


