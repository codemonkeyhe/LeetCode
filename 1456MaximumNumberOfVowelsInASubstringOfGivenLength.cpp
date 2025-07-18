/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-18
 * @tag  slidingWindow
 * @similar  30,438,1456
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 *
 * https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (57.31%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    103.6K
 * Total Submissions: 170.9K
 * Testcase Example:  '"abciiidef"\n3'
 *
 * 给你字符串 s 和整数 k 。
 * 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
 * 英文中的 元音字母 为（a, e, i, o, u）。
 *
 *
 *
 * 示例 1：
 * 输入：s = "abciiidef", k = 3
 * 输出：3
 * 解释：子字符串 "iii" 包含 3 个元音字母。
 *
 *
 * 示例 2：
 * 输入：s = "aeiou", k = 2
 * 输出：2
 * 解释：任意长度为 2 的子字符串都包含 2 个元音字母。
 *
 *
 * 示例 3：
 * 输入：s = "leetcode", k = 3
 * 输出：2
 * 解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母。
 *
 *
 * 示例 4：
 * 输入：s = "rhythms", k = 4
 * 输出：0
 * 解释：字符串 s 中不含任何元音字母。
 *
 *
 * 示例 5：
 * 输入：s = "tryhard", k = 4
 * 输出：1
 *
 *
 *
 *
 * 提示：
 * 1 <= s.length <= 10^5
 * s 由小写英文字母组成
 * 1 <= k <= s.length
 *
 *
 */

// @lc code=start
class Solution {
public:

    int maxVowelsM1(string s, int k) {
        int lens = s.size();
        int left = 0;
        int right = 0;
        int maxV = 0;
        int cnt = 0;
        while (right < k) {
            if (isVowel(s[right])) {
                cnt++;
            }
            right++;
        }
        maxV = max(cnt, maxV);
        // right ==k
        while (right < lens) {
            // move left
            left = right - k;
            if (isVowel(s[left]) ) {
                cnt--;
            }
            if (isVowel(s[right]) ) {
                cnt++;
            }
            right++;
            maxV = max(cnt, maxV);
        }
        return maxV;
    }

    int maxVowelsM2V1(string s, int k) {
        int lens = s.size();
        int left = 0;
        int right = 0;
        int maxV = 0;
        int cnt = 0;
        while (right < lens) { // [left, right]  size=k  , R-L +1 = K
            if (isVowel(s[right])) {
                cnt++;
            }
            if (right - left + 1 >= k) { //reach windowSize
                maxV = max(cnt, maxV);
               // move left
                if (isVowel(s[left])) {
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return maxV;
    }

    int maxVowels(string s, int k) {
        int lens = s.size();
        int left = 0;
        int right = 0;
        int maxV = 0;
        int cnt = 0;
        while (right < lens) { // [left, right)  size=k  , R-L  = K
            if (isVowel(s[right])) {
                cnt++;
            }
            right++;
            if (right - left >= k) { // reach windowSize
                maxV = max(cnt, maxV);
               // move left
                if (isVowel(s[left])) {
                    cnt--;
                }
                left++;
            }
        }
        return maxV;
    }

    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
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


