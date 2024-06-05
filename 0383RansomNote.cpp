/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-06-05
 * @tag OneShot; hashTable
 */

/*

*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode.cn/problems/ransom-note/description/
 *
 * algorithms
 * Easy (64.34%)
 * Likes:    884
 * Dislikes: 0
 * Total Accepted:    496.1K
 * Total Submissions: 769.7K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 如果可以，返回 true ；否则返回 false 。
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 *
 *
 *
 * 示例 1：
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 *
 *
 * 示例 2：
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 *
 *
 * 示例 3：
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    //  M1
    bool canConstruct(string ransomNote, string magazine) {
        int rLen = ransomNote.size();
        int mLen = magazine.size();
        if (rLen > mLen) {
            return false;
        }
        int chCnt[26] = {0};
        for (int i = 0; i < rLen; i++ ) {
            int ch = ransomNote[i] - 'a';
            chCnt[ch]++;
        }
        for (int i = 0; i < mLen; i++ ) {
            int ch = magazine[i] - 'a';
            if (chCnt[ch]== 0) {
                continue;
            }
            chCnt[ch]--;
        }
        for (int i = 0; i < 26; i++) {
            if (chCnt[i] > 0) {
                return false;
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
M1 对ransomNote进行字符计数

M2  对magazine进行字符计数

*/


