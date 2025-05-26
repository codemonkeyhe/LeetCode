/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-05-25
 * @tag  stack
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
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 *
 * https://leetcode.cn/problems/simplify-path/description/
 *
 * algorithms
 * Medium (45.06%)
 * Likes:    807
 * Dislikes: 0
 * Total Accepted:    295K
 * Total Submissions: 623.6K
 * Testcase Example:  '"/home/"'
 *
 * 给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为 更加简洁的规范路径。
 * 在 Unix 风格的文件系统中规则如下：
 * 一个点 '.' 表示当前目录本身。
 * 此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
 * 任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
 * 任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
 *
 *
 * 返回的 简化路径 必须遵循下述格式：
 * 始终以斜杠 '/' 开头。
 * 两个目录名之间必须只有一个斜杠 '/' 。
 * 最后一个目录名（如果存在）不能 以 '/' 结尾。
 * 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
 *
 *
 * 返回简化后得到的 规范路径 。
 * 示例 1：
 * 输入：path = "/home/"
 * 输出："/home"
 * 解释：
 * 应删除尾随斜杠。
 *
 *
 * 示例 2：
 * 输入：path = "/home//foo/"
 * 输出："/home/foo"
 * 解释：
 * 多个连续的斜杠被单个斜杠替换。
 *
 *
 * 示例 3：
 * 输入：path = "/home/user/Documents/../Pictures"
 * 输出："/home/user/Pictures"
 * 解释：
 * 两个点 ".." 表示上一级目录（父目录）。
 *
 *
 * 示例 4：
 * 输入：path = "/../"
 * 输出："/"
 * 解释：
 * 不可能从根目录上升一级目录。
 *
 *
 * 示例 5：
 * 输入：path = "/.../a/../b/c/../d/./"
 * 输出："/.../b/d"
 *
 * 解释：
 * "..." 在这个问题中是一个合法的目录名。
 *
 *
 *
 *
 * 提示：
 * 1 <= path.length <= 3000
 * path 由英文字母，数字，'.'，'/' 或 '_' 组成。
 * path 是一个有效的 Unix 风格绝对路径。
 *
 *
 */

// @lc code=start
class Solution {
public:
    char curDir = '.';
    char parDir = '..';
    char slash = '/';

    string simplifyPathM1(string path) {
        vector<string> dirs  = strSplitBy2(path, slash);

        stack<string> st;
        for (int i = 0; i < dirs.size(); i++) {
            string& cur = dirs[i];
            if (cur == ".") {
                continue;
            } else if (cur == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(cur);
            }
        }
        vector<string> tmp;
        while(!st.empty()) {
            tmp.push_back(st.top());
            st.pop();
        }

        string res = "/";
        for (auto it = tmp.rbegin(); it != tmp.rend(); it++) {
            res += *it+ "/";
        }
        if (res.size() > 1) {
            res.pop_back();
        }
        return res;
    }


    // 可以把vector当stack用，这样不用再自反转
    string simplifyPath(string path) {
        vector<string> dirs  = strSplitBy(path, slash);

        vector<string> st;
        for (int i = 0; i < dirs.size(); i++) {
            string& cur = dirs[i];
            if (cur == ".") {
                continue;
            } else if (cur == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(cur);
            }
        }

        string res = "/";
        for (auto it = st.begin(); it != st.end(); it++) {
            res += *it+ "/";
        }
        if (res.size() > 1) {
            res.pop_back();
        }
        return res;
    }


    vector<string> strSplitBy(string& str, char delimiter) {
        stringstream ss;
        ss << str;
        vector<string> res;
        string tmp;
        while (getline(ss, tmp, delimiter)) {
            if (tmp.size() > 0) {
                res.push_back(tmp);
            }
        }
        return res;
    }

    vector<string> strSplitBy2(string& str, char delimiter) {
        size_t pos = 0;
        size_t prev = 0;
        vector<string> res;
        while ((pos = str.find(delimiter, pos)) != string::npos) {
            int len = pos - prev;
            if (len != 0) {
                res.push_back(str.substr(prev, len));
            }
            pos++;
            prev = pos;
        }
        string lastpart = str.substr(prev);
        if (lastpart.size() > 0) {
            res.push_back(lastpart);
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


