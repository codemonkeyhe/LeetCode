/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2020-09-10
 * @tag
 * @similar
 */

/*
Given an input string, reverse the string word by word.

Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

class Solution {
public:
/*
Runtime: 12 ms, faster than 98.88% of C++ online submissions for Reverse Words in a String.
Memory Usage: 8.2 MB, less than 69.34% of C++ online submissions for Reverse Words in a String.
*/
    string reverseWords(string s) {
        string res("");
        int n = s.size();
        int low = 0;
        int high = n - 1;
        while (low < n && s[low] == ' ') {
            low++;
        }
        while (high >= 0 && s[high] == ' ') {
            high--;
        }
        if (low == n || high < 0) {
            return "";
        }
        int j = high;
        //BUG int i = j - 1;
        int i = j;
        while (i >= low && j >= low) {
            while (i >= low && s[i] != ' ') {
                i--;
            }
            res += s.substr(i + 1, j - i);
            if (i >= low) {
                res += ' ';
            }
            j = i;
            while (j >= low && s[j] == ' ') {
                j--;
            }
            //BUG i = j-1;
            i = j;
        }
        return res;
    }

};

char* reverseWords(char* s) {}

int main() {
    Solution s;
}


/*
Tips
M1 新开一个string
两端压缩，去掉两端空格
逆序遍历，寻找单词分割点

M2 原地倒置-2遍reverse
Input:  "ab bad example"
Output: "example bad ab"
LeftWord ....  RightWord
m ... n
n ... m
if (n!=m)
例如 m=1 n=100
swap(LW, RW)必然会影响中间单词的空间

解决办法
先整体reverse，再reverse每个单词
这样效率太低了


*/


