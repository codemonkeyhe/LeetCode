/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-12-23
 * @tag    string,design
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
 * @lc app=leetcode.cn id=271 lang=cpp
 *
 * [271] 字符串的编码与解码
 *
 * https://leetcode.cn/problems/encode-and-decode-strings/description/
 *
 * algorithms
 * Medium (58.81%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 13.6K
 * Testcase Example:  '["Hello","World"]'
 *
 * 请你设计一个算法，可以将一个 字符串列表 编码成为一个
 * 字符串。这个编码后的字符串是可以通过网络进行高效传送的，并且可以在接收端被解码回原来的字符串列表。
 *
 * 1 号机（发送方）有如下函数：
 * string encode(vector<string> strs) {
 * ⁠ // ... your code
 * ⁠ return encoded_string;
 * }
 *
 * 2 号机（接收方）有如下函数：
 * vector<string> decode(string s) {
 * ⁠ //... your code
 * ⁠ return strs;
 * }
 *
 *
 * 1 号机（发送方）执行：
 * string encoded_string = encode(strs);
 *
 *
 * 2 号机（接收方）执行：
 * vector<string> strs2 = decode(encoded_string);
 *
 *
 * 此时，2 号机（接收方）的 strs2 需要和 1 号机（发送方）的 strs 相同。
 * 请你来实现这个 encode 和 decode 方法。
 *
 * 不允许使用任何序列化方法解决这个问题（例如 eval）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：dummy_input = ["Hello","World"]
 * 输出：["Hello","World"]
 * 解释：
 * 1 号机：
 * Codec encoder = new Codec();
 * String msg = encoder.encode(strs);
 * Machine 1 ---msg---> Machine 2
 *
 * 2 号机：
 * Codec decoder = new Codec();
 * String[] strs = decoder.decode(msg);
 *
 *
 * 示例 2：
 *
 *
 * 输入：dummy_input = [""]
 * 输出：[""]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 包含 256 个有效 ASCII 字符中的任何可能字符。
 *
 *
 *
 *
 * 进阶：你能编写一个通用算法来处理任何可能的字符集吗？
 *
 */

// @lc code=start
class Codec {
public:

    const char sep = '#';

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        for (auto &s : strs) {
            int slen = s.size();
            ss << slen << sep << s;
        }
        //cout << "OOOO=" << ss.str() << endl;
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode2(string s) {
        vector<string> res;
        stringstream ss(s);
        int slen;
        char plus;
        while(ss >> slen) {
            ss >> plus;
            //ss >> tmp;
            vector<char> buf(slen);
            ss.readsome(buf.data(), slen);
            string tmp(buf.begin(), buf.end());
         //   cout << "PP=" << plus << " tmp=" << tmp << endl;
            res.push_back(tmp);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        stringstream ss(s);
        int slen;
        char plus;
        vector<char> buf(201);
        while(ss >> slen) {
            ss >> plus;
            ss.readsome(buf.data(), slen);
            //string tmp(buf.begin(), buf.begin()+slen);
            //res.push_back(tmp);
            res.emplace_back(buf.begin(), buf.begin()+slen);
        }
        return res;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
// @lc code=end



int main() {
    Solution s;
}


/*
Tips
M1

M2

*/
