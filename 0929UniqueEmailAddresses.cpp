/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-19
 * @tag hashmap
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
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 *
 * https://leetcode.cn/problems/unique-email-addresses/description/
 *
 * algorithms
 * Easy (68.47%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    61.8K
 * Total Submissions: 90.3K
 * Testcase Example:  '["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]'
 *
 * 每个 有效电子邮件地址 都由一个 本地名 和一个 域名 组成，以 '@' 符号分隔。除小写字母之外，电子邮件地址还可以含有一个或多个 '.' 或 '+'
 * 。
 * 例如，在 alice@leetcode.com中， alice 是 本地名 ，而 leetcode.com 是 域名 。
 * 如果在电子邮件地址的 本地名 部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名中没有点的同一地址。请注意，此规则 不适用于域名
 * 。
 * 例如，"alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。
 * 如果在 本地名 中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件。同样，此规则 不适用于域名 。
 * 例如 m.y+name@email.com 将转发到 my@email.com。
 * 可以同时使用这两个规则。
 * 给你一个字符串数组 emails，我们会向每个 emails[i] 发送一封电子邮件。返回实际收到邮件的不同地址数目。
 *
 *
 *
 * 示例 1：
 * 输入：emails =
 * ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
 * 输出：2
 * 解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。
 *
 *
 * 示例 2：
 * 输入：emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
 * 输出：3
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= emails.length <= 100
 * 1 <= emails[i].length <= 100
 * emails[i] 由小写英文字母、'+'、'.' 和 '@' 组成
 * 每个 emails[i] 都包含有且仅有一个 '@' 字符
 * 所有本地名和域名都不为空
 * 本地名不会以 '+' 字符作为开头
 * 域名以 ".com" 后缀结尾。
 * 域名在 ".com" 后缀前至少包含一个字符
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> dup;
        for (int i = 0; i < emails.size(); i++) {
            string& cur = emails[i];
            string str = tidyAddr(cur);
            //cout << "str=" << str << endl;
            dup.insert(str);
        }
        return dup.size();
    }

    //Your runtime beats 81.17 % of cpp submissions
    string tidyAddrUgly(string& ss) {
        string res = "";
        bool skip = false;
        bool dom = false;
        for (int i = 0; i < ss.size(); i++) {
            if (!dom && ss[i] == '.') {
                continue;
            }
            if (ss[i] == '@') {
                dom = true;
                skip = false;
            }
            if (!dom && ss[i] == '+') {
                skip = true;
                continue;
            }
            if (skip) {
                continue;
            }
            res += ss[i];
        }
        return res;
    }

    string tidyAddr(string& ss) {
        string res = "";
        int idx = ss.find('@');
        for (int i = 0; i < idx; i++) {
            if (ss[i] == '.') {
                continue;
            }
            if (ss[i] == '+') {
                break;
            }
            res += ss[i];
        }
        res += ss.substr(idx);
        return res;
    }
};
// @lc code=end

/*
ErrorCase

Testcase
["test.email+alex@leetcode.com", "test.email@leetcode.com"]
Answer
2
Expected Answer
1


Testcase
["a@e+c.com", "a@e+c+f.com"]
Answer
1
Expected Answer
2

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


