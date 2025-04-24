/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-04-24
 * @tag array
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
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1 比特与 2 比特字符
 *
 * https://leetcode.cn/problems/1-bit-and-2-bit-characters/description/
 *
 * algorithms
 * Easy (55.40%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    75.8K
 * Total Submissions: 136.7K
 * Testcase Example:  '[1,0,0]'
 *
 * 有两种特殊字符：
 *
 *
 * 第一种字符可以用一比特 0 表示
 * 第二种字符可以用两比特（10 或 11）表示
 *
 *
 * 给你一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一个一比特字符，则返回 true 。
 *
 *
 *
 * 示例 1:
 * 输入: bits = [1, 0, 0]
 * 输出: true
 * 解释: 唯一的解码方式是将其解析为一个两比特字符和一个一比特字符。
 * 所以最后一个字符是一比特字符。
 *
 *
 * 示例 2:
 * 输入：bits = [1,1,1,0]
 * 输出：false
 * 解释：唯一的解码方式是将其解析为两比特字符和两比特字符。
 * 所以最后一个字符不是一比特字符。
 *
 *
 *
 *
 * 提示:
 * 1 <= bits.length <= 1000
 * bits[i] 为 0 或 1
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacterM1(vector<int>& bits) {
        int len = bits.size();
        int i = 0;
        int lastSet = 0;
        while (i < len) {
            if (bits[i] == 0) {
                i++;
                lastSet = 1;
            } else{
                i += 2;
                lastSet = 2;
            }
        }
        if (lastSet == 1) {
            return true;
        }
        return false;
    }


     bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int i = 0;
        while (i < len) {
            if (bits[i] == 0) {
                if (i == len - 1) {
                    return true;
                }
                i++;
            } else{
                i += 2;
            }
        }
        return false;
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


