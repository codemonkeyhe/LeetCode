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
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (59.48%)
 * Likes:    1488
 * Dislikes: 0
 * Total Accepted:    486.1K
 * Total Submissions: 798.6K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 *
 *
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 *
 *
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能
 * 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 *
 *
 *
 * 示例 1：
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 *
 * 示例 2：
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 *
 * 示例 3：
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 1.0.1.023
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 20
 * s 仅由数字组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        int idx = 0;
        bt(s, idx,  path, res);
        return res;
    }

    void bt(const string& s, int idx,  vector<string>& path,  vector<string>& res) {
        if (path.size() == 3 ) {
            string p4 = s.substr(idx);
            if (isValid(p4)) {
                string tmp = path[0]+"."+path[1]+"."+path[2]+".";
                tmp+=p4;
                res.push_back(tmp);
            }
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            int ssLen = i-idx+1 ;
            if (ssLen > 3) {
                continue;
            }
            string ss = s.substr(idx, ssLen);
            if (!isValid(ss)) {
                continue;
            }
            path.push_back(ss);
            bt(s, i+1,  path, res);
            path.pop_back();
        };
        return ;
    }

    bool isValid(string ss) {
        int size = ss.size();
        if (size > 3 || (size == 0)) {
            return false;
        }
        if (size > 1 && (ss[0] == '0')) {
            return false;
        }
        if (size == 3) {
            if (ss[0] > '2') {
                return false;
            }
            if (ss[0] == '2') {
                if (ss[1] > '5') {
                    return false;
                }
                if ((ss[1] == '5') && (ss[2]) > '5') {
                    return false;
                }
            }
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


