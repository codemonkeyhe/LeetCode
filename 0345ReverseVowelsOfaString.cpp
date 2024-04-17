/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2024-04-17
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
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (54.75%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    197.3K
 * Total Submissions: 360.3K
 * Testcase Example:  '"hello"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 * 
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
 * 
 * 示例 1：
 * 输入：s = "hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 输入：s = "leetcode"
 * 输出："leotcede"
 * 
 * 提示：
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        int i = 0;
        int j = len-1; 
        while(i<j) {
            while(i < len && !isVowel(s[i])) {
                i++;
            }

            while(j>=0 && !isVowel(s[j]) ) {
                j--;
            }
            if (i >=j) break;
            char tmp = s[i];
             s[i] = s[j];
             s[j] = tmp;
             i++;
             j--;
        }
        return s;
    }

    bool isVowel(char s) {
        if (s < 'a') { 
            s = s+32;
        }
        if (s == 'a' || s == 'e' || s =='i' || s == 'o' || s == 'u') {
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
M1 双指针
lambda表达式 
       auto isVowel = [vowels = "aeiouAEIOU"s](char ch) {
            return vowels.find(ch) != string::npos;
        };

作者：力扣官方题解
链接：https://leetcode.cn/problems/reverse-vowels-of-a-string/solutions/944385/fan-zhuan-zi-fu-chuan-zhong-de-yuan-yin-2bmos/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


char vowel[] = "aeiouAEIOU";

bool isVowel(char ch) {
    for (int i = 0; vowel[i]; i++) {
        if (vowel[i] == ch) {
            return true;
        }
    }
    return false;
};


*/


