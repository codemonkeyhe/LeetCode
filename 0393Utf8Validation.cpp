/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-05-24
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
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 *
 * https://leetcode.cn/problems/utf-8-validation/description/
 *
 * algorithms
 * Medium (43.67%)
 * Likes:    196
 * Dislikes: 0
 * Total Accepted:    41K
 * Total Submissions: 94K
 * Testcase Example:  '[197,130,1]'
 *
 * 给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。
 *
 * UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
 *
 *
 * 对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
 * 对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10
 * 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
 *
 *
 * 这是 UTF-8 编码的工作方式：
 *
 * ⁠     Number of Bytes  |        UTF-8 octet sequence
 * ⁠                      |              (binary)
 * ⁠  --------------------+---------------------------------------------
 * ⁠           1          | 0xxxxxxx
 * ⁠           2          | 110xxxxx 10xxxxxx
 * ⁠           3          | 1110xxxx 10xxxxxx 10xxxxxx
 * ⁠           4          | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 *
 * x 表示二进制形式的一位，可以是 0 或 1。
 *
 * 注意：输入是整数数组。只有每个整数的 最低 8 个有效位 用来存储数据。这意味着每个整数只表示 1 字节的数据。
 *
 * 示例 1：
 * 输入：data = [197,130,1]
 * 输出：true
 * 解释：数据表示字节序列:11000101 10000010 00000001。
 * 这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。
 *
 *
 * 示例 2：
 * 输入：data = [235,140,4]
 * 输出：false
 * 解释：数据表示 8 位的序列: 11101011 10001100 00000100.
 * 前 3 位都是 1 ，第 4 位为 0 表示它是一个 3 字节字符。
 * 下一个字节是开头为 10 的延续字节，这是正确的。
 * 但第二个延续字节不以 10 开头，所以是不符合规则的。
 *
 *
 * 提示:
 * 1 <= data.length <= 2 * 10^4
 * 0 <= data[i] <= 255
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int mask1 = 0x00000080;
        int mask2 = 0x000000E0; // expect 0b11000000=0xC0
        int mask3 = 0x000000F0;  // expect 0b11100000=0xE0
        int mask4 = 0x000000F8; // expect 0b11110000=0xF0

        int maskS = 0x000000C0;   // expect  0b1000 0000= 0x80;
        int len = data.size();
        int i = 0;
        while (i < len) {
            int num = data[i];
            if ( (num & mask1) == 0)  { // one byte char
            i++;
                continue;
            }
            // multi-bytes char
            if ( (num & mask2) == 0x000000C0) { // two bytes
                if (i > len -2) {
                    return  false;
                }
                if ((data[i+1] & maskS) != 0x00000080 ) {
                    return false;
                }
                i=i+2;
                continue;
            }

            if ( (num & mask3) == 0x000000E0) { // 3 bytes
                if (i > len -3) {
                    return  false;
                }
                if( ((data[i+1] & maskS) != 0x00000080 )
                || ((data[i+2] & maskS) != 0x00000080 ) ) {
                    return false;
                }
                i=i+3;
                continue;
            }

            if ( (num & mask4) == 0x000000F0) { // 4 bytes
                if (i > len -4) {
                    return  false;
                }
                if( ((data[i+1] & maskS) != 0x00000080 )
                || ((data[i+2] & maskS) != 0x00000080 )
                || ((data[i+3] & maskS) != 0x00000080 ) ) {
                    return false;
                }
                i=i+4;
                continue;
            }
            return false;
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
M1 过于冗余
mask2 mask3 mask4可以用一个mask0来代替
MASK0 = 1 << 7; 用于判断最高位是否是0
然后mask0每次右移动一位，用于判断次高位和 次次高位是否是0

M2

*/


