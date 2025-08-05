/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-08-05
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
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 *
 * https://leetcode.cn/problems/validate-ip-address/description/
 *
 * algorithms
 * Medium (28.20%)
 * Likes:    265
 * Dislikes: 0
 * Total Accepted:    74.9K
 * Total Submissions: 264.4K
 * Testcase Example:  '"172.16.254.1"'
 *
 * 给定一个字符串 queryIP。如果是有效的 IPv4 地址，返回 "IPv4" ；如果是有效的 IPv6 地址，返回 "IPv6"
 * ；如果不是上述类型的 IP 地址，返回 "Neither" 。
 *
 * 有效的IPv4地址 是 “x1.x2.x3.x4” 形式的IP地址。 其中 0 <= xi <= 255 且 xi 不能包含 前导零。例如:
 * “192.168.1.1” 、 “192.168.1.0” 为有效IPv4地址， “192.168.01.1” 为无效IPv4地址;
 * “192.168.1.00” 、 “192.168@1.1” 为无效IPv4地址。
 *
 * 一个有效的IPv6地址 是一个格式为“x1:x2:x3:x4:x5:x6:x7:x8” 的IP地址，其中:
 * 1 <= xi.length <= 4
 * xi 是一个 十六进制字符串 ，可以包含数字、小写英文字母( 'a' 到 'f' )和大写英文字母( 'A' 到 'F' )。
 * 在 xi 中允许前导零。
 *
 *
 * 例如 "2001:0db8:85a3:0000:0000:8a2e:0370:7334" 和
 * "2001:db8:85a3:0:0:8A2E:0370:7334" 是有效的 IPv6 地址，而
 * "2001:0db8:85a3::8A2E:037j:7334" 和
 * "02001:0db8:85a3:0000:0000:8a2e:0370:7334" 是无效的 IPv6 地址。
 *
 *
 *
 * 示例 1：
 * 输入：queryIP = "172.16.254.1"
 * 输出："IPv4"
 * 解释：有效的 IPv4 地址，返回 "IPv4"
 *
 *
 * 示例 2：
 * 输入：queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
 * 输出："IPv6"
 * 解释：有效的 IPv6 地址，返回 "IPv6"
 *
 *
 * 示例 3：
 * 输入：queryIP = "256.256.256.256"
 * 输出："Neither"
 * 解释：既不是 IPv4 地址，又不是 IPv6 地址
 *
 *
 * 提示：
 * queryIP 仅由英文字母，数字，字符 '.' 和 ':' 组成。
 *
 *
 */

// @lc code=start
class Solution {
  public:
    vector<string> strSplitBy2(string &str, char delimiter) {
        int start = 0;
        int end = 0;
        vector<string> res;
        while ((end = str.find(delimiter, start)) != string::npos) {
            int len = end - start;
            res.push_back(str.substr(start, len));
            start = end + 1;
        }
        string lastpart = str.substr(start);
        res.push_back(lastpart);
        return res;
    }

    string validIPAddress(string queryIP) {
        //cout << "ErrorData=" << stoi("1e1") << endl;
        if (queryIP.find('.') != string::npos) {
            if (validIPv4(queryIP)) {
                return "IPv4";
            }
            return "Neither";
        }
        if (validIPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

    bool validIPv6(string& ip) {
        auto parts = strSplitBy2(ip, ':');
        if (parts.size() != 8) {
            return false;
        }
        for (auto& part: parts) {
            int len = part.size();
            if (len < 1 || len > 4) {
                return false;
            }
            for (auto& ch: part) {
                if ((ch >= '0' && ch <= '9')
                || (ch >= 'a' && ch <= 'f')
                || (ch >= 'A' && ch <= 'F')) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }


    bool validIPv4(string& ip) {
        auto parts = strSplitBy2(ip, '.');
        if (parts.size() != 4) {
            return false;
        }
        for (auto& part: parts) {
            if (part.size() == 0 || part.size() > 3) {
                return false;
            }
            if (part.size() >= 2 && part[0] == '0') {
                return false;
            }
            for (auto& ch: part) {
                if (ch < '0' || ch > '9') {
                    return false;
                }
            }
            int val = stoi(part);
            if (val < 0 || val > 255) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


/*
Wrong Answer
12/79 cases passed (N/A)
Testcase
"2001:0db8:85a3:0:0:8A2E:0370:7334:"
Answer
"IPv6"
Expected Answer
"Neither"



Wrong Answer
7/79 cases passed (N/A)
Testcase
"1e1.4.5.6"
Answer
"IPv4"
Expected Answer
"Neither"


Runtime Error
8/79 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::invalid_argument'
terminate called after throwing an instance of 'std::invalid_argument'
  what():  stoi
Testcase
"1.0.1."
Expected Answer
"Neither"

Wrong Answer
17/79 cases passed (N/A)
Testcase
"01.01.01.01"
Answer
"IPv4"
Expected Answer
"Neither"


Runtime Error
20/79 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::invalid_argument'
terminate called after throwing an instance of 'std::invalid_argument'
  what():  stoi
Testcase
"A.a.aA.2"
Expected Answer
"Neither"


Runtime Error
24/79 cases passed (N/A)
Error
terminate called after throwing an instance of 'std::out_of_range'
terminate called after throwing an instance of 'std::out_of_range'
  what():  stoi
Testcase
"1.1.1.1111111111111111111111111111111111111111111111111111"
Expected Answer
"Neither"
*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
