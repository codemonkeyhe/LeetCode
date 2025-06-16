/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-06-15
 * @tag stack,string
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
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 *
 * https://leetcode.cn/problems/decode-string/description/
 *
 * algorithms
 * Medium (57.61%)
 * Likes:    1970
 * Dislikes: 0
 * Total Accepted:    442.8K
 * Total Submissions: 741.2K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 *
 *
 *
 * 示例 1：
 * 输入：s = "3[a]2[bc]"
 * 输出："aaabcbc"
 *
 *
 * 示例 2：
 * 输入：s = "3[a2[c]]"
 * 输出："accaccacc"
 *
 *
 * 示例 3：
 * 输入：s = "2[abc]3[cd]ef"
 * 输出："abcabccdcdcdef"
 *
 *
 * 示例 4：
 * 输入：s = "abc3[cd]xyz"
 * 输出："abccdcdcdxyz"
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 30
 * s 由小写英文字母、数字和方括号 '[]' 组成
 * s 保证是一个 有效 的输入。
 * s 中所有整数的取值范围为 [1, 300] 
 *
 *
 */

// @lc code=start
class Solution {
public:
    string decodeStringUgly(string s) {
        int n = s.size();
        stack<string> st;
        int i = 0;
        while(i < n) {
            char& cur = s[i];
            if (cur == '[') {
                st.push("[");
                i++;
                continue;
            }
            if (cur >= '0' && cur <= '9') {
                int j = i;
                string num = "";
                while(j < n) {
                    if ((s[j] < '0') || (s[j] > '9')) {
                        break;
                    }
                    num += s[j];
                    j++;
                }
                st.push(num);
                i = j;
                continue;
            }
            if (cur >= 'a' && cur <= 'z') {
                int j = i;
                string abc = "";
                while(j < n) {
                    if ((s[j] < 'a') || (s[j] > 'z')) {
                        break;
                    }
                    abc += s[j];
                    j++;
                }
                st.push(abc);
                i = j;
                continue;
            }
            if (cur == ']') { // pop
                string allstr = "";
                string abc = st.top();
                while(abc[0]  >= 'a' && abc[0] <= 'z'  ) {
                    allstr = abc + allstr;
                    st.pop();
                    abc = st.top();
                }

                st.pop(); // pop [
                string scnt = st.top();
                int cnt = stoi(scnt);
                st.pop();
                string build = "";
                for (int k = 0; k < cnt; k++) {
                    build += allstr;
                }
                st.push(build);
                i++;
            }
        }

        vector<string> st2;
        while(!st.empty()) {
            st2.push_back(st.top());
            st.pop();
        }
        string res = "";
        for (int i = st2.size() - 1; i >= 0; i--) {
            res += st2[i];
        }
        return res;
    }

    string decodeString(string s) {
        int n = s.size();
        vector<string> st;
        int i = 0;
        while(i < n) {
            char& cur = s[i];
            if (cur == '[') {
                st.push_back("[");
                i++;
            } else if (cur >= '0' && cur <= '9') {
                string num = "";
                while(i < n && ((s[i] >= '0') && (s[i] <= '9') )) {
                    num += s[i];
                    i++;
                }
                st.push_back(num);
            } else if (cur >= 'a' && cur <= 'z') {
                string abc = "";
                while(i < n && ( (s[i] >= 'a') && (s[i] <= 'z'))) {
                    abc += s[i];
                    i++;
                }
                st.push_back(abc);
            } else if (cur == ']') { // pop
                string allstr = "";
                string abc = st.back();
                while (abc[0] >= 'a' && abc[0] <= 'z') {
                    allstr = abc + allstr;
                    st.pop_back();
                    abc = st.back();
                }

                st.pop_back(); // pop [
                int cnt = stoi(st.back());
                st.pop_back();
                string build = "";
                for (int k = 0; k < cnt; k++) {
                    build += allstr;
                }
                st.push_back(build);
                i++;
            }
        }

        string res = "";
        for (auto& ss : st) {
            res += ss;
        }
        return res;
    }

};
// @lc code=end

/*
Wrong Answer
5/34 cases passed (N/A)
Testcase
"2[abc]3[cd]ef"
Answer
"ef"
Expected Answer
"abcabccdcdcdef"



terminate called after throwing an instance of 'std::invalid_argument'
  what():  stoi
s =
"3[z]2[2[y]pq4[2[jk]e1[f]]]ef"

*/



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


